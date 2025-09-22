/*There are N piles of stones arranged in a row. The ith pile has stones [ i ] stones.
A move consists of merging exactly K consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these K piles.
Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function mergeStones() which takes the array of integers stones ,integer N and an integer K as parameters and returns the minimum cost to merge all stones.
*/


class Solution {
public:
  int dp[31][31][31], sum[31]; // 3D array for memoization and array for storing prefix sums
  int f(int L, int R, int piles, int k) { // recursive function for finding the minimum cost
    if (L == R && piles == 1) // base case: if there is only one pile left
      return dp[L][R][piles] = 0; // minimum cost is 0
    if ((R - L + 1 - piles) % (k - 1) != 0) // check if the piles can be evenly merged
      return INT_MAX / 2; // if not, return a large value
    int &ret = dp[L][R][piles]; // reference to memoization value
    if (ret != -1) // if memoization value is already calculated
      return ret; // return the memoization value
    ret = INT_MAX / 2; // initialize memoization value with a large value
    if (piles == 1) // if only one pile left
      ret = f(L, R, k, k) + sum[R + 1] - sum[L]; // merge all the stones into one pile
    else { // if more than one pile left
      for (int i = L; i <= R; i++) { // try merging at different positions
        ret = min(ret, f(L, i, 1, k) + f(i + 1, R, piles - 1, k)); // find minimum cost by merging at each position
      }
    }
    return ret; // return the minimum cost
  }
  int mergeStones(vector<int> &stones, int N, int K) {
    memset(sum, 0, sizeof sum); // initialize sum array with 0
    memset(dp, -1, sizeof dp); // initialize dp array with -1
    for (int i = 0; i < N; i++)
      sum[i + 1] = sum[i] + stones[i]; // calculate prefix sums
    int fin = f(0, N - 1, 1, K); // find the minimum cost using the recursive function
    if (fin >= INT_MAX / 2) // if the minimum cost is a large value, indicating it is not possible
      fin = -1; // set the result as -1
    return fin; // return the final result
  }
};
