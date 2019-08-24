class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(),i,mini,ans;
        if(n==0)
            return 0;
        mini=prices[0];
        ans=0;
        for(i=1;i<n;i++)
        {
            mini=min(mini,prices[i]);
            ans=max(ans,prices[i]-mini);
        }
        return ans;
    }
};
