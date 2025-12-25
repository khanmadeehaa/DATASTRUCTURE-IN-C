#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int vertex_value;
    struct node *next_node;
};

struct node* create_node(int vertex_value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->vertex_value = vertex_value;
    new_node->next_node = NULL;
    return new_node;
}

void add_edge(struct node *adj_list[], int source, int destination)
{
    struct node *new_node = create_node(destination);
    new_node->next_node = adj_list[source];
    adj_list[source] = new_node;

    new_node = create_node(source);
    new_node->next_node = adj_list[destination];
    adj_list[destination] = new_node;
}

void display_graph(struct node *adj_list[], int vertices)
{
    printf("\nAdjacency List:\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%d -> ", i);
        struct node *temp = adj_list[i];
        while (temp != NULL)
        {
            printf("%d ", temp->vertex_value);
            temp = temp->next_node;
        }
        printf("\n");
    }
}

int main()
{
    int vertices, edges;
    struct node *adj_list[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++)
        adj_list[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        scanf("%d %d", &source, &destination);

       
        if (source >= 0 && source < vertices &&
            destination >= 0 && destination < vertices)
        {
            add_edge(adj_list, source, destination);
        }
        else
        {
            printf("Invalid edge! Try again.\n");
            i--;
        }
    }

    display_graph(adj_list, vertices);

    return 0;
}

