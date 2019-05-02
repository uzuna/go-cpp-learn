ARFLAG += -r

SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

include $(subst .cpp,.d,$(SRCS))

build: $(OBJS)
	ar $(ARFLAG) $@ $?
	g++  -std=c++11 -o arymod main.cpp

%.d: %.cpp
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$