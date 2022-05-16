parser: DML_DemoParser.o
	gcc.exe -std=c99 DML_DemoParser.o -o parser -static -O3

DML_DemoParser.o: ../src/parser/DML_DemoParser.c 
	gcc.exe -c -std=c99 ../src/parser/DML_DemoParser.c

clean:
	rm *.o *.exe *.stackdump
