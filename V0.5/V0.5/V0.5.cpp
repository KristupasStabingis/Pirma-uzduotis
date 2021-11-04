#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <fstream>
#include <random>
#include <list>



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
using std::to_string;
using std::chrono::high_resolution_clock;
using std::ofstream;
using std::accumulate;
using std::ifstream;
using std::ws;
using std::list;	


struct studentas {
	string vardas, pavarde;
	float nd[20]{};
	float egzaminas;
	float galutinis_balas;
	float galutinis_balas_mediana;
	float vid;
	double mediana;
};

void pild(studentas& kint);
void printas(studentas& kin);
void spausdinimas(studentas& kin);
void nuskaitymas(vector<studentas>& st, int kiekis);
void nuskaitymasLIST(list<studentas>& student, int kiekis);
studentas get(list<studentas> student, int kiekis);


int random_skaicius()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10); 
	return dist10(rng);
}

vector<int> aut_pazymiai(int pazymiu_sk)
{
	vector<int> paz;
	for (int i = 0; i < pazymiu_sk; i++)
	{
		paz.push_back(random_skaicius());
	}
	return paz;
}	

float count_galutinis_balas_vidurkis(vector<int> paz) {
	studentas st;
	st.egzaminas = random_skaicius();
	st.galutinis_balas = 0.4 * accumulate(paz.begin(), paz.end(), 0) / paz.size() + 0.6 * st.egzaminas;
	return st.galutinis_balas;
}

float count_galutinis_balas_mediana(vector<int> paz) {
	studentas st;
	int vidurinis_skaicius;
	sort(paz.begin(), paz.end());
	vidurinis_skaicius = size(paz) / 2;
	st.egzaminas = random_skaicius();
	st.mediana = size(paz) % 2 == 0 ? (paz[vidurinis_skaicius - 1] + paz[vidurinis_skaicius]) / 2.0 : paz[vidurinis_skaicius];
	st.galutinis_balas_mediana = st.mediana * 0.4 + st.egzaminas * 0.6;

	return st.galutinis_balas_mediana;
}

float count_galutinis_balas_vidurkisLIST(vector<int> paz) {
	studentas student;
	student.egzaminas = random_skaicius();
	student.galutinis_balas = 0.4 * accumulate(paz.begin(), paz.end(), 0) / paz.size() + 0.6 * student.egzaminas;
	return student.galutinis_balas;
}

float count_galutinis_balas_medianaLIST(vector<int> paz) {
	studentas student;
	int vidurinis_skaicius;
	sort(paz.begin(), paz.end());
	vidurinis_skaicius = size(paz) / 2;
	student.egzaminas = random_skaicius();
	student.mediana = size(paz) % 2 == 0 ? (paz[vidurinis_skaicius - 1] + paz[vidurinis_skaicius]) / 2.0 : paz[vidurinis_skaicius];
	student.galutinis_balas_mediana = student.mediana * 0.4 + student.egzaminas * 0.6;

	return student.galutinis_balas_mediana;
}

studentas get(list<studentas> _list, int _i) {
	list<studentas>::iterator it = _list.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}


int main()
{
	list <studentas> student;
	string simbolis;
	string pav;
	studentas studentai[20];
	vector <studentas> st;
	int nd_paz_sk;
	int n;
	vector<int> paz;
	int kiekis;
	vector<studentas> kietiakai;
	vector <studentas> vargsiukai;
	int vargs = 0;
	int kiet = 0;
	list<studentas> kieti;
	list<studentas> vargsai;

	cout << "Ar norite studentus nuskaityti is listo, ar vektoriaus? Jei listo - spauskite L, jei vektoriaus - spauskite V" << endl;
	cin >> simbolis;
	if (simbolis != "L" && simbolis != "l" && simbolis != "V" && simbolis != "v") {
		cout << "Pasirinkimas negalimas, bandykite dar karta" << endl;
	}
	else if (simbolis == "L" || simbolis == "l") {
		cout << "Iveskite studentu skaiciu(1 000, 10 000, 100 000, 1 000 000 arba 10 000 000)" << endl;
		cin >> kiekis;
		if (kiekis != 1000 && kiekis != 10000 && kiekis != 100000 && kiekis != 1000000 && kiekis != 10000000) {
			cout << "Nera tokio pasirinkimo, bandykite dar karta." << endl;
		}
		pav = "Studentai_" + to_string(kiekis) + ".txt";
		auto start = high_resolution_clock::now();
		auto star = start;
		ofstream isvedimas(pav);
		isvedimas << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis_balas" << endl;

		cout << "Ar norite studentu galutini bala gauti suskaiciuota pagal vidurki, ar pagal mediana? Pagal mediana - spauskite M, pagal vidurki - spauskite V" << endl;
		cin >> simbolis;

		if (simbolis != "M" && simbolis != "m" && simbolis != "V" && simbolis != "v") {
			cout << "Simbolis negalimas!!" << endl;
		}
		else if (simbolis == "M" || simbolis == "m") {
			cout << "Kiek namu darbu pazymiu generuojame (Vienas egzamino pazymys bus sugeneruotas atskirai automatiskai) ?" << endl;
			cin >> n;
			if (n < 1) {
				cout << "Skaicius negalimas!!" << endl;
				exit(1);
			}
			else if (n > 0) {
				for (int d = 1; d <= kiekis; d++)
				{
					paz = aut_pazymiai(n);
					isvedimas << setw(20) << "Vardas" + to_string(d) <<
						setw(20) << "Pavarde" + to_string(d) <<
						setw(18) << count_galutinis_balas_medianaLIST(paz) << endl;
					paz.clear();

				}
				auto end = high_resolution_clock::now();
				std::chrono::duration<double> diff = end - start;
				cout << "Failo su " + to_string(kiekis) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n" << endl;
			}
		}
		else if (simbolis == "V" || simbolis == "v") {
			cout << "Kiek namu darbu pazymiu generuojame (vienas egzamino pazymys bus sugeneruotas atskirai automatiskai)?" << endl;
			cin >> n;
			if (n < 1) {
				cout << "Skaicius negalimas!!" << endl;
			}
			else if (n > 0) {
				for (int s = 1; s <= kiekis; s = s + 1)
				{
					paz = aut_pazymiai(n);
					isvedimas << setw(20) << "Vardas" + to_string(s) << setw(20) << "Pavarde" + to_string(s) << setw(18) << count_galutinis_balas_vidurkisLIST(paz) << endl;;
					paz.clear();

				}
				auto end = high_resolution_clock::now();
				std::chrono::duration<double> diff = end - start;
				cout << "Failo su " + to_string(kiekis) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n" << endl;
			}
		}
		cout << "Ar norite sukurti txt faila su pasirinktu kiekiu studentu ir suskirstymu i dvi kategorijas - vargsiukus ir kietiakus? Jei taip - spauskite T, jei ne - spauskite N" << endl;
		cin >> simbolis;

		if (simbolis != "T" && simbolis != "t" && simbolis != "N" && simbolis != "n") {
			cout << "Toks simbolis nera galimas, bandykite is naujo" << endl;
			exit(1);
		}
		else if (simbolis == "T" || simbolis == "t") {
			nuskaitymasLIST(student, kiekis);
			auto start = high_resolution_clock::now();
			auto star = start;
			for (int i = 0; i < kiekis; i++) {
				float paz = 5.00;
				if (get(student, i).galutinis_balas < paz) {
					vargsai.push_back(get(student, i));
					vargs++;
				}
			}
			for (int k = 0; k < kiekis; k++) {
				float paz = 5.00;	
				if (get(student, k).galutinis_balas >= paz) {
					kieti.push_back(get(student, k));
					kiet++;
				}
			}
			auto end = high_resolution_clock::now();
			std::chrono::duration<double> diff = end - start;
			std::cout << "Failo rusiavimas su " + to_string(kiekis) + " studentais i dvi grupes uztruko : " << diff.count() << " s\n";



			string pav;
			pav = "vargsai_" + to_string(kiekis) + ".txt";
			ofstream vargsai_failas(pav);
			auto start1 = high_resolution_clock::now();
			auto st1 = start1;
			for (int i = 0; i < vargs; i++) {
				float paz = 5.00;
				if (get(vargsai, i).galutinis_balas < paz) {
					vargsai_failas << get(vargsai, i).vardas << setw(20) << get(vargsai, i).pavarde << setw(18) << get(vargsai, i).galutinis_balas << endl;
				}

			}
			auto end1 = high_resolution_clock::now();
			std::chrono::duration<double> diff1 = end1 - start1;
			cout << "Failo isvedimas su " + to_string(kiekis) + " studentais  i vargsiukus uztruko : " << diff1.count() << " s\n";

			pav = "kieti_" + to_string(kiekis) + ".txt";
			ofstream kieti_failas(pav);
			auto start2 = high_resolution_clock::now();
			auto st2 = start2;
			for (int k = 0; k < kiet; k++) {
				float paz = 5.00;
				if (get(kieti, k).galutinis_balas >= paz) {
					kieti_failas << get(kieti, k).vardas << setw(20) << get(kieti, k).pavarde << setw(20) << get(kieti, k).galutinis_balas << endl;
				}
			}
			auto end2 = high_resolution_clock::now();
			std::chrono::duration<double> diff2 = end2 - start2;
			cout << "Failo isvedimas su " + to_string(kiekis) + " studentais  i kietiakus uztruko : " << diff2.count() << " s\n";


		}
		else if (simbolis == "n" || simbolis == "N") {
			cout << "Failas nebuvo sukurtas" << endl;
			exit(1);
		}
	}


	else if (simbolis == "V" || simbolis == "v") {
	cout << "Ar norite dirbti su txt kurimu ir nuskaitymu, ar rasyti pazymius ir gauti rezultatus ranka? Jei kurti ir nuskaityti - K, jei gauti ranka - R" << endl;
		cin >> simbolis;
		if (simbolis != "K" && simbolis != "k" && simbolis != "R" && simbolis != "r") {
			cout << "Pasirinkimas negalimas" << endl;
		}
		else if (simbolis == "K" || simbolis == "k") {
			cout << "Iveskite studentu skaiciu(1 000, 10 000, 100 000, 1 000 000 arba 10 000 000)" << endl;
			cin >> kiekis;
			if (kiekis != 1000 && kiekis != 10000 && kiekis != 100000 && kiekis != 1000000 && kiekis != 10000000) {
				cout << "Nera tokio pasirinkimo, bandykite dar karta." << endl;
			}
			pav = "Studentai_" + to_string(kiekis) + ".txt";
			auto start = high_resolution_clock::now();
			auto star = start;
			ofstream isvedimas(pav);
			isvedimas << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis_balas" << endl;

			cout << "Ar norite studentu galutini bala gauti suskaiciuota pagal vidurki, ar pagal mediana? Pagal mediana - spauskite M, pagal vidurki - spauskite V" << endl;
			cin >> simbolis;

			if (simbolis != "M" && simbolis != "m" && simbolis != "V" && simbolis != "v") {
				cout << "Simbolis negalimas!!" << endl;
			}
			else if (simbolis == "M" || simbolis == "m") {
				cout << "Kiek namu darbu pazymiu generuojame (vienas egzamino pazymys bus sugeneruotas atskirai automatiskai) ?" << endl;
				cin >> n;
				if (n < 1) {
					cout << "Skaicius negalimas!!" << endl;
					exit(1);
				}
				else if (n > 0) {
					for (int d = 0; d <= kiekis; d++)
					{
						paz = aut_pazymiai(n);
						isvedimas << setw(20) << "Vardas" + to_string(d) <<
							setw(20) << "Pavarde" + to_string(d) <<
							setw(18) << count_galutinis_balas_mediana(paz) << endl;
						paz.clear();

					}
					auto end = high_resolution_clock::now();
					std::chrono::duration<double> diff = end - start;
					cout << "Failo su " + to_string(kiekis) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n" << endl;
				}
			}
			else if (simbolis == "V" || simbolis == "v") {
				cout << "Kiek namu darbu pazymiu generuojame (vienas egzamino pazymys bus sugeneruotas atskirai automatiskai) ?" << endl;
				cin >> n;
				if (n < 1) {
					cout << "Skaicius negalimas!!" << endl;
				}
				else if (n > 0) {
					for (int s = 1; s <= kiekis; s = s + 1)
					{
						paz = aut_pazymiai(n);
						isvedimas << setw(20) << "Vardas" + to_string(s) << setw(20) << "Pavarde" + to_string(s) << setw(18) << count_galutinis_balas_vidurkis(paz) << endl;;
						paz.clear();

					}
					auto end = high_resolution_clock::now();
					std::chrono::duration<double> diff = end - start;
					cout << "Failo su " + to_string(kiekis) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n" << endl;
				}
			}
			cout << "Ar norite sukurti txt faila su pasirinktu kiekiu studentu ir suskirstymu i dvi kategorijas - vargsiukus ir kietiakus? Jei taip - spauskite T, jei ne - spauskite N" << endl;
			cin >> simbolis;
			if (simbolis != "T" && simbolis != "t" && simbolis != "N" && simbolis != "n") {
				cout << "Toks simbolis nera galimas, bandykite is naujo" << endl;
				exit(1);
			}
			else if (simbolis == "T" || simbolis == "t") {
				nuskaitymas(st, kiekis);
				auto start = high_resolution_clock::now();
				auto star = start;
				for (int i = 0; i < kiekis; i++) {
					float paz = 5.00;
					if (st.at(i).galutinis_balas < paz) {
						vargsiukai.push_back(st.at(i));
						vargs++;
					}
				}
				for (int j = 0; j < kiekis; j++) {
					float paz = 5.00;
					if (st.at(j).galutinis_balas >= paz) {
						kietiakai.push_back(st.at(j));
						kiet++;
					}
				}
				auto end = high_resolution_clock::now();
				std::chrono::duration<double> diff = end - start;
				std::cout << "Failo rusiavimas su " + to_string(kiekis) + " studentais i dvi grupes uztruko : " << diff.count() << " s\n";


				string pav;
				pav = "vargsiukai_" + to_string(kiekis) + ".txt";
				ofstream vargs_failas(pav);
				auto start1 = high_resolution_clock::now();
				auto st1 = start1;
				for (int i = 0; i < kiekis; i++) {

					float paz = 5.00;
					if (st.at(i).galutinis_balas < paz) {
						vargs_failas << st.at(i).vardas << setw(20) << st.at(i).pavarde << setw(18) << st.at(i).galutinis_balas << endl;
					}

				}
				auto end1 = high_resolution_clock::now();
				std::chrono::duration<double> diff1 = end1 - start1;
				cout << "Failo isvedimas su " + to_string(kiekis) + " studentais  i vargsiukus uztruko : " << diff1.count() << " s\n";

				pav = "kietiakai_" + to_string(kiekis) + ".txt";
				ofstream kiet_failas(pav);
				auto start2 = high_resolution_clock::now();
				auto st2 = start2;
				for (int j = 0; j < kiekis; j++) {
					float paz = 5.00;
					if (st.at(j).galutinis_balas >= paz) {
						kiet_failas << st.at(j).vardas << setw(20) << st.at(j).pavarde << setw(18) << st.at(j).galutinis_balas << endl;
					}
				}
				auto end2 = high_resolution_clock::now();
				std::chrono::duration<double> diff2 = end2 - start2;
				cout << "Failo isvedimas su " + to_string(kiekis) + " studentais  i kietiakus uztruko : " << diff2.count() << " s\n";


			}
			else if (simbolis == "n" || simbolis == "N") {
				cout << "Failas nebuvo sukurtas" << endl;
				exit(1);
			}
		}
		else if (simbolis == "R" || simbolis == "r") {
			cout << "Iveskite studentu skaiciu (1-20): ";
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
		cout << "Ar norite pazymius vesti pats, ar norite, kad kompiuteris ivestu uz jus? Pirmuoju atveju spauskite P, antruoju - K." << endl;
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

void nuskaitymas(vector<studentas>& st, int kiekis)
{
	int studentu_skaicius = 0;
	ifstream fileRead;
	string pavadinimas = "Studentai_" + to_string(kiekis) + ".txt";
	string buff;
	fileRead.open(pavadinimas);
	if (fileRead.is_open()) {

		auto start = high_resolution_clock::now();
		auto star = start;
		getline(fileRead >> ws, buff);
		while (studentu_skaicius < kiekis)
		{
			st.resize(st.size() + 1);
			fileRead >> st.at(studentu_skaicius).vardas;
			fileRead >> st.at(studentu_skaicius).pavarde;
			fileRead >> st.at(studentu_skaicius).galutinis_balas;
			studentu_skaicius++;
		}
			auto end = high_resolution_clock::now();
			std::chrono::duration<double> diff = end - start;
			cout << "Failo su " + to_string(kiekis) + " studentais nuskaitymas uztruko: " << diff.count() << " s\n";

		}
	}

void nuskaitymasLIST(list<studentas>& student, int kiekis) {
	int studentu_skaicius = 0;
	ifstream fileRead;
	string pavadinimas = "Studentai_" + to_string(kiekis) + ".txt";
	string buff;
	fileRead.open(pavadinimas);
	if (fileRead.is_open()) {

		auto start = high_resolution_clock::now();
		auto star = start;
		getline(fileRead >> ws, buff);
		while (studentu_skaicius < kiekis){

			studentas stude;
			fileRead >> stude.vardas >> stude.pavarde >> stude.galutinis_balas;
			student.push_back(stude);
			studentu_skaicius++;
		}

		auto end = high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		cout << "Failo su " + to_string(kiekis) + " studentais nuskaitymas uztruko: " << diff.count() << " s\n";

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
