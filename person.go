//
// main.go
// Copyright (C) 2019 Tim Hughes
//
// Distributed under terms of the MIT license.
//
package main

/*
#cgo CFLAGS: -g -Wall
#cgo LDFLAGS: -L. -lperson
#include "person.h"
*/
import "C"
import (
	"fmt"
	"unsafe"
)

type (
	Person C.APerson
)

func GetPerson(name string, long_name string) *Person {
	return (*Person)(C.get_person(C.CString(name), C.CString(long_name)))
}

func ChangePerson(p *Person, name string, long_name string) {
	C.change_person((*C.APerson)(unsafe.Pointer(p)), C.CString(name), C.CString(long_name))
}

func CleanPerson(p *Person) {
	fmt.Printf("Go Cleaning... %p\n", p)
	C.clean_person((**C.APerson)(unsafe.Pointer(&p)))
	fmt.Printf("Go Cleaned... %p\n", p)
}

func main(){
	var f *Person
	f = GetPerson("tim", "tim hughes")
	defer CleanPerson(f)
	fmt.Printf("Go ptr = %p\n", unsafe.Pointer(f))
	fmt.Printf("Hello Go world: My name is %s, %s.\n", C.GoString(f.name), C.GoString(f.long_name))

	ChangePerson(f, "andrea", "andrea baldini");
	fmt.Printf("Now My name is %s, %s.\n", C.GoString(f.name), C.GoString(f.long_name))

}

