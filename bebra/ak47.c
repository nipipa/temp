// Добавить ребро между заданными вершинами

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int print_reb();
int del();
int file_save();

int main()
{
    FILE *file = fopen("matrix.txt", "r");
    char arr[ARR_MAX][ARR_MAX], s;
    int line = 1, ver = 0, reb = 0, max_len = 0;
    while (!feof(file))
    {
        fscanf(file, "%c", &s);
        if (s != ' ' && s != '\n' && s != '\0')
        {
            arr[line][ver] = s;
            ver++;
        }
        else if (s == '\n')
        {
            line++;
            max_len = ver;
            ver = 0;
        }
    }
    arr[line][max_len] = '\0';
    fclose(file);
    file = fopen("matrix.txt", "w");
    select_motion(arr, line, ver);
    return 0;
}