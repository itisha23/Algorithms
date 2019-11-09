int *mergeKArrays(int arr[][N], int k)
{
    //int ans[N*k];
    int *ans = (int*)malloc(sizeof(int)*N*k);
    int i,j;
    pair<int,pair<int,int> >x;
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> >>, greater<pair<int,pair<int,int> >> >pq;
    for(i=0;i<k;i++){
        pq.push(make_pair(arr[i][0],make_pair(i,0)));
    }
    
    j=0;
    while(!pq.empty()){
        x = pq.top();
        pq.pop();
        ans[j]=x.first;
        j++;
        if(((x.second.second)+1)<k){
            pq.push(make_pair(arr[x.second.first][(x.second.second)+1],make_pair(x.second.first,(x.second.second)+1)));
        }
    }
    return ans;
}