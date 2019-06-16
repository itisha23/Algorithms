void getString(string s,int digitsleft,vector<string>&vec)
{
    if(digitsleft==0)
      vec.push_back(s);
    else
    {
        getString(s+"0",digitsleft-1,vec);
        getString(s+"1",digitsleft-1,vec);
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    string s="";
    int n=A.size(),i,j;
    vector<string>vec;vector<int>v;vector<vector<int> >ans;
    getString(s,n,vec);
    for(i=0;i<vec.size();i++)
    {
        v.clear();
        for(j=0;j<vec[i].size();j++)
        {
            if(vec[i][j]=='1')
              v.push_back(A[j]);
        }
        ans.push_back(v);
    }
    return ans;
}
