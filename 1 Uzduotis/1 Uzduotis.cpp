// 1 uduotis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using std::vector;
using std::right;
using std::left;
using std::setw;
using std::setprecision;
using std::cout;
using std::sort;
using std::string;
using std::cin;
using std::endl;


struct studentas {
	string vardas, pavarde;
	float nd[10]{};
	float egzaminas;
	float galutinis_balas;
	double mediana;
};

void pild(studentas& kint);
void printas(studentas &kin);
void spausdinimas(studentas& kin);

int main()
{
	string simbolis;
	studentas studentai[10];
	for (int i = 0; i < 4; i++)
		pild(studentai[i]);
	cout << "Ar norite, kad butu isvestas galutinis studento balas pagal vidurki, ar pagal mediana? Jei pagal vidurki - spauskite V, jei pagal mediana - spauskite M ";
	cin >> simbolis;
	if (simbolis != "V" && simbolis != "v" && simbolis != "M" && simbolis != "m") { cout << "Ivestas blogas simbolis\n"; }
	else if (simbolis == "V" || simbolis == "v")
		void printas(studentas & kin);
	else if (simbolis == "M" || simbolis == "m")
		void spausdinimas(studentas & ki);
	if (simbolis == "M" || simbolis == "m")
	{
		cout << "Vardas" << "\t" << setw(17) << "Pavarde" << "\t" << setw(23) << "Galutinis(Mediana)" << endl;
	}
	else if (simbolis == "V" || simbolis == "v")
	{
		cout << "Vardas" << "\t" << setw(17) << "Pavarde" << "\t" << setw(23) << "Galutinis(Vidurkis)" << endl;
	}
	else if (simbolis != "V" && simbolis != "v" && simbolis != "G" && simbolis != "g")
		exit(1);
	cout << "_____________________________________________________________________________" << endl;
	for (int i = 0; i < 4; i++)
		printas(studentai[i]);
}
void pild(studentas& kint) {
	int n;
	vector <int> nd;
	int vidurinis_skaicius;
	cout << "Iveskite studento varda ir pavarde : "; cin >> kint.vardas >> kint.pavarde;
	cout << "Kiek namu darbu bus? (1-10)"; cin >> n;
	if (n < 1 || n > 10) {
		cout << "Blogas namu darbu skaicius, bandykite dar karta";
		exit(1);
	}
	else
	cout << "Iveskite pazymius:(1-10)" << endl;

	float sum = 0, vid = 0;
	;
	for (int i = 0; i < n; i++) {
		cin >> kint.nd[i];
		if (kint.nd[i] < 1 || kint.nd[i] > 10) {
		cout << "Blogas pazymys, bandykite dar karta";
		exit(1);
	}
		else {
			sum += kint.nd[i];
			nd.push_back(kint.nd[i]);
			sort(nd.begin(), nd.end());
			vidurinis_skaicius = size(nd) / 2;
			kint.mediana = size(nd) % 2 == 0 ? (nd[vidurinis_skaicius - 1] + nd[vidurinis_skaicius]) / 2.0 : nd[vidurinis_skaicius];
		}


	}
	vid = sum / n;
	cout << "Iveskite egzamino pazymi:(1-10)";
	cin >> kint.egzaminas;
	if (kint.egzaminas < 1 || kint.egzaminas > 10) {
		cout << "Blogas egzamino pazymys, bandykite dar karta";
		exit(1);
	}
	else
		kint.galutinis_balas = vid * 0.4 + kint.egzaminas * 0.6;
}
void printas(studentas & kin) {
	cout << setw(17) << left << kin.vardas << " " << setw(17) << left << kin.pavarde << " " << setprecision(3) << setw(3) << left << kin.galutinis_balas << endl;
}
	
void spausdinimas(studentas & kin){
	kin.galutinis_balas = kin.mediana * 0.4 + kin.egzaminas * 0.6;

cout << setw(17) << left << kin.vardas << " " << setw(17) << left << kin.pavarde << " " << setprecision(3) << setw(3) << left << kin.galutinis_balas << endl;
}