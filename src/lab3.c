#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

uint const XDIM = 10000;
uint const YDIM = 10000;

FILE *computo, *resultados;

// We return the pointer
double **alloc_matrix(void) /* Allocate the array */
{
  /* Check if allocation succeeded. (check for NULL pointer) */
  uint  i; 
  double **array;
  array = malloc((long unsigned int)XDIM*sizeof(double *));
  unsigned int tam_double = (unsigned int) sizeof(double);
  unsigned int tam_array = YDIM * tam_double;

  i= XDIM + 1;
  while(i--){
    array[i] = malloc( tam_array );
    memset(array[i], 0 , tam_array );
  }

  return array;
}

void fill(double** arr) 
{
  uint i, j;
  time_t t1; 
  srand ( (unsigned) time (&t1));
  for(i = 0 ; i < XDIM ; i++)
    for(j = 0 ; j < YDIM ; j++)
      arr[i][j] = (double)(rand() % 100);
}

void compute(double** arr, int kern[3][3])
{
  fprintf(computo,"inicio del proceso\n");
  double dato, accum = 0;
  uint i, j, k, l;

  memset(arr[0], (int)accum, YDIM*sizeof(double));

  for(i = 1 ; i < XDIM-1 ; i++)
  {
    arr[i][0] = accum;
    for(j = 1; j < YDIM-1 ; j++)
    {
      accum = 0;
      for(k = 0; k < 3; k++)
        for(l = 0; l < 3; l++)
        {
          int x = (int)(i + (l-1));
          // int y = j + (k-1); Sin usar
          dato = arr[x][j];
          accum += (4*kern[l][k]*dato)/1000 + 1;
        }
      arr[i][j] = accum;
    }    
    arr[i][YDIM-1] = accum;
  }
  
  memset(arr[XDIM-1],(int) accum, YDIM*sizeof(double));

  fprintf(computo,"fin del proceso\n");
}



void print(double** arr) {
  uint i, j;
  for(i = 0 ; i < XDIM ; i++)
    for(j = 0 ; j < YDIM ; j++)
      fprintf(resultados,"[%d][%d] = %f\n", i, j, arr[i][j]);
}


int main(void)
{
  // int i = 0; Sin usar
  double **arr;
  int kern[3][3] = {{0, -1, 0},{-1, 5, -1},{ 0, -1, 0}};

  computo = fopen("./log/computo.txt", "w");
  resultados = fopen("./log/resultados.txt", "w");

  arr = alloc_matrix();
  fill(arr);
  compute(arr, kern);
  print(arr);

  fclose(computo);
  fclose(resultados);

  printf("Fin de la ejecucion\n");

  return 0;
}
