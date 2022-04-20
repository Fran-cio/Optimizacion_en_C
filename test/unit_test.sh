#!/bin/bash
echo --------------------------------------Compilando------------------------------
cd ..
make test
cd test
echo --------------------------------------Ejecutando------------------------------
./test_lab3
./test_lab3_base
echo -------------------------------------Comparo salidas--------------------------
sha1sum test.txt
sha1sum test_base.txt

rm -f *.txt test_lab3 test_lab3_base
