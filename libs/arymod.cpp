#include <iostream>
#include "arymod.hpp"

void Arymod::SetA(float _a) {
	this->a = _a;
}


std::vector<float> Arymod::Add(std::vector<float> list){
	std::vector<float> result(list.size());
	int length = static_cast<int>(list.size());
	for(int i=0;i<length;i++){
		result[i] = list[i] + this->a;
	}
	return result;
}


std::vector<float> Arymod::Multi(std::vector<float> list){
	std::vector<float> result(list.size());
	int length = static_cast<int>(list.size());
	for(int i=0;i<length;i++){
		result[i] = list[i] * this->a;
	}
	return result;
}

