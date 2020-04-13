class Solution {
public:
    
    int findRoot(int a, int root[]) {
        
        if(r == root[r])
            return r;
        return root[r]= findRoot(root[r], root);
        
    }
    
    void union1(int a, int b, int root[]) {
        
        int root_a = findRoot(a, root);
        int root_b = findRoot(b, root);
        
        root[root_b] = root_a;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size(), i, j, k;
        int root[n];
        for(i=0; i<n; i++)
            root[i] = i;
        
        for(i=0; i<pairs.size(); i++) {
            union1(pairs[i][0], pairs[i][1], root);
        }
        
        map<int, vector<int>>mp;
        
        for(i=0; i<n; i++)
        {
            mp[findRoot(i,root)].push_back(i);
        }
    
        
        for(auto it = mp.begin(); it!= mp.end(); it++) {
            string x = "";
            for(i=0; i<it->second.size(); i++)
                x = x + s[it->second[i]];
            
            sort(x.begin(), x.end());
            
            k=0;
            for(i=0; i<it->second.size(); i++)
            {
                s[it->second[i]] = x[k++];
            }
        }
        
        return s;
        
    }
};