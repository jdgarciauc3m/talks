FLAGS=-std=c++11 -O3 -pthread

all:	prodcons

prodcons:	main.o generador.o colamsj.o productor.o consumidor.o
	g++ ${FLAGS} -o prodcons main.o generador.o colamsj.o productor.o consumidor.o

main.o:	main.cpp colamsj.h productor.h consumidor.h
	g++ main.cpp -c -o main.o ${FLAGS}

generador.o:	generador.cpp generador.h
	g++ generador.cpp -c -o generador.o ${FLAGS}

colamsj.o:	colamsj.cpp colamsj.h mensaje.h
	g++ colamsj.cpp -c -o colamsj.o ${FLAGS}
	
productor.o:	productor.cpp productor.h colamsj.h
	g++ productor.cpp -c -o productor.o ${FLAGS}
	
consumidor.o:	consumidor.cpp consumidor.h colamsj.h
	g++ consumidor.cpp -c -o consumidor.o ${FLAGS}

clean:
	rm *.o
	rm prodcons
