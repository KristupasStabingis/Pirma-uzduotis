#include "nuskaitymas.h"
#include"countwordsinstring.h"
#include <iostream>
#include<string>
#include<iomanip>
#include <vector>
#include <fstream>
#include <iterator>

void nuskaitymas(std::vector<studentas>& st) {
	std::ifstream fileRead;
	std::string eilute;
	fileRead.open("studentai10000.txt.txt");
	try {
		if (fileRead.is_open())
		{
			getline(fileRead >> std::ws, eilute);
			while (fileRead.good()) {
				getline(fileRead, eilute);
				std::cout << eilute << "\n";
			}
		}
		else {
			throw(0);
		}
	}
	catch (int myNum) {
		std::cout << "Failas neegzistuoja" << std::endl;
	}
}