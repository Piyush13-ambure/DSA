/*Given an array of integers of size N. For each ith element in the array, calculate the absolute difference between the count of numbers that are to the left of i and are strictly greater than ith element, and the count of numbers that are to the right of i and are strictly lesser than ith element.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function greaterLesser() which takes the array arr[], its size Nas input parameters and returns the required array.
*/

class Solution{   
public:
    struct Seg_Tree{
        vector<int> tree, arr;
	    int n;
        public:
	    Seg_Tree(int _n, vector<int> _arr){
	        n = _n;
		    tree.resize(4 * n + 4);
		    arr = _arr;
	    }
 
        void build(int s, int e, int idx){
            if(s == e){
                tree[idx] = arr[s];
                return ;
            }
 
            int mid = s + (e - s)/2;
            build(s, mid , 2 * idx);
            build(mid + 1, e, 2 * idx + 1);
 
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
        }
 
        void update(int pos, int v, int s, int e, int idx){
            if(pos < s || pos > e)
                return ;
 
            if(s == e){
                tree[idx]++;
                return ;
            } 
 
            int mid = s + (e - s) / 2;
            update(pos, v, s, mid, 2 * idx);
            update(pos, v, mid + 1, e, 2 * idx + 1);
 
            tree[idx] = (tree[2 * idx] + tree[2 * idx +1]);
        }

        void update(int pos, int v){
            update(pos, v, 1, n, 1);
        }
        int query(int qs, int qe, int s, int e, int idx){
            if(qs <= s && qe >= e)
                return tree[idx];

            if(qs > e || qe < s)
                return 0;

            int mid = s + (e - s)/2;
            return query(qs, qe, s, mid, 2 * idx) + query(qs, qe, mid + 1, e, 2 * idx + 1);
        }

        int query(int v){
            return query(v + 1, n, 1, n, 1);
        }
    };
    vector<int> solve(vector<int> arr, int n){
        vector<int> A(n+1);
        map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]=0;
        int c=0;
        for(auto i:mp)
            mp[i.first]=++c;
        for(int i=1;i<=n;i++)
            A[i]=mp[arr[i-1]];
        vector<int> res;
        Seg_Tree ob(n, arr);
        for(int i = 1; i <= n; i++){
            ob.update(A[i], 1);
            res.push_back(ob.query(A[i]));
        }
        return res;
    }
    
    
    vector<int> greaterLesser(vector<int>A, int N){
        // code here 
        vector<int>left,right,ans;
        left=solve(A,N);
        vector<int>temp(N);
        for(int i=0;i<N;i++)
            temp[i]=-A[N-i-1];
        right=solve(temp,N);
        for(int i=0;i<N;i++)
            ans.push_back(abs(left[i]-right[N-i-1]));
        return ans;
    }
    
};
