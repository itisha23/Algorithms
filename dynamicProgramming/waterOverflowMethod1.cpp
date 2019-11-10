#include<bits/stdc++.h>
using namespace std;
typedef  int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,i,j,index,r,tot,row,col; double w;
        cin>>x>>i>>j;
        tot = ((i*(i+1))/2);
        
        r = ((i-1)*i)/2 +(j);
        //tot = (ll)pow(2,i);
        double glass[r+1];
        memset(glass,0,sizeof(glass));
    
        index = 1;
        glass[index]=x;

        //cout<<i<<" "<<r<<endl;
        
        for(row =1;row<=i;row++){
            
            for(col=1;col<=row&& index<=r;col++){
                w=  glass[index];
                
                if(w >1){
                     glass[index]= 1;
                     if(row+index<=r){
                   
                    glass[row+index]+=(w-1)/2.0;
                }
                
                 if(row+index+1<=r){
                    glass[row+index+1]+=(w-1)/2.0;
                    
                }
                }
                
                //cout<<index<<" "<<glass[index]<<endl;
                if(index == r){
                cout<<fixed<<setprecision(6)<<glass[index]<<endl;
                break;
                }
            
            index++;
               
                
            }
            
        }
       
    }
}