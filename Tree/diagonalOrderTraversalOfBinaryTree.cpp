

void diagonalUtility(Node *root, int slope, map<int, vector<int>>&mp) {

    if(root == NULL)
        return;

    mp[slope].push_back(root->data);

    diagonalUtility(root->left, slope+1, mp);
    diagonalUtility(root->right, slope, mp);
}
void diagonal(Node *root) {


    map<int, vector<int>>mp;
    diagonalUtility(root, 0, mp);

    for(auto it= mp.begin(); it!= mp.end(); it++) {
        for(i=0; i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }

}