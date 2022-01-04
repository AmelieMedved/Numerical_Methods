#pragma once
#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const double ksi = M_PI / 4.0; // точка разрыва
const double C1 = -0.3393176034, C2 = 0.3393176034; // коэффициенты аналитического решения
const double C3 = -0.4920418012, C4 = 1.056078261;

//k1(x), 0 <= x < ksi
double k1(double x);

//q1(x), 0 <= x < ksi
double q1(double x);

//f1(x), 0 <= x < ksi
double f1(double x);

//k2(x), ksi < x <= 1
double k2(double x);

//q2(x), ksi < x <= 1
double q2(double x);

//f2(x), ksi < x <= 1
double f2(double x);

//k1*, 0 <= x < ksi
double k1_test(double x);

//q1*, 0 <= x < ksi
double q1_test(double x);

//f1*, 0 <= x < ksi
double f1_test(double x);

//k2*, ksi < x <= 1
double k2_test(double x);

//q2*, ksi < x <= 1
double q2_test(double x);

//f2*, ksi < x <= 1
double f2_test(double x);

//коэффициенты ai 
vector<double> calc_a(int n, double (*k1)(double), double (*k2)(double));

//коэффициенты di 
vector<double> calc_d(int n, double (*q1)(double), double (*q2)(double));

//коэффициенты fi 
vector<double> calc_f(int n, double (*f1)(double), double (*f2)(double));

//значения на нижней, главной и верхней диагоналях
void tridiagonal(int n, vector<double>& lower, vector<double>& center, vector<double>& upper, double (*k1)(double), double (*k2)(double), double (*q1)(double), double (*q2)(double));

//метод прогонки
vector<double> TMA(int n, vector<double> lower, vector<double> center, vector<double> upper, vector<double> free);

//вычисление свободных членов
vector<double> calc_free(int n, double (*f1)(double), double (*f2)(double));

//задание аналитического решения функций и вычисление
double an_func1(double x);

double an_func2(double x);

vector<double> an_func(int n);