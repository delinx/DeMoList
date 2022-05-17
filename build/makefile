objects = ../src/parser/DML_DemoParser.c 
CC = gcc
CFLAGS = -static -O3 -std=c99
CPPFLAGS = -c -std=c99
cleanup := $(wildcard *.o) $(wildcard *.exe) $(wildcard *.stackdump) 
all: dml_parser

path_parser := ../src/parser/


path_db := ../src/db/
path_ftp := ../src/ftp/
path_web := ../src/web/

objects_parser := DML_DemoParser
dml_parser: $(objects_parser).o
	$(CC) $(objects_parser).o ${CFLAGS} -o dml_parser
	rm -f *.o

$(objects_parser).o: $(path_parser)$(objects_parser).c 
	$(CC) $< ${CPPFLAGS} 



clean:
	rm -f ${cleanup}