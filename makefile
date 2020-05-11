code: BigInt.cpp main.cpp
	g++ -std=c++11 -o code BigInt.cpp main.cpp

default: code

run:
	code $(ARGS)
