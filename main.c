#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int main()
{
  FILE *F1;
  F1 = fopen("adjacency_matrix_90.txt", "r");
  int x[MAX_SIZE][MAX_SIZE];
  for (int i = 0; i <= MAX_SIZE - 1; i++)
    for (int j = 0; j <= MAX_SIZE - 1; j++)
      x[i][j] = -1;
  char c1;
  int n = 0, m = 0;
  while (!feof(F1))
  {
    fscanf(F1, "%c", &c1);
    if (c1 != ' ' && c1 != '\n' && c1 != '\0')
    {
      x[n][m] = c1 - '0';
      m++;
    }
    else if (c1 == '\n')
    {
      n++;
      m = 0;
    }
  }
  n = m;
  char c = '"';
  FILE *F2 = fopen("norm.dot", "a+");
  fprintf(F2, "graph G {\n");
  for (int i = 0; i <= n - 1; i++)
  {
    int p = 0;
    for (int t = 0; t <= n - 1; t++)
      if (x[i][t] == 0)
        p++ ;
      if (p == n)
        {
          fprintf(F2,"\tx%d;\n", i + 1);
        }
      else
      {

        for (int j = i; j <= m - 1; j++)
          for (int l = x[i][j]; l >= 1; l--)
            fprintf(F2, "\tx%d -- x%d;\n", i + 1, j + 1);
      }
  }
  int reb = 0;
  for (int i = 0; i <= n - 1; i++)
  {
    for (int j = 0; j <= m - 1; j++)
    {
      if (x[i][j] > 1)
        x[i][j] = 1;
      if (i == j)
        x[i][j] = 0;
    }
  }
  for (int i = 0; i <= n - 1; i++)
    for (int j = 0; j <= i - 1; j++)
      reb += x[i][j];
  if (reb >= (((n - 1) * (n - 2)) / 2))
  {
    fprintf(F2, "\t0 [shape = plaintext,label = %cSvyazniy%c];\n", c, c);
  }
  else
  {
    fprintf(F2, "\t0 [shape = plaintext,label = %cNesvyazniy%c];\n", c, c);
  }
  fprintf(F2, "}");
  fclose(F2);
  system("dot norm.dot -Tpng  -o norm.jpg");
  system("norm.jpg");
}
