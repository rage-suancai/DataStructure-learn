#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 5

typedef char E;

typedef struct matrix_graph {

    int vertex_count; // 顶点数
    int edge_count; // 边数
    int matrix[MAX_VERTEX][MAX_VERTEX]; // 邻接矩阵
    E data[MAX_VERTEX]; // 各个顶点对应的数据

} *matrix_graph;

matrix_graph create() {

    matrix_graph graph = malloc(sizeof(struct matrix_graph));

    if (graph == NULL) exit(1);

    graph->vertex_count = 0;
    graph->edge_count = 0;
    memset(graph->matrix, 0, sizeof(graph->matrix));
    memset(graph->data, 0, sizeof(graph->data));
    return graph;

}

void add_vertex(matrix_graph graph, E element) {

    if (graph->vertex_count >= MAX_VERTEX) return;

    graph->data[graph->vertex_count++] = element;

}
void add_edge(matrix_graph graph, int a, int b) {

    if (a < 0 || a >= graph->vertex_count || b < 0 || b >= graph->vertex_count) return;

    if (graph->matrix[a][b] == 0) {
        graph->matrix[a][b] = 1;
        graph->edge_count++;
    }

}

void print_graph(matrix_graph graph) {

    printf("  ");
    for (int j = 0; j < graph->vertex_count; ++j) printf("%3c", graph->data[j]);

    printf("\n");

    for (int i = 0; i < graph->vertex_count; ++i) {
        printf("%c ", graph->data[i]);
        for (int j = 0; j < graph->vertex_count; ++j) printf("%3d", graph->matrix[i][j]);
        printf("\n");
    }

}

int main() {

    matrix_graph graph = create();
    for (int c = 'A'; c <= 'D'; ++c) add_vertex(graph, (char) c);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 0);
    add_edge(graph, 2, 0);

    print_graph(graph);

    free(graph);
    return 0;

}

