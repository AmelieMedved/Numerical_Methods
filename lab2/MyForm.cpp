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


  // ������� ������� � �������
  this->chart1->Series[0]->Points->Clear();
  this->chart1->Series[1]->Points->Clear();
  this->chart2->Series[0]->Points->Clear();
  dataGridView1->Rows->Clear();

  label8->Text = "������: ������������� ������� u(x) � ��������� ������� v(x)";
  label9->Text = "������: �������� �������������� � ���������� �������";
  this->chart1->Series[0]->Name = "u(xi)";
  this->chart1->Series[1]->Name = "v(xi)";
  this->chart2->Series[0]->Name = "|u(xi)-v(xi)|";


  // ����������� ����������
  int n = Convert::ToInt32(textBox3->Text); // ������������ � ����� �������� �� textbox3->Text
  double h = 1. / (double)n;
  double x = 0.; 
  vector<double> low, cen, up, fr, res1, res2;
  double eps = 0.; // �������� �����������
  double abs_diff = 0.; // ������ �������� �������
  int devX = 0; // ����� ������������� ���������� ������� 
  tridiagonal(n, low, cen, up, k1_test, k2_test, q1_test, q2_test); // ���������� ������ ���������������� �������
  fr = calc_free(n, f1_test, f2_test); // ���������� ��������� ������
  res1 = an_func(n); // ������������� �������
  res2 = TMA(n, low, cen, up, fr); // ���������� ������ �������� ��� ���������� ���������� �������

  for (int i = 0; i < n + 1; i++)
  {
    //this->chart1->Series[0]->Points->AddXY(x, res1[i]); // ���������� ������� �������������� �������
    //this->chart1->Series[1]->Points->AddXY(x, res2[i]); // ���������� ������� ���������� �������
    //dataGridView1->Rows->Add(); // �������� ����� ������
    //dataGridView1->Rows[i]->Cells[0]->Value = i; // � ����
    //dataGridView1->Rows[i]->Cells[1]->Value = x; // �������� i-�� ����
    //dataGridView1->Rows[i]->Cells[2]->Value = res1[i]; // �������� �������������� �������
    //dataGridView1->Rows[i]->Cells[3]->Value = res2[i]; // �������� ���������� �������
    abs_diff = abs(res2[i] - res1[i]);
    //this->chart2->Series[0]->Points->AddXY(x, abs_diff);
    if (abs_diff > eps)
    {
      eps = abs_diff; // ����������� ������
      devX = i;
    }
    //dataGridView1->Rows[i]->Cells[4]->Value = abs_diff; // �������� ������ �������� �������
    x = x + h;
  }
  
  label7->Text = Convert::ToString(n);
  label11->Text = Convert::ToString(eps);
  label12->Text = Convert::ToString(devX*h);
}

System::Void NMLab2::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
  system("start �������.jpg");
}

System::Void NMLab2::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
  this->chart1->Series[0]->Points->Clear();
  this->chart1->Series[1]->Points->Clear();
  this->chart2->Series[0]->Points->Clear();
  dataGridView2->Rows->Clear();

  label8->Text = "������: ��������� ������� v(x) � ��������� ������� � ���������� ����� v2(x)";
  label9->Text = "������: �������� ��������� ������� � ����� �����";
  this->chart1->Series[1]->Name = "v2(xi)";
  this->chart1->Series[0]->Name = "v(xi)";
  this->chart2->Series[0]->Name = "|v(xi)-v2(xi)|";

  int n = Convert::ToInt32(textBox3->Text); // ������������ � ����� �������� �� textbox3->Text
  double h = 1. / (double)n;
  double x = 0.;
  vector<double> low, cen, up, fr1, fr2, res1, res2;
  double eps = 0.; // �������� �����������
  double abs_diff = 0.; // ������ �������� �������
  int devX = 0; // ����� ������������� ���������� ������� 

  tridiagonal(n, low, cen, up, k1, k2, q1, q2);
  fr1 = calc_free(n, f1, f2);
  res1 = TMA(n, low, cen, up, fr1);
  tridiagonal(2 * n, low, cen, up, k1, k2, q1, q2);
  fr2 = calc_free(2 * n, f1, f2);
  res2 = TMA(2 * n, low, cen, up, fr2);

  for (int i = 0; i < n + 1; i++)
  {
    //this->chart1->Series[0]->Points->AddXY(x, res1[i]); // ���������� ������� �������������� �������
    //this->chart1->Series[1]->Points->AddXY(x, res2[2 * i]); // ���������� ������� ���������� �������
    //dataGridView2->Rows->Add(); // �������� ����� ������
    //dataGridView2->Rows[i]->Cells[0]->Value = i; // � ����
    //dataGridView2->Rows[i]->Cells[1]->Value = x; // �������� i-�� ����
    //dataGridView2->Rows[i]->Cells[2]->Value = res1[i]; // �������� �������������� �������
    //dataGridView2->Rows[i]->Cells[3]->Value = res2[2 * i]; // �������� ���������� �������
    abs_diff = abs(res1[i] - res2[2 * i]);
    //this->chart2->Series[0]->Points->AddXY(x, abs_diff);
    if (abs_diff > eps)
    {
      eps = abs_diff; // ����������� ������
      devX = i;
    }
    //dataGridView2->Rows[i]->Cells[4]->Value = abs_diff; // �������� ������ �������� �������
    x = x + h;
  }
 
  label13->Text = Convert::ToString(n);
  label14->Text = Convert::ToString(eps);
  label15->Text = Convert::ToString(devX * h);
}
