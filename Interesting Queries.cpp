/*Given an array nums of n elements and q queries . Each query consists of two integers l and r . You task is to find the number of elements of nums[] in range [l,r] which occur atleast k times.
 */
//Including necessary header files and defining constants.
#define MAXN 100005
#define BLOCK 318

//Defining variables.
int cnt[MAXN], a[MAXN], ans[MAXN], answer=0;
struct query
{
    int L, R, i;
};
query q[MAXN];

class Solution {
public:
    //Function to compare two queries.
    static bool acompare(query x, query y)
    {
        //Sorting queries based on their block.
        if(x.L/BLOCK != y.L/BLOCK)
        {
            return x.L/BLOCK < y.L/BLOCK;
        }
        //If block is same, sort queries based on their end point.
        return x.R < y.R;
    }

    //Function to add a number to the count array and update the answer.
    void add(int p, int k)
    {
        cnt[a[p]]++;
        if(cnt[a[p]] == k)
        {
            answer++;
        }
    }

    //Function to subtract a number from the count array and update the answer.
    void subtract(int p, int k)
    {
        cnt[a[p]]--;
        if(cnt[a[p]] == k-1)
        {
            answer--;
        }
    }

    //Function to solve the given queries.
    vector<int> solveQueries(vector<int> nums, vector<vector<int>> Queries, int k)
    {
        //Calculating size of input arrays.
        int n = nums.size();
        int m = Queries.size();

        //Initializing arrays and variables.
        memset(a, 0, sizeof(a));
        memset(cnt, 0, sizeof(cnt));
        answer = 0;

        //Copying elements from input arrays to necessary arrays.
        for(int i = 0; i < n; i++)
        {
            a[i] = nums[i];
        }
        for(int i = 0; i < m; i++)
        {
            q[i].L = Queries[i][0];
            q[i].R = Queries[i][1];
            q[i].L--;
            q[i].R--;
            q[i].i = i;
        }

        //Sorting queries based on blocks and end points.
        sort(q, q+m, acompare);

        //Initializing variables.
        int c_l = 0, c_r = 0, l, r;
        vector<int> ans(m);

        //Iterating over each query and calculating the answer.
        for(int i = 0; i < m; i++)
        {
            l = q[i].L;
            r = q[i].R;

            //Updating left pointer.
            while(c_l < l)
            {
                subtract(c_l, k);
                c_l++;
            }
            while(c_l > l)
            {
                add(c_l-1, k);
                c_l--;
            }

            //Updating right pointer.
            while(c_r <= r)
            {
                add(c_r, k);
                c_r++;
            }
            while(c_r > r+1)
            {
                subtract(c_r-1, k);
                c_r--;
            }

            //Storing the answer for the current query.
            ans[q[i].i] = answer;
        }

        //Returning the final answers for all queries.
        return ans;
    }
};
