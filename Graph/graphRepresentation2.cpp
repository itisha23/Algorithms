#include<bits/stdc++.h>
using namespace std;


// Here the graph is represented as array of edges.

struct graph{
   int V,E;
   struct edge *array;
  
};

struct edge{
    int src,dest,weight;
}



struct graph* createGraph(int v,int e)
{
    struct graph *g=new graph;
    g->V=v;
    g->E=e;

    g->array=(struct edge*)malloc(e*sizeof(struct edge));
    for(i=0;i<e;i++)
    {
        cin>>src>>dest>>weight;
        g->array[i].src=src;
        g->array[i].dest=dest;
        g->array[i].weight=weight;
    }
    return g;

}



int main()
{
  cin>>v>>e;
  struct graph *g= createGraph(v,e);
}
