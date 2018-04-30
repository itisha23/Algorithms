int func(const vector<int> &vec,int start,int end,int key)
{
   // cout<<"hi";
    int mid,flag=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(vec[mid]==key)
        {
             flag=1;
             break;
        }
        
        else if(vec[mid]>key)
        end=mid-1;
        else
        start=mid+1;
    }
    if(flag==0)
    return -1;
    else
    return mid;
}


int Solution::search(const vector<int> &vec, int key) {
    
    int ind,n,i,a,start,end,flag=0,mid;
    n=vec.size();//cout<<n<<endl;
    
    start=0;end=n-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(mid+1<n && vec[mid+1]<vec[mid])
        {
          ind=mid;
          flag=1;
          break;
        }
        else if(vec[start]>vec[mid])
          end=mid-1;
        else
          start=mid+1;
    }
    if(flag==0)
    ind=n-1;
   //cout<<ind<<endl;
   if(vec[ind]==key)
    return ind;
    else if(key>vec[ind])
    return -1;
    else
    {
        start=0;end=n-1;
        if(key>=vec[start])
        {
            end=ind;
            start=start;
            a=func(vec,start,end,key);
        }
        else
        {
            start=ind+1;
            end=end;
            a=func(vec,start,end,key);
        }
        
        return a;
    }
   
}
