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

    public:
    MainWindow(void)
    {
        InitializeComponent();
        //
        // TODO: Add the constructor code here
        //
    }

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
    System::Windows::Forms::Button ^ btnDB;
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
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Product;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Material;
    System::Windows::Forms::DataGridViewComboBoxColumn ^ Size;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Qty;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ PricePerUnit;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ Off;
    System::Windows::Forms::DataGridViewTextBoxColumn ^ TotalPrice;
    System::Windows::Forms::Button ^ btnQuote;
    System::Windows::Forms::Button ^ btnSave;

private:
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
        this->btnDB = (gcnew System::Windows::Forms::Button());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->cbxCustomer = (gcnew System::Windows::Forms::ComboBox());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->dgbProduct = (gcnew System::Windows::Forms::GroupBox());
        this->nudQty = (gcnew System::Windows::Forms::NumericUpDown());
        this->btnAdd = (gcnew System::Windows::Forms::Button());
        this->cbxSize = (gcnew System::Windows::Forms::ComboBox());
        this->cbxDoorMaterial = (gcnew System::Windows::Forms::ComboBox());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->dgvInvoice = (gcnew System::Windows::Forms::DataGridView());
        this->Product = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Material = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Size = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
        this->Qty = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->PricePerUnit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->Off = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->TotalPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
        this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->txtTotalQty = (gcnew System::Windows::Forms::TextBox());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->txtTotalPrice = (gcnew System::Windows::Forms::TextBox());
        this->btnSave = (gcnew System::Windows::Forms::Button());
        this->btnQuote = (gcnew System::Windows::Forms::Button());
        this->panel1->SuspendLayout();
        this->dgbProduct->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->nudQty))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->dgvInvoice))->BeginInit();
        this->tableLayoutPanel1->SuspendLayout();
        this->flowLayoutPanel1->SuspendLayout();
        this->SuspendLayout();
        //
        // btnDB
        //
        this->btnDB->Location = System::Drawing::Point(397, 3);
        this->btnDB->Name = L"btnDB";
        this->btnDB->Size = System::Drawing::Size(75, 23);
        this->btnDB->TabIndex = 0;
        this->btnDB->Text = L"Connect DB";
        this->btnDB->UseVisualStyleBackColor = true;
        this->btnDB->Click += gcnew System::EventHandler(this, &MainWindow::btnDB_Click);
        //
        // label1
        //
        this->label1->AutoSize = true;
        this->label1->Location = System::Drawing::Point(14, 19);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(82, 13);
        this->label1->TabIndex = 0;
        this->label1->Text = L"Customer Name";
        //
        // cbxCustomer
        //
        this->cbxCustomer->FormattingEnabled = true;
        this->cbxCustomer->Location = System::Drawing::Point(102, 19);
        this->cbxCustomer->Name = L"cbxCustomer";
        this->cbxCustomer->Size = System::Drawing::Size(121, 21);
        this->cbxCustomer->TabIndex = 2;
        //
        // panel1
        //
        this->panel1->AutoSize = true;
        this->panel1->Controls->Add(this->dgbProduct);
        this->panel1->Controls->Add(this->btnDB);
        this->panel1->Controls->Add(this->cbxCustomer);
        this->panel1->Controls->Add(this->label1);
        this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
        this->panel1->Location = System::Drawing::Point(3, 3);
        this->panel1->MaximumSize = System::Drawing::Size(0, 110);
        this->panel1->MinimumSize = System::Drawing::Size(0, 110);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(1163, 110);
        this->panel1->TabIndex = 2;
        //
        // dgbProduct
        //
        this->dgbProduct->Controls->Add(this->nudQty);
        this->dgbProduct->Controls->Add(this->btnAdd);
        this->dgbProduct->Controls->Add(this->cbxSize);
        this->dgbProduct->Controls->Add(this->cbxDoorMaterial);
        this->dgbProduct->Controls->Add(this->label4);
        this->dgbProduct->Controls->Add(this->label3);
        this->dgbProduct->Controls->Add(this->label2);
        this->dgbProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->dgbProduct->Location = System::Drawing::Point(3, 46);
        this->dgbProduct->Name = L"dgbProduct";
        this->dgbProduct->Size = System::Drawing::Size(657, 58);
        this->dgbProduct->TabIndex = 3;
        this->dgbProduct->TabStop = false;
        this->dgbProduct->Text = L"Product";
        //
        // nudQty
        //
        this->nudQty->Location = System::Drawing::Point(414, 20);
        this->nudQty->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4) { 1000, 0, 0, 0 });
        this->nudQty->Minimum = System::Decimal(gcnew cli::array<System::Int32>(4) { 1, 0, 0, 0 });
        this->nudQty->Name = L"nudQty";
        this->nudQty->Size = System::Drawing::Size(55, 20);
        this->nudQty->TabIndex = 3;
        this->nudQty->Value = System::Decimal(gcnew cli::array<System::Int32>(4) { 1, 0, 0, 0 });
        //
        // btnAdd
        //
        this->btnAdd->Location = System::Drawing::Point(531, 18);
        this->btnAdd->Name = L"btnAdd";
        this->btnAdd->Size = System::Drawing::Size(75, 23);
        this->btnAdd->TabIndex = 2;
        this->btnAdd->Text = L"Add";
        this->btnAdd->UseVisualStyleBackColor = true;
        this->btnAdd->Click += gcnew System::EventHandler(this, &MainWindow::btnAdd_Click);
        //
        // cbxSize
        //
        this->cbxSize->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->cbxSize->Items->AddRange(gcnew cli::array<System::Object ^>(3) { L"S", L"M", L"L" });
        this->cbxSize->Location = System::Drawing::Point(267, 19);
        this->cbxSize->Name = L"cbxSize";
        this->cbxSize->Size = System::Drawing::Size(80, 21);
        this->cbxSize->TabIndex = 1;
        //
        // cbxDoorMaterial
        //
        this->cbxDoorMaterial->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->cbxDoorMaterial->Items->AddRange(gcnew cli::array<System::Object ^>(2) { L"Wood", L"Metal" });
        this->cbxDoorMaterial->Location = System::Drawing::Point(83, 20);
        this->cbxDoorMaterial->Name = L"cbxDoorMaterial";
        this->cbxDoorMaterial->Size = System::Drawing::Size(121, 21);
        this->cbxDoorMaterial->TabIndex = 1;
        //
        // label4
        //
        this->label4->AutoSize = true;
        this->label4->Location = System::Drawing::Point(353, 20);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(54, 13);
        this->label4->TabIndex = 0;
        this->label4->Text = L"Quantities";
        //
        // label3
        //
        this->label3->AutoSize = true;
        this->label3->Location = System::Drawing::Point(210, 20);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(51, 13);
        this->label3->TabIndex = 0;
        this->label3->Text = L"Door size";
        //
        // label2
        //
        this->label2->AutoSize = true;
        this->label2->Location = System::Drawing::Point(7, 20);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(69, 13);
        this->label2->TabIndex = 0;
        this->label2->Text = L"Door material";
        //
        // dgvInvoice
        //
        this->dgvInvoice->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
        this->dgvInvoice->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn ^>(7) { this->Product, this->Material,
            this->Size, this->Qty, this->PricePerUnit, this->Off, this->TotalPrice });
        this->dgvInvoice->Dock = System::Windows::Forms::DockStyle::Fill;
        this->dgvInvoice->Location = System::Drawing::Point(3, 112);
        this->dgvInvoice->Name = L"dgvInvoice";
        this->dgvInvoice->Size = System::Drawing::Size(1163, 471);
        this->dgvInvoice->TabIndex = 3;
        this->dgvInvoice->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::dgvInvoice_CellValueChanged);
        this->dgvInvoice->CurrentCellChanged += gcnew System::EventHandler(this, &MainWindow::dgvInvoice_CurrentCellChanged);
        this->dgvInvoice->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MainWindow::dgvInvoice_RowsAdded);
        //
        // Product
        //
        this->Product->HeaderText = L"Product";
        this->Product->Name = L"Product";
        //
        // Material
        //
        this->Material->HeaderText = L"Material";
        this->Material->Name = L"Material";
        //
        // Size
        //
        this->Size->HeaderText = L"Size";
        this->Size->Items->AddRange(gcnew cli::array<System::Object ^>(3) { L"Small", L"Medium", L"Large" });
        this->Size->Name = L"Size";
        this->Size->Resizable = System::Windows::Forms::DataGridViewTriState::True;
        this->Size->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
        //
        // Qty
        //
        this->Qty->HeaderText = L"Qty";
        this->Qty->Name = L"Qty";
        //
        // PricePerUnit
        //
        this->PricePerUnit->HeaderText = L"Unit Price";
        this->PricePerUnit->Name = L"PricePerUnit";
        this->PricePerUnit->ReadOnly = true;
        //
        // Off
        //
        this->Off->HeaderText = L"Off";
        this->Off->Name = L"Off";
        //
        // TotalPrice
        //
        this->TotalPrice->HeaderText = L"Total Price";
        this->TotalPrice->Name = L"TotalPrice";
        this->TotalPrice->ReadOnly = true;
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
        this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
        this->tableLayoutPanel1->RowCount = 3;
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.65794F)));
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 81.34206F)));
        this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
        this->tableLayoutPanel1->Size = System::Drawing::Size(1169, 632);
        this->tableLayoutPanel1->TabIndex = 4;
        //
        // flowLayoutPanel1
        //
        this->flowLayoutPanel1->Controls->Add(this->label5);
        this->flowLayoutPanel1->Controls->Add(this->txtTotalQty);
        this->flowLayoutPanel1->Controls->Add(this->label6);
        this->flowLayoutPanel1->Controls->Add(this->txtTotalPrice);
        this->flowLayoutPanel1->Controls->Add(this->btnSave);
        this->flowLayoutPanel1->Controls->Add(this->btnQuote);
        this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
        this->flowLayoutPanel1->Location = System::Drawing::Point(3, 589);
        this->flowLayoutPanel1->MinimumSize = System::Drawing::Size(0, 25);
        this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
        this->flowLayoutPanel1->Padding = System::Windows::Forms::Padding(3);
        this->flowLayoutPanel1->Size = System::Drawing::Size(1163, 40);
        this->flowLayoutPanel1->TabIndex = 4;
        //
        // label5
        //
        this->label5->AutoSize = true;
        this->label5->Location = System::Drawing::Point(6, 9);
        this->label5->Margin = System::Windows::Forms::Padding(3, 6, 3, 3);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(84, 13);
        this->label5->TabIndex = 0;
        this->label5->Text = L"Total Quantities:";
        //
        // txtTotalQty
        //
        this->txtTotalQty->Location = System::Drawing::Point(96, 6);
        this->txtTotalQty->Name = L"txtTotalQty";
        this->txtTotalQty->ReadOnly = true;
        this->txtTotalQty->Size = System::Drawing::Size(67, 20);
        this->txtTotalQty->TabIndex = 1;
        //
        // label6
        //
        this->label6->AutoSize = true;
        this->label6->Location = System::Drawing::Point(169, 9);
        this->label6->Margin = System::Windows::Forms::Padding(3, 6, 3, 3);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(58, 13);
        this->label6->TabIndex = 2;
        this->label6->Text = L"Total Price";
        //
        // txtTotalPrice
        //
        this->txtTotalPrice->Location = System::Drawing::Point(233, 6);
        this->txtTotalPrice->Name = L"txtTotalPrice";
        this->txtTotalPrice->ReadOnly = true;
        this->txtTotalPrice->Size = System::Drawing::Size(100, 20);
        this->txtTotalPrice->TabIndex = 3;
        //
        // btnSave
        //
        this->btnSave->Location = System::Drawing::Point(339, 6);
        this->btnSave->Name = L"btnSave";
        this->btnSave->Size = System::Drawing::Size(75, 23);
        this->btnSave->TabIndex = 5;
        this->btnSave->Text = L"Save";
        this->btnSave->UseVisualStyleBackColor = true;
        this->btnSave->Click += gcnew System::EventHandler(this, &MainWindow::btnSave_Click);
        //
        // btnQuote
        //
        this->btnQuote->AutoSize = true;
        this->btnQuote->Location = System::Drawing::Point(420, 6);
        this->btnQuote->Name = L"btnQuote";
        this->btnQuote->Size = System::Drawing::Size(93, 23);
        this->btnQuote->TabIndex = 4;
        this->btnQuote->Text = L"Generate Quote";
        this->btnQuote->UseVisualStyleBackColor = true;
        this->btnQuote->Click += gcnew System::EventHandler(this, &MainWindow::btnQuote_Click);
        //
        // MainWindow
        //
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->AutoSize = true;
        this->ClientSize = System::Drawing::Size(1169, 632);
        this->Controls->Add(this->tableLayoutPanel1);
        this->Name = L"MainWindow";
        this->Text = L"MainWindow ";
        this->Shown += gcnew System::EventHandler(this, &MainWindow::MainWindow_Shown);
        this->panel1->ResumeLayout(false);
        this->panel1->PerformLayout();
        this->dgbProduct->ResumeLayout(false);
        this->dgbProduct->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->nudQty))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->dgvInvoice))->EndInit();
        this->tableLayoutPanel1->ResumeLayout(false);
        this->tableLayoutPanel1->PerformLayout();
        this->flowLayoutPanel1->ResumeLayout(false);
        this->flowLayoutPanel1->PerformLayout();
        this->ResumeLayout(false);
    }
#pragma endregion
private:
    System::Void btnDB_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void btnAdd_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void dgvInvoice_CurrentCellChanged(System::Object ^ sender, System::EventArgs ^ e);
    System::Void dgvInvoice_RowsAdded(System::Object ^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs ^ e);
    System::Void btnQuote_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void MainWindow_Shown(System::Object ^ sender, System::EventArgs ^ e);
    System::Void btnSave_Click(System::Object ^ sender, System::EventArgs ^ e);
    System::Void dgvInvoice_CellValueChanged(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e);
};
}
