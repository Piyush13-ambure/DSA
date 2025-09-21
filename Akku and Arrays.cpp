/*Akku have solved many problems, she is genius. One day her friend gave her an Array of size n and asked her to perform
some queries of following type:
Each query consists of three integers
1 A B : Update the Array at index A by value B
2 A B : if the subarray from index A to B (both inclusive) is
        1. Both increasing(Non-decreasing) and decreasing(Non-increasing) print -1
        2. Only increasing(Non-decreasing) print 0
        3. Only decreasing(Non-increasing) print 1
        4. Neither increasing nor decreasing print -1

Akku needs your help, can you help her*/




using ll = long long int;
struct node
{
	bool isIncreasing=true,isDecreasing=true;
	int st=-1,en=-1;
};
  node tree[40005];
  ll a[10001],l,r,idx,val;

class Solution {
public:
  node add(node n1,node n2)
  {
     node ret;
     if(n1.st==-1)
      return n2;
     else if(n2.st==-1)
      return n1;
     ret.st=n1.st;
     ret.en=n2.en;
     if((n1.isIncreasing==false and n1.isDecreasing==false) or (n2.isIncreasing==false and n2.isDecreasing==false))
     {
      ret.isIncreasing=false;ret.isDecreasing=false;
      return ret;
     }
     if(n1.isIncreasing and n1.isDecreasing and n2.isIncreasing and n2.isDecreasing)
     {
        if(n1.en>n2.st)
        {
          ret.isDecreasing=true;
          ret.isIncreasing=false;
        }
        else if(n1.en<n2.st)
        {
          ret.isDecreasing=false;
          ret.isIncreasing=true;
        }
        else if(n1.en==n2.st)
        {
          ret.isDecreasing=true;ret.isIncreasing=true;
        }
        return ret;
     }
     if(n1.isIncreasing and n2.isIncreasing)
     {
        ret.isDecreasing=false;
        if(n1.en<=n2.st)
          ret.isIncreasing=true;
        else
          ret.isIncreasing=false;
        return ret;
     }
     if(n1.isDecreasing and n2.isDecreasing)
     {
       ret.isIncreasing=false;
       if(n1.en>=n2.st)
       ret.isDecreasing=true;
       else
       ret.isDecreasing=false;
       return ret;
     }
     ret.isDecreasing=false;ret.isIncreasing=false;
     return ret;
  }

  void b(int nd,int st,int en)
  {
    if(st>en)return;
    if(st==en)
    {
      tree[nd].isIncreasing=true;
      tree[nd].isDecreasing=true;
      tree[nd].st=a[st];
      tree[nd].en=a[st];
    }
    else
    {
      ll mid=(st+en)>>1;
      b(nd*2+1,st,mid);
      b(nd*2+2,mid+1,en);
      tree[nd]=add(tree[nd*2+1],tree[nd*2+2]);
    }
  }

  void u(int nd,int st,int en)
  {
    if(st>en or idx<st or idx>en)
      return;
    if(st==en)
    {
      a[idx]=val;
      tree[nd].isIncreasing=true;
      tree[nd].isDecreasing=true;
      tree[nd].st=a[st];
      tree[nd].en=a[st];
    }
    else
    {
      ll mid=(st+en)>>1;
      if(idx>=st and idx<=mid)
        u(nd*2+1,st,mid);
      else
        u(nd*2+2,mid+1,en);
      tree[nd]=add(tree[nd*2+1],tree[nd*2+2]);
    }
  }

  node q(int nd,int st,int en)
  {
    node ret;
    if(st>en or l>en or r<st)
      return ret;
    if(l<=st and en<=r)
      return tree[nd];
    int mid=(st+en)>>1;
    return add(q(nd*2+1,st,mid),q(nd*2+2,mid+1,en));
  }

  int solve(node n1)
  {
    if(n1.isIncreasing and n1.isDecreasing)return -1;
    if(n1.isIncreasing)return 0;
    if(n1.isDecreasing)return 1;
    return -1;
  }
  vector<int>solveQueries(vector<int>nums, vector<vector<int>>Queries){
  	for(int i = 0; i < nums.size(); i++)a[i] = nums[i];
  	int n = nums.size();
  	b(0,0,n-1);
  	vector<int>ans;
  	for(auto i: Queries){
  		int x = i[0];
  		if(x == 1){
  			idx = i[1];
  			val = i[2];
  			idx--;
  			u(0,0,n-1);
  		}
  		else{
  			l = i[1];
  			r = i[2];
  			l--;
  			r--;
  			ans.push_back(solve(q(0,0,n-1)));
  		}
  	}
  	return ans;

  }

};
