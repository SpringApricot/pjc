#pragma once
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

template <typename T, typename FunType>
std::vector<T> filter(const std::vector<T>& v, FunType p);

//template <typename T, typename FunType1, typename FunType2>
//std::vector<T> transfilt(vector<T>& v, FunType1 t, FunType2 p);

template <typename T>
void printVec(const std::vector<T>& v);