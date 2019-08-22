#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
#define inf 2e18



int row[8] = {1,1,1,0,0,-1,-1,-1};
int column[8] = {0,1,-1,1,-1,0,-1,1};


bool isSafe(ll a,ll b,ll m,ll n){
    if(a>=0 && a<m && b>=0 && b<n)
        return true;
    return false;
}
void func(vector<char>mat[],unordered_set<string>se,set<string>&ans,ll x,ll y,vector<int>visited[],string s,ll m,ll n,ll maxi){
    
    s= s+ mat[x][y];
    
    visited[x][y]=1;
    
    int i,j,a,b;
    
    if(se.find(s)!=se.end())
        ans.insert(s);
        
    if(s.size()>=maxi){
        
        visited[x][y]=0;
    s.erase(s.size()-1);
         return;
    }
       

       for(i=0;i<8;i++){
           if(isSafe(x+row[i],y+column[i],m,n)){
               a = x+row[i]; b= y+column[i];
               if(visited[a][b]==0){
                   func(mat,se,ans,a,b,visited,s,m,n,maxi);
               }
           }
       } 
    
    
    visited[x][y]=0;
    s.erase(s.size()-1);
    
}

int main(){
    
  ll t;
  cin>>t;
  while(t--){
      ll d,i,j,m,n,maxi=0;
      string s;
      cin>>d;
      unordered_set<string>se;
      
      f(i,0,d){
          cin>>s;
          se.insert(s);
          ll x=s.size();
          maxi=max(maxi,x);
      }
      
      set<string>ans;
      
      cin>>m>>n;
     
      vector<char>mat[m];
      vector<int>visited[m];
      
      for(i=0;i<m;i++){
           mat[i].resize(n);
           visited[i].resize(n);
      }
       
        
      f(i,0,m){
          f(j,0,n){
              cin>>mat[i][j];
              visited[i][j] =0;
          }
      }
      
    
     
      
      f(i,0,m){
          f(j,0,n){
              
            s="";
            func(mat,se,ans,i,j,visited,s,m,n,maxi);
            
          }
      }
      
     set<string>::iterator it;
     for(it=ans.begin();it!=ans.end();it++)
        cout<<*it<<" ";
     if(ans.size()==0)
        cout<<-1;
    cout<<endl;
  }
  
}
