#include<bits/stdc++.h>
using namespace std;

struct adjNode{
    int dest;
    int weight;
    struct adjNode* next;
}

struct adjList{
    struct adjNode* head;
}

struct graph{
    int v;
    struct adjList *array;
}

struct graph* createGraph(int n)
{
    int i;
    struct graph *g=(struct graph*)malloc(sizeof(struct graph));
    g->v=n;
    g->array=(struct adjList*)malloc(v*sizeof(struct adjList));

    f(i,0,v)
      g->array[i].head=NULL;
}

void add_edge(struct graph *g,int src,int dest,int weight)
{
    // for undirectional graph add both ways. and here we are adding newnode in the beginning.
     struct adjNode *newnode=(struct adjNode*)malloc(sizeof(struct adjNode));
     newnode->dest=dest;
     newnode->weight=weight;
     newnode->next=g->array[src].head;
     g->array[src].head=newnode;

     struct adjNode *newnode2=(struct adjNode*)malloc(sizeof(struct adjNode));
     newnode2->dest=src;
     newnode2->weight=weight;
     newnode2->next=g->array[dest].head;
     g->array[dest].head=newnode2;
}




int main()
{
   cin>>v;
  struct graph g*=createGraph(v);
}
