class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
     int count=0,temp,n,ci,ni,x,start=0;
        
      count=0;
      temp=nums[0];
      n=nums.size();
      ci=0;
      while(count<n)
      {
         
          ci=start;
          temp=nums[ci];
          do
          {
            ni=(ci+k)%n;
            x=nums[ni];
            nums[ni]=temp;
             temp=x;
             ci=ni;
             count++;
          }
          while(ci!=start);
              start++;
         
      }
        
    }
};
