class Solution {
public:
    
    void dfs(int x, int parent, int visited[], int id[], int low[], int &index, vector<int>vec[],  vector<vector<int>>&bridges) {
        
        visited[x] = 1;
        id[x] = index++;
        low[x] = id[x];
        
        int i;
        
        for(i=0; i<vec[x].size(); i++) {
            if(vec[x][i] == parent)
                continue;
            
            if(visited[vec[x][i]] == 0) {
                dfs(vec[x][i], x, visited, id, low, index, vec, bridges);
                low[x] = min(low[x], low[vec[x][i]]);
            
            } else {
                low[x] = min(low[x], id[vec[x][i]]);
            }
            
            if(id[x] < low[vec[x][i]])
            {
                vector<int>v{x, vec[x][i]};
                bridges.push_back(v);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>bridges;
        vector<int>vec[n];
        int edges = connections.size(), i;
        if(edges == 0)
            return bridges;
        
        for(i=0; i<edges; i++)
        {
            vec[connections[i][0]].push_back(connections[i][1]);
            vec[connections[i][1]].push_back(connections[i][0]);
        }
        
        int visited[n];
        memset(visited, 0, sizeof(visited));
        
        int id[n] ;
        int low[n];
        
        int index = 1;
        for(i=0; i<n ;i++) {
            dfs(i, -1, visited, id, low, index, vec, bridges);
        }
        
        return bridges;
    }
};