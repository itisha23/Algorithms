#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

void func(vector<char>vec[10],vector<string>&ans,string str,int i,int arr[],int n){
    
    if(i>=n)
        return;
        
    int j;
    
    for(j=0;j<vec[arr[i]].size();j++){
        
        str=str+vec[arr[i]][j];
        if(str.size()==n)
            ans.push_back(str);
        else
            func(vec,ans,str,i+1,arr,n);
        str.erase(str.size()-1,1);
    }
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        
        int n,i;
        cin>>n;
        int arr[n];
        f(i,0,n)
            cin>>arr[i];
        
        vector<string>ans;
        string str="";
        vector<char>vec[10];
        vec[2]={'a','b','c'};
        vec[3]={'d','e','f'};
        vec[4]={'g','h','i'};
        vec[5]={'j','k','l'};
        vec[6]={'m','n','o'};
        vec[7]={'p','q','r','s'};
        vec[8]={'t','u','v'};
        vec[9]={'w','x','y','z'};
        
        func(vec,ans,str,0,arr,n);
        for(i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        
    }
}

