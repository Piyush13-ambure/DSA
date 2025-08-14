/*Given an array of N integers, you have to find if it is possible to partition the array with following rules:

Each element should belong to exactly one partition.
Each partition should have atleast K elements.
Absolute difference between any pair of elements in the same partition should not exceed M.*/


vector<int> seg(800010);
vector<bool> marked(800010);

//function to push changes in segment tree
void push(int v){
    //if node is marked, propagate the changes to its children
    if(marked[v]){
        seg[2 * v] |= seg[v];
        seg[2 * v + 1] |= seg[v];
        marked[v] = false;
        marked[2 * v] = marked[2 * v + 1] = true;
    }
}

//function to get segment value at a particular position
int get_segment(int v, int l, int r, int pos){
    //if leaf node, return segment value
    if(l == r){
        return seg[v];
    }
    else{
        //push changes and recursively search for the value in left or right subtree
        push(v);
        int m = (l + r) / 2;
        if(pos <= m){
            return get_segment(2 * v, l, m, pos);
        }
        else{
            return get_segment(2 * v + 1, m + 1, r, pos);
        }
    }
}

//function to update segment values in a given range
void update_segment(int v, int l, int r, int query_l, int query_r){
    //if range matches exactly with the node, update the segment value and mark it
    if(l == query_l && r == query_r){
        seg[v] |= 1;
        marked[v]=true;
    }
    else{
        //push changes and recursively update left or right subtree
        push(v);
        int m = (l + r) / 2;
        if(query_r <= m){
            update_segment(2 * v, l, m, query_l, query_r);
        }
        else if(query_l > m){
            update_segment(2 * v + 1, m + 1, r, query_l, query_r);
        }
        else{
            update_segment(2 * v, l, m, query_l, m);
            update_segment(2 * v + 1, m + 1, r, m + 1, query_r);
        }
        //update the segment value based on the values in left and right subtree
        seg[v] = seg[2 * v] | seg[2 * v + 1];
    }
}

class Solution{
    public:
    //function to check if it is possible to partition array with given conditions
    bool partitionArray(int N, int K, int M, vector<int> &A){
        //initializing segment tree and marked array
        for(int i = 0; i <= 4 * N; i++){
            seg[i] = 0;
            marked[i] = false;
        }
        
        //sorting the array in ascending order
        sort(A.begin(), A.end());
        
        //iterating over the array
        for(int i = 0; i < N; i++){
            int right = (int )(upper_bound(A.begin(), A.end(), A[i] + M) - A.begin());
            right--;
            int left = K + i - 1;
            
            //if first element, update segment tree for given left and right range
            if(i == 0){
                if(left <= right){
                    update_segment(1, 1, N, left + 1, right + 1);
                }
            }
            //if previous element can be partitioned, update segment tree for given range
            else if(get_segment(1, 1, N, i)){
                if(left <= right){
                    update_segment(1, 1, N, left + 1, right + 1);
                }
            }
                
        }
        //check if last element can be partitioned
        if(get_segment(1, 1, N, N)){
            return true;
        }
        return false;
    }
};
