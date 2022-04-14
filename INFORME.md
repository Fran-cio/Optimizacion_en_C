[![](http://assets.amuniversal.com/a10595106d5401301d7c001dd8b71c47)](https://dilbert.com/strip/2004-12-25)

# Sistemas operativos 2-Trabajo practico 3
## Informe
### Equipo de pruebas
El equipo ultilizado para las pruebas es el siguiente:
![Diagrama de Componentes](./doc_informe/equipo_1.png)

Los resultados que se exponen corresponden a la mejor de 3 pruebas que se ejecutan con el script *init* en la raiz del proyecto. A lo largo del informe se enumeran los cambios generados en el archivo [archivo base](./src/lab3_base.c), apartir del cual surgen las comparativas para considerar una mejora o no en el rendimiento de la ejecucion.

### Primera ejecucion
La primera ejecucion corresponde al archivo base descargado del informe. El mismo tardo mas tiempo del que se comenta enel profiling, asumo que es el gran numero de prints que generan una lentitud en la consola, apesar de que la ejecucion como tal ya termino.

Each sample counts as 0.01 seconds.
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


Es decir, se abrieron 2 archivos, y en los cuales se escriben los 2 print que anteriormente estaban en el programa.
