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
  double dato, accum = 0;
  uint i, j;

  memset(arr[0], (int)accum, YDIM*sizeof(double));

  for(i = 1 ; i < XDIM-1 ; i++)
  {
    arr[i][0] = accum;
    for(j = 1; j < YDIM-1 ; j++)
    {
      accum = 0;

      int x = ((int)i + (0-1));
      // int y = j + (k-1); Sin usar
      dato = arr[x][j];
      accum += (4*kern[0][0]*dato)/1000 + 1;

      x = ((int)i + (0-1));
      dato = arr[x][j];
      accum += (4*kern[0][1]*dato)/1000 + 1;

      x = ((int)i + (0-1));
      dato = arr[x][j];
      accum += (4*kern[0][2]*dato)/1000 + 1;

      x = ((int)i + (1-1));
      dato = arr[x][j];
      accum += (4*kern[1][0]*dato)/1000 + 1;

      x = ((int)i + (1-1));
      dato = arr[x][j];
      accum += (4*kern[1][1]*dato)/1000 + 1;

      x = ((int)i + (1-1));
      dato = arr[x][j];
      accum += (4*kern[1][2]*dato)/1000 + 1;

      x = ((int)i + (2-1));
      dato = arr[x][j];
      accum += (4*kern[2][0]*dato)/1000 + 1;

      x = ((int)i + (2-1));
      dato = arr[x][j];
      accum += (4*kern[2][1]*dato)/1000 + 1;

      x = ((int)i + (2-1));
      dato = arr[x][j];
      accum += (4*kern[2][2]*dato)/1000 + 1;

      arr[i][j] = accum;
    }    
    arr[i][YDIM-1] = accum;
  }

  j = YDIM;

  while(j--)
    arr[XDIM-1][j]=accum;
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
