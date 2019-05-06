package arymod

// #cgo CFLAGS: -I../../libs
// #cgo LDFLAGS: -L../../libs -larymodgo -larymod -lm -lstdc++
// #include <stdlib.h>
// #include "arymod_c.h"
import "C"

type Arymod struct {
	id C.Mod
}

func New(a float32) Arymod {
	var ret Arymod
	ret.id = C.Mod_construct(C.float(a))
	return ret
}
func (a Arymod) Release() {
	C.Mod_destruct(a.id)
}

func (a Arymod) Add(ary []float32) ([]float32, error) {
	result := make([]float32, len(ary))
	C.Add(a.id, (*C.float)(&ary[0]), C.int(len(ary)), (*C.float)(&result[0]))
	return result, nil
}
func (a Arymod) Multi(ary []float32) ([]float32, error) {
	result := make([]float32, len(ary))
	C.Multi(a.id, (*C.float)(&ary[0]), C.int(len(ary)), (*C.float)(&result[0]))
	return result, nil
}
