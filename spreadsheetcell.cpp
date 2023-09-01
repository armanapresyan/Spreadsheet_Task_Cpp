#include "spreadsheetcell.h"
#include <sstream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Spreadsheetcell& s) {
    os << s.getStringValue();
    return os;
}

Spreadsheetcell::Spreadsheetcell() : m_value{" "} {}

Spreadsheetcell& Spreadsheetcell::operator=(const Spreadsheetcell& rhs) {
	if (this == &rhs) {
        return *this; 
    }
	m_value = rhs.m_value;
	return *this;
}

Spreadsheetcell::~Spreadsheetcell(){}

Spreadsheetcell::operator int() {
    return this->getIntValue();
}

Spreadsheetcell::operator double() {
    return this->getDoubleValue();
}

void Spreadsheetcell::operator++() {
	this->m_value += "Prefix";
}

Spreadsheetcell Spreadsheetcell::operator++(int) {
    Spreadsheetcell temp(*this);
    this->m_value += "Postfix";
	return temp;
}

void Spreadsheetcell::operator--() {
	std::cout<<"Prefix"<<std::endl;
}

void Spreadsheetcell::operator--(int) {
	std::cout<<"Postfix"<<std::endl;
}


void Spreadsheetcell::setStringValue(const std::string& str) {
	m_value = str;
}

std::string Spreadsheetcell::getStringValue() const{
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


