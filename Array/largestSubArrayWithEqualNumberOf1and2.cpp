int maxLen(int arr[], int n)
{
        map<int,int>mp;
        int sum=0, i, ans=0;
        
        mp[0]=-1;
        for(i=0;i<n;i++){
            if(arr[i] ==0)
                arr[i]=-1;
        }
        for(i=0;i<n;i++){
            sum+=arr[i];
            if(mp.count(sum)){
                ans = max(ans, i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        
        return ans;
}