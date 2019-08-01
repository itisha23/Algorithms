 #include<bits/stdc++.h>
 using namespace std;
 typedef long long int ll;
 #define f(i,a,b) for(i=a;i<b;i++)
 int main(){
     
     ll t;
     cin>>t;
     while(t--){
         ll n,k,i;
         cin>>n>>k;
         ll arr[n];
         f(i,0,n)
            cin>>arr[i];
        deque<int>dq;
        dq.push_back(0);
        f(i,1,k){
            if(i<n){
             
            
                    while(dq.empty()!=1 && arr[dq.back()]<=arr[i]){
                        dq.pop_back();
                    }
                    dq.push_back(i);
                
            }
        }
        cout<<arr[dq.front()]<<" ";
        f(i,k,n){
            while(dq.empty()!=1 && dq.front()<=i-k)
              dq.pop_front();
           
             
                    while(dq.empty()!=1 && arr[dq.back()]<=arr[i]){
                        dq.pop_back();
                    }
                    dq.push_back(i);
            
            cout<<arr[dq.front()]<<" ";
        }
        
        cout<<endl;
        
     }
 }
