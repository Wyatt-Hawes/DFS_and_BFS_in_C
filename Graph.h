#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "List.h"


#define INF -1
#define NIL -9
#define UNDEF -10

typedef struct GraphObj* Graph;

/*** Constructors-Destructors ***/
// Constructors-Destructors
Graph newGraph(int n);
void freeGraph(Graph* pG);
// Access functions
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getDiscover(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
// Manipulation procedures
void addArc(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void addEdge(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */
void BFS(Graph G, int s);
// Other Functions
Graph transpose(Graph G);
Graph copyGraph(Graph G);
/*** Other operations ***/
void printGraph(FILE* out, Graph G);
#endif
