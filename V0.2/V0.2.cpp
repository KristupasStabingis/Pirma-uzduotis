// 1 užduotis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>

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
	float nd[20]{};
	float egzaminas;
	float galutinis_balas;
	float vid;
	double mediana;
};

void pild(studentas& kint);
void printas(studentas& kin);
void spausdinimas(studentas& kin);
void nuskaitymas();

int main()
{
	string simbolis;
	studentas studentai[20];
	vector <studentas> st;
	vector <int> nd;
	int nd_paz_sk;
	char temp;
	cout << "Ar norite studentus rasyti pats, ar norite nuskaityti txt faila? Jei norite rasyti pats - spauskite P, jei nuskaityti - spauskite N" << endl;
	cin >> simbolis;
	if (simbolis != "P" && simbolis != "p" && simbolis != "N" && simbolis != "n") {
		cout << "Tokio pasirinkimo nera. Bandykite dar karta" << endl;
		exit(1);
	}
	else if (simbolis == "N" || simbolis == "n") {
	 cout << "Pavarde" << "\t" << setw(10) << "Vardas" << "\t" << setw(10) << "Namu darbu pazymiai" << "\t" << setw(18) << "Egzamino pazymys" << endl;
		cout << "______________________________________________________________________" << endl;
		nuskaitymas();

	}
	else if (simbolis == "P" || simbolis == "p") {


		cout << "Iveskite studentu skaiciu (1-20): ";
		int n;
		cin >> n;
		if (n > 20 || n < 1) {
			cout << "Skaicius negalimas, prasome ivesti skaiciu nuo 1 - 20" << endl;
			exit(1);
		}
		for (int i = 0; i < n; i++) {
			pild(studentai[i]);
		}

		cout << "Ar norite, kad butu isvestas galutinis studento balas pagal vidurki, ar pagal mediana? Jei pagal vidurki - spauskite V, jei pagal mediana - spauskite M ";
		cin >> simbolis;
		if (simbolis != "V" && simbolis != "v" && simbolis != "M" && simbolis != "m") {
			cout << "Ivestas blogas simbolis\n";
			exit(1);
		}
		if (simbolis == "M" || simbolis == "m")

		{
			cout << "Vardas" << "\t" << setw(17) << "Pavarde" << "\t" << setw(23) << "Galutinis(Mediana)" << endl;
			cout << "_____________________________________________________________________________" << endl;
			for (int i = 0; i < n; i++)
				spausdinimas(studentai[i]);
		}
		else if (simbolis == "V" || simbolis == "v")
		{
			cout << "Vardas" << "\t" << setw(17) << "Pavarde" << "\t" << setw(23) << "Galutinis(Vidurkis)" << endl;
			cout << "_____________________________________________________________________________" << endl;
			for (int i = 0; i < n; i++)
				printas(studentai[i]);
		}
		else if (simbolis != "V" && simbolis != "v" && simbolis != "G" && simbolis != "g") {
			exit(1);
		}
	}
}

void pild(studentas& kint) {
	vector <int> nd;
	int vidurinis_skaicius;
	int n; float sum = 0;
	float vid = 0;
	string simbolis;
	float nd_counter = 0;
	srand(time(NULL));

	cout << "Iveskite studento varda ir pavarde : "; cin >> kint.vardas >> kint.pavarde;
	cout << "Ar zinote, kiek namu darbu pazymiu bus? Jei taip, spauskite T, jei ne, spauskite N" << endl;
	cin >> simbolis;
	if (simbolis != "T" && simbolis != "t" && simbolis != "N" && simbolis != "n") {
		cout << "Blogai ivestas simbolis, bandykite dar karta." << endl;
		exit(1);
	}
	else if (simbolis == "T" || simbolis == "t") {
		cout << "Kiek namu darbu bus? (1-20)" << endl;
		cin >> n;
		if (n < 1 || n > 20) {
			cout << "Blogas namu darbu skaicius, bandykite dar karta";
			exit(1);
		}
		else
			cout << "Ar norite pazymius vesti pats, ar norite, kad kompiuteris ivestu uz jus? Pirmuoju atveju spauskite P, antruoju - K" << endl;
		cin >> simbolis;
		if (simbolis != "P" && simbolis != "p" && simbolis != "K" && simbolis != "k") {
			cout << "Ivestas blogas simbolis, bandykite dar karta" << endl;
			exit(1);
		}
		else if (simbolis == "P" || simbolis == "p") {
			cout << "Veskite pazymius" << endl;
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
					cout << "Blogas egzamino pazymys, bandykite dar karta" << endl;
					exit(1);
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
					cout << "Blogas egzamino pazymys, bandykite dar karta" << endl;
					exit(1);
				}
				else {
					cout << "Sugeneruotas jusu egzamino pazymys: " << kint.egzaminas << endl;
				}
			}
		}
	}
		else if (simbolis == "N" || simbolis == "n") {
			cout << "Ar norite pazymius vesti pats, ar norite, kad kompiuteris ivestu uz jus? Pirmuoju atveju spauskite P, antruoju - K."<< endl;
			cout << "Atsiminkite, pasirinkus kompiuterio generavima, kompiuteris jums sugeneruos tik 10 namu darbu pazymiu!!" << endl;
			cin >> simbolis;
			if (simbolis != "P" && simbolis != "p" && simbolis != "K" && simbolis != "k") {
				cout << "Ivestas blogas simbolis, bandykite dar karta" << endl;
				exit(1);
			}	
			else if (simbolis == "P" || simbolis == "p") {
				cout << "Veskite namu darbu pazymius, baigus spauskite -1" << endl;
				while (cin >> n) {
					if (n == -1) { break; }
					else if (n < 1 || n > 10) {
						cout << "Ivestas blogas pazymys, bandykite dar karta" << endl;
						exit(1);
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
						cout << "Blogas egzamino pazymys, bandykite dar karta" << endl;
						exit(1);
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
						cout << "Blogas pazymys, bandykite dar karta";
						exit(1);
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
						cout << "Blogas egzamino pazymys, bandykite dar karta" << endl;
						exit(1);
					}
					else {
						cout << "Sugeneruotas jusu egzamino pazymys: " << kint.egzaminas << endl;
					}
				}
			}


		}
	}
void nuskaitymas() {
	std::ifstream fileRead;
	string eilute;
	fileRead.open("Kursiokai.txt");
	if (fileRead.is_open()) {
		getline(fileRead, eilute);
		while (fileRead.good()){
			getline(fileRead, eilute);
			cout << eilute << "\n";

		}
		
	}
	else {
		cout << "-\n";
	}
}
void printas(studentas& kin) {
	kin.galutinis_balas = kin.vid * 0.4 + kin.egzaminas * 0.6;
	cout << setw(17) << left << kin.vardas << " " << setw(17) << left << kin.pavarde << " " << setprecision(3) << setw(3) << left << kin.galutinis_balas << endl;
}
void spausdinimas(studentas& kin) {
	kin.galutinis_balas = kin.mediana * 0.4 + kin.egzaminas * 0.6;

	cout << setw(17) << left << kin.vardas << " " << setw(17) << left << kin.pavarde << " " << setprecision(3) << setw(3) << left << kin.galutinis_balas << endl;
}
