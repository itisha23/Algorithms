vector<pair<int,int>>vec[n];
for(i=0;i<n;i++)
vec[i].resize(n);

for(i=0;i<n;i++)
vec[i][i]=make_pair(arr[i],0);

for(l=2;l<=n;l++){
  for(i=0;i<=n-l;i++){
      j=i+l-1;
      if(arr[i]+dp[i+1][j].second > arr[j]+dp[i][j-1].second){
        dp[i][j].first=arr[i]+dp[i+1][j].second ;
        dp[i][j].second= dp[i+1][j].first;
      }
      else{
       dp[i][j].first= arr[j]+dp[i][j-1].second ;
        dp[i][j].second= dp[i][j-1].first;
      }
    }
}
