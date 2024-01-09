class Solution {
public:
    class job{
        public:
    int s,e,profit;
};

static bool comp(job j1,job j2)
{
    return j1.e<j2.e;
}
    
int binarys(job v[],int i)
{
    int l=0,h=i-1;
    int ans=-1;
    
    while(l<=h)
    {
        int m=(h+l)/2;
        if(v[m].e<=v[i].s)
        {
            ans=max(ans,m);
            l=m+1;
        }
         else
             h=m-1;
    }
    
    return ans;
}

    
    
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pr) {
        int n=pr.size();
        job v[n];
        for(int i=0;i<n;i++)
        {
          v[i].s=st[i];
          v[i].e=et[i];
          v[i].profit=pr[i];
        }
    sort(v,v+n,comp);
    long long dp[n];
    dp[0]=v[0].profit;
    
    for(int i=1;i<n;i++)
    {

        int last=binarys(v,i);
        long long including=last!=-1? dp[last]+v[i].profit : v[i].profit;
        dp[i]=max(dp[i-1],including);
        
    }
        
        return dp[n-1];
    }
};
