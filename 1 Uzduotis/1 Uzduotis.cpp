// 1 uduotis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <iomanip>
using std::right;
using std::left;
using std::setw;
using std::setprecision;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::string;


struct studentas {
	string vardas, pavarde;
	float nd[10]{};
	float egzaminas;
	float galutinis_balas;
};
void pild(studentas& kint);
void printas(studentas &kin);

int main()
{
	studentas studentai[10];
	for (int i = 0; i < 4; i++)
		pild(studentai[i]);
	cout << "Vardas" <<  "\t" << setw(17) << "Pavarde" << "\t" << setw(23) << "Galutinis(Vidurkis)" << endl;
	cout << "_________________________________________________________" << endl;
	for (int i = 0; i < 4; i++)
		printas(studentai[i]);
}
void pild(studentas& kint) {
	int n;
	cout << "Iveskite studento varda ir pavarde : "; cin >> kint.vardas >> kint.pavarde;
	cout << "Kiek namu darbu bus? (1-10)"; cin >> n;
	if (n < 1 || n > 10) {
		cout << "Blogas namu darbu skaicius, bandykite dar karta";
		exit(1);
	}
	else
	cout << "Iveskite pazymius:(1-10)" << endl;

	float sum = 0, vid = 0;
	for (int i = 0; i < n; i++) {
		cin >> kint.nd[i];
		if (kint.nd[i] < 1 || kint.nd[i] > 10) {
		cout << "Blogas pazymys, bandykite dar karta";
		exit(1);
	}
		else
		sum += kint.nd[i];
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

		void printas(studentas &kin) {
			cout << setw(17) << left << kin.vardas << " " << setw(17) << left << kin.pavarde << " " << setprecision(3) << setw(3) << left << kin.galutinis_balas << endl;}
