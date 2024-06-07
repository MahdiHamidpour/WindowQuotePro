#include "MainWindow.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iostream>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <random>
#include <sstream>
#include <sstream>
#include <string>
#include <vector>
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
	double totPrice = 0;
	for each (DataGridViewRow ^ row in dgvInvoice->Rows)
	{
		if (!row->IsNewRow)
		{
			totQty += Convert::ToInt32(row->Cells[3]->Value);
			totPrice += Convert::ToDouble(row->Cells[6]->Value);
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
	row->Cells[2]->Value = this->cbxSize->Text == "S" ? "Small" : (this->cbxSize->Text == "M" ? "Medium" : "Large");
	row->Cells[3]->Value = this->nudQty->Value.ToString();
	row->Cells[4]->Value = Convert::ToString(price);
	row->Cells[5]->Value = "0";
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
	if (e->ColumnIndex >= 3)
	{
		if (e->RowIndex >= 0 && e->RowIndex < dgvInvoice->RowCount)
		{
			int new_qty = Convert::ToInt32(dgvInvoice->Rows[e->RowIndex]->Cells[3]->Value);
			int price = Convert::ToInt32(dgvInvoice->Rows[e->RowIndex]->Cells[4]->Value);
			int new_off= Convert::ToInt32(dgvInvoice->Rows[e->RowIndex]->Cells[5]->Value);
			double new_total = new_qty * price;
			new_total = new_total - (new_total * double(new_off) / 100.0);
			
			std::stringstream stream;
			stream << std::fixed << std::setprecision(2) << new_total;
			std::string formattedString = stream.str();
			dgvInvoice->Rows[e->RowIndex]->Cells[6]->Value = msclr::interop::marshal_as<System::String^>(formattedString);
		}

	}

	editingStarted();
	updateTotals();
}

inline System::Void CPQ::MainWindow::dgvInvoice_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e)
{
	// Check if the current cell is the one you want to restrict (e.g., Column2)
	if (dgvInvoice->CurrentCell->ColumnIndex >= 3)
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

inline System::Void CPQ::MainWindow::btnOpen_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (isEdited)
	{
		auto result = MessageBox::Show(this, "You've some data that not saved. Do you want to discard them and load invoice?", "Caoution", MessageBoxButtons::YesNoCancel);
		if (result != System::Windows::Forms::DialogResult::Yes)
		{
			return;
		}
	}

	dgvInvoice->Rows->Clear();
	if (import_from_file())
	{
		editingFinished();
	}
}

inline System::Void CPQ::MainWindow::btnImport_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (import_from_file())
		editingStarted();
}

inline System::Void CPQ::MainWindow::textBox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	// Allow digits and control keys (Backspace, etc.)
	if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar))
	{
		e->Handled = true; // Prevent other characters from being entered
	}
}

bool CPQ::MainWindow::import_from_file()
{
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Filter = "Comma-Separated Values(*.csv)|*.csv";
	openFileDialog->Title = "Open invoice";

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		std::string filePath = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);

		// Open the file for reading
		std::ifstream inputFile(filePath);

		if (inputFile.is_open())
		{
			std::string line;
			std::string token;
			while (std::getline(inputFile, line))
			{
				std::vector<std::string> row_cells;
				std::stringstream lineStream(line);
				std::string cell;

				while (std::getline(lineStream, cell, ',')) {
					row_cells.push_back(cell);
				}

				// Check for a trailing comma with no data after it.
				if (!lineStream && cell.empty()) {
					row_cells.push_back(""); // Add an empty element.
				}

				if (row_cells.size() == 7)
				{
					System::Windows::Forms::DataGridViewRow^ row = gcnew System::Windows::Forms::DataGridViewRow();
					row->CreateCells(this->dgvInvoice);
					//cli::array <System::Object^>^ values=gcnew System::Object[7];
					for (int c = 0; c < 7; c++)
					{
						row->Cells[c]->Value = msclr::interop::marshal_as<System::String^>(row_cells.at(c));
						//values[c] = msclr::interop::marshal_as<System::String^>(row_cells.at(c));
					}
					//row->SetValues(values);
					this->dgvInvoice->Rows->Add(row);
				}
				else
				{
					std::string error = "Error reading line:\n" + line;

					MessageBox::Show(
						this,
						msclr::interop::marshal_as<System::String^>(error),
						msclr::interop::marshal_as<System::String^>("Error"),
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
				}
			}
			if (this->dgvInvoice->RowCount > 1)
				this->dgvInvoice->FirstDisplayedScrollingRowIndex = this->dgvInvoice->RowCount - 1;
		}
		else
		{
			MessageBox::Show(
				this,
				msclr::interop::marshal_as<System::String^>("Can't read the file"),
				msclr::interop::marshal_as<System::String^>("Error"),
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			return false;
		}
		return true;
	}
	return false;

}

inline CPQ::MainWindow::MainWindow(void)
{
	InitializeComponent();
	//
	// TODO: Add the constructor code here
	//
	srand(time(0));
}
