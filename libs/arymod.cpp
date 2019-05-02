#include <iostream>
#include "arymod.hpp"

void Arymod::SetA(float _a) {
	this->a = _a;
}


std::vector<float> Arymod::Add(std::vector<float> &list){
	auto length = static_cast<int>(list.size());
	for(auto i=0;i<length;i++){
		list[i] += this->a;
	}
	return list;
}


std::vector<float> Arymod::Multi(std::vector<float> &list){
	auto length = static_cast<int>(list.size());
	for(auto i=0;i<length;i++){
		list[i] *= this->a;
	}
	return list;
}

