#include "spreadsheet.h"
#include <iostream>


std::ostream& operator<<(std::ostream& os, const Spreadsheet& s) {
    for (int i = 0; i < s.get_row(); ++i) {
        for (int j = 0; j < s.get_column(); ++j) {
            os << s.getCell(i, j)->getStringValue() << '\t'; 
        }
        os << '\n'; 
    }
    return os;
}


Spreadsheet::Spreadsheet() {
	m_row = 2;
	m_column = 2;
	m_cell = new Spreadsheetcell*[m_row];
	for(int i = 0; i < m_row; ++i){
		m_cell[i] = new Spreadsheetcell[m_column];
	}
}



Spreadsheet::Spreadsheet(int row, int column) {
	m_row = row; 
	m_column = column;
	m_cell = new Spreadsheetcell*[m_row];
	for(int i = 0; i < m_row; ++i){
		m_cell[i] = new Spreadsheetcell[m_column];
	}
}

Spreadsheet::Spreadsheet(const Spreadsheet& oth) {
	m_row = oth.m_row;
	m_column = oth.m_column;
	m_cell = new Spreadsheetcell*[m_row];
	for(int i = 0; i < m_row; ++i){
		m_cell[i] = new Spreadsheetcell[m_column];
	}

   for(int i  = 0; i < m_row; ++i){
	for(int j = 0; j < m_column; ++j){
		m_cell[i][j] = oth.m_cell[i][j];
	}
   }

}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
	if(this == &rhs){
		return *this;
	}
	for(int i = 0; i < m_row; ++i){
		delete[] m_cell[i];
	}
	delete[] m_cell;
   
    m_row = rhs.m_row;
	m_column = rhs.m_column;
	m_cell = new Spreadsheetcell*[m_row];
	for(int i = 0; i < m_row; ++i){
		m_cell[i] = new Spreadsheetcell[m_column];
	}

   for(int i  = 0; i < m_row; ++i){
	for(int j = 0; j < m_column; ++j){
		m_cell[i][j] = rhs.m_cell[i][j];
	}
   }

   return *this;

}

Spreadsheet Spreadsheet::operator+(const Spreadsheet& cell) {
	int row = m_row + cell.m_row;
	int column = (m_column > cell.m_column) ? m_column : cell.m_column;
    Spreadsheet res(row, column);

	for(int i = 0; i < m_row; ++i){
        for(int j = 0; j < m_column; ++j){
			res.m_cell[i][j] = m_cell[i][j];
		}
	}

    
	for(int i = 0; i < cell.m_row; ++i){
        for(int j = 0; j < cell.m_column; ++j){
			res.m_cell[i + m_row][j] = cell.m_cell[i][j];
		}
	}
	
	return res;
}

Spreadsheetcell* Spreadsheet::operator[](int row) const{
        return m_cell[row];
}


void Spreadsheet::addRow(int number) {
	Spreadsheet* tmp = new Spreadsheet(number, m_column);
	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_column; ++j) {
			tmp->m_cell[i][j] = m_cell[i][j];
		} 
	}

	m_row = number;
	m_cell = std::move(tmp->m_cell);
	tmp->m_row = 0;
	tmp = nullptr;
}

void Spreadsheet::addColumn(int number) {
	Spreadsheet* tmp = new Spreadsheet(m_row, number);

	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_column; ++j) {
			tmp->m_cell[i][j] = m_cell[i][j];
		}
	}

	m_column = number;
	m_cell = std::move(tmp->m_cell);
	tmp->m_row = 0;
	tmp = nullptr;

}

void Spreadsheet::removeRow(int number) {
	if (number >= m_row || number < 0) {
		std::cout << "Invalid row number to remove." << std::endl;
		return;
	}

	delete[] m_cell[number]; 

	for (int i = number; i < m_row - 1; ++i) {
		m_cell[i] = m_cell[i + 1];
	}

	m_cell[m_row - 1] = nullptr; 

	--m_row;
}

void Spreadsheet::removeColumn(int number) {
	if (number >= m_column || number < 0) {
		std::cout << "Invalid column number to remove." << std::endl;
		return;
	}

	for (int i = 0; i < m_row; ++i) {
		for (int j = number; j < m_column - 1; ++j) {
			m_cell[i][j] = m_cell[i][j + 1];
		}
	}

	--m_column;
}

int Spreadsheet::get_row() const{
	return m_row;
}

int Spreadsheet::get_column() const{
	return m_column;
}

Spreadsheetcell* Spreadsheet::getCell(int row, int column) const {
   if (row >= m_row || column >= m_column || row < 0 || column < 0) {
      throw std::out_of_range{"Wrong coordinates."};
   }
   return &m_cell[row][column];
}
int Spreadsheet::getCellInt(int row, int col){
	if (row >= m_row || col >= m_column || row < 0 || col < 0) {
		std::cout << "Invalid cell coordinates." << std::endl;
		return 0; 
	}
	return  m_cell[row][col].getIntValue();

}

double Spreadsheet::getCellDouble(int row, int col){
	if (row >= m_row || col >= m_column || row < 0 || col < 0) {
		std::cout << "Invalid cell coordinates." << std::endl;
		return 0; 
	}
	return  m_cell[row][col].getDoubleValue();

}

void Spreadsheet::setCell(int row, int col, const std::string& value) {
	if (row >= m_row || col >= m_column || row < 0 || col < 0) {
		std::cout << "Invalid cell coordinates." << std::endl;
		return;
	}

	m_cell[row][col].setStringValue(value);
}




Spreadsheet::~Spreadsheet(){
	for(int i = 0; i < m_row; ++i){
		delete[] m_cell[i];
	}

	delete[] m_cell;
}


void Spreadsheet::print() {
	for(int i = 0; i < m_row; ++i){
		for(int j = 0; j < m_column; ++j){
			std::cout << "|" << m_cell[i][j].getStringValue() << "|";
		}
		std::cout<<""<<std::endl;
	}

}



