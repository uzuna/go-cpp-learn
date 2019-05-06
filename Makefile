.PHONY: clean

TARGET=go-cpp-learn


#
# libsのbuild + link
#
link:
	$(MAKE) -C libs

#
# libs配下をclean
#
clean:
	$(MAKE) -C libs clean

#
# CGOを使うarymodをテスト
#
test:
	CGO_ENABLED=1 go test ./pkg/arymod -v -count=1
#
bench:
	CGO_ENABLED=1 go test ./pkg/arymod -bench .

test-docker:
	$(eval containerid=${TARGET}-cpp)

	docker build -t ${containerid} .

	docker run --rm ${containerid} make test
	docker run --rm ${containerid} make bench


run:
	$(eval containerid=${TARGET})
	docker run --rm ${containerid} ./bin/${TARGET}