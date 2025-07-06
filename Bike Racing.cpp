/*Geek is organising a bike race with N bikers. The initial speed of the ith biker is denoted by Hi Km/hr and the acceleration of ith biker as Ai Km/Hr2. A biker whose speed is 'L' or more, is considered be a fast biker. The total speed on the track for every hour is calculated by adding the speed of each fast biker in that hour. When the total speed on the track is 'M' kilometers per hour or more, the safety alarm turns on. 
Find the minimum number of hours after which the safety alarm will start.
Your Task:
You do not need to read input or print anything. Your task is to complete the function buzzTime() which takes N, M, L and array H and array A as input parameters and returns the time when alarm buzzes.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long buzzTime(long N, long M, long L, long H[], long A[]) {
        long low = 0, high = 1e10, ans = -1;

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long totalSpeed = 0;

            for (long i = 0; i < N; i++) {
                long currentSpeed = H[i] + A[i] * mid;
                if (currentSpeed >= L) {
                    totalSpeed += currentSpeed;
                }
            }

            if (totalSpeed >= M) {
                ans = mid;
                high = mid - 1;  // try for a smaller hour
            } else {
                low = mid + 1;   // need more time
            }
        }

        return ans;
    }
};

// Example main function
int main() {
    Solution sol;

    // Example 1
    long N1 = 3, M1 = 400, L1 = 120;
    long H1[] = {20, 50, 20};
    long A1[] = {20, 70, 90};
    cout << "Example 1 Output: " << sol.buzzTime(N1, M1, L1, H1, A1) << endl;

    // Example 2
    long N2 = 2, M2 = 60, L2 = 120;
    long H2[] = {50, 30};
    long A2[] = {20, 40};
    cout << "Example 2 Output: " << sol.buzzTime(N2, M2, L2, H2, A2) << endl;

    return 0;
}
