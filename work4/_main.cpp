#define _USE_MATH_DEFINES // M_PI
#include <iostream>
#include <cmath>
#include <locale>
#include <vector>
#include <fstream>
#include <string>

#define DBL_EPSILON 2.2204460492503131e-16

// n - кол-во участков (разбиений) на [a, b] по x
// m - кол-во участков (разбиений) на [0, T] по t
// i - номер участка на [a, b] по x
// j - номер участка на [0, T] по t
// Слой - это узлы сетки, для которых значение аргумента t (время) является одинаковым: (xi, t0) , i = [0, n]

using namespace std;

// граничное условие 1
double mu1(double t)
{
  return cos(t);
}

// граничное условие 2
double mu2(double t)
{
  return sin(4.0 * t);
}

// начальное условие 
double ux0(double x)
{
  return (1.0 - x * x);
}

// вычисление значений координаты сечения x с шагом h
double calcX(double h, int i)
{
  return h * i;
}

// вычисление значений координаты сечения x с шагом h
vector<vector<double>> calcX012(double h, int n, vector<vector<double>> vx)
{
  for (int i = 0; i < n; i++)
  {
    vx[0].push_back(h * ((double)i - 1.0));
    vx[1].push_back(h * i);
    vx[2].push_back(h * ((double)i + 1.0));
  }

  return vx;
}

// вычисление оператора для вычисления температуры с 1 по m-й слои
vector<double> opVij(vector<vector<double>> Vij,int j, int nx,double h)
{
  vector<double> opVij(nx-1);
  double denominator = h * h;
  for (int i = 1; i < nx-1; i++)
  {
    double term1 = Vij[j][i-1]; // 1-е слагаемое уравнения
    double term2 = (-1.0)*(2.0)*Vij[j][i]; // 2-е слагаемое уравнения
    double term3 = Vij[j][i+1]; // 3-е слагаемое уравнения
    double numerator = term1 + term2 + term3; // числитель уравнения
    opVij[i-1] = numerator / denominator; // вычисление оператора
  }
  return opVij;
}

// вычисление температуры с 1 по m-й слои 
vector<vector<double>> funcVij(vector<vector<double>> Vij, int mt, double gam_qd, int nx, double h, vector<vector<double>> vx, double tau)
{
  double t = 0.0;
  for (int j = 1; j < mt; j++)
  {
    t += tau;
    Vij[j][0] = mu1(t);
    Vij[j][nx - 1] = mu2(t);
    vector<double> opV = opVij(Vij, j - 1, nx, h);
    for (int i = 1; i < nx-1; i++)
    {
      double g = (t * cos((M_PI * vx[1][i]))) / (t + 1.0);
      Vij[j][i] = (gam_qd * opV[i-1] + g) * tau + Vij[j - 1][i];
    }
  }
  return Vij;
}
 
int main()
{
  setlocale(LC_ALL, "RUS");

  // проверка значения параметра DBL_EPSILON
 /* if ((1.0 + DBL_EPSILON) != 1.0 && (1.0 + DBL_EPSILON / 2) != 1.0)
  {
    return -1;
  }
  else
  {
    cout << "Точность гарантируется" << '\n';
  }*/

  // ввод параметров
  double gam_qd = 3.0, a = 0.0, b = 1.0, T; // известные коэффициент гамма квадрат, левая и правая грань стержня 
  double h, tau = 0., con = 1.;
  int t0 = 0, n, m; // t0 - начальное время
  int flag = 1;

  while (flag)
  {
    n = -1, 
    m = -1,
    T = -1;
    cout << "Введите параметры:" << '\n';
    while (T <= 0)
    {
      cout << '\n' << "Значение ограничения по времени положительное вещественное число" << '\n';
      cout << "Ограничение по времени (T):" << ' ';
      cin >> T;
    }
    while (m <= 0)
    {
      cout << '\n' << "Число разбиений положительное целое число" << '\n';
      cout << "Число разбиений по оси времени (m):" << ' ';
      cin >> m;
    }
    while (n <= 0)
    {
      cout << "Число разбиений положительное целое число" << '\n';
      cout << "Число разбиений по оси координат поперечных сечений стержня (n):" << ' ';
      cin >> n;
    }

    h = ((b - a) / (double)n); // вычисление шага по оси значений сечения стержня x
    tau = ((double)(T - 0) / (double)m); // вычисление шага по оси значений времени t
    // проверка ограниченая на шаг
    con = ((h * h) / (2.0 * gam_qd)); // правая часть неравенства
    //cout << "tau: " << tau << endl; // левая часть неравенства
    //cout << "h: " << h << endl;
    //cout << "con: " << con << endl;
    if (con - tau >= DBL_EPSILON)
    {
      system("cls");
      cout << "Согласование шагов выполняется" << endl;
      cout << "Выполняется вычисление значений температур в разные моменты времени (послойно)..." << '\n';
      flag = 0;
    }
    else
    {
      system("cls");
      cout << "Согласование шагов не выполняется. Введите новые параметры" << endl;
    }
  }
  flag = 1;
  // количество узлов по x и t
  int nx = n + 1;
  int mt = m + 1;

  // 2D вектор значений координат сечений x
  vector<vector<double>> vx(3, vector<double>());
  vx = calcX012(h, nx, vx);

  //// вывод содержимого вектора vx
  //for (int j = 0; j < 3; j++)
  //{
  //  for (int i = 0; i < n; i++)
  //    cout << vx[j][i] << ' ';
  //  cout << '\n';
  //}

  // 2D вектор значений температуры в узлах (i, j), где i значение по оси x, j - значение по оси t
  vector<vector<double>> Vij(mt, vector<double>(nx));

  // поиск значения на нулевом слое (слой#0)
  // поиск значений по x (с текущим шагом h) (слой#0)
  double* x = new double[nx];
  for (int i = 0; i < nx; i++)
    x[i] = calcX(h, i);

  // заполняем вектор значений на нулевом слое (слой#0)
  vector<double> V0(nx);
  V0[0] = mu1(0.);
  V0[nx - 1] = mu2(0.);
  for (int i = 1; i < nx - 1; i++)
    V0[i] = ux0(x[i]);

  // вывод значений температуры на нулевом слое
  //for (int i = 0; i < n; i++)
  //  cout << V0[i] << ' ';
  //cout << endl;

  // поиск значения оператора на нулевом слое (слой#0)
  vector<double> opV0(nx);
  double denominator = h * h; // знаменатель уравнения
  for (int i = 0; i < nx; i++)
  {
    double term1 = ux0(vx[0][i]); // 1-е слагаемое уравнения
    double term2 = (-1.0) * 2.0 * ux0(vx[1][i]); // 2-е слагаемое уравнения
    double term3 = ux0(vx[2][i]); // 3-е слагаемое уравнения
    double numerator = term1 + term2 + term3; // числитель уравнения
    opV0[i] = numerator / denominator; // вычисление оператора
    //cout << "оператор на нулевом слое: " << opV0[i] << '\n';
  }

  // присваивание нулевого слоя основным вектором значений температур на всех слоях от 0 до m
  Vij[0] = V0;

  // поиск значений температур во всех узлах сетки на всех оставшихся слоях от 1 до m
  Vij = funcVij(Vij, mt, gam_qd, nx, h, vx, tau);

  // вывод значений температур во всех узлах сетки
  //for (vector<double> i : Vij) 
  //{
  //  for (double j : i)
  //    cout << j << " ";
  //  cout << "\n";
  //}

  // создание файла в формате csv для записи значений температур
  string numberT = "T.txt";
  ofstream wNumberT;
  wNumberT.open(numberT);
  wNumberT << T;
  wNumberT.close();

  string table = "table.csv";
  ofstream wData;
  wData.open(table);
  double time = 0.0;
  wData << "," << "Время:" << ",";
  for (int i = 0; i < mt; i++)
  {   
    wData << "t = " << time  << ",";
    time += tau;
  }
  wData << endl;
  wData << "Номер сечения х" << "," << "Координата сечения" << ",";
  for (int j = 0; j < mt; j++)
  {
    if (j < mt - 1)
      wData << "Слой " << j << ",";
    else
      wData << "Слой " << j;
  }
  wData << endl;
  for (int i = 0; i < nx; i++)
  {
    wData << i << "," << vx[1][i] << ",";
    for (int j = 0; j < mt; j++)
    {
      if (j < mt - 1)
        wData << Vij[j][i] << ",";
      else
        wData << Vij[j][i];
    }
    wData << endl;
  }
  system("python csv_to_xlsx.py");
  wData.close();

  int var;
  do
  {
    cout << "Что вы хотите сделать? Введите соответствующий пункт меню" << '\n';
    cout << "1. Справка" << '\n';
    cout << "2. Таблица значений температур" << '\n';
    cout << "3. Вывод слоя" << '\n';
    cout << "4. Вывод трехмерного графика температур" << '\n';
    cout << "5. Выход" << '\n';

    cin >> var;
    switch (var)
    {
    case 1:
    {
      system("start справка.png");
      cout << "Число слоев: " << m << '\n';
      cout << "Число разбиений поперечного сечения стержня: " << n << '\n';
      cout << "Координата левого и правого края стержня: 0, 1" <<'\n';
      cout << "Минимальное и максимальное значение по времени: 0, " << T << '\n';
      cout << "Количество узлов по x: " << nx << '\n';
      cout << "Количество узлов по t: " << mt << '\n';
      break;
    }
    case 2:
    {
      system("start table.xlsx");
      system("cls");
      break;
    }
    case 3:
    {
      int N = -1;
      int layer = -1;
      string number = "number.txt";
      ofstream wNumber;
      wNumber.open(number);
      while (layer < 0)
      {
        cout << "Доступно слоев: " << m << '\n';
        cout << "Сколько слоев вывести?" << '\n';
        cin >> N;
        for (int i = 0; i < N; i++)
        {
          while (layer < 0 || layer >= mt)
          {
            cout << "Введите номер слоя (начиная с номера 0):" << '\n';
            cin >> layer;
          }
          layer += 1;
          wNumber << layer;
          wNumber << ' ';
          layer = -1;
        }
        layer = 0;
      }
      wNumber.close();
      system("python layer.py");
      system("cls");
      break;
    }
    case 4:
    {
      system("python graphic.py");
      system("cls");
      break;
    }
    case 5:
    {
      flag = 0;
      break;
    }
    default:
    {
      cout << "Выберете предложенные пункты меню";
      break;
    }
    }
  } while (flag == 1);

  return 0;
}

