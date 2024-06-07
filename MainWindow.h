#pragma once

namespace CPQ {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Summary for MainWindow
/// </summary>
public
ref class MainWindow : public System::Windows::Forms::Form {
    private:
        bool isEdited = false;

        void editingStarted();
        void editingFinished();
        void updateTotals();

        void textBox_KeyPress(Object^ sender, KeyPressEventArgs^ e);
        bool import_from_file();

    public:
    MainWindow(void);

protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~MainWindow()
    {
        if (components) {
            delete components;
        }
    }


private:

    System::Windows::Forms::Label ^ label1;
    System::Windows::Forms::ComboBox ^ cbxCustomer;
    System::Windows::Forms::Panel ^ panel1;
    System::Windows::Forms::GroupBox ^ dgbProduct;
    System::Windows::Forms::Label ^ label2;
    System::Windows::Forms::ComboBox ^ cbxDoorMaterial;
    System::Windows::Forms::ComboBox ^ cbxSize;
    System::Windows::Forms::Label ^ label3;
    System::Windows::Forms::Button ^ btnAdd;
    System::Windows::Forms::DataGridView ^ dgvInvoice;
    System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel1;
    System::Windows::Forms::Label ^ label4;
    System::Windows::Forms::NumericUpDown ^ nudQty;
    System::Windows::Forms::FlowLayoutPanel ^ flowLayoutPanel1;
    System::Windows::Forms::Label ^ label5;
    System::Windows::Forms::TextBox ^ txtTotalQty;
    System::Windows::Forms::Label ^ label6;
    System::Windows::Forms::TextBox ^ txtTotalPrice;

    System::Windows::Forms::Button ^ btnSave;







    System::Windows::Forms::Button^ btnDelete;
    System::Windows::Forms::Button^ btnOpen;
private: System::Windows::Forms::Button^ btnImport;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Product;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ Material;
private: System::Windows::Forms::DataGridViewComboBoxColumn^ Size;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Qty;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ PricePerUnit;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Off;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ TotalPrice;










    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->cbxCustomer = (gcnew System::Windows::Forms::ComboBox());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->dgbProduct = (gcnew System::Windows::Forms::GroupBox());
        this->btnDelete = (gcnew System::Windows::Forms::Button());
        this->nudQty = (gcnew System::Windows::Forms::NumericUpDown());
        this->btnAdd = (gcnew System::Windows::Forms::Button());
        this->cbxSize = (gcnew System::Windows::Forms::ComboBox());
        this->cbxDoorMaterial = (gcnew System::Windows::Forms::ComboBox());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->dgvInvoice = (gcnew System::Windows::Forms::DataGridView());
        this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
        this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->txtTotalQty = (gcnew System::Windows::Forms::TextBox());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->txtTotalPrice = (gcnew System::Windows::Forms::TextBox());
        this->btnSave = (gcnew System::Windows::Forms::Button());
        this->btnOpen = (gcnew System::Windows::Forms::Button());
        this->btnImport = (gcnew System::Windows::Forms::Button());
        this->Product = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Material = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
        this->Size = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
        this->Qty = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->PricePerUnit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Off = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->TotalPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->panel1->SuspendLayout();
        this->dgbProduct->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudQty))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInvoice))->BeginInit();
        this->tableLayoutPanel1->SuspendLayout();
        this->flowLayoutPanel1->SuspendLayout();
        this->SuspendLayout();
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Location = System::Drawing::Point(28, 37);
        this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(166, 25);
        this->label1->TabIndex = 0;
        this->label1->Text = L"Customer Name";
        // 
        // cbxCustomer
        // 
        this->cbxCustomer->FormattingEnabled = true;
        this->cbxCustomer->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Load From DB if needed" });
        this->cbxCustomer->Location = System::Drawing::Point(204, 37);
        this->cbxCustomer->Margin = System::Windows::Forms::Padding(6);
        this->cbxCustomer->Name = L"cbxCustomer";
        this->cbxCustomer->Size = System::Drawing::Size(513, 33);
        this->cbxCustomer->TabIndex = 2;
        // 
        // panel1
        // 
        this->panel1->AutoSize = true;
        this->panel1->Controls->Add(this->dgbProduct);
        this->panel1->Controls->Add(this->cbxCustomer);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(6, 6);
        this->panel1->Margin = System::Windows::Forms::Padding(6);
        this->panel1->MaximumSize = System::Drawing::Size(0, 212);
        this->panel1->MinimumSize = System::Drawing::Size(0, 212);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(2326, 212);
        this->panel1->TabIndex = 2;
        // 
        // dgbProduct
        // 
        this->dgbProduct->Controls->Add(this->btnDelete);
        this->dgbProduct->Controls->Add(this->nudQty);
        this->dgbProduct->Controls->Add(this->btnAdd);
        this->dgbProduct->Controls->Add(this->cbxSize);
        this->dgbProduct->Controls->Add(this->cbxDoorMaterial);
        this->dgbProduct->Controls->Add(this->label4);
        this->dgbProduct->Controls->Add(this->label3);
        this->dgbProduct->Controls->Add(this->label2);
        this->dgbProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->dgbProduct->Location = System::Drawing::Point(6, 88);
        this->dgbProduct->Margin = System::Windows::Forms::Padding(6);
        this->dgbProduct->Name = L"dgbProduct";
        this->dgbProduct->Padding = System::Windows::Forms::Padding(6);
        this->dgbProduct->Size = System::Drawing::Size(1452, 112);
        this->dgbProduct->TabIndex = 3;
        this->dgbProduct->TabStop = false;
        this->dgbProduct->Text = L"Product";
        // 
        // btnDelete
        // 
        this->btnDelete->Location = System::Drawing::Point(1240, 35);
        this->btnDelete->Name = L"btnDelete";
        this->btnDelete->Size = System::Drawing::Size(170, 43);
        this->btnDelete->TabIndex = 4;
        this->btnDelete->Text = L"Delete";
        this->btnDelete->UseVisualStyleBackColor = true;
        this->btnDelete->Click += gcnew System::EventHandler(this, &MainWindow::btnDelete_Click);
        // 
        // nudQty
        // 
        this->nudQty->Location = System::Drawing::Point(828, 38);
        this->nudQty->Margin = System::Windows::Forms::Padding(6);
        this->nudQty->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
        this->nudQty->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        this->nudQty->Name = L"nudQty";
        this->nudQty->Size = System::Drawing::Size(110, 31);
        this->nudQty->TabIndex = 3;
        this->nudQty->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        // 
        // btnAdd
        // 
        this->btnAdd->Location = System::Drawing::Point(1062, 35);
        this->btnAdd->Margin = System::Windows::Forms::Padding(6);
        this->btnAdd->Name = L"btnAdd";
        this->btnAdd->Size = System::Drawing::Size(150, 44);
        this->btnAdd->TabIndex = 2;
        this->btnAdd->Text = L"Add";
        this->btnAdd->UseVisualStyleBackColor = true;
        this->btnAdd->Click += gcnew System::EventHandler(this, &MainWindow::btnAdd_Click);
        // 
        // cbxSize
        // 
        this->cbxSize->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->cbxSize->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"S", L"M", L"L" });
        this->cbxSize->Location = System::Drawing::Point(534, 37);
        this->cbxSize->Margin = System::Windows::Forms::Padding(6);
        this->cbxSize->Name = L"cbxSize";
        this->cbxSize->Size = System::Drawing::Size(156, 33);
        this->cbxSize->TabIndex = 1;
        // 
        // cbxDoorMaterial
        // 
        this->cbxDoorMaterial->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->cbxDoorMaterial->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Wood", L"Metal" });
        this->cbxDoorMaterial->Location = System::Drawing::Point(166, 38);
        this->cbxDoorMaterial->Margin = System::Windows::Forms::Padding(6);
        this->cbxDoorMaterial->Name = L"cbxDoorMaterial";
        this->cbxDoorMaterial->Size = System::Drawing::Size(238, 33);
        this->cbxDoorMaterial->TabIndex = 1;
        // 
        // label4
        // 
        this->label4->AutoSize = true;
        this->label4->Location = System::Drawing::Point(706, 38);
        this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(109, 25);
        this->label4->TabIndex = 0;
        this->label4->Text = L"Quantities";
        // 
        // label3
        // 
        this->label3->AutoSize = true;
        this->label3->Location = System::Drawing::Point(420, 38);
        this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(103, 25);
        this->label3->TabIndex = 0;
        this->label3->Text = L"Door size";
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Location = System::Drawing::Point(14, 38);
        this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(140, 25);
        this->label2->TabIndex = 0;
        this->label2->Text = L"Door material";
        // 
        // dgvInvoice
        // 
        this->dgvInvoice->AllowUserToAddRows = false;
        this->dgvInvoice->ColumnHeadersHeight = 46;
        this->dgvInvoice->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
            this->Product, this->Material,
                this->Size, this->Qty, this->PricePerUnit, this->Off, this->TotalPrice
        });
        this->dgvInvoice->Dock = System::Windows::Forms::DockStyle::Fill;
        this->dgvInvoice->Location = System::Drawing::Point(6, 216);
        this->dgvInvoice->Margin = System::Windows::Forms::Padding(6);
        this->dgvInvoice->Name = L"dgvInvoice";
        this->dgvInvoice->RowHeadersWidth = 40;
        this->dgvInvoice->Size = System::Drawing::Size(2326, 905);
        this->dgvInvoice->TabIndex = 3;
        this->dgvInvoice->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::dgvInvoice_CellValueChanged);
        this->dgvInvoice->CurrentCellChanged += gcnew System::EventHandler(this, &MainWindow::dgvInvoice_CurrentCellChanged);
        this->dgvInvoice->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MainWindow::dgvInvoice_EditingControlShowing);
        this->dgvInvoice->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MainWindow::dgvInvoice_RowsAdded);
        // 
        // tableLayoutPanel1
        // 
        this->tableLayoutPanel1->AutoScroll = true;
        this->tableLayoutPanel1->ColumnCount = 1;
        this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
            50)));
        this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
            50)));
        this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
        this->tableLayoutPanel1->Controls->Add(this->dgvInvoice, 0, 1);
        this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 0, 2);
        this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
        this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(6);
        this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
        this->tableLayoutPanel1->RowCount = 3;
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.65794F)));
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 81.34206F)));
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 87)));
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
        this->tableLayoutPanel1->Size = System::Drawing::Size(2338, 1215);
        this->tableLayoutPanel1->TabIndex = 4;
        // 
        // flowLayoutPanel1
        // 
        this->flowLayoutPanel1->Controls->Add(this->label5);
        this->flowLayoutPanel1->Controls->Add(this->txtTotalQty);
        this->flowLayoutPanel1->Controls->Add(this->label6);
        this->flowLayoutPanel1->Controls->Add(this->txtTotalPrice);
        this->flowLayoutPanel1->Controls->Add(this->btnSave);
        this->flowLayoutPanel1->Controls->Add(this->btnOpen);
        this->flowLayoutPanel1->Controls->Add(this->btnImport);
        this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->flowLayoutPanel1->Location = System::Drawing::Point(6, 1133);
        this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(6);
        this->flowLayoutPanel1->MinimumSize = System::Drawing::Size(0, 48);
        this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
        this->flowLayoutPanel1->Padding = System::Windows::Forms::Padding(6);
        this->flowLayoutPanel1->Size = System::Drawing::Size(2326, 76);
        this->flowLayoutPanel1->TabIndex = 4;
        // 
        // label5
        // 
        this->label5->AutoSize = true;
        this->label5->Location = System::Drawing::Point(12, 18);
        this->label5->Margin = System::Windows::Forms::Padding(6, 12, 6, 6);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(169, 25);
        this->label5->TabIndex = 0;
        this->label5->Text = L"Total Quantities:";
        // 
        // txtTotalQty
        // 
        this->txtTotalQty->Location = System::Drawing::Point(193, 12);
        this->txtTotalQty->Margin = System::Windows::Forms::Padding(6);
        this->txtTotalQty->Name = L"txtTotalQty";
        this->txtTotalQty->ReadOnly = true;
        this->txtTotalQty->Size = System::Drawing::Size(130, 31);
        this->txtTotalQty->TabIndex = 1;
        // 
        // label6
        // 
        this->label6->AutoSize = true;
        this->label6->Location = System::Drawing::Point(335, 18);
        this->label6->Margin = System::Windows::Forms::Padding(6, 12, 6, 6);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(115, 25);
        this->label6->TabIndex = 2;
        this->label6->Text = L"Total Price";
        // 
        // txtTotalPrice
        // 
        this->txtTotalPrice->Location = System::Drawing::Point(462, 12);
        this->txtTotalPrice->Margin = System::Windows::Forms::Padding(6);
        this->txtTotalPrice->Name = L"txtTotalPrice";
        this->txtTotalPrice->ReadOnly = true;
        this->txtTotalPrice->Size = System::Drawing::Size(196, 31);
        this->txtTotalPrice->TabIndex = 3;
        // 
        // btnSave
        // 
        this->btnSave->Location = System::Drawing::Point(670, 12);
        this->btnSave->Margin = System::Windows::Forms::Padding(6);
        this->btnSave->Name = L"btnSave";
        this->btnSave->Size = System::Drawing::Size(150, 44);
        this->btnSave->TabIndex = 5;
        this->btnSave->Text = L"Save";
        this->btnSave->UseVisualStyleBackColor = true;
        this->btnSave->Click += gcnew System::EventHandler(this, &MainWindow::btnSave_Click);
        // 
        // btnOpen
        // 
        this->btnOpen->Location = System::Drawing::Point(832, 12);
        this->btnOpen->Margin = System::Windows::Forms::Padding(6);
        this->btnOpen->Name = L"btnOpen";
        this->btnOpen->Size = System::Drawing::Size(150, 44);
        this->btnOpen->TabIndex = 5;
        this->btnOpen->Text = L"Open";
        this->btnOpen->UseVisualStyleBackColor = true;
        this->btnOpen->Click += gcnew System::EventHandler(this, &MainWindow::btnOpen_Click);
        // 
        // btnImport
        // 
        this->btnImport->Location = System::Drawing::Point(994, 12);
        this->btnImport->Margin = System::Windows::Forms::Padding(6);
        this->btnImport->Name = L"btnImport";
        this->btnImport->Size = System::Drawing::Size(150, 44);
        this->btnImport->TabIndex = 5;
        this->btnImport->Text = L"Import";
        this->btnImport->UseVisualStyleBackColor = true;
        this->btnImport->Click += gcnew System::EventHandler(this, &MainWindow::btnImport_Click);
        // 
        // Product
        // 
        this->Product->HeaderText = L"Product";
        this->Product->MinimumWidth = 50;
        this->Product->Name = L"Product";
        this->Product->ReadOnly = true;
        this->Product->Width = 200;
        // 
        // Material
        // 
        this->Material->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
        this->Material->HeaderText = L"Material";
        this->Material->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Wood", L"Metal" });
        this->Material->MinimumWidth = 50;
        this->Material->Name = L"Material";
        this->Material->Resizable = System::Windows::Forms::DataGridViewTriState::True;
        this->Material->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
        this->Material->Width = 134;
        // 
        // Size
        // 
        this->Size->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
        this->Size->HeaderText = L"Size";
        this->Size->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Small", L"Medium", L"Large" });
        this->Size->MinimumWidth = 10;
        this->Size->Name = L"Size";
        this->Size->Resizable = System::Windows::Forms::DataGridViewTriState::True;
        this->Size->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
        this->Size->Width = 99;
        // 
        // Qty
        // 
        this->Qty->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
        this->Qty->HeaderText = L"Qty";
        this->Qty->MinimumWidth = 10;
        this->Qty->Name = L"Qty";
        this->Qty->Width = 90;
        // 
        // PricePerUnit
        // 
        this->PricePerUnit->HeaderText = L"Unit Price";
        this->PricePerUnit->MinimumWidth = 50;
        this->PricePerUnit->Name = L"PricePerUnit";
        this->PricePerUnit->ReadOnly = true;
        this->PricePerUnit->Width = 150;
        // 
        // Off
        // 
        this->Off->HeaderText = L"Off(%)";
        this->Off->MinimumWidth = 10;
        this->Off->Name = L"Off";
        this->Off->Width = 80;
        // 
        // TotalPrice
        // 
        this->TotalPrice->HeaderText = L"Total Price";
        this->TotalPrice->MinimumWidth = 50;
        this->TotalPrice->Name = L"TotalPrice";
        this->TotalPrice->ReadOnly = true;
        this->TotalPrice->Width = 160;
        // 
        // MainWindow
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->AutoSize = true;
        this->ClientSize = System::Drawing::Size(2338, 1215);
        this->Controls->Add(this->tableLayoutPanel1);
        this->Margin = System::Windows::Forms::Padding(6);
        this->Name = L"MainWindow";
        this->Text = L"MainWindow ";
        this->Shown += gcnew System::EventHandler(this, &MainWindow::MainWindow_Shown);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->dgbProduct->ResumeLayout(false);
        this->dgbProduct->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudQty))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInvoice))->EndInit();
        this->tableLayoutPanel1->ResumeLayout(false);
        this->tableLayoutPanel1->PerformLayout();
        this->flowLayoutPanel1->ResumeLayout(false);
        this->flowLayoutPanel1->PerformLayout();
        this->ResumeLayout(false);

    }
#pragma endregion
private:
    System::Void btnAdd_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void dgvInvoice_CurrentCellChanged(System::Object ^ sender, System::EventArgs ^ e);
    System::Void dgvInvoice_RowsAdded(System::Object ^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs ^ e);
    System::Void MainWindow_Shown(System::Object ^ sender, System::EventArgs ^ e);
    System::Void btnSave_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void dgvInvoice_CellValueChanged(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e);
    System::Void dgvInvoice_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e);
    System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
    System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e);
    System::Void btnImport_Click(System::Object^ sender, System::EventArgs^ e);
};
}
