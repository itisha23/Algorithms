//lazy propogation is a an optimisation technique when there are tons on tons of update in segment tree
// generally range updates

// total_overlap : stop and upadtes its children in lzay tree if exists
//lazy updates are even done when querying

void update(int tree[], int lazy[], int up_start, int up_end, int tree_start, int tree_end, int value, int tree_index) {

    if(tree_start > tree_end)
        return;

    if(lazy[tree_index]!=0) {
        tree[tree_index] + = lazy[tree_index];
        if(tree_start != tree_end) {
            lazy[2*tree_index] + = val;
            lazy[2*tree_index] +=val;
        }
        lazy[lazy_index] =0;
    }

    // check for no overlap
    if(up_start > tree_end || up_end< tree_start)
        return;

    // total overlap
    if (tree_start >= up_start && tree_end <= up_end)
    {
        tree[tree_index]+ = val;
        // if its not the child node
        if(tree_start ! =tree_end){
            lazy[2*tree_index + 1] = val;
            lazy[2*tree_index +2] = val;
        }
        return;
    }

    int mid = (tree_start + tree_end)/2;
    update(tree, lazy, up_start, up_end, tree_start, mid, value, 2*tree_index+1);
    update(tree, lazy, up_start, up_end, mid+1, tree_end, value, 2*tree_index+2);

    tree[tree_index] = min(tree[2*tree_index +1], tree[2*tree_index]+2);
}


// now there will be updates in tree when you query as well during lazy propogation
int query(int tree[], int lazy[], int qstart, int qend, int treeStart, int treeEnd, int treeIndex) {

        if(treeStart > treeEnd)
            return;

     if(lazy[treeIndex] != 0) {
         tree[treeIndex] + = lazy[treeIndex];
         if(treeStart != treeEnd){
             lazy[2*treeIndex+1]+ = lazy[treeIndex];
             lazy[2*treeIndex+2]+= lazy[treeIndex];
         }
         lazy[treeIndex] =0;
     }

     // no-overlap
     if(qstart > treeEnd || qend<treeStart){
         return INT_MAX;
     }

     //total_overlop
     if(treeStart > qstart && treeEnd < qend){
         return tree[treeIndex];
     }

     //partial overlap
     int mid = (treeEnd  - treeStart) /2;
     return min(query(tree, lazy, qstart,  qend, treeStart, mid, 2*treeIndex+1), query(tree, lazy, qstart, qstart, mid+1, treeEnd, 2*treeIndex+2));

}