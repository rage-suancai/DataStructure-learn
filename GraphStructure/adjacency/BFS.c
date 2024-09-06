#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTEX 10

typedef struct edge_node {

    int adjvex;
    struct edge_node* next;

} edge_node;
typedef struct {

    char data;
    edge_node* firstedge;

} vertex_node;
typedef struct {

    vertex_node* vertices;
    int vertex_num, edge_num;
    int* queue;
    int front, rear;
    bool* visited;

} graph;

graph* init_graph(int vertex_num) {

    graph* G = (graph*) malloc(sizeof(graph));
    G->vertices = (vertex_node*) malloc(vertex_num * sizeof(vertex_node));
    G->vertex_num = vertex_num;
    G->edge_num = 0;

    G->queue = (int*) malloc(vertex_num * sizeof(int));
    G->visited = (bool*) calloc(vertex_num, sizeof(bool));
    G->front = G->rear = 0;

    return G;

}

void add_edge(graph* G, int from, int to) {

    edge_node* edge = (edge_node*) malloc(sizeof(edge_node));
    edge->adjvex = to;
    edge->next = NULL;

    if (G->vertices[from].firstedge == NULL) {
        G->vertices[from].firstedge = edge;
    } else {
        edge_node* current = G->vertices[from].firstedge;
        while (current->next != NULL) current = current->next;
        current->next = edge;
    }

    edge = (edge_node*) malloc(sizeof(edge_node));
    edge->adjvex = from;
    edge->next = NULL;

    if (G->vertices[to].firstedge == NULL) {
        G->vertices[to].firstedge = edge;
    } else {
        edge_node* current = G->vertices[to].firstedge;
        while (current->next != NULL) current = current->next;
        current->next = edge;
    }

    G->edge_num++;

}

void enqueue(graph* G, int v) {
    G->queue[G->rear++] = v;
}
int dequeue(graph* G) {
    return G->queue[G->front++];
}

bool BFS(graph* G, int start, char target) {

    memset(G->visited, 0, G->vertex_num * sizeof(bool));
    G->front = G->rear = 0;
    G->visited[start] = true;
    printf("%c -> ", G->vertices[start].data);

    if (G->vertices[start].data == target) return true;
    enqueue(G, start);

    while (G->front != G->rear) {
        int v = dequeue(G);
        for (edge_node* p = G->vertices[v].firstedge; p; p = p->next) {
            int w = p->adjvex;
            if (!G->visited[w]) {
                G->visited[w] = true;
                printf("%c -> ", G->vertices[w].data);
                if (G->vertices[w].data == target) return true;
                enqueue(G, w);
            }
        }
    }
    return false;

}

void free_graph(graph* G) {

    for (int i = 0; i < G->vertex_num; ++i) {
        edge_node* current = G->vertices[i].firstedge;
        while (current) {
            edge_node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(G->vertices);
    free(G->queue);
    free(G->visited);
    free(G);

}

int main() {

    graph* G = init_graph(6);
    for (int i = 0; i < G->vertex_num; ++i) {
        G->vertices[i].data = 'A' + i;
        G->vertices[i].firstedge = NULL;
    }

    add_edge(G, 0, 1);
    add_edge(G, 0, 2);
    add_edge(G, 1, 3);
    add_edge(G, 1, 4);
    add_edge(G, 2, 5);
 
    bool found = BFS(G, 0, 'F');
    printf("\nTarget %s\n", found ? "found" : "not found");

    free_graph(G);
    return 0;

}



