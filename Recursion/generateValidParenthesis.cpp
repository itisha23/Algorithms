void func(int open,int close,string s,int n,vector<string>&vec)
{
   if(open==n&& close==n)
   vec.push_back(s);
   else
   {
       if(open<n)
       func(open+1,close,s+"(",n,vec);
       if(close<open)
       func(open,close+1,s+")",n,vec);
   }
}


vector<string> Solution::generateParenthesis(int n) {
    
    vector<string>vec;
    string s="";
    func(0,0,s,n,vec);
    return vec;
}
