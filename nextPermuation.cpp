void Solution::nextPermutation(vector<int> &vec) {
    int i,j;
    int n=vec.size();
   i=n-2;
   while(i>=0 && vec[i]>=vec[i+1])
      i--;
      
    if(i<0)
    {
        sort(vec.begin(),vec.end());
    }
    else
    {
        for(j=n-1;j>i;j--)
        {
            if(vec[j]>vec[i])
               break;
        }
        swap(vec[j],vec[i]);
        sort(vec.begin()+i+1,vec.end());
    }
   
}
