int Solution::searchMatrix(vector<vector<int> > &mat, int key) {
   
   int m,n,i,low,high,mid,flag=0;
   m=mat.size();
   n=mat[0].size();
   for(i=0;i<m;i++)
   {
       low=0;high=n-1;
       while(low<=high)
       {
           mid=(low+high)/2;
           if(mat[i][mid]==key)
           {
               flag=1;
               break;
           }
           else if(mat[i][mid]<key)
           low=mid+1;
           else if(mat[i][mid]>key)
           high=mid-1;
       }
       if(flag)
       break;
   }
   return flag;
   
}
