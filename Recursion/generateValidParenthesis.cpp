class Solution {
public:
    void func(int open,int close,string s,int n,vector<string>&vec)
{
   if(open==0 && close==0)
        vec.push_back(s);
   else
   {
       if(open != 0)
            func(open-1,close,s+"(",n,vec);
        if(close > open)
            func(open,close-1,s+")",n,vec);
   }
}
    
    vector<string> generateParenthesis(int n) {
        vector<string>vec;
        string s="";
        func(n,n,s,n,vec);
        return vec;   
    }
};


