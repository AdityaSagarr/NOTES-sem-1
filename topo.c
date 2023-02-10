/*
0 1 1 1 1
0 0 1 0 0
0 0 0 0 0
0 0 0 0 1
0 0 1 0 0

Topological Order will be 0 1 3 4 2
*/
#include <stdio.h>

void main()
{
    int n, i, j, indegree, flag = 0, count = 0;
    printf("enter the value of n: ");
    scanf("%d", &n);

    int arr[n][n], visit[n];
    printf("enter the adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
        visit[i] = 0;
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }

    printf("Topological Order is: ");
    while (flag == 0)
    {
        flag = 1;
        for (i = 0; i < n; i++)
        {
            if (visit[i] == 0)
            {
                indegree = 0;
                for (j = 0; j < n; j++)
                {
                    if (!((visit[j] == 1) || (arr[j][i] == 0)))
                    {
                        indegree = 1;
                        break;
                    }
                }
                if (indegree == 0)
                {
                    visit[i] = 1;
                    printf("%d ", i);
                    flag = 0;
                    count++;
                    break;
                }
            }
        }
    }

    if (count != n)
        printf("topological order is not possible!");
}
