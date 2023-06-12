#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int h, adj[50][50];
    printf("Enter the number of hops: \n");
    scanf("%d", &h);
    int distance[h], visited[h];
    for (int i = 0; i < h; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[0] = 0;
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    for (int i = 0; i < h - 1; i++)
    {
        int min = INT_MAX, min_index;
        for (int j = 0; j < h; j++)
        {

            if (!visited[j] && distance[j] < min)
            {
                min = distance[j];
                min_index = j;
            }
            visited[min_index] = 1;
        }
        for(int d=0;d<h;d++){
            if(!visited[d] && adj[min_index][d] && distance[min_index] !=INT_MAX && distance[min_index]+adj[min_index][d]<distance[d]){
                distance[d]=adj[min_index][d]+distance[min_index];
            }
        }
    }
    printf("Result: \n");
    printf("node\tDistance\n");
    for(int i=0;i<h;i++){
        printf("%d\t%d\n",i,distance[i]);
    }
}