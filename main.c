#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *F1;
  F1 = fopen("adjacency_matrix_90.txt", "r");
  int x[5][5];
  for (int i = 0; i <= 4; i++)
    for (int j = 0; j <= 4; j++)
      x[i][j] = 0;
  for (int i = 0; i <= 4; i++)
    fscanf(F1, "%d %d %d %d %d", &x[i][0], &x[i][1], &x[i][2], &x[i][3], &x[i][4]);
  fclose(F1);
  char c = '"';
  FILE *F2 = fopen("norm.dot", "a+");
  fprintf(F2, "graph G {\n");
  for (int i = 0; i <= 4; i++)
    if (x[i][0] == 0 && x[i][1] == 0 && x[i][2] == 0 && x[i][3] == 0 && x[i][4] == 0)
    {
      fprintf(F2, "\tx%d\n", i + 1);
    }
    else
    {
      for (int j = i; j <= 4; j++)
        for (int l = x[i][j]; l >= 1; l--)
          fprintf(F2, "\tx%d -- x%d;\n", i + 1, j + 1);
    }
  int reb = 0;
  for (int i = 0; i <= 4; i++)
  {
    for (int j = 0; j <= 4; j++)
    {
      if (x[i][j] > 1)
        x[i][j] = 1;
      if (i == j)
        x[i][j] = 0;
    }
  }
  for (int i = 0; i <= 4; i++)
    for (int j = 0; j <= i - 1; j++)
      reb += x[i][j];
  if (reb >= (((5 - 1) * (5 - 2)) / 2))
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
