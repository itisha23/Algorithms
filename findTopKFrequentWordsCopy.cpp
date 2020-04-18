#include<bits/stdc++.h>
using namespace std;

#define MAX_CHARS 26

struct TrieNode {
    bool isLeaf;
    int count;
    int indexMinHeap;
    TrieNode *child[MAX_CHARS];
};

struct MinHeapNode {

    string word;
    int count;
    TrieNode *leafNode;
};

struct MinHeap {
    int capacity;
    int filled;
    MinHeapNode *array;
}

TrieNode* getNewNode() {
    TrieNode* newnode = new TrieNode;

    newnode -> isLeaf = false;
    newnode->count =0;
    newnode->indexMinHeap = -1;

    for(i=0; i< MAX_CHARS; i++)
        newnode ->child[i] =  NULL;

    return newnode;
}

MinHeap* createMinHeap(int capacity) {

    MinHeap *root = new MinHeap;

    root->capacity = capacity;
    root->filled = 0;

    root->array = new MinHeapNode[capacity];
}

void printKMostFreq(FILE *fp, int k) {

    MinHeap *minheap = createMinHeap(k) ;

    TrieNode *root = NULL;

    char buffer[32];

    while(fscanf( fp, "%s", buffer) != EOF) {
        insertTrieAndHeap(buffer, root, minheap);
    }

}

void insertTrieAndHeap(string s, TrieNode* &root, MinHeap* minheap) {

    insertUtil(root, minheap, word, word);
}

void insertUtil(TrieNode* &root, string word) {

    TrieNode *curr = root;

    for(i=0; i<word.size(); i++) {

        if(curr->child[word[i]] == NULL) {
            TrieNode *newnode = getNewNode();

            curr->child[word[i]] = newnode;
        }
        curr = curr->child[word[i]];
    }

    if(curr->isLeaf == true) {
        curr->count++;
    } else {
        curr->isLeaf = true;
        curr->count = 1;
    }

    // fill the current word in the min heap now.
    insertInMinHeap(minheap, curr);
}

void heapify(MinHeap *minheap, int index) {

    int left = 2 * index + 1;
    int right = 2*index +2;


    smallest = left;
    if(left < minHeap->filled && minHeap->array[left].count < minHeap->array[index].count) {
        smallest = left;
    }

    if(right< minheap->filled && minheap->array[right].count < minheap->array[index]) {
        smallest = right;
    }

    if(smallest != index) {
        minheap->array[left]->leafnode->indexMinHeap = index;
        minheap->array[smallest]->leafNode->indexMinHeap = smallest;

        swap(minheap->array[left], minheap->array[right]);

        minheapify(minheap, smallest);
    }
}

void  minheapifyTopBottom(MinHeap *minheap, int idx) {

    int parent = (idx - 1)/2;

    if(parent >=0) {
        if(minheap->array[parent]->count < minheap->array[idx]->count) {

        minheap->array[parent]->leafNode ->indexMinHeapNode = idx;
        minheap->array[idx]->leafNode->indexMinHeapNode = parent;

        swap(minheap->array[parent], minheap->array[idx]);

        minheapifyTopBottom(minheap, parent);
    }
    }
    
}

void insertInMinHeap(MinHeap *minheap, TrieNode *curr, string word) {

    if(curr->indexMinHeap != -1) {

        minheap->array[curr->indexMinHeap].count = curr->count;

        heapify(minheap, curr->indexMinHeap);
    }

    else if(minheap->count < minheap->capacity) {

        minheap->array[count].count = curr->count;
        minheap->array[count].word = word;

        minheap->array[count].leafNode = curr;

        curr->indexMinHeap = minheap->count;

        minheap->count++;

        minheapifyTopBottom(minheap, minheap->count-1);
    }

    else if(minheap->array[0].count < curr->count) {

        minheap->array[0].leafNode->indexMinHeap = -1;

        minheap->array[0].count = curr->count;
        minheap->array[0].word = curr->word;
        minheap->array[0].leafNode = curr;

        curr->indexMinheap = 0;

        minheapify(minheap, 0);