#include "Vidurkis.h"

double average(std::vector<int>& pazymiai)
{
	double return_value = 0.0;
	int n = pazymiai.size();

	for (int i = 0; i < n; i++)
	{
		return_value += pazymiai[i];
	}

	return (return_value / (pazymiai.size() - 1));
}