void func(vector<string>keywords, vector<vector<string>>reviews) {

    set<string>se;
    for(i=0; i<keywords.size(); i++){
        se.insert(keywords[i]);
    }

    for(i=0; i<reviews.size(); i++) {

        for(j=0; j<reviews[i].size(); j++) {

            string s="";
            while(j< reviews[i][j].size() && reviews[i][j]!=' ') {
                s+=reviews[i][j];
                j++;
            }

            if(se.find(s) != se.end) {
                if(mp.count(s)==0) {
                    mp[s] = make_pair(1, i);
                } else {
                    if(mp[s].second != i)
                        mp[s] = make_pair(mp[s].first+1, i); // only increase if the last review is not i
                }
            }

        }
    }

    // Now add map elements in priority queue and perform k top elemennts.
}