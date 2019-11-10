#include "pdf4_zad2.h"

int main()
{
	std::vector<int> v{ 1, -3, 4, -2, 6, -8, 5 };
	printVec(v);
	std::vector<int> r = filter(v, [](int x) { return x % 2 == 0; });
	printVec(r);
	std::vector<int> s = filter(v, [](int x) { return x > 0; });
	printVec(s);
	std::vector<double> w{ 1.5, -3.1, 4.0, -2.0, 6.3 };
	printVec(w);
	//double mn = -0.5, mx = 0.5;
	//std::vector<double> d = transfilt(w, /* lambda_3*/, /* lambda_4 */);
	//printVec(w);
	//printVec(d);
}

template<typename T, typename FunType>
std::vector<T> filter(const std::vector<T>& v, FunType p)
{
	std::vector<T> result;

	for (int i = 0; i < v.size(); i++) {
		if (p(v[i])) result.push_back(v[i]);
	}

	return result;
}

//template<typename T, typename FunType1, typename FunType2>
//std::vector<T> transfilt(vector<T>& v, FunType1 t, FunType2 p)
//{
//	return std::vector<T>();
//}

template<typename T>
void printVec(const std::vector<T>& v)
{
	std::cout << "[ ";
	for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
	std::cout << " ]" << std::endl;
}
