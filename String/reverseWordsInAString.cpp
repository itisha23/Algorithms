using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
	ll t;
	cin>>t;
	while(t--){
		string s,ans="",temp="";
		ll i,n;
		cin>>s;
		n=s.size();
		for(i=0;i<n;i++){
			if(s[i]=='.'){
                                       if(ans.size()==0)
                                      ans=temp+ans;
                                      else
                                     ans= temp+"."+ans;
                                     temp="";
                                    }
			else{
			 temp=temp+s[i];
			 
			}
                        }
                            if(ans.size()==0)
                                      ans=temp+ans;
                                      else
                                     ans= temp+"."+ans;
                          cout<<ans<<endl;

}
}
