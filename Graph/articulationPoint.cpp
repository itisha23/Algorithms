#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a; i<b; i++)


void dfs(int root, int x, int parent, int visited[], int low[], int id[], int ar[], vector<int>vec[], outedges) {

    static int time = 0;
    visited[x] = 1;
    if(root == parent)
        outedges++; // count only the dfs edges

    id[x] = low[x] = time++;

    for(i=0; i<vec[x].size(); i++) {
        if(vec[x][i] == parent)
            continue;

        if(!visited[vec[x][i]]) {

            dfs();
            low[x] = min(low[x], low[vec[x][i]]);

            if(low[x] <= id[vec[x][i]])
                ar[x] = true;
        } else {
            low[x] = min(low[x], id[vec[x][i]]);
        }
    }
}

vector<int>vec articulation(vector<int>vec[], int v) {

    int visited[v]; // 0
    int id[v]; // DFS-ID
    int low[v];
    in ar[v]; // 0;

    for(i=0; i<v; i++) {
        if(!visited[i])
            outedges = 0;
            dfs(i, i, -1, id, visited, id, low, ar, vec, outedges )
            art[x] = outeges > 1;
    }

    // pritn art
}