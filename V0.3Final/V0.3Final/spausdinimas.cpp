#include "spausdinimas.h"
#include <iomanip>
#include <iostream>

void spausdinimas(studentas& kin) {
	kin.galutinis_balas = kin.mediana * 0.4 + kin.egzaminas * 0.6;

	std::cout << std::setw(17) << std::left << kin.vardas << " " << std::setw(17) << std::left << kin.pavarde << " " << std::setprecision(3) << std::setw(3) << std::left << kin.galutinis_balas << std::endl;
}