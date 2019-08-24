class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size(),i,prev,result=0;
        stack<int>st;
        for(i=0;i<n;i++){
            
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                
                if(!st.empty() && s[st.top()]=='(')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
        }
        
        if(st.empty())
            return n;
        prev=n;
        while(!st.empty()){
            result=max(result,prev-st.top()-1);
             prev=st.top();
            st.pop();
           
        }
        
        result=max(result,prev);
        return result;
    }
};
