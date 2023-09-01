#ifndef Spreadsheet_H
#define Spreadsheet_H
#include "spreadsheetcell.h"



class Spreadsheet{

	public:
		Spreadsheet();
		Spreadsheet(int row, int column);
		Spreadsheet(const Spreadsheet& oth);
		Spreadsheet operator+(const Spreadsheet& rhs);
		Spreadsheet& operator=(const Spreadsheet& rhs);
		Spreadsheetcell* operator[](int row) const;
		~Spreadsheet();
	public: 
		void addRow(int number);
		void addColumn(int number);
		void removeRow(int number);
		void removeColumn(int number);
		int get_row() const;
		int get_column() const;
		Spreadsheetcell* getCell(int row, int col) const;
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



std::ostream& operator<<(std::ostream& os, const Spreadsheet& s);

#endif //SPREADSHEET_H 
