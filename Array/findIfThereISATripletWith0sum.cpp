bool findTriplets(int arr[], int n)
{ 
   int i,x,j;
   for(i=0;i<n-2;i++){
      x=-arr[i];
      unordered_set<int>se;
      for(j=i+1;j<n;j++){
          if(se.find(x-arr[j])!=se.end())
            return true;
          else
           se.insert(arr[j]);
      }
   }
   return false;
}
