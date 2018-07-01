string convert(long long int a)
{
    string s;
    stringstream ss;
    ss<<a;
    s=ss.str();
    return s;
}

string Solution::fractionToDecimal(int num, int dum) {
    
    int sign=1;
    if((num<0 && dum>0) || (num>0 && dum<0))
    {
          sign=-1;
    }
    
    long long int n,d;
    n=num;d=dum;
    if(num<0)
    n=num*-1L;
    if(d<0)
    d=dum*-1L;
    
  //  cout<<n<<d<<endl;
  
    map<long long int,long long int>mp;
    long long int  rem,a,q,p,flag=0,i;
    string ans="",h;
    string sn=convert(n);
    rem=0;
    for(i=0;i<sn.size();i++)
    {
        a=(rem*10)+sn[i]-'0';
        rem=a%d;
        q=a/d;
        ans=ans+convert(q);
        
    }
  while(ans[0]=='0')
    ans.erase(0,1);
         if(ans.size()==0)
          ans=ans+"0";
          
    if(rem!=0)
    {
        ans=ans+".";
    }
    p=ans.size();
    while(rem!=0 && flag==0)
    {
        
        a=rem*10;
        q=a/d;
        if(mp.count(rem)==0)
        {
            mp[rem]=q;
           ans=ans+convert(q);
           rem=a%d;
        }
        else
        {
            int ind;
            for(i=p;i<ans.size();i++)
            {
                if(mp[rem]==ans[i]-'0')
                   {
                       ind=i;
                       break;
                   }
            }
            //cout<<ind<<endl;
            ans=ans.substr(0,ind)+"("+ans.substr(ind,ans.size()-ind)+")";
          flag=1;
        }
    }
    if(sign==-1)
    ans="-"+ans;
    return ans;
    
}
