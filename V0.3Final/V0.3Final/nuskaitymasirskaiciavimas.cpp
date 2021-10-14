#include "nuskaitymasirskaiciavimas.h"
#include "StudentasStruktura.h"
#include<vector>
#include <iomanip>
#include <iostream>
#include <string>
#include<fstream>

void nuskaitymasirskaiciavimas(std::vector<studentas>& st, int* nd_paz_sk) {
	int studentu_skaicius = 0;
	int temp;
	std::ifstream fileRead;
	std::string eilute;
	fileRead.open("studentai1000.txt.txt");
	try {
		if (fileRead.is_open())
		{
			getline(fileRead >> std::ws, eilute);
			*nd_paz_sk = countWordsInString(eilute) - 3;
			while (true)
			{
				st.resize(st.size() + 1);
				fileRead >> st.at(studentu_skaicius).vardas;
				if (fileRead.eof()) { st.pop_back(); break; }
				fileRead >> st.at(studentu_skaicius).pavarde;
				for (int i = 0; i < *nd_paz_sk; i++)
				{
					fileRead >> temp;
					st.at(studentu_skaicius).paz.push_back(temp);
				}

				fileRead >> st.at(studentu_skaicius).egzaminas;
				st.at(studentu_skaicius).vidurkis = average(st.at(studentu_skaicius).paz);
				st.at(studentu_skaicius).mediana = count_median(st.at(studentu_skaicius).paz);
				studentu_skaicius++;
			}
		}
		else {
			throw(0);
		}
	}
	catch(int myNum){
		std::cout << "Failas neegzistuoja" << std::endl;
	}
	for (int i = 0; i < st.size(); i++)
	{
		std::cout << std::setw(20) << std::left << st[i].vardas << std::setw(20) << std::left << st[i].pavarde << std::setw(18) << std::left << std::setprecision(3) << st[i].vidurkis * 0.4 + st[i].egzaminas * 0.6 << st[i].mediana * 0.4 + st[i].egzaminas * 0.6 << std::endl;
	}

	std::cout << "\n\n";

}