//https://leetcode.com/problems/container-with-most-water/submissions/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(), i, j, ans;
        
        ans  = INT_MIN;
        
        i=0; j=n-1;
        while(i<j) {
            
            ans = max(ans, min(height[i], height[j])*(j-i));
            
            if(height[i] == height[j]) {
                i++; j--;
            } else if(height[i] < height[j]) {
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};