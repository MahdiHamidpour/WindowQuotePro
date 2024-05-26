#include "MainWindow.h"
#include <windows.system.h>
#include <random>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

inline System::Void CPQ::MainWindow::btnDB_Click(System::Object^ sender, System::EventArgs^ e) {
	
}

System::Void CPQ::MainWindow::btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(time(0));
	auto price = rand() % 100 + 1;

	System::Windows::Forms::DataGridViewRow^ row = gcnew System::Windows::Forms::DataGridViewRow();
	row->CreateCells(this->dgvInvoice);
	row->Cells[0]->Value = "Door";
	row->Cells[1]->Value = this->cbxDoorMaterial->Text;
	//row->Cells[2]->Value = this->cbxSize->SelectedIndex;// == "S" ? "Small" : (this->cbxSize->Text == "M" ? "Medium" : "Large");
	row->Cells[2]->Value = this->cbxSize->Text == "S" ? "Small" : (this->cbxSize->Text == "M" ? "Medium" : "Large");
	//DataGridViewComboBoxCell cbx = static_cast<DataGridViewComboBoxCell>(row->Cells[2]);
	row->Cells[3]->Value = this->nudQty->Value.ToString();
	row->Cells[4]->Value = Convert::ToString(price);
	row->Cells[5]->Value = "0%";
	row->Cells[6]->Value = Convert::ToString(price * this->nudQty->Value);
	this->dgvInvoice->Rows->Add(row);
	// Assuming 'i' is the index of the new row
	this->dgvInvoice->FirstDisplayedScrollingRowIndex = this->dgvInvoice->RowCount-1;

}

inline System::Void CPQ::MainWindow::dgvInvoice_CurrentCellChanged(System::Object^ sender, System::EventArgs^ e) {
	int totQty = 0;
	int totPrice = 0;
	for (int i = 0; i < this->dgvInvoice->RowCount; i++)
	{
		totQty += Convert::ToInt16(this->dgvInvoice->Rows[i]->Cells[3]->Value); //qty
		totPrice += Convert::ToInt16(this->dgvInvoice->Rows[i]->Cells[6]->Value); //qty
	}
	this->txtTotalQty->Text = Convert::ToString(totQty);
	this->txtTotalPrice->Text = Convert::ToString(totPrice);
}

inline System::Void CPQ::MainWindow::dgvInvoice_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
	int totQty = 0;
	int totPrice = 0;
	for (int i = 0; i < this->dgvInvoice->RowCount; i++)
	{
		totQty += Convert::ToInt16(this->dgvInvoice->Rows[i]->Cells[3]->Value); //qty
		totPrice += Convert::ToInt16(this->dgvInvoice->Rows[i]->Cells[6]->Value); //qty
	}
	this->txtTotalQty->Text = Convert::ToString(totQty);
	this->txtTotalPrice->Text = Convert::ToString(totPrice);
}
