#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "List.h"
#include "Graph.h"

int main(){

    printf("test\n");
    
    Graph a = newGraph(6);
    List l = newList();
    addEdge(a,1,2);
    addEdge(a,2,3);
    addEdge(a,2,4);
    addEdge(a,2,5);
    addEdge(a,3,6);
    addEdge(a,5,3);
    addEdge(a,6,5);

    append(l,6);
    append(l,5);
    append(l,4);
    append(l,3);
    append(l,2);
    append(l,1);

    printGraph(stdout, a);
    printf("-------------\n");
    DFS(a,l);

    for(int i = 1; i < getOrder(a) + 1; i ++){
        printf("%d:  %d-%d\n",i,getDiscover(a,i),getFinish(a,i));
    }
    printList(stdout,l);
    
    
    
    freeGraph(&a);
    freeList(&l);
    
    
    
    return 0;
}   