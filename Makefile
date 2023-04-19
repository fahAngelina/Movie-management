compile: main.cpp 
	 g++ Node.cpp theater.cpp LL.cpp main.cpp -o Movie

run: Movie
	 ./Movie name1 19.30 1 name2 20.10 2 name3 23.20 3 name4 24.00 4


clean: Movie
	 rm Movie