/*You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.

In one operation you can choose any subarray from initial and increment each value by one.

Return the minimum number of operations to form a target array from initial.

The test cases are generated so that the answer fits in a 32-bit integer.*/


class Solution {
public:
    static int minNumberOperations(vector<int>& target) {
        adjacent_difference(target.begin(), target.end(), target.begin());
        return accumulate(target.begin(), target.end(), 0,
        [](int sum, int x){ return sum+=max(0,x);});
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
