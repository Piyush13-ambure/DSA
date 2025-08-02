/*Geek is organizing a party at his house. For the party, he needs exactly n donuts for the guests. Geek decides to order the donuts from a nearby restaurant, which has m chefs and each chef has a rank r.
A chef with rank r can make 1 donut in the first r minutes, 1 more donut in the next 2r minutes, 1 more donut in the next 3r minutes, and so on.
For example, a chef with rank 2, can make one donut in 2 minutes, one more donut in the next 4 minutes, and one more in the next 6 minutes. So, it take 2 + 4 + 6 = 12 minutes to make 3 donuts. A chef can move on to making the next donut only after completing the previous one. All the chefs can work simultaneously.
Since, it's time for the party, Geek wants to know the minimum time required in completing n donuts. Return an integer denoting the minimum time.*/

class Solution {
  public:

    // returns number of donuts a chef with
    // rank r can make in time t
    int donutsByChef(int t, int r) {
        double D = 1.0 + 8.0 * t / r;
        return int((-1.0 + sqrt(D)) / 2.0);
    }

    // Checks if all chefs can make
    // at least n donuts in time t
    bool canMake(vector<int>& ranks, int n, int t) {
        int total = 0;
        for (int r : ranks) {
            total += donutsByChef(t, r);
            if (total >= n)
                return true;
        }
        return false;
    }

    int minTime(vector<int>& ranks, int n) {
        int rmin = *min_element(ranks.begin(), ranks.end());
        int hi = rmin * n * (n + 1) / 2;
        int lo = 0, ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(ranks, n, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
