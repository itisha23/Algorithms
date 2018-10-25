class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size(),i,j,ans=0;
        int hash[256];
        for(i=0;i<256;i++)
            hash[i]=-1;
        
        i=0;
        for(j=0;j<n;j++)
        {
            if(hash[s[j]]==-1)
            {
                hash[s[j]]=j;
                ans=max(ans,j-i+1);
            }
            else if(hash[s[j]]!=-1 && hash[s[j]]<i)
            {
                hash[s[j]]=j;
                ans=max(ans,j-i+1);
            }
            else
            {
                i=hash[s[j]]+1;
                hash[s[j]]=j;
                
            }
            //cout<<j<<" "<<ans<<endl;
        }
        return ans;
        
    }
};
