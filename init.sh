#!/bin/sh
echo "--------------------------------------------Compilando lab3------------------------------"
make lab3
mkdir -p out
echo "------------------------------------------Ejecutando programa----------------------------"
for i in 1 2 3
do
echo Ejecucion $i
./bin/lab3
mv gmon.out ./out/
gprof -p -b ./bin/lab3 ./out/gmon.out > ./profiling/profiling.txt
/bin/cat ./profiling/profiling.txt >> ./profiling/ejecucion.txt
done
/bin/cat ./profiling/ejecucion.txt
echo "Ejecucion lista"
