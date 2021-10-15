#include "pild.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void pild(studentas& kint) {
	std::vector <int> nd;
	int vidurinis_skaicius;
	int n; float sum = 0;
	float vid = 0;
	std::string simbolis;
	float nd_counter = 0;
	srand(time(NULL));
	try{
	cout << "Iveskite studento varda ir pavarde : ";
	cin >> kint.vardas >> kint.pavarde;
	cout << "Ar zinote, kiek namu darbu pazymiu bus? Jei taip, spauskite T, jei ne, spauskite N" << endl;
	cin >> simbolis;
		if (simbolis != "T" && simbolis != "t" && simbolis != "N" && simbolis != "n") {
			throw 0;
		}
		else if (simbolis == "T" || simbolis == "t") {
			cout << "Kiek namu darbu bus? (1-20)" << endl;
			cin >> n;
			if (n < 1 || n > 20) {
				throw(0);
			}
			else
				cout << "Ar norite pazymius vesti pats, ar norite, kad kompiuteris ivestu uz jus? Pirmuoju atveju spauskite P, antruoju - K" << endl;
			cin >> simbolis;
			if (simbolis != "P" && simbolis != "p" && simbolis != "K" && simbolis != "k") {
				throw 0;
			}
			else if (simbolis == "P" || simbolis == "p") {
				cout << "Veskite pazymius" << endl;
				for (int i = 0; i < n; i++) {
					cin >> kint.nd[i];
					if (kint.nd[i] < 1 || kint.nd[i] > 10) {
						throw(0);
					}
					else {
						sum += kint.nd[i];
						nd.push_back(kint.nd[i]);
						sort(nd.begin(), nd.end());
						vidurinis_skaicius = size(nd) / 2;
						kint.mediana = size(nd) % 2 == 0 ? (nd[vidurinis_skaicius - 1] + nd[vidurinis_skaicius]) / 2.0 : nd[vidurinis_skaicius];
					}
				}
				cout << "Jusu ivesti pazymiai didejimo tvarka yra : " << endl;
				int* arr = nd.data(); // Duomenis iš vektoriaus talpina į dinaminį masyvą.
				for (int i = 0; i < nd.size(); i++)
				{
					{cout << arr[i] << "  ";
					}
				}
				cout << endl;
				kint.vid = sum / n;
				cout << "Iveskite egzamino pazymi:(1-10)" << endl;
				cin >> kint.egzaminas;
				for (int i = 0; i < 1; i++) {
					if (kint.egzaminas < 1 || kint.egzaminas > 10) {
						throw(0);
					}
					else {
						cout << "Jusu ivestas egzamino pazymys: " << kint.egzaminas << endl;
					}
				}
			}

			else if (simbolis == "K" || simbolis == "k") {

				for (int i = 0; i < n; i++) {
					kint.nd[i] = (rand() % 10) + 1;
					if (kint.nd[i] < 1 || kint.nd[i] > 10) {
						throw(0);
					}
					else {
						sum += kint.nd[i];
						nd.push_back(kint.nd[i]);
						sort(nd.begin(), nd.end());
						vidurinis_skaicius = size(nd) / 2;
						kint.mediana = size(nd) % 2 == 0 ? (nd[vidurinis_skaicius - 1] + nd[vidurinis_skaicius]) / 2.0 : nd[vidurinis_skaicius];
					}
				}
				cout << "Jusu sugeneruoti pazymiai didejimo tvarka yra : " << endl;
				int* arr = nd.data(); // Duomenis iš vektoriaus talpina į dinaminį masyvą.
				for (int i = 0; i < nd.size(); i++)
				{
					{cout << arr[i] << "  ";
					}
				}
				cout << endl;
				kint.vid = sum / n;
				cout << "Iveskite egzamino pazymi:(1-10)" << endl;
				for (int i = 0; i < 1; i++) {
					kint.egzaminas = (rand() % 10) + 1;
					if (kint.egzaminas < 1 || kint.egzaminas > 10) {
						throw(0);
					}
					else {
						cout << "Sugeneruotas jusu egzamino pazymys: " << kint.egzaminas << endl;
					}
				}
			}
		}
		else if (simbolis == "N" || simbolis == "n") {
			cout << "Ar norite pazymius vesti pats, ar norite, kad kompiuteris ivestu uz jus? Pirmuoju atveju spauskite P, antruoju - K." << endl;
			cout << "Atsiminkite, pasirinkus kompiuterio generavima, kompiuteris jums sugeneruos tik 10 namu darbu pazymiu!!" << endl;
			cin >> simbolis;
			if (simbolis != "P" && simbolis != "p" && simbolis != "K" && simbolis != "k") {
				throw 0;
			}
			else if (simbolis == "P" || simbolis == "p") {
				cout << "Veskite namu darbu pazymius, baigus spauskite -1" << endl;
				while (cin >> n) {
					if (n == -1) { break; }
					else if (n < 1 || n > 10) {
						throw(0);
					}
					else if (n >= 1 || n <= 10) {
						nd_counter += 1;
						sum += n;
						nd.push_back(n);
						sort(nd.begin(), nd.end());
						vidurinis_skaicius = size(nd) / 2;
						kint.mediana = size(nd) % 2 == 0 ? (nd[vidurinis_skaicius - 1] + nd[vidurinis_skaicius]) / 2.0 : nd[vidurinis_skaicius];
					}
				}
				cout << "Jusu ivesti namu darbu pazymiai didejimo tvarka yra : " << endl;
				int* arr = nd.data(); // Duomenis iš vektoriaus talpina į dinaminį masyvą.
				for (int i = 0; i < nd.size(); i++)
				{
					{cout << arr[i] << "  ";
					}
				}
				cout << endl;
				kint.vid = sum / n;
				cout << "Iveskite egzamino pazymi:(1-10)" << endl;
				cin >> kint.egzaminas;
				for (int i = 0; i < 1; i++) {
					if (kint.egzaminas < 1 || kint.egzaminas > 10) {
						throw(0);
					}
					else {
						cout << "Jusu ivestas egzamino pazymys: " << kint.egzaminas << endl;
					}
				}
			}

			else if (simbolis == "K" || simbolis == "k") {

				for (int i = 0; i < 10; i++) {
					kint.nd[i] = (rand() % 10) + 1;
					if (kint.nd[i] < 1 || kint.nd[i] > 10) {
						throw(0);
					}
					else {
						nd_counter += 1;
						sum += kint.nd[i];
						nd.push_back(kint.nd[i]);
						sort(nd.begin(), nd.end());
						vidurinis_skaicius = size(nd) / 2;
						kint.mediana = size(nd) % 2 == 0 ? (nd[vidurinis_skaicius - 1] + nd[vidurinis_skaicius]) / 2.0 : nd[vidurinis_skaicius];
					}
				}
				cout << "Jusu sugeneruoti namu darbu pazymiai didejimo tvarka yra : " << endl;
				int* arr = nd.data(); // Duomenis iš vektoriaus talpina į dinaminį masyvą.
				for (int i = 0; i < nd.size(); i++)
				{
					{cout << arr[i] << "  ";
					}
				}
				cout << endl;
				kint.vid = sum / nd_counter;
				cout << "Iveskite egzamino pazymi:(1-10)" << endl;
				for (int i = 0; i < 1; i++) {
					kint.egzaminas = (rand() % 10) + 1;
					if (kint.egzaminas < 1 || kint.egzaminas > 10) {
						throw(0);
					}
					else {
						cout << "Sugeneruotas jusu egzamino pazymys: " << kint.egzaminas << endl;
					}
				}
			}


		}
	}
	catch (int Mynum) {
		cout << "Negalimas simbolis, bandykite is naujo" << endl;
		exit(1);
	}

}