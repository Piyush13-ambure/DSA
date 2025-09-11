/*Given an array arr of size N, the task is to make strictly increasing and strictly decreasing subsequences from the array such that each array element belongs to increasing subsequence or decreasing subsequence, but not both, or can be part of none of the subsequence. Minimize the number of elements that are not part of any of the subsequences and find the count of such elements.*/

class Solution{
		
	private:
	int countMinUtil(int arr[], vector<vector<vector<int>>> &dp, int n, int dec, 
                                            int inc, int i) 
	{ 
	  
	    // If whole array is traversed. 
	    if (i == n) 
	        return 0; 

	    // If already calculated, return value. 
	    if (dp[dec][inc][i] != -1) 
	        return dp[dec][inc][i]; 
	  
	    // calculating by considering element as part of 
	    // decreasing sequence. 
	    if (arr[i] < arr[dec]) 
	        dp[dec][inc][i] = countMinUtil(arr, dp, n, i, inc, i + 1); 
	  
	    // calculating by considering element as part of 
	    // increasing sequence. 
	    if (arr[i] > arr[inc]) 
	    { 
	        // If cannot be calculated for decreasing sequence. 
	        if (dp[dec][inc][i] == -1) 
	            dp[dec][inc][i] = countMinUtil(arr, dp, n, dec, i, i + 1); 
	  
	        // After considering once by decreasing sequence, now try 
	        // for increasing sequence. 
	        else
	            dp[dec][inc][i] = min(countMinUtil(arr, dp, n, dec, i, i + 1), 
	                                                  dp[dec][inc][i]); 
	    } 
	  
	    // If element cannot be part of any of the sequence. 
	    if (dp[dec][inc][i] == -1) 
	        dp[dec][inc][i] = 1 + countMinUtil(arr, dp, n, dec, inc, i + 1); 
	  
	    // After considering element as part of increasing and 
	    // decreasing sequence trying as not part of any of the 
	    // sequence. 
	    else
	        dp[dec][inc][i] = min(1 + countMinUtil(arr, dp, n, dec, inc, i + 1), 
	                                                    dp[dec][inc][i]); 
	  
	    return dp[dec][inc][i]; 
	} 

	public:
	int minCount(int arr[], int N) 
	{ 

		// Adding two number at the end of array, so that 
	    // increasing and decreasing sequence can be made. 
	    // MAX - 2 index is assigned INT_MAX for decreasing sequence 
	    // because/ next number of sequence must be less than it. 
	    // Similarly, for Increasing sequence INT_MIN is assigned to 
	    // MAX - 1 index. 

	    int a[N+2];
	    for(int i = 0; i < N; i++)
	    	a[i] = arr[i];

	    a[N] = INT_MAX; 
	    a[N+1] = INT_MIN; 

	    N += 2;
	  
	    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, -1)));
	  
	    return countMinUtil(a, dp, N, N - 2, N - 1, 0); 
	} 
};
