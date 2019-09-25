all: Rubik333 Rubik222 Anchura222

Rubik333: 3x3/BusquedaAnchura.o 3x3/BusquedaLocal.o 3x3/Cubo.o 3x3/Secuencia.o 3x3/main.o 3x3/BusquedaProfundidad.o 3x3/Genetico.o 3x3/Menu.o
	g++ 3x3/BusquedaAnchura.o 3x3/BusquedaLocal.o 3x3/Cubo.o 3x3/Secuencia.o 3x3/main.o 3x3/BusquedaProfundidad.o 3x3/Genetico.o 3x3/Menu.o -O4 -o Rubik333
3x3/BusquedaAnchura.o: 3x3/BusquedaAnchura.h 3x3/BusquedaAnchura.cpp
	g++ -c 3x3/BusquedaAnchura.cpp -O4 -o 3x3/BusquedaAnchura.o
3x3/BusquedaLocal.o: 3x3/BusquedaLocal.h 3x3/BusquedaLocal.cpp
	g++ -c 3x3/BusquedaLocal.cpp -O4 -o 3x3/BusquedaLocal.o
3x3/Cubo.o: 3x3/Cubo.h 3x3/Cubo.cpp
	g++ -c 3x3/Cubo.cpp -O4 -o 3x3/Cubo.o
3x3/Secuencia.o: 3x3/Secuencia.h 3x3/Secuencia.cpp
	g++ -c 3x3/Secuencia.cpp -O4 -o 3x3/Secuencia.o
3x3/BusquedaProfundidad.o: 3x3/BusquedaProfundidad.h 3x3/BusquedaProfundidad.cpp
	g++ -c 3x3/BusquedaProfundidad.cpp -O4 -o 3x3/BusquedaProfundidad.o
3x3/Menu.o: 3x3/Menu.h 3x3/Menu.cpp
	g++ -c 3x3/Menu.cpp -O4 -o 3x3/Menu.o
3x3/Genetico.o: 3x3/Genetico.h 3x3/Genetico.cpp
	g++ -c 3x3/Genetico.cpp -O4 -o 3x3/Genetico.o
3x3/main.o: 3x3/main.cpp
	g++ -c 3x3/main.cpp -O4 -o 3x3/main.o
Rubik222: 2x2/Secuencia.o 2x2/cubo222.o 2x2/main.o
	g++ 2x2/Secuencia.o 2x2/cubo222.o 2x2/main.o -O4 -o  Rubik222
Anchura222: 2x2/cubo2x2.cpp
	g++ 2x2/cubo2x2.cpp -O4 -o Anchura222
2x2/Secuencia.o: 2x2/Secuencia.h 2x2/Secuencia.cpp
	g++ -c 2x2/Secuencia.cpp -O4 -o 2x2/Secuencia.o
2x2/cubo222.o: 2x2/cubo222.h 2x2/cubo222.cpp
	g++ -c 2x2/cubo222.cpp -O4 -o 2x2/cubo222.o
2x2/main.o: 2x2/main.cpp
	g++ -c 2x2/main.cpp -O4 -o 2x2/main.o
clean:
	rm -f 2x2/*.o 3x3/*.o Rubik333 Anchura222 Rubik222
