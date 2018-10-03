int remove_duplicate(int arr[],int n)
{
   if(n==0 || n==1)
   return n;
   
   int i,j;
   j=0;
   for(i=0;i<n-1;i++)
   {
       if(arr[i]!=arr[i+1])
       {
           arr[j]=arr[i];
           j++;
       }a
   }
   arr[j]=arr[n-1];
   /*for(i=0;i<=j;i++)
   cout<<arr[i]<<" ";
   cout<<endl;*/
   
   return j+1;
   
   // here j+1 returns the number of elements in the array.
   
}
