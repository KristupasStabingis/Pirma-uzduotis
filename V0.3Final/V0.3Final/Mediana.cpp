#include "Mediana.h"
#include <vector>
#include <algorithm>

double count_median(std::vector<int> pazymiai)
{
	double vidurinis;
	double mediana;
	sort(pazymiai.begin(), pazymiai.end());
	vidurinis = size(pazymiai) / 2;
	mediana = size(pazymiai) % 2 == 0 ? (pazymiai[vidurinis - 1] + pazymiai[vidurinis]) / 2.0 : pazymiai[vidurinis];
	return mediana;
}