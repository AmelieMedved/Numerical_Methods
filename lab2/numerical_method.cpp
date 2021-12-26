#include "numerical_method.h"

// Tridiagonal matrix algorithm

double k1(double x)
{
  return sqrt(2) * sin(x);
}

double k2(double x)
{
  return cos(x) * cos(x);
}

double q1(double x)
{
  return 1.0;
}

double q2(double x)
{
  return x * x;
}

double f1(double x)
{
  return sin(2.0 * x);
}

double f2(double x)
{
  return cos(x);
}

double k1_test(double x)
{
  return sqrt(2.0) * sin(ksi);
}

double k2_test(double x)
{
  return cos(ksi) * cos(ksi);
}

double q1_test(double x)
{
  return 1.0;
}

double q2_test(double x)
{
  return ksi * ksi;
}

double f1_test(double x)
{
  return sin(2.0 * ksi);
}

double f2_test(double x)
{
  return cos(ksi);
}

double an_func1(double x)
{
  return C1 * exp(x) + C2 * exp(-x) + 1.0;
}

double an_func2(double x)
{
  return C3 * exp((M_PI * x) / (2.0 * sqrt(2.0))) + C4 * exp(((-1.0) * (M_PI)*x) / (2.0 * sqrt(2.0))) + ((8.0 * sqrt(2.0)) / (M_PI * M_PI));
}

vector<double> calc_a(int n, double (*k1)(double), double (*k2)(double))
{
  vector<double> res(n + 1);
  res[0] = 0.0;
  double x = 0.0;
  double h = 1.0 / (double)n;
  for (int i = 1; i <= n; i++)
  {
	double x1 = x + h;
	if (x1 <= ksi)
	  res[i] = k1(x + h/(2.0));
	else
	  if (x >= ksi)
		res[i] = k2(x + h/(2.0));
	  else
	  {
		double tmp = ((1.0) / h) * ((ksi - x) / k1((x + ksi)/(2.0)) + (x1 - ksi) / k2((x1 + ksi)/(2.0)));
		res[i] = 1.0 / tmp;
	  }
	x = x1;
  }
  return res;
}

vector<double> calc_d(int n, double (*q1)(double), double (*q2)(double))
{
  vector<double> res(n + 1);
  res[0] = 0.0;
  double h = 1.0 / (double)n;
  double x = h/(2.0);
  for (int i = 1; i <= n - 1; i++)
  {
	double x1 = x + h;
	if (x1 <= ksi)
	  res[i] = q1(x + h/(2.0));
	else
	  if (x >= ksi)
		res[i] = q2(x + h/(2.0));
	  else
		res[i] = ((1.0) / h) * ((ksi - x) * q1((x + ksi)/(2.0)) + (x1 - ksi) * q2((x1 + ksi)/(2.0)));
	x = x1;
  }
  return res;
}

vector<double> calc_f(int n, double (*f1)(double), double (*f2)(double))
{
  vector<double> res(n + 1);
  res[0] = 0.0;
  double h = 1.0 / (double)n;
  double x = h/(2.0);
  for (int i = 1; i <= n - 1; i++)
  {
	double x1 = x + h;
	if (x1 <= ksi)
	  res[i] = f1(x + h/(2.0));
	else
	  if (x >= ksi)
		res[i] = f2(x + h/(2.0));
	  else
		res[i] = (1.0 / h) * ((ksi - x) * f1((x + ksi)/(2.0)) + (x1 - ksi) * f2((x1 + ksi)/(2.0)));
	x = x1;
  }
  return res;
}

void tridiagonal(int n, vector<double>& lower, vector<double>& center, vector<double>& upper, double (*k1)(double), double (*k2)(double), double (*q1)(double), double (*q2)(double))
{
  lower = calc_a(n, k1, k2);
  upper = lower;
  center = calc_d(n, q1, q2);
  lower[1] *= ((double)n * (double)n);
  for (int i = 2; i <= n; i++)
  {
	lower[i] *= ((double)n * (double)n);
	upper[i - 1] = lower[i];
	center[i - 1] += lower[i] + lower[i - 1];
  }
  lower[n] = 0.0;
  center[0] = 1.0;
  center[n] = 1.0;
  upper[n] = 0.0;
}

vector<double> calc_free(int n, double (*f1)(double), double (*f2)(double))
{
  vector<double> res = calc_f(n, f1, f2);
  res[0] = 1.0;
  res[n] = 0.0;
  return res;
}

// upper - B
// bottom - A

vector<double> TMA(int n, vector<double> lower, vector<double> center, vector<double> upper, vector<double> free)
{
  vector<double> res(n + 1);
  vector<double> alpha(n + 1);
  vector<double> beta(n + 1);
  //	alpha[1] = 0;
  alpha[1] = upper[0];
  //	beta[1] = 0;
  beta[1] = free[0];
  for (int i = 2; i < n + 1; i++)
  {
	double tmp = center[i - 1] - alpha[i - 1] * lower[i - 1];
	alpha[i] = upper[i - 1] / tmp;
	beta[i] = (free[i - 1] + beta[i - 1] * lower[i - 1]) / tmp;
  }
  //	res[n] = 0.0;
  res[n] = (free[n] + lower[n] * beta[n]) / (1.0 - lower[n] * alpha[n]);
  for (int i = n - 1; i >= 0; i--)
	res[i] = alpha[i + 1] * res[i + 1] + beta[i + 1];
  return res;
}

vector<double> an_func(int n)
{
  vector<double> res(n + 1);
  res[0] = 1.0;
  double x = 0.0;
  double h = 1.0 / (double)n;
  for (int i = 1; i <= n; i++)
  {
	double x1 = x + h;
	if (x1 <= ksi)
	  res[i] = an_func1(x1);
	else
	  res[i] = an_func2(x1);
	x = x1;
  }

  return res;
}