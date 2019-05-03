OBJS = main.o libarymod.a 

link : $(OBJS)
	g++ -o out.exe $(OBJS)

libarymod.a : arymod.o
	ar r $@ $<
	ranlib $@

.cpp.o : 
	g++ -std=c++11 -c $< -g -O2 

all : link

clean:
	rm -rf *.o *.a out.exe

