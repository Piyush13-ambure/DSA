/*You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // dp array to store max points from index i onwards
        
        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            
            // Solve the current question
            long long solve = points + (i + brainpower + 1 < n ? dp[i + brainpower + 1] : 0);
            
            // Skip the current question
            long long skip = dp[i + 1];
            
            // Store the maximum of both choices
            dp[i] = max(solve, skip);
        }
        
        return dp[0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> questions1 = {{3,2},{4,3},{4,4},{2,5}};
    cout << "Output: " << sol.mostPoints(questions1) << endl;
    
    vector<vector<int>> questions2 = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    cout << "Output: " << sol.mostPoints(questions2) << endl;
    
    return 0;
}
