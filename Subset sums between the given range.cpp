/*Given an array A[] of N integers and two integers L and R. The task is to return the total subsets of array A whose sum lies between the range [L, R], inclusive*/

class Solution{
    public:
    //Function to generate all the subsets of the array.
    void subset(vector<int> &s,vector<int> &v,int n,int start)
    {
        int i;
        int j;
        int sum;

        //Generating all possible subsets using bitmasking technique.
        for(i = 0; i < pow(2,n); i++) {
            sum = 0;
            for(j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    sum = sum + s[j+start];
                }
            }
            v.push_back(sum);
        }
    }
    
    //Function to count the number of subsets whose sum lies in the given range.
    long long int countSubsets(vector<int>&arr, int n, int l, int r){
        vector<int> left,right;
        int hi, lo;
        long long int sum;
        sum = 0;
        
        //Generating the subsets of the left half of the array.
        subset(arr,left,n/2,0);

        //Generating the subsets of the right half of the array.
        subset(arr,right,(n&1)?n/2+1:n/2,n/2);
        sort(right.begin(),right.end());

        //Calculating the count of subsets whose sum lies in the given range.
        for(int i = 0; i < left.size();i++) {
            lo = lower_bound(right.begin(),right.end(),l-left[i])-right.begin();
            hi = upper_bound(right.begin(),right.end(),r-left[i])-right.begin();
            sum = sum + (hi-lo);
        }
        return sum;
    }
};
