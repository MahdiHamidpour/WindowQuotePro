#include "MainWindow.h"
#include <windows.system.h>
#include <random>
#include <iostream>
#include <fstream>
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

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

inline System::Void CPQ::MainWindow::btnQuote_Click(System::Object^ sender, System::EventArgs^ e) {

}

inline System::Void CPQ::MainWindow::MainWindow_Shown(System::Object^ sender, System::EventArgs^ e) {
	cbxDoorMaterial->SelectedIndex = 0;
	cbxSize->SelectedIndex = 0;
}

inline System::Void CPQ::MainWindow::btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
	// Specify the file path where you want to save the data
	std::string filePath = "C:\\Users\\M_Hamidpour\\source\\repos\\MahdiHamidpour\\dgv.csv";

	// Open the file for writing
	std::ofstream outputFile(filePath);

	if (outputFile.is_open()) {
		for (int i = 0; i < dgvInvoice->Rows->Count; i++) {
			for (int j = 0; j < dgvInvoice->Columns->Count; j++) {
				// Get the value from the cell
				System::Object^ cellValue = dgvInvoice->Rows[i]->Cells[j]->Value;

				// Convert the value to a string (if it's not null)
				std::string cellString = (cellValue != nullptr ? static_cast<std::string>(cellValue->ToString()) : "");
				//auto cellString = (cellValue != nullptr ? cellValue->ToString() : "");

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

		// Close the file
		outputFile.close();
		std::cout << "Data saved to " << filePath << std::endl;
	}
	else {
		std::cerr << "Error opening file for writing." << std::endl;
	}
}
