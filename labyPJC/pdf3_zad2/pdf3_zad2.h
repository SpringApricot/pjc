#pragma once

int main();
void ord3(double& a, double& b, double& c);
void ord3(double* a, double* b, double* c);
void getMinMax(double& a, double& b, double& c, double*& ptrMin, double*& ptrMax);
void getMinMax(double* a, double* b, double* c, double** ptrMin, double** ptrMax);
void printOrd(const double* a, const double* b, const double* c);
void printMinMax(const double* pmn, const double* pmx);
