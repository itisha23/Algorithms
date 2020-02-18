void dfs(int x, int visited[], vector<int>vec[], stack<int>&st){
    visited[x] =1;
    for(int i=0; i<vec[x].size();i++){
        if(visited[vec[x][i]] == 0){
            dfs(vec[x][i], visited, vec, st);
        }
    }
    st.push(x);
}


string printOrder(string dict[], int n, int k)
{
	
	int i,j,m;
	string ans="";

    vector<int>vec[k];
    
    i=0;
	while(i<=n-2){
        j=i+1;
         m=0;
	    while(m<dict[i].size() && m< dict[j].size()){

		if(dict[i][m] != dict[j][m]){

			vec[dict[i][m]-'a'].push_back(dict[j][m]-'a');
			//i++;
			break;
		}
		else
			m++;
    	}
    	i++;
	}

    int visited[k];
    memset(visited, 0, sizeof(visited));
    
    stack<int>st;
    
    for(i=0; i<k; i++){
        if(visited[i]==0) {
            dfs(i, visited, vec, st);
        }
    }
	
	while(st.empty()!=1){
	    ans= ans+(char)(st.top()+'a');
	    st.pop();
	}
    
   
 	return ans;
}

