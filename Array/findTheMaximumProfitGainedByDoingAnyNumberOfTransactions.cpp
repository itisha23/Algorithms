#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,count=0,j;
        cin>>n;
        vector<int>vec(n);
        for(i=0;i<n;i++)
        cin>>vec[i];
        
        i=1;
        while(i<n) {
            
            j = i;
            while(j<n && vec[j] > vec[j-1])
                j++;
                
            if(j != i){
                count++;
                cout<<"("<<i-1<<" "<<j-1<<")"<<" ";
            }
            
            i = j+1;
        }
        
        if(count)
        cout<<endl;
        else{
            cout<<"No Profit"<<endl;
        }
    }
}