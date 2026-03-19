#include <stdio.h>
#include <stdbool.h>
#include "graph.h"


int main(void) {

    Graph *graph = create_graph(3, 2, false);
    if (graph == NULL) {
        printf("Error creating graph\n");
        return 1;
    }
    printf("graph created\n");

    create_edge(graph, 0, 1, false, 0.0);
    create_edge(graph, 0, 2, false, 0.0);
    create_edge(graph, 1, 2, false, 0.0);

    print_graph(graph);

    destroy_graph(graph);

    return 0;
}
