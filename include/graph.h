//
// Created by Marcus on 18/03/2026.
//

#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph {
    bool is_weighted;      // false = unweighted, true = weighted
    int num_vertices;
    int max_degree;
    int **edges;
    float **weights;
    int *degree;
} Graph;

/**
 * @brief Creates a graph using adjacency lists with fixed maximum degree per vertex.
 *
 * This function allocates and initializes a graph structure where:
 * - Each vertex has an adjacency list with a maximum capacity defined by max_degree.
 * - The degree array stores the current number of neighbors for each vertex (initialized to 0).
 * - If the graph is weighted, a parallel structure is allocated to store edge weights.
 *
 * @param num_vertices Number of vertices in the graph.
 * @param max_degree Maximum number of edges (neighbors) per vertex.
 * @param is_weighted Indicates whether the graph is weighted (true) or unweighted (false).
 *
 * @return Pointer to the created Graph structure, or NULL if allocation fails.
 */
Graph* create_graph(int num_vertices, int max_degree, bool is_weighted);
void destroy_graph(Graph *graph);
bool create_edge(Graph *graph, int origin, int destination, bool is_digraph, float weight);
bool remove_edge(Graph *graph, int origin, int destination, bool is_digraph);
void print_graph(Graph *graph);
// busca em profundidade: percorre o grafo procurando componentes conectados antes de realizar o backtracking.
void dfs(Graph *graph, int initial_vertex, int* visited);
// busca em largura: busca os vertices vizinhos e repete para vertices n explorados. Usado para a char o menor caminho e componentes conectedas a um vértice
void bfs();
