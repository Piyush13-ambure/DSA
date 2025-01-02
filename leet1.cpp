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
    int size;

    // Take array size as input
    cout << "Enter the size of the array: ";
    cin >> size;

    int nums[size];

    // Take array elements as input
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    while (true) {
        int choice, target;

        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Find new target\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Take target as input
                cout << "Enter the target value: ";
                cin >> target;

                // Find and print indices
                twoSum(nums, size, target);
                break;

            case 2:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
