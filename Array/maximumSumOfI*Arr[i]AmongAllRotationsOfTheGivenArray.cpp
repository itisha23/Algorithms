
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/


int max_sum(int arr[],int n)
{
     int i,sum=0,curr=0,ans,sum1;
   for(i=0;i<n;i++)
    {
    sum+=arr[i];
    curr+=arr[i]*i;
    }
    ans=curr;
       for(i=0;i<n-1;i++)
        {
            sum1=curr-(sum-arr[i])+arr[i]*(n-1);// sum1 = curr-sum+n*arr[i]
            ans=max(ans,sum1);
            curr=sum1;
        }
        
    return ans;
}
