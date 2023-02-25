#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 21

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct Queue
{
    Node *front;
    Node *back;
} Queue;

bool empty(Queue *q)
{
    if (q->front == NULL)
    {
        return true;
    }

    return false;
}

void push(Queue *q, int x)
{
    Node *nextNode = (Node *)malloc(sizeof(Node));
    nextNode->data = x;
    nextNode->next = NULL;

    // checking if heap is full or not
    if (nextNode == NULL)
    {
        printf("Heap is full\n");
        return;
    }

    if (q->front == NULL)
    {
        q->front = q->back = nextNode;
    }

    q->back->next = nextNode;
    q->back = q->back->next;
}

void pop(Queue *q)
{
    if (empty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    if (q->front == q->back)
    {
        free(q->front);
        q->front = q->back = NULL;
        return;
    }

    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
}

int front(Queue *q)
{
    if (empty(q))
    {
        return -1;
    }

    return q->front->data;
}

void bfs(int V, int adj[max][max])
{
    Queue qt;
    qt.back = NULL;
    qt.front = NULL;

    bool visited[max] = {false};

    // starting from 0
    push(&qt, 0);
    visited[0] = true;
    printf("%d ", 0);

    while (!empty(&qt))
    {
        int t = front(&qt);
        pop(&qt);

        int no_of_adj_v = adj[t][0];

        for (int i = 1; i <= no_of_adj_v; i++)
        {
            if (visited[adj[t][i]] == false)
            {
                printf("%d ", adj[t][i]);
                visited[adj[t][i]] = true;
                push(&qt, adj[t][i]);
            }
        }
    }
};

void dfsR(int adj[max][max], bool *visited, int start)
{
    if (visited[start] == false)
    {
        printf("%d ", start);
        visited[start] = true;

        int no_of_adj_v = adj[start][0];

        for (int i = 1; i <= no_of_adj_v; i++)
        {
            if (visited[adj[start][i]] == false)
            {
                dfsR(adj, visited, adj[start][i]);
            }
        }
    }
}

void dfsOfGraph(int V, int adj[max][max])
{
    bool visited[max] = {false};

    for (int i = 0; i < V; i++)
    {
        dfsR(adj, visited, i);
    }
}

int main(int argc, char const *argv[])
{

    int V, E;
    printf("Enter the no of vertices : ");
    scanf("%d", &V);
    printf("Enter the no of edges : ");
    scanf("%d", &E);

    int adj[max][max];

    // adj[i][0] -> no of adj vertices of vertex i
    for (int i = 0; i < V; i++)
    {
        adj[i][0] = 0;
    }

    printf("Enter the edges one by one in given format \nif an goes from b to c then enter b c\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d", &u);
        scanf("%d", &v);

        adj[u][0]++;

        adj[u][adj[u][0]] = v;
    }

    printf("\nBFS : ");
    bfs(V, adj);
    printf("\nDFS : ");
    dfsOfGraph(V, adj);

    return 0;
}