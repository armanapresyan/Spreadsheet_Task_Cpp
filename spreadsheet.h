#ifndef Spreadsheet_H
#define Spreadsheet_H
#include "spreadsheetcell.h"

class Spreadsheet{

	public:
		Spreadsheet();
		Spreadsheet(int row, int column);
		Spreadsheet(const Spreadsheet& oth);
		Spreadsheet& operator=(const Spreadsheet& rhs);
		~Spreadsheet();
	public: 
		void addRow(int number);
		void addColumn(int number);
		void removeRow(int number);
		void removeColumn(int number);
		std::string getCell(int row, int col);
		int getCellInt(int row, int col);
		double getCellDouble(int row, int col);
		void setCell(int row, int col,const std::string& str);
		void print();
	private:
		Spreadsheetcell** m_cell;
		int m_row;
		int m_column;
	private:
		void m_create(int m_row, int m_column);
};


#endif //SPREADSHEET_H 
