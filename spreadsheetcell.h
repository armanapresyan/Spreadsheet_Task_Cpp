#ifndef SPREADSHEETCELL_H
#define SPREADSHEETCELL_H
#include <string>

class Spreadsheetcell{
	public:
		Spreadsheetcell();
		~Spreadsheetcell();

	public:
		void setStringValue(const std::string& str);
		std::string getStringValue();
		int getIntValue();
		double getDoubleValue();


	private:
		std::string m_value;

};



#endif //SPREADSHEETCELL_H
