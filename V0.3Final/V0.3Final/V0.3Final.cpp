#include<string>
#include<vector>
#include<iomanip>
#include<iostream>
#include "StudentasStruktura.h"
#include"nuskaitymasirskaiciavimas.h"
#include"nuskaitymas.h"
#include"printas.h"
#include"pild.h"
#include"spausdinimas.h"
using std::endl;


int main()
{
	std::string simbolis;
	studentas studentai[20];
	std::vector <studentas> st;
	std::vector <int> nd;
	std::vector <int> pazym;
	int nd_paz_sk;
	char temp;

	std::cout << "Ar norite studentus rasyti pats, ar norite nuskaityti txt faila? Jei norite rasyti pats - spauskite P, jei nuskaityti - spauskite N" << std::endl;
	std::cin >> simbolis;
	try {
		if (simbolis != "P" && simbolis != "p" && simbolis != "N" && simbolis != "n") {
			throw 0;
		}

		else if (simbolis == "N" || simbolis == "n") {
			std::cout << "Ar faila norite tiesiog nuskaityti, ar norite rasti isvesta studentu galutini pazymi pagal mediana ir vidurki? Jei nuskaityti - spauskite N, jei isvesti - spauskite I" << endl;
			std::cin >> simbolis;
			if (simbolis != "N" && simbolis != "n" && simbolis != "I" && simbolis != "i") {
				throw 0;
			}
			else if (simbolis == "N" || simbolis == "n") {
				std::cout << std::setw(12) << std::left << "Vardas" << "\t" << "\t" << std::left << "Pavarde" << "\t" << "\t" << "\t" << "\t" << std::left << "Pazymiai" << std::endl;
				std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
				nuskaitymas(st);
			}
			else if (simbolis == "I" || simbolis == "i") {
				std::cout << std::setw(20) << std::left << "Vardas"
					<< std::setw(20) << std::left << "Pavarde"
					<< std::setw(18) << std::left << "Galutinis(vid.)/"
					<< std::left << "Galutinis(med.)\n"
					<< "--------------------------------------------------------------------------\n";
				nuskaitymasirskaiciavimas(st, &nd_paz_sk);
			}
		}
		else if (simbolis == "P" || simbolis == "p") {


			std::cout << "Iveskite studentu skaiciu (1-20): ";
			int n;
			std::cin >> n;
			if (n > 20 || n < 1) {
				throw(0);
			}
			for (int i = 0; i < n; i++) {
				pild(studentai[i]);
			}

			std::cout << "Ar norite, kad butu isvestas galutinis studento balas pagal vidurki, ar pagal mediana? Jei pagal vidurki - spauskite V, jei pagal mediana - spauskite M ";
			std::cin >> simbolis;
			if (simbolis != "V" && simbolis != "v" && simbolis != "M" && simbolis != "m") {
				throw 0;
			}
			if (simbolis == "M" || simbolis == "m")

			{
				std::cout << "Vardas" << "\t" << std::setw(17) << "Pavarde" << "\t" << std::setw(23) << "Galutinis(Mediana)" << endl;
				std::cout << "_____________________________________________________________________________" << endl;
				for (int i = 0; i < n; i++)
					spausdinimas(studentai[i]);
			}
			else if (simbolis == "V" || simbolis == "v")
			{
				std::cout << "Vardas" << "\t" << std::setw(17) << "Pavarde" << "\t" << std::setw(23) << "Galutinis(Vidurkis)" << endl;
				std::cout << "_____________________________________________________________________________" << endl;
				for (int i = 0; i < n; i++)
					printas(studentai[i]);
			}
			else if (simbolis != "V" && simbolis != "v" && simbolis != "G" && simbolis != "g") {
				throw 0;
			}
		}
	}
	catch (int myNum) {
		std::cout << "Simbolis negalimas, bandykite is naujo.\n";
	}  
}

	