#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_MAX 1001


int select_motion();
int print_reb();
int del();
int file_save();
int draw_graph();



int print_reb(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    puts("------------------");
    puts("Adjacency list:");
    for (int j = 0; j <= line; j++)
    {
        for (int k = 0; k <= ver; k++)
        {
            if (arr[j][k] == '1')
            {
                for (int f = j; f <= line; f++)
                {
                    if (arr[f][k] == '1' && f != j)
                    {
                        printf("%d -- %d\n", j, f);
                    }
                }
            }
        }
    }
    select_motion(arr, line, ver);
    return 0;
}

int matrix(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    puts("------------------------");
    puts("Your matrix:\n");
    for (int a = 0; a <= line; a++)
    {
        int c = a + 1;
        for (int b = 0; b <= ver; b++)
        {
            printf("%c ", arr[a][b]);
        }
        putchar('\n');
    }
    puts("------------------------");
    select_motion(arr, line, ver);
    return 0;
}

int del(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    int ver1 = 0, ver2 = 0;
    puts("print the vertices between which you need to remove the edge:");
    puts("first:");
    scanf("%d", &ver1);
    puts("second:");
    scanf("%d", &ver2);
    getc(stdin);
    for (int i = 0; i < ver; i++)
        if (arr[ver1][i] == '1' && arr[ver2][i] == '1')
        {
            arr[ver1][i] = '0';
            arr[ver2][i] = '0';
        }
    select_motion(arr, line, ver);
    return 0;
}

int file_save(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    FILE *file = fopen("matrix.txt", "w");
    for (int i = 1; i <= line; i++)
    {
        int c = i + 1;
        for (int j = 0; j < ver - 1; j++)
        {
            fprintf(file, "%c ", arr[i][j]);
        }
        fputc('\n', file);
    }
    fclose(file);
    exit(EXIT_SUCCESS);
    return 0;
}

int draw_graph(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    FILE *file;
    file = fopen("graph.gv", "w");
    fprintf(file, "graph Grah {\n");
    puts("------------------\n");
    puts("Your graph will be opened as a photo\n");
    puts("------------------\n");    
    for (int d = 1; d <= line; d++)
    {
        fprintf(file, "%d\n", d);
    }
    for (int j = 0; j <= line; j++)
    {
        for (int k = 0; k <= ver; k++)
        {
            if (arr[j][k] == '1')
            {
                for (int f = j; f <= line; f++)
                {
                    if (arr[f][k] == '1' && f != j)
                    {
                        fprintf(file, "%d -- %d\n", j, f);
                    }
                }
            }
        }
    }
    fputc('}', file);
    fclose(file);
    system("dot graph.gv -Tpng -o graph.png");
    system("graph.png");
    select_motion(arr, line, ver);
    return 0;
}

int select_motion(char arr[ARR_MAX][ARR_MAX], int line, int ver){
    int j = 0;
    puts("Select motion:");
    puts("0 - exit");
    puts("1 - delete edges");
    puts("2 - show edges");
    puts("3 - show your matrix");
    puts("4 - draw your graf");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        del(arr, line, ver);
        break;
    case 2:
        print_reb(arr, line, ver);
        break;
    case 3:
        matrix(arr, line, ver);
        break;
    case 4:
        draw_graph(arr, line, ver);
        break;
    case 0:
        file_save(arr, line, ver);
        break;
    default:
        file_save(arr, line, ver);
        break;
    }
    return 0;
}
