/**
 * Graph Traversal Algorithms - BFS & DFS
 * Case Study:"Course Prerequisite" graph between subjects, to advise students which order to study them 
*/
#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n; /* number of subjects (vertices) */

void addEdge(int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1; /* undirected: "related to" */
}

void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS from Subject %d: ", start);

    while (front < rear)
    {
        int curr = queue[front++];
        printf("%d ", curr);
        for (int i = 0; i < n; i++)
        {
            if (adj[curr][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFSUtil(int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj[v][i] == 1 && !visited[i])
            DFSUtil(i);
}

void DFS(int start)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("DFS from Subject %d: ", start);
    DFSUtil(start);
    printf("\n");
}

int main()
{
    n = 6; /* Subjects 0-5: e.g., 0=C Prog,1=DSA,2=OOPS,3=DBMS,4=OS,5=CN */

    addEdge(0, 1); /* C Programming -> DSA */
    addEdge(1, 2); /* DSA -> OOPS */
    addEdge(1, 3); /* DSA -> DBMS */
    addEdge(2, 4); /* OOPS -> OS */
    addEdge(3, 4); /* DBMS -> OS */
    addEdge(4, 5); /* OS -> CN */

    BFS(0);
    DFS(0);

    return 0;
}
