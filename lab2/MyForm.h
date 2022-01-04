#pragma once

namespace NMLab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;




	private: System::Windows::Forms::DataGridView^ dataGridView2;










	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;


	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::TextBox^ textBox3;


	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label2;




	private: System::Windows::Forms::Label^ label6;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;






	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;

	private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;












	protected:
























	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		  System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
		  System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
		  System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		  System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		  System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
		  System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
		  System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		  this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
		  this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
		  this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
		  this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
		  this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
		  this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
		  this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		  this->button1 = (gcnew System::Windows::Forms::Button());
		  this->button2 = (gcnew System::Windows::Forms::Button());
		  this->button3 = (gcnew System::Windows::Forms::Button());
		  this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		  this->textBox3 = (gcnew System::Windows::Forms::TextBox());
		  this->label1 = (gcnew System::Windows::Forms::Label());
		  this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
		  this->label16 = (gcnew System::Windows::Forms::Label());
		  this->label12 = (gcnew System::Windows::Forms::Label());
		  this->label11 = (gcnew System::Windows::Forms::Label());
		  this->label7 = (gcnew System::Windows::Forms::Label());
		  this->label3 = (gcnew System::Windows::Forms::Label());
		  this->label4 = (gcnew System::Windows::Forms::Label());
		  this->label2 = (gcnew System::Windows::Forms::Label());
		  this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
		  this->label17 = (gcnew System::Windows::Forms::Label());
		  this->label15 = (gcnew System::Windows::Forms::Label());
		  this->label14 = (gcnew System::Windows::Forms::Label());
		  this->label13 = (gcnew System::Windows::Forms::Label());
		  this->label5 = (gcnew System::Windows::Forms::Label());
		  this->label10 = (gcnew System::Windows::Forms::Label());
		  this->label6 = (gcnew System::Windows::Forms::Label());
		  this->label8 = (gcnew System::Windows::Forms::Label());
		  this->label9 = (gcnew System::Windows::Forms::Label());
		  this->tableLayoutPanel1->SuspendLayout();
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
		  this->tableLayoutPanel2->SuspendLayout();
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
		  this->groupBox1->SuspendLayout();
		  this->groupBox2->SuspendLayout();
		  this->groupBox3->SuspendLayout();
		  this->SuspendLayout();
		  // 
		  // tableLayoutPanel1
		  // 
		  this->tableLayoutPanel1->ColumnCount = 2;
		  this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			50.11848F)));
		  this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			49.88152F)));
		  this->tableLayoutPanel1->Controls->Add(this->dataGridView1, 0, 0);
		  this->tableLayoutPanel1->Controls->Add(this->chart1, 1, 0);
		  this->tableLayoutPanel1->Location = System::Drawing::Point(279, 41);
		  this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
		  this->tableLayoutPanel1->RowCount = 1;
		  this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		  this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 347)));
		  this->tableLayoutPanel1->Size = System::Drawing::Size(1098, 347);
		  this->tableLayoutPanel1->TabIndex = 1;
		  // 
		  // dataGridView1
		  // 
		  this->dataGridView1->AllowUserToAddRows = false;
		  this->dataGridView1->AllowUserToDeleteRows = false;
		  this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		  this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
			this->Column1,
			  this->Column2, this->Column3, this->Column4, this->Column5
		  });
		  this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
		  this->dataGridView1->Location = System::Drawing::Point(3, 3);
		  this->dataGridView1->Name = L"dataGridView1";
		  this->dataGridView1->ReadOnly = true;
		  this->dataGridView1->Size = System::Drawing::Size(544, 341);
		  this->dataGridView1->TabIndex = 4;
		  this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
		  // 
		  // Column1
		  // 
		  this->Column1->HeaderText = L"№ узла";
		  this->Column1->Name = L"Column1";
		  this->Column1->ReadOnly = true;
		  // 
		  // Column2
		  // 
		  this->Column2->HeaderText = L"xi";
		  this->Column2->Name = L"Column2";
		  this->Column2->ReadOnly = true;
		  // 
		  // Column3
		  // 
		  this->Column3->HeaderText = L"u(xi)";
		  this->Column3->Name = L"Column3";
		  this->Column3->ReadOnly = true;
		  // 
		  // Column4
		  // 
		  this->Column4->HeaderText = L"v(xi)";
		  this->Column4->Name = L"Column4";
		  this->Column4->ReadOnly = true;
		  // 
		  // Column5
		  // 
		  this->Column5->HeaderText = L"|u(xi)-v(xi)|";
		  this->Column5->Name = L"Column5";
		  this->Column5->ReadOnly = true;
		  // 
		  // chart1
		  // 
		  chartArea3->CursorX->IsUserEnabled = true;
		  chartArea3->CursorX->IsUserSelectionEnabled = true;
		  chartArea3->Name = L"ChartArea1";
		  this->chart1->ChartAreas->Add(chartArea3);
		  legend3->Name = L"Legend1";
		  this->chart1->Legends->Add(legend3);
		  this->chart1->Location = System::Drawing::Point(553, 3);
		  this->chart1->Name = L"chart1";
		  series4->BorderWidth = 2;
		  series4->ChartArea = L"ChartArea1";
		  series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		  series4->Color = System::Drawing::Color::Blue;
		  series4->Legend = L"Legend1";
		  series4->Name = L"Series0";
		  series5->BorderWidth = 2;
		  series5->ChartArea = L"ChartArea1";
		  series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		  series5->Color = System::Drawing::Color::Red;
		  series5->Legend = L"Legend1";
		  series5->Name = L"Series1";
		  this->chart1->Series->Add(series4);
		  this->chart1->Series->Add(series5);
		  this->chart1->Size = System::Drawing::Size(541, 341);
		  this->chart1->TabIndex = 5;
		  this->chart1->Text = L"chart1";
		  // 
		  // tableLayoutPanel2
		  // 
		  this->tableLayoutPanel2->ColumnCount = 2;
		  this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			50)));
		  this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			50)));
		  this->tableLayoutPanel2->Controls->Add(this->chart2, 1, 0);
		  this->tableLayoutPanel2->Controls->Add(this->dataGridView2, 0, 0);
		  this->tableLayoutPanel2->Location = System::Drawing::Point(276, 420);
		  this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
		  this->tableLayoutPanel2->RowCount = 1;
		  this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		  this->tableLayoutPanel2->Size = System::Drawing::Size(1101, 352);
		  this->tableLayoutPanel2->TabIndex = 2;
		  // 
		  // chart2
		  // 
		  chartArea4->Name = L"ChartArea1";
		  this->chart2->ChartAreas->Add(chartArea4);
		  legend4->Name = L"Legend1";
		  this->chart2->Legends->Add(legend4);
		  this->chart2->Location = System::Drawing::Point(553, 3);
		  this->chart2->Name = L"chart2";
		  series6->BorderWidth = 2;
		  series6->ChartArea = L"ChartArea1";
		  series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
		  series6->Color = System::Drawing::Color::Red;
		  series6->Legend = L"Legend1";
		  series6->Name = L"Series0";
		  this->chart2->Series->Add(series6);
		  this->chart2->Size = System::Drawing::Size(545, 341);
		  this->chart2->TabIndex = 7;
		  this->chart2->Text = L"chart2";
		  // 
		  // dataGridView2
		  // 
		  this->dataGridView2->AllowUserToAddRows = false;
		  this->dataGridView2->AllowUserToDeleteRows = false;
		  this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		  this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
			this->Column6,
			  this->Column7, this->Column8, this->Column9, this->Column10
		  });
		  this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
		  this->dataGridView2->Location = System::Drawing::Point(3, 3);
		  this->dataGridView2->Name = L"dataGridView2";
		  this->dataGridView2->ReadOnly = true;
		  this->dataGridView2->Size = System::Drawing::Size(544, 346);
		  this->dataGridView2->TabIndex = 6;
		  // 
		  // Column6
		  // 
		  this->Column6->HeaderText = L"№ узла";
		  this->Column6->Name = L"Column6";
		  this->Column6->ReadOnly = true;
		  // 
		  // Column7
		  // 
		  this->Column7->HeaderText = L"xi";
		  this->Column7->Name = L"Column7";
		  this->Column7->ReadOnly = true;
		  // 
		  // Column8
		  // 
		  this->Column8->HeaderText = L"v(xi)";
		  this->Column8->Name = L"Column8";
		  this->Column8->ReadOnly = true;
		  // 
		  // Column9
		  // 
		  this->Column9->HeaderText = L"v2(xi)";
		  this->Column9->Name = L"Column9";
		  this->Column9->ReadOnly = true;
		  // 
		  // Column10
		  // 
		  this->Column10->HeaderText = L"|v(xi)-v2(xi)|";
		  this->Column10->Name = L"Column10";
		  this->Column10->ReadOnly = true;
		  // 
		  // button1
		  // 
		  this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->button1->Location = System::Drawing::Point(9, 72);
		  this->button1->Name = L"button1";
		  this->button1->Size = System::Drawing::Size(249, 23);
		  this->button1->TabIndex = 6;
		  this->button1->Text = L"Решить тестовую задачу";
		  this->button1->UseVisualStyleBackColor = true;
		  this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		  // 
		  // button2
		  // 
		  this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->button2->Location = System::Drawing::Point(9, 101);
		  this->button2->Name = L"button2";
		  this->button2->Size = System::Drawing::Size(249, 23);
		  this->button2->TabIndex = 6;
		  this->button2->Text = L"Решить основную задачу";
		  this->button2->UseVisualStyleBackColor = true;
		  this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
		  // 
		  // button3
		  // 
		  this->button3->Location = System::Drawing::Point(12, 12);
		  this->button3->Name = L"button3";
		  this->button3->Size = System::Drawing::Size(186, 23);
		  this->button3->TabIndex = 6;
		  this->button3->Text = L"Справка";
		  this->button3->UseVisualStyleBackColor = true;
		  this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
		  // 
		  // groupBox1
		  // 
		  this->groupBox1->Controls->Add(this->textBox3);
		  this->groupBox1->Controls->Add(this->label1);
		  this->groupBox1->Controls->Add(this->button1);
		  this->groupBox1->Controls->Add(this->button2);
		  this->groupBox1->Location = System::Drawing::Point(6, 41);
		  this->groupBox1->Name = L"groupBox1";
		  this->groupBox1->Size = System::Drawing::Size(264, 136);
		  this->groupBox1->TabIndex = 7;
		  this->groupBox1->TabStop = false;
		  this->groupBox1->Text = L"Ввод параметра";
		  // 
		  // textBox3
		  // 
		  this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->textBox3->Location = System::Drawing::Point(9, 35);
		  this->textBox3->Multiline = true;
		  this->textBox3->Name = L"textBox3";
		  this->textBox3->Size = System::Drawing::Size(249, 20);
		  this->textBox3->TabIndex = 13;
		  // 
		  // label1
		  // 
		  this->label1->AutoSize = true;
		  this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label1->Location = System::Drawing::Point(6, 16);
		  this->label1->Name = L"label1";
		  this->label1->Size = System::Drawing::Size(126, 16);
		  this->label1->TabIndex = 9;
		  this->label1->Text = L"Число разбиений:";
		  // 
		  // groupBox2
		  // 
		  this->groupBox2->Controls->Add(this->label16);
		  this->groupBox2->Controls->Add(this->label12);
		  this->groupBox2->Controls->Add(this->label11);
		  this->groupBox2->Controls->Add(this->label7);
		  this->groupBox2->Controls->Add(this->label3);
		  this->groupBox2->Controls->Add(this->label4);
		  this->groupBox2->Controls->Add(this->label2);
		  this->groupBox2->Location = System::Drawing::Point(6, 183);
		  this->groupBox2->Name = L"groupBox2";
		  this->groupBox2->Size = System::Drawing::Size(264, 284);
		  this->groupBox2->TabIndex = 8;
		  this->groupBox2->TabStop = false;
		  this->groupBox2->Text = L"Решение тестовой задачи";
		  // 
		  // label16
		  // 
		  this->label16->AutoSize = true;
		  this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label16->Location = System::Drawing::Point(3, 84);
		  this->label16->Name = L"label16";
		  this->label16->Size = System::Drawing::Size(164, 48);
		  this->label16->TabIndex = 25;
		  this->label16->Text = L"Задача должна быть\r\nрешена с погрешностью\r\nне более ε = 0.5 * 10^(-6)";
		  // 
		  // label12
		  // 
		  this->label12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		  this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label12->Location = System::Drawing::Point(57, 251);
		  this->label12->Name = L"label12";
		  this->label12->Size = System::Drawing::Size(201, 20);
		  this->label12->TabIndex = 20;
		  // 
		  // label11
		  // 
		  this->label11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		  this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label11->Location = System::Drawing::Point(3, 164);
		  this->label11->Name = L"label11";
		  this->label11->Size = System::Drawing::Size(255, 20);
		  this->label11->TabIndex = 19;
		  // 
		  // label7
		  // 
		  this->label7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		  this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label7->Location = System::Drawing::Point(6, 64);
		  this->label7->Name = L"label7";
		  this->label7->Size = System::Drawing::Size(252, 20);
		  this->label7->TabIndex = 18;
		  // 
		  // label3
		  // 
		  this->label3->AutoSize = true;
		  this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label3->Location = System::Drawing::Point(0, 197);
		  this->label3->Name = L"label3";
		  this->label3->Size = System::Drawing::Size(186, 64);
		  this->label3->TabIndex = 14;
		  this->label3->Text = L"Максимальное отклонение\r\nточного и численного \r\nрешений наблюдается в \r\nточке x:\r"
			L"\n";
		  // 
		  // label4
		  // 
		  this->label4->AutoSize = true;
		  this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label4->Location = System::Drawing::Point(3, 132);
		  this->label4->Name = L"label4";
		  this->label4->Size = System::Drawing::Size(173, 32);
		  this->label4->TabIndex = 2;
		  this->label4->Text = L"Тестовая задача решена\r\nс точностью ε1:\r\n";
		  // 
		  // label2
		  // 
		  this->label2->AutoSize = true;
		  this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label2->Location = System::Drawing::Point(3, 16);
		  this->label2->Name = L"label2";
		  this->label2->Size = System::Drawing::Size(194, 48);
		  this->label2->TabIndex = 0;
		  this->label2->Text = L"Для решения задачи\r\nиспользована равномерная\r\nсетка с числом разбиений n:";
		  this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
		  // 
		  // groupBox3
		  // 
		  this->groupBox3->Controls->Add(this->label17);
		  this->groupBox3->Controls->Add(this->label15);
		  this->groupBox3->Controls->Add(this->label14);
		  this->groupBox3->Controls->Add(this->label13);
		  this->groupBox3->Controls->Add(this->label5);
		  this->groupBox3->Controls->Add(this->label10);
		  this->groupBox3->Controls->Add(this->label6);
		  this->groupBox3->Location = System::Drawing::Point(6, 473);
		  this->groupBox3->Name = L"groupBox3";
		  this->groupBox3->Size = System::Drawing::Size(264, 299);
		  this->groupBox3->TabIndex = 9;
		  this->groupBox3->TabStop = false;
		  this->groupBox3->Text = L"Решение основной задачи";
		  // 
		  // label17
		  // 
		  this->label17->AutoSize = true;
		  this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label17->Location = System::Drawing::Point(3, 94);
		  this->label17->Name = L"label17";
		  this->label17->Size = System::Drawing::Size(169, 48);
		  this->label17->TabIndex = 26;
		  this->label17->Text = L"Задача должна быть\r\nрешена с заданной\r\nточностью ε = 0.5 * 10^(-6)";
		  // 
		  // label15
		  // 
		  this->label15->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		  this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label15->Location = System::Drawing::Point(6, 258);
		  this->label15->Name = L"label15";
		  this->label15->Size = System::Drawing::Size(252, 20);
		  this->label15->TabIndex = 24;
		  // 
		  // label14
		  // 
		  this->label14->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		  this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label14->Location = System::Drawing::Point(6, 174);
		  this->label14->Name = L"label14";
		  this->label14->Size = System::Drawing::Size(252, 20);
		  this->label14->TabIndex = 23;
		  // 
		  // label13
		  // 
		  this->label13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		  this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label13->Location = System::Drawing::Point(6, 74);
		  this->label13->Name = L"label13";
		  this->label13->Size = System::Drawing::Size(252, 20);
		  this->label13->TabIndex = 22;
		  // 
		  // label5
		  // 
		  this->label5->AutoSize = true;
		  this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label5->Location = System::Drawing::Point(3, 142);
		  this->label5->Name = L"label5";
		  this->label5->Size = System::Drawing::Size(175, 32);
		  this->label5->TabIndex = 21;
		  this->label5->Text = L"Основная задача решена\r\nс точностью ε2:\r\n";
		  // 
		  // label10
		  // 
		  this->label10->AutoSize = true;
		  this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label10->Location = System::Drawing::Point(1, 26);
		  this->label10->Name = L"label10";
		  this->label10->Size = System::Drawing::Size(194, 48);
		  this->label10->TabIndex = 20;
		  this->label10->Text = L"Для решения задачи\r\nиспользована равномерная\r\nсетка с числом разбиений n:";
		  // 
		  // label6
		  // 
		  this->label6->AutoSize = true;
		  this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label6->Location = System::Drawing::Point(4, 194);
		  this->label6->Name = L"label6";
		  this->label6->Size = System::Drawing::Size(168, 64);
		  this->label6->TabIndex = 17;
		  this->label6->Text = L"Максимальная разность\r\nчисленных решений в \r\nобщих узлах сетки \r\nнаблюдается в то"
			L"чке x:\r\n";
		  // 
		  // label8
		  // 
		  this->label8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		  this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label8->Location = System::Drawing::Point(279, 21);
		  this->label8->Name = L"label8";
		  this->label8->Size = System::Drawing::Size(1095, 20);
		  this->label8->TabIndex = 10;
		  // 
		  // label9
		  // 
		  this->label9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		  this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		  this->label9->Location = System::Drawing::Point(279, 400);
		  this->label9->Name = L"label9";
		  this->label9->Size = System::Drawing::Size(1098, 20);
		  this->label9->TabIndex = 11;
		  // 
		  // MyForm
		  // 
		  this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		  this->ClientSize = System::Drawing::Size(1459, 780);
		  this->Controls->Add(this->label9);
		  this->Controls->Add(this->label8);
		  this->Controls->Add(this->groupBox3);
		  this->Controls->Add(this->button3);
		  this->Controls->Add(this->groupBox2);
		  this->Controls->Add(this->groupBox1);
		  this->Controls->Add(this->tableLayoutPanel2);
		  this->Controls->Add(this->tableLayoutPanel1);
		  this->Name = L"MyForm";
		  this->Text = L"MyForm";
		  this->tableLayoutPanel1->ResumeLayout(false);
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
		  this->tableLayoutPanel2->ResumeLayout(false);
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
		  this->groupBox1->ResumeLayout(false);
		  this->groupBox1->PerformLayout();
		  this->groupBox2->ResumeLayout(false);
		  this->groupBox2->PerformLayout();
		  this->groupBox3->ResumeLayout(false);
		  this->groupBox3->PerformLayout();
		  this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
