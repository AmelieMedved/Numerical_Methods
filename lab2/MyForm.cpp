#include "MyForm.h"
#include "numerical_method.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(cli::array<String^>^ args) {
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);

  NMLab2::MyForm form;
  Application::Run(% form);
}


System::Void NMLab2::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{


  // очистка графика и таблицы
  this->chart1->Series[0]->Points->Clear();
  this->chart1->Series[1]->Points->Clear();
  this->chart2->Series[0]->Points->Clear();
  dataGridView1->Rows->Clear();

  label8->Text = "График: аналитическое решение u(x) и численное решение v(x)";
  label9->Text = "График: разность аналитического и численного решения";
  this->chart1->Series[0]->Name = "u(xi)";
  this->chart1->Series[1]->Name = "v(xi)";
  this->chart2->Series[0]->Name = "|u(xi)-v(xi)|";


  // определение переменных
  int n = Convert::ToInt32(textBox3->Text); // конвертирует в числа значения из textbox3->Text
  double h = 1. / (double)n;
  double x = 0.; 
  vector<double> low, cen, up, fr, res1, res2;
  double eps = 0.; // контроль погрешности
  double abs_diff = 0.; // модуль разности решений
  int devX = 0; // точка максимального отклонения решений 
  tridiagonal(n, low, cen, up, k1_test, k2_test, q1_test, q2_test); // вычисление членов трехдиагональной матрицы
  fr = calc_free(n, f1_test, f2_test); // вычисление свободных членов
  res1 = an_func(n); // аналитическое решение
  res2 = TMA(n, low, cen, up, fr); // применения метода прогонки для вычисления численного решения

  for (int i = 0; i < n + 1; i++)
  {
    //this->chart1->Series[0]->Points->AddXY(x, res1[i]); // построение графика аналитического решения
    //this->chart1->Series[1]->Points->AddXY(x, res2[i]); // построение графика численного решения
    //dataGridView1->Rows->Add(); // добавить новую строку
    //dataGridView1->Rows[i]->Cells[0]->Value = i; // № узла
    //dataGridView1->Rows[i]->Cells[1]->Value = x; // значение i-го узла
    //dataGridView1->Rows[i]->Cells[2]->Value = res1[i]; // значение аналитического решения
    //dataGridView1->Rows[i]->Cells[3]->Value = res2[i]; // значение численного решения
    abs_diff = abs(res2[i] - res1[i]);
    //this->chart2->Series[0]->Points->AddXY(x, abs_diff);
    if (abs_diff > eps)
    {
      eps = abs_diff; // погрешность растет
      devX = i;
    }
    //dataGridView1->Rows[i]->Cells[4]->Value = abs_diff; // значение модуля разности решений
    x = x + h;
  }
  
  label7->Text = Convert::ToString(n);
  label11->Text = Convert::ToString(eps);
  label12->Text = Convert::ToString(devX*h);
}

System::Void NMLab2::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
  system("start Справка.jpg");
}

System::Void NMLab2::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
  this->chart1->Series[0]->Points->Clear();
  this->chart1->Series[1]->Points->Clear();
  this->chart2->Series[0]->Points->Clear();
  dataGridView2->Rows->Clear();

  label8->Text = "График: численное решение v(x) и численное решение с половинным шагом v2(x)";
  label9->Text = "График: разность численных решений в общих узлах";
  this->chart1->Series[1]->Name = "v2(xi)";
  this->chart1->Series[0]->Name = "v(xi)";
  this->chart2->Series[0]->Name = "|v(xi)-v2(xi)|";

  int n = Convert::ToInt32(textBox3->Text); // конвертирует в числа значения из textbox3->Text
  double h = 1. / (double)n;
  double x = 0.;
  vector<double> low, cen, up, fr1, fr2, res1, res2;
  double eps = 0.; // контроль погрешности
  double abs_diff = 0.; // модуль разности решений
  int devX = 0; // точка максимального отклонения решений 

  tridiagonal(n, low, cen, up, k1, k2, q1, q2);
  fr1 = calc_free(n, f1, f2);
  res1 = TMA(n, low, cen, up, fr1);
  tridiagonal(2 * n, low, cen, up, k1, k2, q1, q2);
  fr2 = calc_free(2 * n, f1, f2);
  res2 = TMA(2 * n, low, cen, up, fr2);

  for (int i = 0; i < n + 1; i++)
  {
    //this->chart1->Series[0]->Points->AddXY(x, res1[i]); // построение графика аналитического решения
    //this->chart1->Series[1]->Points->AddXY(x, res2[2 * i]); // построение графика численного решения
    //dataGridView2->Rows->Add(); // добавить новую строку
    //dataGridView2->Rows[i]->Cells[0]->Value = i; // № узла
    //dataGridView2->Rows[i]->Cells[1]->Value = x; // значение i-го узла
    //dataGridView2->Rows[i]->Cells[2]->Value = res1[i]; // значение аналитического решения
    //dataGridView2->Rows[i]->Cells[3]->Value = res2[2 * i]; // значение численного решения
    abs_diff = abs(res1[i] - res2[2 * i]);
    //this->chart2->Series[0]->Points->AddXY(x, abs_diff);
    if (abs_diff > eps)
    {
      eps = abs_diff; // погрешность растет
      devX = i;
    }
    //dataGridView2->Rows[i]->Cells[4]->Value = abs_diff; // значение модуля разности решений
    x = x + h;
  }
 
  label13->Text = Convert::ToString(n);
  label14->Text = Convert::ToString(eps);
  label15->Text = Convert::ToString(devX * h);
}
