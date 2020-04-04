void func(vector<vector<int>>edges, int v, vector<vector<int>>newEdges) {

    map<pair<int, int>, pair<int, int>>mp;

    for(i=0; i<edges.size(); i++) {
        mp[make_pair(0, edges[0]+edges[1]+edges[0]*edges[1])] = make_pair(edges[0], edges[1]);
    }

    for(i=0; i<newEdges.size(); i++) {
        mp.insert(make_pair(make_pair(newEdges[2], newEdges[0] + newEdges[1] + newEdges[0]*newEdges[1]),make_pair(edge1, edge2) ));
    }

    int count =0;
    auto it = mp.begin();
    while(count!= v) {

        pair<p1, p2>p = it->first, it->seconf
        union if cycle not present
        union array

    }
}