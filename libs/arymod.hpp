#ifndef _MY_PACKAGE_FOO_HPP_
#define _MY_PACKAGE_FOO_HPP_
#include <vector>

// 渡された配列を加工するクラス
class Arymod {
private:
	// 任意の計算を行う時の定数
	float a;

public:
	Arymod(float _a):a(_a){};
	~Arymod(){};

	void SetA(float _a);
	std::vector<float> Add(std::vector<float> list);
	std::vector<float> Multi(std::vector<float> list);
};

#endif
