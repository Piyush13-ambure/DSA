/*Given an array nums[ ] of size n, a triplet (nums[i], nums[j], nums[k]) is called a Magic Triplet if nums[i] < nums[j] < nums[k] and i < j < k.
Count the number of magic triplets in the given array.*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define oset                 tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
//User function Template for C++

class Solution {
public:
    long long countTriplets(vector<int> &nums) {
        // Code here.

        oset lef, rig;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
            rig.insert({nums[i], i});

        for (int i = 0; i < nums.size(); i++) {
            rig.erase({nums[i], i});


            long long fir = lef.order_of_key({nums[i], -1000});
            long long sec = (int)rig.size() - rig.order_of_key({nums[i], 1e9});

            ans += fir * sec;

            lef.insert({nums[i], i});
        }

        return ans;

    }
};
