//Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

//Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD = 100000;
        if (start == end) return 0;

        queue<pair<int, int>> q; // {current_value, steps}
        vector<int> visited(MOD, 0); // To mark visited values

        q.push({start, 0});
        visited[start] = 1;

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            for (int num : arr) {
                int next = (current * num) % MOD;
                
                // If we reach the end value
                if (next == end) return steps + 1;
                
                // If not visited, push into queue
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1; // If end is not reachable
    }
};

int main() {
    int n, start, end;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter start and end: ";
    cin >> start >> end;

    Solution sol;
    int result = sol.minimumMultiplications(arr, start, end);
    cout << "Minimum steps to reach end: " << result << endl;

    return 0;
}
