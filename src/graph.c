//
// Created by Marcus on 18/03/2026.
//
// grafos muito conectados, usa-se matriz de adjacencia
// pouco conectados lista de adjacencia

#include <stdlib.h>
#include "graph.h"
#include <stdio.h>


Graph* create_graph(int num_vertices, int max_degree, bool is_weighted) {
    Graph* graph = malloc(sizeof(Graph));
    if (graph == NULL) return NULL;

    graph->num_vertices = num_vertices;
    graph->max_degree = max_degree;
    graph->is_weighted = is_weighted;

    // armazena o número atual de vizinhos de cada vértice (inicializado com 0)
    graph->degree = calloc(num_vertices, sizeof(int));

    // aloca a lista de adjacência: para cada vértice, um array com capacidade max_degree
    graph->edges = malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = malloc(max_degree * sizeof(int));
    }

    // se tiver peso, aloca
    if (is_weighted) {
        graph->weights = malloc(num_vertices * sizeof(float*));
        for (int i = 0; i < num_vertices; i++) {
            graph->weights[i] = malloc(max_degree * sizeof(float));
        }
    }else {
        graph->weights = NULL;
    }

    return graph;
}

void destroy_graph(Graph *graph) {
    if (graph == NULL) return;
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->edges[i]);
        if (graph->weights != NULL) {
            free(graph->weights[i]);
        }
    }
    free(graph->edges);
    if (graph->weights != NULL) {
        free(graph->weights);
    }
    free(graph->degree);
    free(graph);
}

// graph->edges[origin] => lista de vértices adjacentes (vizinhos) do vértice "origin".
// graph->edges[origin][graph->degree[origin]] => próxima posição livre na lista de adjacência,
// onde será inserido o novo vértice vizinho.
// Em outras palavras, adiciona uma aresta de "origin" para "destination".
bool create_edge(Graph *graph, int origin, int destination, bool is_digraph, float weight) {
    if (graph == NULL) return false;
    if (origin < 0 || origin >= graph->num_vertices) return false;
    if (destination < 0 || destination >= graph->num_vertices) return false;
    if (graph->degree[origin] >= graph->max_degree) return false;


    graph->edges[origin][graph->degree[origin]] = destination;

    if (graph->is_weighted && graph->weights != NULL) {
        graph->weights[origin][graph->degree[origin]] = weight;
    }
    graph->degree[origin]++;

    if (!is_digraph) {
        if (graph->degree[destination] >= graph->max_degree) return false;

        graph->edges[destination][graph->degree[destination]] = origin;

        if (graph->is_weighted && graph->weights != NULL) {
            graph->weights[destination][graph->degree[destination]] = weight;
        }

        graph->degree[destination]++;
    }
    return true;
}

bool remove_edge(Graph *graph, int origin, int destination, bool is_digraph) {
    if (graph == NULL) return false;
    if (origin < 0 || origin >= graph->num_vertices) return false;
    if (destination < 0 || destination >= graph->num_vertices) return false;


    // procura aresta
    int i = 0;
    while (i < graph->degree[origin] &&  graph->edges[origin][i] != destination) {
        i++;
    }
    // não encontrou
    if (i == graph->degree[origin]) return false;

    graph->degree[origin]--;

    // substitui a aresta removida pela última da lista para manter O(1)
    graph->edges[origin][i] = graph->edges[origin][graph->degree[origin]];

    if (graph->is_weighted) {
        graph->weights[origin][i] = graph->weights[origin][graph->degree[origin]];
    }

    if (is_digraph == false)
        remove_edge(graph, destination, origin, true);

    return true;
}

void print_graph(Graph *graph) {
    if (graph == NULL) return;

    for (int i = 0; i < graph->num_vertices; i++) {
        printf("graph vertex %d: ", i);
        for (int j = 0; j < graph->degree[i]; j++) {
            printf(" -> %d ", graph->edges[i][j]);
        }
        printf("\n");
    }
}