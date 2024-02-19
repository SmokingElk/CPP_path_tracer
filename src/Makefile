all: crunc

_c_vec:
	g++ -c -O3 .\vec.cpp -o .\vec.o

_c_utils:
	g++ -c -O3 .\utils.cpp -o .\utils.o

_c_figures:
	g++ -c -O3 .\figures.cpp -o .\figures.o

_c_renderer:
	g++ -c -O3 .\renderer.cpp -o .\renderer.o

_c_ppm:
	g++ -c -O3 .\ppm.cpp -o .\ppm.o

_c_main:
	g++ -c -O3 .\main.cpp -o .\main.o

compile: _c_vec _c_utils _c_figures _c_renderer _c_ppm _c_main

link:
	g++ -O3 .\vec.o .\utils.o .\figures.o .\renderer.o .\ppm.o .\main.o -o .\app.exe

run:
	.\app.exe

clean:
	DEL *.o
	
crun: compile link run
lrun: link run
crunc: compile link clean run
lrunc: link clean run		