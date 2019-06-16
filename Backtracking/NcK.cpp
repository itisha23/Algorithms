void func(int k,int n,vector<int>&v,vector<vector<int> >&vec,int b)
{
    int i;
    for(i=k;i<n;i++)
    {
        
        v.push_back(i+1);
        if(v.size()==b)
        vec.push_back(v);
        if(v.size()<b)
        func(i+1,n,v,vec,b);
        v.pop_back();
    }
}


vector<vector<int> > Solution::combine(int n, int b) {
    
    int i;
    int arr[n];
   for(i=1;i<=n;i++)
     arr[i-1]=i;
   vector<int>v;
   vector<vector<int> >vec;
  
   func(0,n,v,vec,b);
   return vec;
}
