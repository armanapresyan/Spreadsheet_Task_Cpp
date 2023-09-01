#ifndef SPREADSHEETCELL_H
#define SPREADSHEETCELL_H
#include <string>

class Spreadsheetcell{
	public:
		Spreadsheetcell();
		Spreadsheetcell& operator=(const Spreadsheetcell& rhs);
		operator int();
		operator double();
		void operator++();
		Spreadsheetcell operator++(int);
		void operator--();
		void operator--(int);
		~Spreadsheetcell();
	

	public:
		void setStringValue(const std::string& str);
		std::string getStringValue() const;
		int getIntValue();
		double getDoubleValue();


	private:
		std::string m_value;

};



#endif //SPREADSHEETCELL_H
