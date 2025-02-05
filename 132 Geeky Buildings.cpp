//There are N buildings in Linear Land. They appear in a linear line one after the other and their heights are given in the array arr[]. Geek wants to select three buildings in Linear Land and remodel them as recreational spots. The third of the selected building must be taller than the first and shorter than the second.
//Can geek build the three-building recreational zone? 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool recreationalSpot(int arr[], int n) {
        if (n < 3) return false;  // At least 3 buildings required

        vector<int> minHeight(n);  // To store the minimum height up to index i
        minHeight[0] = arr[0];

        for (int i = 1; i < n; i++)
            minHeight[i] = min(minHeight[i - 1], arr[i]);

        stack<int> st;  // Monotonic decreasing stack to maintain possible `arr[k]`

        for (int j = n - 1; j >= 0; j--) {
            if (arr[j] > minHeight[j]) { // Ensure arr[i] < arr[k] condition
                while (!st.empty() && st.top() <= minHeight[j]) 
                    st.pop(); // Remove invalid `arr[k]` candidates

                if (!st.empty() && st.top() < arr[j]) 
                    return true; // Found a valid (arr[i], arr[k], arr[j])

                st.push(arr[j]); // Push current building as a candidate for `arr[k]`
            }
        }

        return false;
    }
};

int main() {
    Solution obj;
    int arr1[] = {4, 7, 11, 5, 13, 2};
    int n1 = 6;
    cout << (obj.recreationalSpot(arr1, n1) ? "True" : "False") << endl;

    int arr2[] = {11, 11, 12, 9};
    int n2 = 4;
    cout << (obj.recreationalSpot(arr2, n2) ? "True" : "False") << endl;

    return 0;
}
