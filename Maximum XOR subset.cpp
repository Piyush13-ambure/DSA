/*Given an array arr[ ] of positive integers, the task is to find the maximum XOR value of the elements from all the possible subsets.


Your Task:  
You don't need to read input or print anything. Complete the function maxXor() which takes N and array arr as input parameter and returns the maximum xor value.
*/


class Solution{
	public:
	int maxXor(int arr[], int n)
	{
		int INT_BITS = 32; 

		// Initialize index of 
	    // chosen elements 
	    int index = 0; 
	  
	    // Traverse through all 
	    // bits of integer  
	    // starting from the most 
	    // significant bit (MSB) 
	    for (int i = INT_BITS-1; i >= 0; i--) 
	    { 
	        // Initialize index of 
	        // maximum element and 
	        // the maximum element 
	        int maxInd = index; 
	        int maxEle = INT_MIN; 
	        for (int j = index; j < n; j++) 
	        { 
	            // If i'th bit of arr[j] 
	            // is arr and arr[j] is  
	            // greater than max so far. 
	            if ( (arr[j] & (1 << i)) != 0  
	                     && arr[j] > maxEle ) 
	                maxEle = arr[j], maxInd = j; 
	        } 
	  
	        // If there was no  
	        // element with i'th 
	        // bit arr, move to 
	        // smaller i 
	        if (maxEle == INT_MIN) 
	        continue; 
	  
	        // Put maximum element 
	        // with i'th bit arr  
	        // at index 'index' 
	        swap(arr[index], arr[maxInd]); 
	  
	        // Update maxInd and  
	        // increment index 
	        maxInd = index; 
	  
	        // Do XOR of arr[maxIndex] 
	        // with all numbers having 
	        // i'th bit as arr. 
	        for (int j=0; j<n; j++) 
	        { 
	            // XOR arr[maxInd] those 
	            // numbers which have the 
	            // i'th bit arr 
	            if (j != maxInd && 
	               (arr[j] & (1 << i)) != 0) 
	                arr[j] = arr[j] ^ arr[maxInd]; 
	        } 
	  
	        // Increment index of 
	        // chosen elements 
	        index++; 
	    }

	    // Final result is  
	    // XOR of all elements 
	    int res = 0; 
	    for (int i = 0; i < n; i++) 
	        res ^= arr[i]; 
	    return res; 

	}
};
