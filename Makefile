.PHONY: clean

TARGET=howto-go-with-cpp

$(TARGET): libfoo.a
	go build -o bin/${TARGET} .

libfoo.a: foo.o cfoo.o
	ar r $@ $^

%.o: %.cpp
	g++ -O2 -o $@ -c $^

clean:
	rm -f *.o *.so *.a $(TARGET)



build-docker:
	$(eval containerid=${TARGET})
	$(eval imageid=${TARGET}-extract)

	docker build -t ${containerid} .


run:
	$(eval containerid=${TARGET})
	docker run --rm ${containerid} ./bin/${TARGET}