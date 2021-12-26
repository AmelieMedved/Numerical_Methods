#pragma once
#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double ksi = M_PI / 4.0;
const double C1 = (-1.0) * 0.314616898, C2 = 0.314616898;
const double C3 = (-1.0) * 0.521407591700856, C4 = 1.326848837;
const double control_eps = 0.0000005;

//k1(x), 0 <= x < кси
double k1(double x);

//q1(x), 0 <= x < кси
double q1(double x);

//f1(x), 0 <= x < кси
double f1(double x);

//k2(x), кси < x <= 1
double k2(double x);

//q2(x), кси < x <= 1
double q2(double x);

//f2(x), кси < x <= 1
double f2(double x);

//k1*, 0 <= x < кси
double k1_test(double x);

//q1*, 0 <= x < кси
double q1_test(double x);

//f1*, 0 <= x < кси
double f1_test(double x);

//k2*, кси < x <= 1
double k2_test(double x);

//q2*, кси < x <= 1
double q2_test(double x);

//f2*, кси < x <= 1
double f2_test(double x);

//вычисляет коэффициенты ai - возвращает вектор размерности n+1
vector<double> calc_a(int n, double (*k1)(double), double (*k2)(double));

//вычисляет коэффициенты di - возвращает вектор размерности n+1
vector<double> calc_d(int n, double (*q1)(double), double (*q2)(double));

//вычисляет коэффициенты fi - возвращает вектор размерности n+1
vector<double> calc_f(int n, double (*f1)(double), double (*f2)(double));

void tridiagonal(int n, vector<double>& lower, vector<double>& center, vector<double>& upper, double (*k1)(double), double (*k2)(double), double (*q1)(double), double (*q2)(double));

vector<double> TMA(int n, vector<double> lower, vector<double> center, vector<double> upper, vector<double> free);

vector<double> calc_free(int n, double (*f1)(double), double (*f2)(double));

double an_func1(double x);

double an_func2(double x);

vector<double> an_func(int n);