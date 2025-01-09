//Given an array arr of integers, find all the elements that occur more than once in the array. If no element repeats, return an empty array.
//  main.cpp
//  duplicate
//
//  Created by piyush ambure on 09/01/25.
//

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to find elements that occur more than once in the array
    std::vector<int> findDuplicates(const std::vector<int>& arr) {
        std::unordered_map<int, int> freqMap; // To store frequency of each element
        std::vector<int> result; // To store the elements that occur more than once

        // Count the frequency of each element
        for (int num : arr) {
            freqMap[num]++;
        }

        // Check for elements with frequency greater than 1
        for (const auto& entry : freqMap) {
            if (entry.second > 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};

    std::vector<int> duplicates = solution.findDuplicates(arr);

    if (duplicates.empty()) {
        std::cout << "No duplicates found." << std::endl;
    } else {
        std::cout << "Duplicates: ";
        for (int num : duplicates) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
