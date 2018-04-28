int Solution::searchMatrix(vector<vector<int> > &mat, int key) {
   
   int m,n,i,low,high,mid,flag=0;
   m=mat.size();
   n=mat[0].size();
   low=0;high=(m*n-1);
   while(low<=high)
   {
       mid=(low+high)/2;
       if(mat[mid/n][mid%n]==key)
       {
           flag=1;
           break;
       }
       else if(mat[mid/n][mid%n]<key)
       low=mid+1;
       else if(mat[mid/n][mid%n]>key)
       high=mid-1;
   }
   return flag;
   
}
