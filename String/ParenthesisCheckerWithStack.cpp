using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll i;
        string s;
        cin>>s;
        stack<char>st;
        for(i=0;i<s.size();i++){
            if(s[i]=='('|| s[i]=='['|| s[i]=='{')
            st.push(s[i]);
            else if(s[i]==')'&& st.size()!=0 && st.top()=='(')
            st.pop();
            else if(s[i]==']' && st.size()!=0 && st.top()=='[')
            st.pop();
            else if(s[i]=='}' && st.size()!=0 && st.top()=='{')
            st.pop();
            else
            {
                break;
            }
            
        }
        if(i!=s.size() || st.size()!=0)
        cout<<"not balanced"<<endl;
        else
         cout<<"balanced"<<endl;
    }
}
