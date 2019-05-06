package arymod_test

import (
	"sync"
	"testing"

	"github.com/pkg/errors"
	"github.com/uzuna/go-cpp-learn/pkg/arymod"
)

func checkError(t *testing.T, err error) {
	if err != nil {
		t.Logf("%+v", err)
		t.FailNow()
	}
}

func TestArymod(t *testing.T) {
	table := []float32{1.0, 2.0, 3.3, 4.4}

	f := func(wg *sync.WaitGroup, v float32) {
		defer wg.Done()
		a := arymod.New(v)
		{
			ary := []float32{1.0, 2.0, 3.0, 4.0}
			result, err := a.Add(ary)
			checkError(t, err)
			t.Logf("%#v", result)
		}
		a.Release()
	}
	wg := new(sync.WaitGroup)
	for _, v := range table {
		wg.Add(1)
		go f(wg, v)
	}
	wg.Wait()
}

//
// BenchmarkArymodSingle シングルタスク時の
//
func BenchmarkArymodSingle(b *testing.B) {
	f := func(v float32) error {
		a := arymod.New(v)
		defer a.Release()
		{
			ary := []float32{1.0, 2.0, 3.0, 4.0}
			_, err := a.Add(ary)
			if err != nil {
				return errors.WithStack(err)
			}
		}
		return nil
	}
	for i := 0; i < b.N; i++ {
		err := f(4.4)
		if err != nil {
			b.Logf("%+v", err)
			b.FailNow()
		}
	}
}

//
// BenchmarkArymodMulti 並行処理時のパフォーマンス
//
func BenchmarkArymodMulti(b *testing.B) {
	a := arymod.New(4.4)
	defer a.Release()
	f := func(wg *sync.WaitGroup, v float32) error {
		defer wg.Done()
		a.SetA(v)
		{
			ary := []float32{1.0, 2.0, 3.0, 4.0}
			_, err := a.Add(ary)
			if err != nil {
				return errors.WithStack(err)
			}
		}
		return nil
	}
	wg := new(sync.WaitGroup)
	for i := 0; i < b.N; i++ {
		wg.Add(1)
		go func(wg *sync.WaitGroup, v float32) {
			err := f(wg, 4.4)
			if err != nil {
				b.Logf("%+v", err)
				b.FailNow()
			}
		}(wg, 4.4)
	}
	wg.Wait()
}
