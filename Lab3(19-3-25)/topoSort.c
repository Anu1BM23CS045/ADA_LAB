#include <stdio.h>

int queue[25], front = -1, rear = -1, n;
int vis[25] = {0};

int indegree(int v, int adj[25][25]);
void enqueue(int v);
int dequeue();
int isEmpty(int q[]);

void topologicalSort(int adj[25][25]);

void main()
{
    int adj[25][25];
    printf("Enter the number od vertices:");
    scanf("%d", &n);
    printf("Enter adjacency matrix:");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    topologicalSort(adj);
}

int indegree(int v, int adj[25][25])
{
    int id = 0;
    for (int j = 1; j <= n; j++)
    {
        id += adj[j][v];
    }
    return id;
}

void enqueue(int v)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = v;
}

int dequeue()
{
    int item = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return item;
}

int isEmpty(int q[])
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void topologicalSort(int adj[25][25])
{
    int u;
    for (int v = 1; v <= n; v++)
    {
        if (indegree(v, adj) == 0)
        {
            enqueue(v);
            vis[v] = 1;
        }
    }
    printf("Topoogical order:");
    while (isEmpty(queue) != 1)
    {
        
        u=dequeue();
        printf("%d \t",u);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0 && adj[u][i]==1)
            {
                adj[u][i]=0;
                if(indegree(i,adj)==0)
                {
                  enqueue(i);
                  vis[i]=1;
                }
            }
        }

    }
    for(int v=1;v<=n;v++)
        {
            if(vis[v]==0)
            {
                printf("Cycle exists.");
                break;
            }
        }
}
