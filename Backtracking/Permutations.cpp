void func(int k,int n,vector<int>&v,vector<vector<int> >&vec,int hash[],vector<int>&A)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(hash[i]==0)
        {
           hash[i]=1;
           v[i]=A[k];
           if(k==n-1)
            vec.push_back(v);
          else
            func(k+1,n,v,vec,hash,A);
           hash[i]=0;
        
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    int i;
    vector<vector<int> >vec;
    int n=A.size();
    int hash[n];
    vector<int>v(n);
    for(i=0;i<n;i++)
    hash[i]=0;
    func(0,n,v,vec,hash,A);
    return vec;
}
