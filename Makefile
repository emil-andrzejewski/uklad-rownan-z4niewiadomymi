run: uklady_rownan
	rm -f core*; ./uklady_rownan

uklady_rownan: obj/main.o obj/wektor.o obj/amacierz.o
	g++ -o uklady_rownan obj/main.o obj/amacierz.o obj/wektor.o

obj/main.o: src/main.cpp inc/amacierz.hh inc/wektor.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/main.o src/main.cpp

obj/amacierz.o: src/amacierz.cpp inc/amacierz.hh 
	g++ -c -Wall -pedantic -g -Iinc -o obj/amacierz.o src/amacierz.cpp

obj/wektor.o: src/wektor.cpp inc/wektor.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/wektor.o src/wektor.cpp


clean:
	rm obj/*.o
