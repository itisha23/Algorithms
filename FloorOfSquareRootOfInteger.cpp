int Solution::sqrt(int n) {
    
   
    if(n==0 || n==1)
      return n;
   long int low=1,end=n,mid, ans;
    while(low<=end)
     {
         mid=(low+end)/2;
         if(mid*mid==n)
           return mid;
         else if(mid*mid<n)
         {
             low=mid+1; 
             ans=mid;
         }
         else
         {
            end=mid-1;  
         }
     }
     return ans;
}
