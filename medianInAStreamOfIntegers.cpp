#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)
int main()
{
    ll n,i,x,mean;
    cin>>n;
   
    priority_queue<ll>pmax;
    priority_queue<ll,vector<ll>,greater<ll> >pmin;
    
    f(i,0,n)
    {
        cin>>x;
        if(i==0)
        {
              pmax.push(x);
              cout<<x<<endl;
        }
        else if(i==1)
        {
            if(x>pmax.top())
            {
                pmin.push(x);
                mean=(x+pmax.top())/2;
                cout<<mean<<endl;
            }
            else
            {
                pmin.push(pmax.top());
                pmax.pop();
                pmax.push(x);
                mean=(x+pmin.top())/2;
                cout<<mean<<endl;
            }
        }
        else
        {
          if(x>mean)
          {
              pmin.push(x);
              if(pmin.size()-pmax.size()>1)
              {
                  pmax.push(pmin.top());
                  pmin.pop();
              }
          }
          else
          {
              pmax.push(x);
              if(pmax.size()-pmin.size()>1)
              {
                  pmin.push(pmax.top());
                  pmax.pop();
              }
          }
          if(pmin.size()==pmax.size())
          {
              mean=(pmax.top()+pmin.top())/2;
          }
          else if(pmin.size()>pmax.size())
          {
              mean=pmin.top();
          }
          else
             mean=pmax.top();
            
           cout<<mean<<endl;
        }
        
    }
    
}
