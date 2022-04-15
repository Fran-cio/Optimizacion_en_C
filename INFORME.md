[![](http://assets.amuniversal.com/a10595106d5401301d7c001dd8b71c47)](https://dilbert.com/strip/2004-12-25)

# Sistemas operativos 2-Trabajo practico 3
## Informe
### Equipo de pruebas
El equipo ultilizado para las pruebas es el siguiente:
![Neofetch de la pc](./doc_informe/equipo_1.png)

Los resultados que se exponen corresponden a la mejor de 3 pruebas que se ejecutan con el script *init* en la raiz del proyecto. A lo largo del informe se enumeran los cambios generados en el archivo [archivo base](./src/lab3_base.c), apartir del cual surgen las comparativas para considerar una mejora o no en el rendimiento de la ejecucion.

### Primera ejecucion
La primera ejecucion corresponde al archivo base descargado del informe. El mismo tardo mas tiempo del que se comenta enel profiling, asumo que es el gran numero de prints que generan una lentitud en la consola, apesar de que la ejecucion como tal ya termino.

 %     | cumulative | self    |        | self     | total           
 ---   | ---        | ---     | ---    | ---      | ---
 time  | seconds    | seconds | calls  | s/call   | s/call  name    
 73.52 | 22.10      | 22.10   | 1      | 22.10    | 22.10  compute
 24.45 | 29.45      | 7.35    | 1      | 7.35     | 7.35  print
 0.93  | 29.73      | 0.28    | 1      | 0.28     | 0.28  fill
 0.70  | 29.94      | 0.21    | 1      | 0.21     | 0.21  alloc_matrix
 0.40  | 30.06      | 0.12    |        |          |     _init


Obteniendo un acumulado de 30.06
___
### Primer Cambio
> Como habia una tardanza en la muestra de los datos, tal vez sea mejor llevarlos a un log el cual lo iba a guardar alli.

 %     | cumulative | self    |       | self   | total           
 ---   | ---        | ---     | ---   | ---    | ---
 time  | seconds    | seconds | calls | s/call | s/call name    
 89.41 | 15.11      | 15.11   | 1     | 15.11  | 15.11  compute
 7.57  | 16.39      | 1.28    | 1     | 1.28   | 1.28   print
 1.42  | 16.63      | 0.24    | 1     | 0.24   | 0.24   alloc_matrix
 1.18  | 16.83      | 0.20    | 1     | 0.20   | 0.20   fill
 0.41  | 16.90      | 0.07    |       |        |        _init

El tiempo de ejecucion acumulado fue de 16.90s, es decir, casi la mitad.

Es decir, se abrieron 2 archivos, y en los cuales se escriben los 2 print que anteriormente estaban en el programa.
Comparandos las tablas se ve una disminucion en las 2 funciones modificadas.
___
### Segundo Cambio
> Para el primer cambio me olvide de cambiar las flags de compilacion, por lo tanto me saltie los warnings que habia en el.
Los warnings corregidos fueron:
![Warnigs](./doc_informe/Warnings.png)

Los errores de conversion se castearon, los sin uso estan comentados y las llaves se colocaron.

 %     | cumulative | self    |       | self   | total           
 ---   | ---        | ---     | ---   | ---    | ---
 time  | seconds    | seconds | calls | s/call | s/call name    
 88.26 | 14.13      | 14.13   | 1     | 14.13  | 14.13  compute
 8.37  | 15.47      | 1.34    | 1     | 1.34   | 1.34   print
 2.00  | 15.79      | 0.32    | 1     | 0.32   | 0.34   alloc_matrix
 0.87  | 15.93      | 0.14    | 1     | 0.14   | 0.14   fill
 0.50  | 16.01      | 0.08    |       |        |        _init

El tiempo acumulado fue de 16.01 s. Es un cambio muy pequeño respecto a la prueba anterior, pero el resto de pruebas arrojaron resultados inferiores en todas las pruebas, por lo tanto hubo una mejoria de algun tipo.
___
### Cambios descartados
* En la funcion *alloc_matrix* se intento cambiar los for por while retrocediendo, empeoro los resultados de la funcion
* En la misma que anterior se intento separar el malloc en 1 solo for, el mismo tambien empeoro los tiempos
* Cambiar los *int* por *unsigned int* empeoro en pequeña escala los tiempos a nivel general
