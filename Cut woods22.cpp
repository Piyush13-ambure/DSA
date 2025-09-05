/*Given an array A[] of N integers, where A[i] denotes the height of ith tree. 
Geek needs to cut down M meters of wood. He has a woodcutting machine that works as follows:  Set the blade at a height parameter H, and the machine cuts off all trees having a height greater than H. The trees having less than height H remains intact.
Since Geek is an environmentalist, he doesn't want to cut woods more than necessary, so he set the height H as high as possible.
Find the maximum height H of the blade that still allows to cutoff at least M meters of wood.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxHeight() which takes an array and an integer and returns an integer as output.

*/




class Solution{
    public:
    //Function to find the maximum height of the box.
    int maxHeight(vector<int>&A, int B){
        int hi = 0,ans, n = A.size();
        
        //finding the maximum height among all the boxes.
        for(int i = 0; i < n; i++){
          hi = max(hi,A[i]);
        }
        int lo = 0;
        
        //applying binary search to find the maximum height possible
        //by comparing with the given maximum allowed height.
        while(lo <= hi)
        {
            long long int mid = (lo+hi)/2,sum = 0;
            
            //calculating the total difference of heights of each box
            //from the current mid height.
            for(int i = 0; i < n; i++)
                if(A[i] > mid)
                    sum += A[i] - mid;
            
            //if the total difference is greater than the given maximum
            //allowed sum, then we store the mid height and update the
            //lowest possible height by setting start = mid + 1.
            if(sum > B)
            {
                ans = mid;
                lo = mid+1;              
            }
            
            //if the total difference is less than the given maximum
            //allowed sum, then we update the highest possible height
            //by setting end = mid - 1.
            else if(sum < B)
                hi = mid-1;
            
            //if the total difference is equal to the given maximum
            //allowed sum, then we return the mid height as the maximum
            //possible height.
            else
                return mid;
        }
        //returning the maximum height of the box.
        return ans;
    }
};
