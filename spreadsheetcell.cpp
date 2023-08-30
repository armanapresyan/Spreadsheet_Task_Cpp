#include "spreadsheetcell.h"
#include <sstream>
#include <iostream>

Spreadsheetcell::Spreadsheetcell() : m_value{" "} {}


Spreadsheetcell::~Spreadsheetcell(){}


void Spreadsheetcell::setStringValue(const std::string& str) {
	m_value = str;
}

std::string Spreadsheetcell::getStringValue() {
	return m_value;
}

double Spreadsheetcell::getDoubleValue() {
	double num;
	std::stringstream ss(m_value);
	if (!(ss >> num)) {
		throw ("Cannot convert cell value to double.");
	}
	return num;
}


int Spreadsheetcell::getIntValue(){
	int num;
	std::stringstream ss(m_value);	
	if (!(ss >> num)) {
		throw ("Cannot convert cell value to int.");
	}
	return num;
}


