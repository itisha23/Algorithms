// Method 1: using q and  map
    // the first enetry will be the answer
    //print the map


queue<Node*, int>q;
map<int, int>mp;
q.push(root, 0);

while(q.empty()!=1) {
    p = q.front();
    h = p.second;
    if(mp.count(h) == 0) {
        mp[count] = p.first;
    }
    q.pop();

    if(p->first->left)
        q.push(p->first->left);

    if(pi-first->right)
        q.push(p->first->right);
}

//print map

//Method2: Using Preorder Traversal 
// This was asked in amazon also and also asked to convert top view code to bottom view.
// Instead of using queue we can using built in stack and do the preorder traversal and also keep a variable in recursive calls so that we know we are at level below or above  and also store the level in map

map<int, pair<int, int> >mp;

fillmap(root, mp, 0, 0);

void fillmap(Node *root, map<int, pair<int, int> >mp, int hd, int l) {
    if(root==NULL)
        return;
    if(mp.count(hd)==0){
        mp[hd] = make_pair(root->data, l);
    } else if(mp[hd].second > l)
    {
        mp[hd] = make_pair(root->data, l);
    }

    fillmap(root->left, mp, hd-1, l+1);
    fillmap(root->right, mp, hd+1, l+1);
}

