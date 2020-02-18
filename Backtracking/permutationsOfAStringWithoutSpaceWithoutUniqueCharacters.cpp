void print(string s, int l, int r){

    if(l==r)
        cout<<s<<endl;
        return ;
    
    for(i=l; i<=r; i++) {

        swap(s[i], s[l]);
        print(s,l+1, r);
        swap(s[i], s[l]);
    }
}

// T(n) : n * n!