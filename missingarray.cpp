#include <vector>
#include <numeric> // For std::accumulate
#include <iostream>

class Solution {
public:
    int findMissingElement(const std::vector<int>& arr, int n) {
        // Calculate the sum of integers from 1 to n
        int totalSum = n * (n + 1) / 2;

        // Calculate the sum of elements in the array
        int arraySum = std::accumulate(arr.begin(), arr.end(), 0);

        // The missing element is the difference between the total sum and the array sum
        return totalSum - arraySum;
    }
};

int main() {
    Solution solution;
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<int> arr(n - 1);
    std::cout << "Enter " << n - 1 << " elements: ";
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> arr[i];
    }

    int missingElement = solution.findMissingElement(arr, n);
    std::cout << "Missing element: " << missingElement << std::endl;

    return 0;
}

