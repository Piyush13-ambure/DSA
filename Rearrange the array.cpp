/*Given an sequence from 1 to N and also given an array arr[] of size N. Basically the array is the permutation of 1 to N which determines that the element from ith position should move to the jth position. Now the task is to find the minimum number of operations such that each array element is present at its original positions.
(For more understanding please go through the examples)

Note: the answer can be large, so return the answer modulo 10^9+7.Your Task:
You don't need to read or print anything. Your task is to complete the function rearrange_array() which take arr[] of size N as input parameter and returns an integer which denotes the minimum number of operations needed.*/

class Solution{

    #define M 1000000007 // modulo value for calculations
    #define K 1000005 // size of prime array
    #define pb push_back // push_back function for vector

    public:
    vector<long long int> prime1; // vector to store prime numbers
    Solution(){
        prime1.resize(K,0); // initialize prime vector with 0    
    }
    
    // function to generate prime numbers upto K using sieve of Eratosthenes
    void sieve(){
        for(long long int i=2;i<1000005;i++){
            if(prime1[i]==0){
                for(long long int j=i;j<1000005;j+=i){
                    prime1[j]=i;
                }
            }
        }
    }
    
    // function to calculate power of a number modulo M
    long long int power(long long int a,long long int n){
        if (n == 0) 
            return 1; 
        long long int p = power(a, n / 2) % M; 
        p = (p * p) % M; 
        if (n & 1) 
            p = (p * a) % M; 
        return p; 
    }
    
    // function to calculate the LCM of all cycle lengths
    long long int lcm_calc(vector <long long int> &cycle_len){
        unordered_map<long long int,long long int> m; // map to store maximum frequency of prime factors
         unordered_map <long long int,long long int>:: iterator itr;
        for(long long int i=0;i<cycle_len.size();i++){
            unordered_map<long long int,long long int> m1;
            long long int z=cycle_len[i];
            while(z>1){
                int temp=prime1[z];
                m1[temp]+=1;
                z=z/temp;
            }
            for(itr=m1.begin();itr!=m1.end();itr++){
                m[itr->first]=max(itr->second,m[itr->first]);
            }
        }
        // calculate LCM using maximum frequency of prime factors
        long long int lcm=1;
        for(itr=m.begin();itr!=m.end();itr++){
                lcm=(lcm*power(itr->first,itr->second))%M;
        }
        return lcm;
    }
    
    // DFS function to find cycle lengths in the array
    void DFS(vector <int> &a,vector <long long int> &visited,long long int pos,long long int p){
        if(visited[pos]==0){
            visited[pos]=p;
        }
        else{
            return ;
        }
        DFS(a,visited,a[pos]-1,p);
    }
    
    // main function to rearrange the array
    int rearrange_array(vector<int> a){
        long long int n = a.size();
        vector <long long int> visited(n,0); // vector to store visited nodes
        long long int p=1; // variable to store number of cycles
        for(long long int i=0;i<n;i++){
            if(visited[i]==0){
                DFS(a,visited,i,p);
                p++;
            }
        }
        p-=1; // reduce p by 1 as it represents the number of cycles
        vector <long long int> cycle_len(p,0); // vector to store lengths of each cycle
        for(long long int i=0;i<n;i++){
            cycle_len[visited[i]-1]+=1; // increment length of cycle visited[i]
        }
        sieve(); // generate prime numbers
        long long int ans=lcm_calc(cycle_len); // calculate LCM of cycle lengths
        ans = (ans+M)%M; // take modulo of answer
        return (int)ans; // return answer as integer
    }
};
