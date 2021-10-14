#pragma once
#include <string>
#include <vector>

struct studentas {
	std::string vardas, pavarde;
	float nd[20]{};
	float egzaminas;
	std::vector<int> paz = { 0 };
	float galutinis_balas;
	float vidurkis;
	float vid;
	double mediana;
};

