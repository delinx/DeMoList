objects = ../src/parser/DML_DemoParser.c 
CC = gcc
CFLAGS = -static -O3 -std=c99
CPPFLAGS = -c -std=c99
all: dml_parser dml_ftp dml_db dml_web
	ls -lh

# make aliases
parser: dml_parser
	ls -lh
ftp: dml_ftp
	ls -lh
db: dml_db
	ls -lh
web: dml_web
	ls -lh


# parser
parser_dir := ../src/parser/
parser_src := DML_DemoParser

dml_parser: $(parser_src).o
	$(CC) $(parser_src).o ${CFLAGS} -o $@
	rm -f *.o

$(parser_src).o: $(parser_dir)$(parser_src).c 
	$(CC) $< ${CPPFLAGS} 

# ftp
ftp_dir := ../src/ftp/
ftp_src := ftp_main

dml_ftp: $(ftp_src).o
	$(CC) $(ftp_src).o ${CFLAGS} -o $@
	rm -f *.o

$(ftp_src).o: $(ftp_dir)$(ftp_src).c 
	$(CC) $< ${CPPFLAGS} 

# db
db_dir := ../src/db/
db_src := db_main

dml_db: $(db_src).o
	$(CC) $(db_src).o ${CFLAGS} -o $@
	rm -f *.o

$(db_src).o: $(db_dir)$(db_src).c 
	$(CC) $< ${CPPFLAGS} 

# web
web_dir := ../src/web/
web_src := web_main

dml_web: $(web_src).o
	$(CC) $(web_src).o ${CFLAGS} -o $@
	rm -f *.o

$(web_src).o: $(web_dir)$(web_src).c 
	$(CC) $< ${CPPFLAGS} 

# clean up
cleanup := $(wildcard *.o) $(wildcard *.exe) $(wildcard *.stackdump) 

#clean aliases
clr: clean 
cls: clean

clean:
	rm -f ${cleanup}
	ls -lh