class Solution {
public:
    bool isSafe(int k, int j, vector<string>v, int n) {
    
    int i;
    // same column
    for(i=0; i< k;i++) {
        if(v[i][j]!='.'){
            return false;
        }
    }
    
    // same diagonal -
    for(i=0; i<k ;i++) {
        if(j-(k-i) >=0 && v[i][j-(k-i)] != '.'){
            return false;
        }
    }
    
    //same diagonal +
    for(i=0; i<k ;i++) {
        if(j+(k-i) < n && v[i][j+(k-i)] != '.'){
            return false;
        }
    }
    
    return true;
}
void func(vector<vector<string>>&ans, vector<string>&v, int k, int n) {
    
    if(k == n){
        ans.push_back(v);
        return;
    }
    int j;
    
    for(j=0; j<n ;j++) {
        if(isSafe(k, j, v, n )) {
            v[k][j] = 'Q';
            func(ans, v, k+1, n);
            v[k][j] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        vector<string>v;
        
        int k=0, i;
        string s="";
        for(i=0; i<n;i++){
            s = s+'.';
        }
        for(i=0; i<n; i++){
            v.push_back(s);
        }
        func(ans, v,k, n);
        return ans;
    }
};

