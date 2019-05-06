.PHONY: clean

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

build-docker:
	$(eval containerid=${TARGET})
	$(eval imageid=${TARGET}-extract)

	docker build -t ${containerid} .


run:
	$(eval containerid=${TARGET})
	docker run --rm ${containerid} ./bin/${TARGET}