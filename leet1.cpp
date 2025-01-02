//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.You may assume that each input would have exactly one solution, and you may not use the same element twice.You can return the answer in any order. in cpp
#include <iostream>
using namespace std;

void twoSum(int nums[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (nums[i] + nums[j] == target) {
                cout << "[" << i << ", " << j << "]" << endl;
                return;
            }
        }
    }
    cout << "No solution found." << endl;
}

int main() {
    int size, target;

    // Take array size as input
    cout << "Enter the size of the array: ";
    cin >> size;

    int nums[size];

    // Take array elements as input
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    // Take target as input
    cout << "Enter the target value: ";
    cin >> target;

    // Find and print indices
    twoSum(nums, size, target);

    return 0;
}
