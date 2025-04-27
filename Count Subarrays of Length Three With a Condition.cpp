/*Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i <= n - 3; ++i) {
            int first = nums[i];
            int middle = nums[i+1];
            int third = nums[i+2];
            
            if (middle % 2 == 0) { // Only if middle is even
                if (first + third == middle / 2) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int result = obj.countSubarrays(nums);
    cout << "Number of valid subarrays of length 3: " << result << endl;
    
    return 0;
}
