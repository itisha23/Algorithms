bool isSafe(int k,int i,int x[])
{
    int j;
    for(j=1;j<k;j++)
    {
        if(x[j]==i || abs(j-k)==abs(x[j]-i))
         return false;
    
    }
    return true;
}

void func(vector<vector<string> >&vec, vector<string>&v,int k,int n,int x[])
{
    int i,p;
    string s;
    for(i=1;i<=n;i++)
    {
        if(isSafe(k,i,x))
        {
            x[k]=i;
            s="";
            for(p=1;p<=n;p++)
            {
               if(p==i)
                s=s+"Q";
               else
                s=s+".";
            }
            v.push_back(s);
            if(k==n)
            {
                vec.push_back(v);
               
                
            }
            else
            {
                func(vec,v,k+1,n,x);
                 
            }
            v.pop_back();
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,j;
    vector<vector<string> >vec;
    vector<string>v;
    int x[n+1];
    func(vec,v,1,n,x);
    reverse(vec.begin(),vec.end());
    return vec;
}



