#include "MainWindow.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <random>
#include <string>
#include <windows.system.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
// using namespace System::Windows::Forms::Form::DialogResult;

void CPQ::MainWindow::editingStarted()
{
	if (isEdited)
		return;
	isEdited = true;
	this->Text += "*";
}

void CPQ::MainWindow::editingFinished()
{
	isEdited = false;
	this->Text = this->Text->Replace("*", "");
}

void CPQ::MainWindow::updateTotals()
{
	int totQty = 0;
	int totPrice = 0;
	for each (DataGridViewRow ^ row in dgvInvoice->Rows)
	{
		if (!row->IsNewRow)
		{
			totQty += Convert::ToInt32(row->Cells[3]->Value);
			totPrice += Convert::ToInt32(row->Cells[6]->Value);
		}
	}
	this->txtTotalQty->Text = Convert::ToString(totQty);
	this->txtTotalPrice->Text = Convert::ToString(totPrice);
}

System::Void CPQ::MainWindow::btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto price = rand() % 100 + 1;

	System::Windows::Forms::DataGridViewRow^ row = gcnew System::Windows::Forms::DataGridViewRow();
	row->CreateCells(this->dgvInvoice);
	row->Cells[0]->Value = "Door";
	row->Cells[1]->Value = this->cbxDoorMaterial->Text;
	// row->Cells[2]->Value = this->cbxSize->SelectedIndex;// == "S" ? "Small" : (this->cbxSize->Text == "M" ? "Medium" : "Large");
	row->Cells[2]->Value = this->cbxSize->Text == "S" ? "Small" : (this->cbxSize->Text == "M" ? "Medium" : "Large");
	// DataGridViewComboBoxCell cbx = static_cast<DataGridViewComboBoxCell>(row->Cells[2]);
	row->Cells[3]->Value = this->nudQty->Value.ToString();
	row->Cells[4]->Value = Convert::ToString(price);
	row->Cells[5]->Value = "0%";
	row->Cells[6]->Value = Convert::ToString(price * this->nudQty->Value);
	this->dgvInvoice->Rows->Add(row);

	this->dgvInvoice->FirstDisplayedScrollingRowIndex = this->dgvInvoice->RowCount - 1;
}

inline System::Void CPQ::MainWindow::dgvInvoice_CurrentCellChanged(System::Object^ sender, System::EventArgs^ e)
{
	editingStarted();
	updateTotals();
}

inline System::Void CPQ::MainWindow::dgvInvoice_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e)
{
	editingStarted();
	updateTotals();
}

inline System::Void CPQ::MainWindow::MainWindow_Shown(System::Object^ sender, System::EventArgs^ e)
{
	cbxDoorMaterial->SelectedIndex = 0;
	cbxSize->SelectedIndex = 0;
	cbxCustomer->SelectedIndex = 0;

	editingFinished();
}

inline System::Void CPQ::MainWindow::btnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
	saveFileDialog->Filter = "Comma-Separated Values(*.csv)|*.csv";
	saveFileDialog->Title = "Save invoice";

	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// String^ fileName = saveFileDialog->FileName;
		// std::string filePath = "C:\\Users\\M_Hamidpour\\source\\repos\\MahdiHamidpour\\dgv.csv";
		std::string filePath = msclr::interop::marshal_as<std::string>(saveFileDialog->FileName);

		// Open the file for writing
		std::ofstream outputFile(filePath);

		if (outputFile.is_open()) {
			for (int i = 0; i < dgvInvoice->Rows->Count; i++) {
				for (int j = 0; j < dgvInvoice->Columns->Count; j++) {
					// Get the value from the cell
					System::Object^ cellValue = dgvInvoice->Rows[i]->Cells[j]->Value;

					// Convert the value to a string (if it's not null)
					std::string cellString = (cellValue != nullptr ? msclr::interop::marshal_as<std::string>(cellValue->ToString()) : "");
					// auto cellString = (cellValue != nullptr ? cellValue->ToString() : "");

					// Write the value to the file
					outputFile << cellString;

					// Add a comma (except for the last column)
					if (j < dgvInvoice->Columns->Count - 1) {
						outputFile << ",";
					}
				}

				// Write a newline after each row
				outputFile << std::endl;
			}
			outputFile.close();
			editingFinished();
		}
		else {
			MessageBox::Show(this, "Can't save to file.", "error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

inline System::Void CPQ::MainWindow::dgvInvoice_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->ColumnIndex == 3)
	{
		if (e->RowIndex >= 0 && e->RowIndex < dgvInvoice->RowCount)
		{
			int new_qty = Convert::ToInt32(dgvInvoice->Rows[e->RowIndex]->Cells[3]->Value);
			int price = Convert::ToInt32(dgvInvoice->Rows[e->RowIndex]->Cells[4]->Value);
			int new_total = new_qty * price;
			dgvInvoice->Rows[e->RowIndex]->Cells[6]->Value = Convert::ToString(new_total);
		}

	}

	editingStarted();
	updateTotals();
}

inline System::Void CPQ::MainWindow::dgvInvoice_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e)
{
	// Check if the current cell is the one you want to restrict (e.g., Column2)
	if (dgvInvoice->CurrentCell->ColumnIndex == 3)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(e->Control);
		if (textBox != nullptr)
		{
			// Attach an event handler for the KeyPress event
			textBox->KeyPress += gcnew KeyPressEventHandler(this, &MainWindow::textBox_KeyPress);
		}
	}
}

inline System::Void CPQ::MainWindow::btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	for each (DataGridViewRow ^ row in dgvInvoice->SelectedRows)
	{
		if (!row->IsNewRow)
		{
			dgvInvoice->Rows->RemoveAt(row->Index);
		}
	}
}

inline System::Void CPQ::MainWindow::textBox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	// Allow digits and control keys (Backspace, etc.)
	if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar))
	{
		e->Handled = true; // Prevent other characters from being entered
	}
}

inline CPQ::MainWindow::MainWindow(void)
{
	InitializeComponent();
	//
	// TODO: Add the constructor code here
	//
	srand(time(0));
}
