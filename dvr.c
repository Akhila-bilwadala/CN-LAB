#include <stdio.h>

int main()
{
    int n, i, j, k;
    int cost[10][10], dist[10][10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
        }
    }

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nShortest distance table:\n");
    for(i = 0; i < n; i++)
    {
        printf("Router %d:\n", i+1);
        for(j = 0; j < n; j++)
        {
            printf("To node %d distance = %d\n", j+1, dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}