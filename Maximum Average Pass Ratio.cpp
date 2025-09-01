/*There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.*/

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        using p = pair<double, int>;
        priority_queue<p> pq;

        // Push initial marginal gain for each class
        for (int i = 0; i < classes.size(); ++i) {
            double curr = (double)classes[i][0] / classes[i][1];
            double newPr = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            pq.push({newPr - curr, i});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto it = pq.top();
            pq.pop();
            int i = it.second;
            classes[i][0] += 1;
            classes[i][1] += 1;
            double curr = (double)classes[i][0] / classes[i][1];
            double newPr = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            pq.push({newPr - curr, i});
        }

        // Compute final average pass ratio
        double ans = 0.0;
        for (auto& it : classes) {
            ans += (double)it[0] / it[1];
        }

        return ans / classes.size();
    }
};
