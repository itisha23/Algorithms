#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
#define inf 2e18


vector<int>vec3;
int hashi[1000001];


int myFunc(int a,int b){
    int idx1= hashi[a];
    int idx2=hashi[b];
    
    if(idx1!=-1 && idx2!=-1){
        if(idx1<idx2)
         return 1;
        return 0;
    }
    
    else if(idx1 ==-1 && idx2==-1){
        if(a<b)
         return 1;
        return 0;
    }
    
    else if(idx1 == -1){
        return 0;
    }
    else if(idx2== -1){
        return 1;
    }
}

int main(){
    
   ll t;
   cin>>t;
   while(t--){
       ll m,n,i,x;
       cin>>m>>n;
      vector<int>vec1,vec2;
      
      for(i=0;i<=1000000;i++){
          hashi[i]=-1;
      }
       f(i,0,m){
        cin>>x; 
        vec1.push_back(x);
       }
      
      f(i,0,n){
          cin>>x;
         vec2.push_back(x); 
         hashi[x]=i;
      }
      
       vec3=vec2;
       sort(vec1.begin(),vec1.end(),myFunc);
       
       for(i=0;i<m;i++)
         cout<<vec1[i]<<" ";
        cout<<endl;
   }
  
}
