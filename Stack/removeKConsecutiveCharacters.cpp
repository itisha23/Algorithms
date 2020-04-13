

int main() {

    stack<pair<char, int>>st;
    cin>>k;

    for(i=0; i<s.size(); i++) {

        if(!st.empty()) {
            st.push(make_pair(i,1));
        }

        else if(st.top().first == s[i]){
            st.push(make_pair(s[i], st.top().second+1));
        }

        else {
            st.push(make_pair(s[i], 1));
        }

        if(st.top().second == k) {
            char x = st.top().first;
            while( !st.empty() && st.top().first == x)
                st.pop();
        }
    }

    // Now pop out all the characters from the stack and form the
    //desired string.
}

