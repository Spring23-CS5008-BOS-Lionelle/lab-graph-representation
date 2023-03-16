#ifndef ADJ_LIST_H
#define ADJ_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int vertex;
    int weight;
    struct edge *next;
} edge_t;

typedef struct graph
{
    int size;
    edge_t **adj_lists;
} AdjList;

static edge_t *creat_node(int v, int weight)
{
    edge_t *new_node = (edge_t *)malloc(sizeof(edge_t));
    new_node->vertex = v;
    new_node->weight = weight;
    new_node->next = NULL;
    return new_node;
}

static AdjList *create_graph(int num_vertices)
{
    AdjList *graph = (AdjList *)malloc(sizeof(AdjList));
    graph->size = num_vertices;
    graph->adj_lists = (edge_t **)malloc(num_vertices * sizeof(edge_t *));
    for (int i = 0; i < num_vertices; i++)
    {
        graph->adj_lists[i] = NULL;
    }
    return graph;
}

static void free_graph(AdjList *graph)
{
    for (int i = 0; i < graph->size; i++)
    {
        edge_t *curr = graph->adj_lists[i];
        while (curr != NULL)
        {
            edge_t *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(graph->adj_lists);
    free(graph);
}

static void add_edge(AdjList *graph, int src, int dest, int weight)
{
    edge_t *new_node = creat_node(dest, weight);
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;
}

static void print_graph(AdjList *graph)
{
    for (int i = 0; i < graph->size; i++)
    {
        edge_t *curr = graph->adj_lists[i];
        if (curr == NULL)
            continue;
        printf("Adjacency list of vertex %d: ", i);
        while (curr != NULL)
        {
            printf("(%d, %d) -> ", curr->vertex, curr->weight);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}




#endif