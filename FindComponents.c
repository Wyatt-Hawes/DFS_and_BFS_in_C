#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "List.h"
#include "Graph.h"

int main(int argc, char* argv[]){

    if (argc != 3){
        fprintf(stderr, "Please enter 2 arguments.\n Ex: Lex <input file> <output file>\n");
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    if (input == NULL){

        fprintf(stderr, "Input file does not exist.\n");
        return 1;
    }

    int a,b = -1;
    fscanf(input,"%d\n", &a);

    //printf("%d\n",a);
    int n = a;
    Graph g = newGraph(n);

    while (a != 0 && b != 0){
        fscanf(input,"%d %d\n", &a, &b);

        if(a == 0 && a == b){break;}
        addArc(g, a, b);
    }
    fprintf(output, "Adjacency list representation of G:\n");
    printGraph(output,g);
    fprintf(output, "\n");
    //fprintf(output,"\n");
    List stack = newList();
    for(int i = 1; i < n + 1; i++){
        //prepend(stack,i);
        append(stack,i);
    }
    //printList(stdout,stack);

    DFS(g,stack);
    List stack2 = copyList(stack);
    /*
    for(int i = 1; i < getOrder(g) + 1; i ++){
        printf("%d:  %d-%d\n",i,getDiscover(g,i),getFinish(g,i));
    }
    printList(stdout,stack);    
    */
    //printf("*****************************\n");
    //printGraph(stdout,g);
    //printf("\n");
    Graph tran = transpose(g);
    DFS(tran, stack2);
    //printGraph(stdout,tran);
    //printf("*****************************\n");
    //printList(stdout,stack);
    //printList(stdout,stack2);
    int comp = 0;
    //int val = 0;
    List solutions = newList();
    append(solutions, 0);
    moveBack(solutions);

    moveBack(stack2);
    while(index(stack2) != -1){
        insertAfter(solutions, get(stack2));
        if(getParent(tran,get(stack2)) == NIL){
            append(solutions, 0);
            moveBack(solutions);
            comp++;
        }
        movePrev(stack2);
        //printf("--------\n");
        //printList(stdout,solutions);
    }
    //printf("---END---\n");
    //printList(stdout,solutions);

    //printList(stdout, solutions);
    //printf("comp:%d\n", comp);
    moveFront(solutions);
    moveNext(solutions);
    // Add \n to below print statement to add newline 
    fprintf(output, "G contains %d strongly connected components:\n", comp);
    for(int i = 1; i < comp + 1; i++){
        if(i != 1){
            fprintf(output,"\n");
        }
        fprintf(output, "Component %d:",i);
        while(index(solutions) != -1 && get(solutions) != 0){
            fprintf(output, " %d", get(solutions));
            moveNext(solutions);
        }
        //uncomment if you need newline at the bottom of the file
        //fprintf(output,"\n");
        moveNext(solutions);

    }


    //Time to free all the memory
    fclose(input);
    fclose(output);

    freeList(&stack);
    freeList(&stack2);
    freeList(&solutions);
    freeGraph(&g);
    freeGraph(&tran);
}