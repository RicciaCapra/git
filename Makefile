RAYLIBPATH=/opt/homebrew

local:
	g++ -o GUI -std=c++20 GUI.cpp -Iinclude -Llib -lraylib

homebrew:
	g++ -o GUI -std=c++20 GUI.cpp -I${RAYLIBPATH}/include -L${RAYLIBPATH}/lib -lraylib

bin/tris: out/tris.o out/TrisGrid.o 
	g++ -o bin/tris out/tris.o out/TrisGrid.o

out/tris.o: src/tris.cpp include/TrisGrid.h
	g++ -o out/tris.o -c src/tris.cpp -I include

out/TrisGrid.o: src/TrisGrid.cpp include/TrisGrid.h
	g++ -o out/TrisGrid.o -c src/TrisGrid.cpp -I include

# Modified target for out/GUI to include out/TrisGrid.o
out/GUI: src/GUI.cpp out/TrisGrid.o
	g++ -o out/GUI -std=c++20 src/GUI.cpp out/TrisGrid.o -Iinclude -Llib -lraylib