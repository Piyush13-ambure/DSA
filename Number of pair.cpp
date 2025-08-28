/*The director of your college is planning to send 2 people to the ICPC regionals. He wants them to be from different branches. You will be given a list of pairs of student ids. Each pair is made of students from the same branch. Determine how many pairs of students from different branches they can choose from
Your Task:  
You don't need to read input or print anything. Your task is to complete the function numberOfPairs() which takes the 2d array pairs[], its size P and an integer N representing total number of students as input parameters and returns the total number of pairs(as explianed in the question)..*/





int find(int s[],int u)
{
    int x=u;
    while(s[u]!=u)
        u=s[u];
    s[x]=u;
    return u;
}
void functUnion(int s[],int r[],int u,int v)
{
    int x=find(s,u);
    int y=find(s,v);
    if(x==y)
        return;
    r[y]+=r[x];
    s[x]=y;
}
class Solution {
    public:
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n)
        {
            int s[n];
            int r[n];
            for(auto &j:r)
                j=1;
            for(int i=0;i<n;i++)
                s[i]=i;
            for(int i=0;i<p;i++)
            {
                functUnion(s,r,pairs[i][0],pairs[i][1]);
            }
            vector <long long int> ans;
            for(int i=0;i<n;i++)
            {
                if(s[i]==i)
                    ans.push_back(r[i]);
            }
            long long int n1=n;
            // cout<<(n1*n1-n1)/2<<endl;
            long long int fans=(n1*n1-n1)/2;
            // cout<<fans<<" ";
            // cout<<endl;
            long long int tans=0;
            for(auto j:ans)
                tans+=(j*j-j)/2;
            // cout<<tans<<endl;
            return fans-tans;
        }
};
