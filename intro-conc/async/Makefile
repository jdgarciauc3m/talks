FLAGS=-std=c++11 -O3 -pthread

all:	test1 test2 test3 test4

clean:
	rm -f test1
	rm -f test2
	rm -f test3
	rm -f test4

test1:	main1.cpp tasks.h
	g++ main1.cpp -o test1 ${FLAGS}

test2:	main2.cpp tasks.h
	g++ main2.cpp -o test2 ${FLAGS}

test3: main3.cpp
	g++ main3.cpp -o test3 ${FLAGS}

test4: main4.cpp
	g++ main4.cpp -o test4 ${FLAGS}
