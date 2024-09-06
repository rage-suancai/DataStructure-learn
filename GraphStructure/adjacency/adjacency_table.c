#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTEX 10

typedef char E;

typedef struct edge_node {

    int adjvex;
    struct edge_node* next;

} edge_node;
typedef struct vertex_node {

    E data;
    edge_node* firstedge;
    edge_node* lastedge;

} vertex_node;
typedef struct {

    vertex_node vertices[MAX_VERTEX];
    int vertex_num, edge_num;

} graph;

graph* create() {

    graph* G = (graph*) malloc(sizeof(graph));
    G->vertex_num = 0;
    G->edge_num = 0;
    return G;

}

void add_vertex(graph* G, E data) {

    if (G->vertex_num >= MAX_VERTEX) return;
    G->vertices[G->vertex_num].data = data;
    G->vertices[G->vertex_num].firstedge = NULL;
    G->vertices[G->vertex_num].lastedge = NULL;
    G->vertex_num++;

}

void add_edge(graph* G, int start, int end) {

    edge_node* new_edge = (edge_node*) malloc(sizeof(edge_node));
    new_edge->adjvex = end;
    new_edge->next = NULL;

    if (G->vertices[start].firstedge == NULL) G->vertices[start].firstedge = new_edge;
    else G->vertices[start].lastedge->next = new_edge;
    G->vertices[start].lastedge = new_edge;
    G->edge_num++;

}

bool DFS(graph* G, int v, int target, int* visited) {

    visited[v] = 1;
    printf("%c -> ", G->vertices[v].data);

    if (v == target) return true;

    for (edge_node* p = G->vertices[v].firstedge; p; p = p->next) {
        if (!visited[p->adjvex]) {
            if (DFS(G, p->adjvex, target, visited)) return true;
        }
    }
    return false;

}

void print_graph(graph* G) {

    for (int i = 0; i < G->vertex_num; i++) {
        printf("%d | %c", i, G->vertices[i].data);
        for (edge_node* p = G->vertices[i].firstedge; p; p = p->next) {
            printf(" -> %d", p->adjvex);
        }
        printf("\n");
    }

}

void free_graph(graph* G) {

    for (int i = 0; i < G->vertex_num; i++) {
        edge_node* current = G->vertices[i].firstedge;
        while (current) {
            edge_node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(G);

}

int main() {
 
    graph* G = create();
    for (int c = 'A'; c <= 'F'; ++c) add_vertex(G, c);
    add_edge(G, 0, 1);
    add_edge(G, 1, 2);
    add_edge(G, 1, 3);
    add_edge(G, 1, 4);
    add_edge(G, 4, 5);

    int visited[MAX_VERTEX] = {0};
    int target = 5;
    bool found = DFS(G, 0, target, visited);
    printf("\nTarget %s\n", found ? "found" : "not found");

    return 0;

}

