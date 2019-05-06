#include <unistd.h>
#include "arymod.hpp"
#include "arymod_c.h"

//
// transform C interface -> C++
//
std::vector<float> array2vector(float *array, int length) {
	std::vector<float> v(length);
	for (int i=0; i<length; i++){
		v[i] = array[i];
	}
	return v;
}
void vector2array(std::vector<float> v, float *array) {
	int length = v.size();
	for (int i=0; i<length; i++){
		array[i] = v[i];
	}
}

Mod Mod_construct(float a_) {
	Arymod *a = new Arymod(a_);
	return (void*)a;
}

void Mod_destruct(Mod id) {
	Arymod *a = (Arymod*)id;
	delete a;
}

void SetA(Mod id, float a_) {
	Arymod *a = (Arymod*)id;
	a->SetA(a_);
}

void Add(Mod id, float *in_, int length, float *out_) {
	Arymod *a = (Arymod*)id;
	std::vector<float> v = array2vector(in_, length);
	std::vector<float> result = a->Add(v);
	vector2array(result, out_);
}

void AddSleep(Mod id, float *in_, int length, float *out_, int usec) {
	Arymod *a = (Arymod*)id;
	std::vector<float> v = array2vector(in_, length);
	usleep(usec);
	std::vector<float> result = a->Add(v);
	vector2array(result, out_);
}

void Multi(Mod id, float *in_, int length, float *out_) {
	Arymod *a = (Arymod*)id;
	std::vector<float> v = array2vector(in_, length);
	std::vector<float> result = a->Multi(v);
	vector2array(result, out_);
}
