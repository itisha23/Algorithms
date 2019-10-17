//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s,p;
        cin>>s>>p;
        int m=p.size(),n=s.size(),i,ans,low,count=0,len,start;
        int pat[256]={0};
        int hash[256]={0};

        
        for(i=0;i<m;i++)
            pat[p[i]]++;
          
          
        ans=INT_MAX; 
        low=0; 
        for(i=0;i<n;i++){
            hash[s[i]]++;
            if(pat[s[i]]!=0 && hash[s[i]]<=pat[s[i]])
                count++;
            
            if(count==m){
                
                while(pat[s[low]]==0 || pat[s[low]]<hash[s[low]]){
                    if(pat[s[low]]<hash[s[low]])
                       hash[s[low]]--;
                    low++;
                }
                len=i-low+1;
                if(len<ans){
                     ans=min(ans,len);start=low;
                }
               
            }
         
        }
        if(ans==INT_MAX)
            cout<<-1<<endl;
        else{
            cout<<s.substr(start,ans)<<endl;
        }
           
    }
}
