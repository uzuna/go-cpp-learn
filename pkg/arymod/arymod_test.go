package arymod_test

import "testing"
import "github.com/uzuna/go-cpp-learn/pkg/arymod"

func TestArymod(t *testing.T) {
	a := arymod.New(3.2)
	a.Release()
}
