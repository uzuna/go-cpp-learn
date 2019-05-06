OBJS = main.o libarymod.a
LIBS = libarymodgo.a libarymod.a

build : $(LIBS)

link : $(OBJS)
	g++ -o out.exe $(OBJS)

libarymod.a : arymod.o
	ar r $@ $<
	ranlib $@

libarymodgo.a : arymod_c.o arymod.o 
	ar r $@ $<
	ranlib $@

.c.cpp.o : 
	g++ -std=c++11 -c $< -g -O2 


all : link

clean:
	rm -rf *.o *.a out.exe

