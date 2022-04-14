CC=gcc
CFLAGS=-Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11
OPT=-O0
PROF=-pg
PATHbin=./bin/
PATHrec=./src/

lab3: $(PATHbin)lab3

$(PATHbin)lab3_base: $(PATHrec)lab3_base.c 
	mkdir -p $(PATHbin) log
	$(CC) $(OPT) $(PROF) -o $(PATHbin)lab3_base $(PATHrec)lab3_base.c


$(PATHbin)lab3: $(PATHrec)lab3.c 
	mkdir -p $(PATHbin) log
	$(CC) $(OPT) $(PROF) -o $(PATHbin)lab3 $(PATHrec)lab3.c

clean:
	rm -f -d $(PATHbin)* $(PATHbin) ./log/* ./log 
