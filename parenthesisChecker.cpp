using namespace std;
typedef long long int ll;
int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
     string s;char a;ll flag=0,i;
     cin>>s;
     stack<char>st;
     for(i=0;i<s.size();i++)
     {
       if(s[i]=='[')
         st.push('[');
       else if(s[i]=='{')
         st.push('{');
       else if(s[i]=='(')
         st.push('(');
       else if(s[i]==']')
        {  
           if(st.empty()==1)
           {flag=1; break;}
           a=st.top();
           if(a=='[')
             st.pop();
           else
             {flag=1;break;}
         }
        else if(s[i]==')')
        {  
           
           if(st.empty()==1)
           {flag=1; break;}
           a=st.top();
           if(a=='(')
             st.pop();
           else
             {flag=1;break;}
         }
       else if(s[i]=='}')
        { 
           
           if(st.empty()==1)
           {flag=1; break;}
           a=st.top();
           if(a=='{')
             st.pop();
           else
             {flag=1;break;}
         }
     }
     if(flag==1||st.empty()!=1)
     cout<<"not balanced\n";
     else
     cout<<"balanced\n"; 
     for(i=0;i<st.size();i++)
      if(st.empty()!=1)
         st.pop();
  }
}
