/*Given three integers m, n and k. Consider a grid of m * n, where mat[i][j] = i * j (1 based index). The task is to return the kth smallest element in the m * n multiplication table.

*/
#include <iostream>
using namespace std;

class Solution {
public:
    int countLessEqual(int m, int n, int mid) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += min(mid / i, n);
        }
        return count;
    }

    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(m, n, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    int m, n, k;

    cout << "Enter m, n, and k: ";
    cin >> m >> n >> k;

    int result = sol.kthSmallest(m, n, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
