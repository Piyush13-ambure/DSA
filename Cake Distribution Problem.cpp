//Geek is organizing a birthday party, so his friends brought a cake for him. The cake consists of N chunks, whose individual sweetness is represented by the sweetness array. Now at the time of distribution, Geek cuts the cake into K + 1 pieces to distribute among his K friends. One piece he took for himself. Each piece consists of some consecutive chunks. He is very kind, so he left the piece with minimum sweetness for him.

//You need to find the maximum sweetness that the Geek can get if he distributes the cake optimally.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canDivide(vector<int>& sweetness, int N, int K, int minSweet) {
        int pieces = 0, currentSum = 0;

        for (int i = 0; i < N; i++) {
            currentSum += sweetness[i];
            if (currentSum >= minSweet) {
                pieces++;
                currentSum = 0;
            }
        }

        return pieces >= (K + 1);
    }

    int maxSweetness(vector<int>& sweetness, int N, int K) {
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0);
        int result = left;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canDivide(sweetness, N, K, mid)) {
                result = mid;  // Try to maximize the minimum sweetness
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    vector<int> sweetness = {6, 3, 2, 8, 7, 5};
    int N = sweetness.size();
    int K = 2;

    Solution obj;
    cout << "Maximum sweetness Geek can get: " << obj.maxSweetness(sweetness, N, K) << endl;

    return 0;
}
