/*You are given an array arr of N integers. You need to find the maximum score of an array.

The score of an array is calculated as follows.

Choose an integer i, 1<=i<=size of current array and add a[i-1] * a[i] * a[i+1] to the score.
Delete a[i], on deleting a[i], i-1 and i+1 become adjacent. i.e i+1 becomes i and size of an array shrinks.
Repeat the process till the size of an array becomes 0.
Note:  Assume an extra 1 at each boundary.*/



class Solution{
public:
    long long int maxProductSum(int N, int arr[])
    {
           // Add Bordering Balloons
    long long int B[N+2];
    B[0] = B[N + 1] = 1;
         
    for(int i = 1; i <= N; i++)
        B[i] = arr[i - 1];
     
    // Declaring DP array
    
    long long dp[N+2][N+2];
     for(int i=0;i<=N+1;i++)for(int j=0;j<=N+1;j++)dp[i][j]=0;
     
    for(int length = 1;length < N + 1; length++)
    {
        for(int left = 1;left < N - length + 2; left++)
        {
            int right = left + length -1;
             
            // For a sub-array from indices
            // left, right. This innermost
            // loop finds the last balloon burst
            for(int last = left; last < right + 1; last++)
            {
                dp[left][right] = max(dp[left][right], dp[left][last - 1] + B[left - 1] * B[last] * B[right + 1] +dp[last + 1][right]);
            }
        }
    }
    return dp[1][N];
    }
};
