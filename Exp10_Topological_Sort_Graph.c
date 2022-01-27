/*Write a program to perform a topological sort on given direct acyclic graph. 
Consider a set of tasks and a set of dependencies (precedence constraints) of form 
“task A must be done before task B” as  shown  in  the figure. 
Topological  Sort is  an  ordering  of  the  tasks  that conforms with the given 
dependencies In a Directed Acyclic Graph (DAG) G = (V, E), vertices V represent tasks, 
and each edge (u, v) ∊E means that task u must be done before task v. 
Topological sort of G is an ordering of vertices 1, 2, 3, ..., |V| such that for every edge 
(u, v), u appears before vin the ordering. Note that here can be multiple topological sorts of G.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int n;
int adj[MAX][MAX];
void create_graph();
int queue[MAX], front = -1, rear = -1;
void insert_queue(int v);
int delete_queue();
int isEmpty_queue();
int indegree(int v);
int main()
{
    int i, v, count, topo_order[MAX], indeg[MAX];
    create_graph();
    for (i = 0; i < n; i++)
    {
        indeg[i] = indegree(i);
        if (indeg[i] == 0)
            insert_queue(i);
    }
    count = 0;
    while (!isEmpty_queue() && count < n)
    {
        v = delete_queue();
        topo_order[++count] = v;
        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1)
            {
                adj[v][i] = 0;
                indeg[i] = indeg[i] - 1;
                if (indeg[i] == 0)
                    insert_queue(i);
            }
        }
    }
    if (count < n)
    {
        printf("\nNo topological ordering possible, graph contains cycle\n");
        exit(1);
    }
    printf("\nVertices in topological order are :\n");
    for (i = 1; i <= count; i++)
        printf("%c ", topo_order[i] + 97);
    printf("\n");
    return 0;
}
void insert_queue(int vertex)
{
    if (rear == MAX - 1)
        printf("\nQueue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}
int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}
int delete_queue()
{
    int del_item;
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    else
    {
        del_item = queue[front];
        front = front + 1;
        return del_item;
    }
}
int indegree(int v)
{
    int i, in_deg = 0;
    for (i = 0; i < n; i++)
        if (adj[i][v] == 1)
            in_deg++;
    return in_deg;
}
void create_graph()
{
    int i, max_edges, origin, destin;
    char from, to;
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter number of edges: ");
    scanf("%d", &max_edges);
    scanf("%c");
    for (i = 1; i <= max_edges; i++)
    {
        fflush(stdin);
        printf("\nEnter edge %d: ", i);
        scanf("%c %c", &from, &to);
        origin = (int)from - 97;
        destin = (int)to - 97;
        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("\nInvalid edge!\n");
            i--;
        }
        else
            adj[origin][destin] = 1;
    }
}