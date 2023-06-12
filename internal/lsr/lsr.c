#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int h, adj[50][50], d;
    printf("Enter the no of hops: \n");
    scanf("%d", &h);
    int distance[h], visited[h];
    for (int i = 0; i < h; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    distance[0] = 0;
    for (int i = 0; i < h - 1; i++)
    {
        int min = INT_MAX, min_index;
        for (int j = 0; j < h; j++)
        {
            if (visited[j] == 0 && distance[j] < min)
            {
                min = distance[j];
                min_index = j;
            }
            visited[min_index] = 1;
        }

        for (int d = 0; d < h; d++)
        {
            if (!visited[d] && adj[min_index][d] && distance[min_index] != INT_MAX && distance[min_index] + adj[min_index][d] < distance[d])
            {
                distance[d] = distance[min_index] + adj[min_index][d];
            }
        }
        printf("\n");
    }
    printf("Vertex   Distance from Source: \n");
    for (int i = 0; i < h; i++)
    {
        printf("%d\t%d\t\n", i, distance[i]);
    }
}