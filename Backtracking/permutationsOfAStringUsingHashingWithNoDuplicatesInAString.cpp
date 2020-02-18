using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

void func(string s,set<string>&se,int hash[],string temp,int n){

	int i;
	for(i=0;i<n;i++){
	  if(hash[i]==0){
	      	hash[i]=1;
	    	temp=temp+s[i];
            if(temp.size()==n)
			   se.insert(temp);
			else
        	func(s,se,hash,temp,n);
        	hash[i]=0;
            temp.erase(temp.size()-1,1);
	  }
   }
}
int main(){
	ll t;
	cin>>t;
	string s;
	while(t--){
		int i,n;
		string temp="";
		cin>>s;
		n=s.size();
		set<string>se;
		int hash[n];
		for(i=0;i<n;i++)
			hash[i]=0;
		func(s,se,hash,temp,n);
		set<string>::iterator it;
		for(it=se.begin();it!=se.end();it++)
		cout<<*it<<" ";
		cout<<endl;
		
}
}

