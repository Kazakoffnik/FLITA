//Я выбрал файл adjacency_matrix_90.txt
#include <stdio.h>

int main() {
  FILE *F1;
  F1 = fopen("adjacency_matrix_90.txt", "r");//открываем нашу смежную матрицу
  int x[5][5];
  for (int i = 0; i <= 4; i++)
    for (int j = 0; j <= 4; j++)
      x[i][j] = 0;
  for (int i = 0; i <= 4; i++) {
    fscanf(F1, "%d %d %d %d %d", &x[i][0], &x[i][1], &x[i][2], &x[i][3],
           &x[i][4]);
  }
  fclose(F1);
  FILE *F2;
  F2 = fopen("norm.dot", "a");
  fprintf(F2, "graph G {\n");
  for (int i = 0; i <= 4; i++)
    for (int j = i; j <= 4; j++)
      for (int l = x[i][j]; l >= 1; l--)
        fprintf(F2, "\tx%d -- x%d;\n", i + 1, j + 1);
  fprintf(F2, "}");
  fclose(F2);
}
