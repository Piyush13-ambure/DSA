//Given an array of n integers. Find the minimum non-negative number to be inserted in array, so that sum of all elements of array becomes prime.



#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to check if a number is prime
    bool isPrime(int num) {
        if (num < 2) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    // Function to find the minimum number to be added to make sum prime
    int minNumber(int arr[], int N) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }

        int x = 0;
        while (!isPrime(sum + x)) {
            x++;
        }
        return x;
    }
};

// Main function
int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    
    int arr[N];
    cout << "Enter the array elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int result = obj.minNumber(arr, N);
    cout << "Minimum number to be added: " << result << endl;

    return 0;
}
