output: main.o AVLTree.o analysis.o
	g++ main.o AVLTree.o analysis.o -o hw3

main.o: main.cpp
	g++ -c main.cpp

AVLTree.o: AVLTree.cpp AVLTree.h
	g++ -c AVLTree.cpp

analysis.o: analysis.cpp analysis.h
	g++ -c analysis.cpp

clean:
	rm *.o hw3

