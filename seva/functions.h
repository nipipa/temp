#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_MAX 1001

struct timeval tv1, tv2, dtv;
struct timezone tz;

int select_motion();
int print_reb();
int del();
int file_save();
int draw_graph();
int selectionSort();

void time_start()
{
    mingw_gettimeofday(&tv1, &tz);
}

long time_stop()
{
    mingw_gettimeofday(&tv2, &tz);
    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
    if (dtv.tv_usec < 0)
    {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }
    return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
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

int calc(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    int v, num = 0, kol = 0, vertex[ARR_MAX];
    puts("------------------------");
    puts("Grades:");
    for (int a = 1; a <= line; a++)
    {
        for (int b = 0; b <= ver; b++)
        {
            if (arr[a][b] == '1')
            {
                for (int i = 0; i <= line; i++)
                {
                    if (arr[i][b] == '1' && i != a)
                        num++;
                }
            }
        }
        vertex[a] = num;
        printf("Vertex %d <--> grade %d \n", a, num);
        num = 0;
    }
    puts("------------------------");
    puts("Grades after sorting:");
    time_start();
    selectionSort(vertex, line);
    for (int i = 1; i <= line; i++)
    {
        printf("%d\n", vertex[i]);
    }
    puts("------------------------");
    printf("Time of sorting: %ld mc\n", time_stop());
    puts("------------------------");
    select_motion(arr, line, ver);
    return 0;
}

int selectionSort(int *num, int size)
{
    int min, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (num[j] < num[min])
                min = j;
        }
        temp = num[i];
        num[i] = num[min];
        num[min] = temp;
    }
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

int select_motion(char arr[ARR_MAX][ARR_MAX], int line, int ver)
{
    int j = 0;
    puts("Select motion:");
    puts("0 - exit");
    puts("1 - calculate");
    puts("2 - show your matrix");
    puts("3 - draw your graf");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        calc(arr, line, ver);
        break;
    case 2:
        matrix(arr, line, ver);
        break;
    case 3:

        draw_graph(arr, line, ver);
        break;
    case 0:
        exit(111);
        break;
    default:
        exit(111);
        break;
    }
    return 0;
}