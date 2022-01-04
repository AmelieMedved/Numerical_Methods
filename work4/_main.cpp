#define _USE_MATH_DEFINES // M_PI
#include <iostream>
#include <cmath>
#include <locale>
#include <vector>
#include <fstream>
#include <string>

#define DBL_EPSILON 2.2204460492503131e-16

// n - ���-�� �������� (���������) �� [a, b] �� x
// m - ���-�� �������� (���������) �� [0, T] �� t
// i - ����� ������� �� [a, b] �� x
// j - ����� ������� �� [0, T] �� t
// ���� - ��� ���� �����, ��� ������� �������� ��������� t (�����) �������� ����������: (xi, t0) , i = [0, n]

using namespace std;

// ��������� ������� 1
double mu1(double t)
{
  return cos(t);
}

// ��������� ������� 2
double mu2(double t)
{
  return sin(4.0 * t);
}

// ��������� ������� 
double ux0(double x)
{
  return (1.0 - x * x);
}

// ���������� �������� ���������� ������� x � ����� h
double calcX(double h, int i)
{
  return h * i;
}

// ���������� �������� ���������� ������� x � ����� h
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

// ���������� ��������� ��� ���������� ����������� � 1 �� m-� ����
vector<double> opVij(vector<vector<double>> Vij,int j, int nx,double h)
{
  vector<double> opVij(nx-1);
  double denominator = h * h;
  for (int i = 1; i < nx-1; i++)
  {
    double term1 = Vij[j][i-1]; // 1-� ��������� ���������
    double term2 = (-1.0)*(2.0)*Vij[j][i]; // 2-� ��������� ���������
    double term3 = Vij[j][i+1]; // 3-� ��������� ���������
    double numerator = term1 + term2 + term3; // ��������� ���������
    opVij[i-1] = numerator / denominator; // ���������� ���������
  }
  return opVij;
}

// ���������� ����������� � 1 �� m-� ���� 
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

  // �������� �������� ��������� DBL_EPSILON
 /* if ((1.0 + DBL_EPSILON) != 1.0 && (1.0 + DBL_EPSILON / 2) != 1.0)
  {
    return -1;
  }
  else
  {
    cout << "�������� �������������" << '\n';
  }*/

  // ���� ����������
  double gam_qd = 3.0, a = 0.0, b = 1.0, T; // ��������� ����������� ����� �������, ����� � ������ ����� ������� 
  double h, tau = 0., con = 1.;
  int t0 = 0, n, m; // t0 - ��������� �����
  int flag = 1;

  while (flag)
  {
    n = -1, 
    m = -1,
    T = -1;
    cout << "������� ���������:" << '\n';
    while (T <= 0)
    {
      cout << '\n' << "�������� ����������� �� ������� ������������� ������������ �����" << '\n';
      cout << "����������� �� ������� (T):" << ' ';
      cin >> T;
    }
    while (m <= 0)
    {
      cout << '\n' << "����� ��������� ������������� ����� �����" << '\n';
      cout << "����� ��������� �� ��� ������� (m):" << ' ';
      cin >> m;
    }
    while (n <= 0)
    {
      cout << "����� ��������� ������������� ����� �����" << '\n';
      cout << "����� ��������� �� ��� ��������� ���������� ������� ������� (n):" << ' ';
      cin >> n;
    }

    h = ((b - a) / (double)n); // ���������� ���� �� ��� �������� ������� ������� x
    tau = ((double)(T - 0) / (double)m); // ���������� ���� �� ��� �������� ������� t
    // �������� ����������� �� ���
    con = ((h * h) / (2.0 * gam_qd)); // ������ ����� �����������
    //cout << "tau: " << tau << endl; // ����� ����� �����������
    //cout << "h: " << h << endl;
    //cout << "con: " << con << endl;
    if (con - tau >= DBL_EPSILON)
    {
      system("cls");
      cout << "������������ ����� �����������" << endl;
      cout << "����������� ���������� �������� ���������� � ������ ������� ������� (��������)..." << '\n';
      flag = 0;
    }
    else
    {
      system("cls");
      cout << "������������ ����� �� �����������. ������� ����� ���������" << endl;
    }
  }
  flag = 1;
  // ���������� ����� �� x � t
  int nx = n + 1;
  int mt = m + 1;

  // 2D ������ �������� ��������� ������� x
  vector<vector<double>> vx(3, vector<double>());
  vx = calcX012(h, nx, vx);

  //// ����� ����������� ������� vx
  //for (int j = 0; j < 3; j++)
  //{
  //  for (int i = 0; i < n; i++)
  //    cout << vx[j][i] << ' ';
  //  cout << '\n';
  //}

  // 2D ������ �������� ����������� � ����� (i, j), ��� i �������� �� ��� x, j - �������� �� ��� t
  vector<vector<double>> Vij(mt, vector<double>(nx));

  // ����� �������� �� ������� ���� (����#0)
  // ����� �������� �� x (� ������� ����� h) (����#0)
  double* x = new double[nx];
  for (int i = 0; i < nx; i++)
    x[i] = calcX(h, i);

  // ��������� ������ �������� �� ������� ���� (����#0)
  vector<double> V0(nx);
  V0[0] = mu1(0.);
  V0[nx - 1] = mu2(0.);
  for (int i = 1; i < nx - 1; i++)
    V0[i] = ux0(x[i]);

  // ����� �������� ����������� �� ������� ����
  //for (int i = 0; i < n; i++)
  //  cout << V0[i] << ' ';
  //cout << endl;

  // ����� �������� ��������� �� ������� ���� (����#0)
  vector<double> opV0(nx);
  double denominator = h * h; // ����������� ���������
  for (int i = 0; i < nx; i++)
  {
    double term1 = ux0(vx[0][i]); // 1-� ��������� ���������
    double term2 = (-1.0) * 2.0 * ux0(vx[1][i]); // 2-� ��������� ���������
    double term3 = ux0(vx[2][i]); // 3-� ��������� ���������
    double numerator = term1 + term2 + term3; // ��������� ���������
    opV0[i] = numerator / denominator; // ���������� ���������
    //cout << "�������� �� ������� ����: " << opV0[i] << '\n';
  }

  // ������������ �������� ���� �������� �������� �������� ���������� �� ���� ����� �� 0 �� m
  Vij[0] = V0;

  // ����� �������� ���������� �� ���� ����� ����� �� ���� ���������� ����� �� 1 �� m
  Vij = funcVij(Vij, mt, gam_qd, nx, h, vx, tau);

  // ����� �������� ���������� �� ���� ����� �����
  //for (vector<double> i : Vij) 
  //{
  //  for (double j : i)
  //    cout << j << " ";
  //  cout << "\n";
  //}

  // �������� ����� � ������� csv ��� ������ �������� ����������
  string numberT = "T.txt";
  ofstream wNumberT;
  wNumberT.open(numberT);
  wNumberT << T;
  wNumberT.close();

  string table = "table.csv";
  ofstream wData;
  wData.open(table);
  double time = 0.0;
  wData << "," << "�����:" << ",";
  for (int i = 0; i < mt; i++)
  {   
    wData << "t = " << time  << ",";
    time += tau;
  }
  wData << endl;
  wData << "����� ������� �" << "," << "���������� �������" << ",";
  for (int j = 0; j < mt; j++)
  {
    if (j < mt - 1)
      wData << "���� " << j << ",";
    else
      wData << "���� " << j;
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
    cout << "��� �� ������ �������? ������� ��������������� ����� ����" << '\n';
    cout << "1. �������" << '\n';
    cout << "2. ������� �������� ����������" << '\n';
    cout << "3. ����� ����" << '\n';
    cout << "4. ����� ����������� ������� ����������" << '\n';
    cout << "5. �����" << '\n';

    cin >> var;
    switch (var)
    {
    case 1:
    {
      system("start �������.png");
      cout << "����� �����: " << m << '\n';
      cout << "����� ��������� ����������� ������� �������: " << n << '\n';
      cout << "���������� ������ � ������� ���� �������: 0, 1" <<'\n';
      cout << "����������� � ������������ �������� �� �������: 0, " << T << '\n';
      cout << "���������� ����� �� x: " << nx << '\n';
      cout << "���������� ����� �� t: " << mt << '\n';
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
        cout << "�������� �����: " << m << '\n';
        cout << "������� ����� �������?" << '\n';
        cin >> N;
        for (int i = 0; i < N; i++)
        {
          while (layer < 0 || layer >= mt)
          {
            cout << "������� ����� ���� (������� � ������ 0):" << '\n';
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
      cout << "�������� ������������ ������ ����";
      break;
    }
    }
  } while (flag == 1);

  return 0;
}

