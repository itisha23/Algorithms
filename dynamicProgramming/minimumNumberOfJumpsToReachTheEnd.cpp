#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
	ll t;
	cin>>t;
	while(t--){
	ll n,i,flag,max_curr,ladder,jump;
	cin>>n;
	ll arr[n];
	f(i,0,n)
	cin>>arr[i];
	ladder=arr[0];
	max_curr=0;
	jump=1;
	flag=0;
	for(i=1;i<n;i++){
		if(ladder==0)
             		{
			flag=1;break;
		}
		ladder--;
		if(max_curr!=0){
			max_curr--;
		}
		max_curr=max(max_curr,arr[i]);
		if(ladder==0 && i!=n-1){

			if(max_curr!=0)
                                                 {
			 ladder=max_curr;jump++;max_curr=0;
			}
			else{
			flag=1;break;
		}
		}
		
	}
	if(flag==1)
	cout<<-1<<endl;
	else
	cout<<jump<<endl;
	}
}
