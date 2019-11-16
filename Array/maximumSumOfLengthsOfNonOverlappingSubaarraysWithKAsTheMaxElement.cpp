typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,flag,count,sum,k;
        cin>>n;
        vector<ll>vec(n);
        for(i=0;i<n;i++)
        cin>>vec[i];
        cin>>k;
        sum=0,count=0,flag=0;
        for(i=0;i<n;i++)
        {
            if(vec[i]<=k)
            count++;
            if(vec[i]>k)
            {
                if(flag==1)
                sum+=count;
                count=0;
                flag=0;
                
            }
            if(vec[i]==k)
            flag=1;
        }
        if(flag==1)
        sum+=count;
        cout<<sum<<endl;
        
    }
}
