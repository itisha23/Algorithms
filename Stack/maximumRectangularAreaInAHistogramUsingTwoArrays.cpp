//SEGMENATATION FAULT
//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0


#include<bits/stdc++.h>
 using namespace std;
 typedef long long int ll;
 #define f(i,a,b) for(i=a;i<b;i++)
 int main(){
     
     ll t;
     cin>>t;
     while(t--){
         ll n,i,ans=INT_MIN;
         cin>>n;
         ll arr[n];
         f(i,0,n)
            cin>>arr[i];
         stack<ll>st;
         ll next[n];
         for(i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            if(!st.empty())
                next[i]=st.top();
            else
                next[i]=n;
            st.push(i);
         }
         
        //  for(i=0;i<n;i++)
        //   cout<<next[i]<<" ";
        //   cout<<endl;
         
         stack<ll>st2;
         ll prev[n];
         for(i=0;i<n;i++){
             
             while(!st2.empty() && arr[st2.top()]>arr[i])
                st2.pop();
            if(!st2.empty())
                prev[i]=st2.top();
            else
                prev[i]=-1;
            st2.push(i);
             
         }
         
        //  for(i=0;i<n;i++)
        //   cout<<prev[i]<<" ";
        //   cout<<endl;
         
         
         for(i=0;i<n;i++){
             ans=max(ans,(next[i]-prev[i]-1)*arr[i]);
         }
         
         cout<<ans<<endl;
     }
 }
