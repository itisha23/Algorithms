  #include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll root[3001];

void initialize(int n){
   int i;
    for(i=1;i<=n;i++)
       root[i]=i;
} 

int findroot(int a){
   while(root[a]!=a)
     a=root[a];
   return a;
}

int iscycle(int a,int b){
   int root_a=findroot(a);
   int root_b=findroot(b);
   if(root_a==root_b)
     return 1;
   else
    return 0;
}

void unionmst(int a,int b){
   int root_a=findroot(a);
   int root_b=findroot(b);
   root[root_a]=root_b;
}  

int main()
{ 
   freopen("inputf.in","r",stdin);
   freopen("out1.out","w",stdout);
   ll n,e,i,u,w,wt,count=0,mstsum=0,v;
   cin>>n>>e;
   map<pair<int,int>, pair<int,int> >mp;
   for(i=1;i<=e;i++){
       cin>>u>>w>>wt;
       mp.insert(make_pair ( make_pair(wt,(u+w+wt)),make_pair(u,w) ) );
    }
   
     map<pair<int,int>, pair<int,int> >::iterator it;
     pair<int,int>p1,p2;
     initialize(n);
     it=mp.begin();
     while(count!=n-1){
      p1=it->first;
      p2=it->second;
      u=p2.first;
      v=p2.second;
      if(!iscycle(u,v)){
         unionmst(u,v);
         mstsum=mstsum+p1.first;
         count++;
      }         
     advance(it,1);
 }
cout<<mstsum<<endl;
}


//Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply find-union algorithm. T
//he find and union operations can take atmost O(LogV) time. So overall complexity is O(ELogE + ELogV) time. 
//The value of E can be atmost O(V2), so O(LogV) are O(LogE) same. Therefore, overall time complexity is O(ElogE) or O(ElogV)

