

int pivot(const vector<int>&vec,int low,int high)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(vec[mid]>vec[mid+1])
         return mid;
        
        if(vec[low]>vec[mid])
        high=mid-1;
        
        else
        low=mid+1;
    }
    
    return high;
}

int Solution::search(const vector<int> &vec, int key) {
    
// FIRST WE TRY TO FIND THE LAST ELELMENT OF THE ACTUAL ARRAY. THAT WILL BE OUR PIVOT. IN THE ROTATED SORTED ARRAY THAT ELEMENT IS
   //THE ELEMENT AFTER WHICH THE NEXT ELEMENT IS SMALLEST. ALSO IF THE ARRAY IS ALRAEDY SORTED THE OUR FUCNTION SHOULD RETURN
   // LAST INDEX OF THE ARRAY.
   
   
   
    int n=vec.size();
   int ind=pivot(vec,0,n-1);
   
   if(vec[ind]==key)
   return ind;
   
   // ALREADY SORTED
   if(ind==n-1)
   {
       if(binary_search(vec.begin(),vec.end(),key))
       return lower_bound(vec.begin(),vec.end(),key)-vec.begin();
         return -1;
   }
   else
   {
      // CHECK FOR FIRST HALF BEFORE INDEX  
      if(binary_search(vec.begin(),vec.begin()+ind,key))
       return lower_bound(vec.begin(),vec.begin()+ind,key)-vec.begin();// THIS WILL GIVE ORIGINAL ONLY. NOT CONSIDERING 0
      // BUT FOR END IT WILL CONSIDER LAST SPECIFIED ONLY.
      
       
       else if(binary_search(vec.begin()+ind+1,vec.end(),key))
       return lower_bound(vec.begin()+ind+1,vec.end(),key)-vec.begin();
       
       return -1;
       
       
   }
 
}
