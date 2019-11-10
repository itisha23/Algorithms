//https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/

#include<vector>
#include<queue>
void findSmallestRange(int arr[][N], int n, int k)
{
    //priority_queue< >pq;
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> >> >pq;
    int i,flag=0,ans=INT_MAX,maxi=INT_MIN,diff,low_ans,high_ans;
    for(i=0;i<k;i++){
        pq.push(make_pair(arr[i][0],make_pair(i,0)));
        maxi = max(maxi,arr[i][0]);
    }
    
    flag=1;
    pair<int,pair<int,int> >x;
    while(flag){
        x = pq.top();
        pq.pop();
        diff = maxi-x.first+1;
        if(diff<ans){
            low_ans = x.first;
            high_ans = maxi;
        }
        ans = min(ans,diff);
        
        if(x.second.second+1<n){
          pq.push(make_pair(arr[x.second.first][x.second.second+1],make_pair(x.second.first, x.second.second+1)));
          maxi = max(maxi, arr[x.second.first][x.second.second+1]);
        }
        
        else{
            flag=0;
        }
        
    }
    cout<<low_ans<<" "<<high_ans<<endl;
}