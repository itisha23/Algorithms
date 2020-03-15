class Solution {
public:
    void func(vector<int>vec,vector<vector<int>>&ans, vector<int>v, int sum, int target, int n, int k ) {
      
        int i;
        for(i=k; i<n; i++) {
        
            sum+= vec[i];
            v.push_back(vec[i]);
            
            if(sum == target){
                ans.push_back(v);
            }
            
            else if(sum < target) {
                func(vec, ans, v, sum, target, n, i+1);
               
            } 
             v.pop_back();
             sum-=vec[i];
            
            // This step is one of the most important steps
            while(i+1 < n && vec[i] == vec[i+1]) {
                i++;
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        
        sort(A.begin(), A.end());
        vector<vector<int>>ans;
        vector<int>v;
        int k=0;
        int sum=0;
        int n = A.size();
        func(A, ans, v, sum, target, n, k);
        return ans;
    }
};




