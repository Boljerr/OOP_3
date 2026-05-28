//ReSharper disable All

#include <cstdlib>
#include <ctime>
#include <limits>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<filesystem>
#include<climits>
#include<chrono>

#include "struktura.h"
#include "Bendra.h"
#include "Tyrimai.h"
#include "VectorFunkcijos.h"
#include "Studentas.h"
#include "Testai.h"

int main()
{
	std::srand(std::time(nullptr));
	int pasirinkimas;
	do {
		std::cout << "\n=============MENIU=============\n";
		std::cout << "1 - Rankinis ivedimas\n";
		std::cout << "2 - Generuoti tik pazymius \n";
		std::cout << "3 - Generuoti studentus ir pazymius\n";
		std::cout << "4 - Nuskaityti is failo\n";
		std::cout << "5 - Generuoti studentu faila\n";
		std::cout << "6 - Atlikti failo kurimo tyrima\n";
		std::cout << "7 - Atlikti v0.4 duomenu apdorojimo tyrima(vector)\n";
		std::cout << "8 - Atlikti v1.1 konteineriu tyrima\n";
		std::cout << "9 - Atlikti v1.1 skirstymo strategiju tyrima\n";
		std::cout << "10 - Testuoti Studentas klase\n";
		std::cout << "11 - Atlikti V3.0 duomenu  apdorojimo tyrima (mano Vector)\n";
		std::cout << "12 - Baigti\n";
		std::cin >> pasirinkimas;
		if (std::cin.fail())
		{
			std::cout << "Ivestis turi buti skaicius.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (pasirinkimas)
		{
		case 1:
		{
			std::vector<Studentas> studentai;
			char testi;

			do {
				Studentas studentas;
				studentas.setVardas(ivestiVardaArPavarde("Iveskite varda: "));
				studentas.setPavarde( ivestiVardaArPavarde("Iveskite pavarde: "));

				std::cout << "Iveskite pazymi (0 - 10). Baigti -1\n";

				while (true)
				{
					int temp = ivestiIntSuValidacija("Pazymys: ", -1, 10);

					if (temp == -1)
					{
						break;
					}

					studentas.pridetiPazymi(temp);
				}
				if (studentas.getPazymiai().empty())
				{
					std::cout << "Nerasta pazymiu, galutinis bus skaiciuojamas tik is egzamino\n";
				}

				studentas.setEgzaminas(ivestiIntSuValidacija("Iveskite egzamino rezultata (0-10): ", 0, 10));

				studentai.push_back(studentas);

				std::cout << "Ar norite ivesti kito studento duomenis? (t/n) ";
				std::cin >> testi;

			} while (testi == 't' || testi == 'T');

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();

			skaiciuotiRezultatusVector(studentai, skaiciavimoTipas);
			isvestiRezultatusVector(studentai, skaiciavimoTipas);

			break;
		}
		case 2:
		{
			std::vector<Studentas> studentai;
			char testi;

			do
			{
				Studentas studentas;
				studentas.setVardas(ivestiVardaArPavarde("Iveskite varda: "));
				studentas.setPavarde(ivestiVardaArPavarde("Iveskite pavarde: "));

				int kiekis = ivestiIntSuValidacija("Kiek generuoti namu darbu pazymiu? ", 1, INT_MAX - 1);


				for (int i = 0; i < kiekis; ++i)
				{
					int paz = std::rand() % 10 + 1;
					studentas.pridetiPazymi(paz);
				}

				studentas.setEgzaminas(std::rand() % 10 + 1);

				studentai.push_back(studentas);

				std::cout << "Ar generuoti dar viena studenta? (t/n): ";
				std::cin >> testi;

			} while (testi == 't' || testi == 'T');

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();
			skaiciuotiRezultatusVector(studentai, skaiciavimoTipas);
			isvestiRezultatusVector(studentai, skaiciavimoTipas);

			break;
		}
		case 3:
		{
			std::vector<Studentas> studentai;

			int studentuKiekis = ivestiIntSuValidacija("Kiek generuoti studentu? ", 1, INT_MAX - 1);
			int ndKiekis = ivestiIntSuValidacija("Kiek generuoti namu darbu pazymiu kiekvienam? ", 1, INT_MAX - 1);

			for (int i = 0; i < studentuKiekis; i++)
			{
				zmogus z = gen();

				Studentas studentas;
				studentas.setVardas(z.vardas);
				studentas.setPavarde(z.pavarde);

				for (int j = 0; j < ndKiekis; ++j)
				{
					studentas.pridetiPazymi(gen().paz);
				}

				studentas.setEgzaminas(std::rand() % 10 + 1);
				studentai.push_back(studentas);
			}
			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();

			skaiciuotiRezultatusVector(studentai, skaiciavimoTipas);
			isvestiRezultatusVector(studentai, skaiciavimoTipas);
			break;
		}
		case 4:
		{
			std::cout << "Working directory: "
				<< std::filesystem::current_path()
				<< std::endl;
			std::vector<Studentas> studentai;

			std::string failas;
			std::cout << "Iveskite failo pavadinima: ";
			system("dir *.txt");
			std::cin >> failas;

			studentai.clear();

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();
			int rusiavimoTipas = pasirinktiRusiavimoTipa();

			try
			{
				auto start = std::chrono::high_resolution_clock::now();
				skaitytiIsFailoVector(failas, studentai);

				if (studentai.empty())
				{
					std::cout << "Nerasta studentu duomenu faile arba failas tuscias.\n";
					break;
				}


				skaiciuotiRezultatusVector(studentai, skaiciavimoTipas);
				rusiuotiStudentusVector(studentai, rusiavimoTipas);
				auto end = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> diff = end - start;


				std::cout << "Kur norite isvesti rezultatus?\n";
				std::cout << "1 - i ekrana\n";
				std::cout << "2 - i faila\n";

				int isvestiesTipas = ivestiIntSuValidacija("Pasirinkite: ", 1, 2);
				if (isvestiesTipas == 1)
				{
					if (studentai.size() <= 10000)
					{
						isvestiRezultatusVector(studentai, skaiciavimoTipas);
					}
					else
					{
						std::cout << "Per didelis duomenu kiekis isvedimui i konsole. \n";
					}
				}
				else
				{
					isvestiRezultatusIFailaVector(studentai, skaiciavimoTipas, "rezultatai.txt");
				}

				std::cout << "Laikas: " << diff.count() << "sekundes\n";
			}
			catch (const std::exception& ex)
			{
				std::cout << "Klaida: " << ex.what() << "\n";
			}
			break;
		}
		case 5:
		{
			std::string failas;
			int studentuKiekis;
			int ndKiekis;

			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> failas;

			studentuKiekis = ivestiIntSuValidacija("Kiek studentu generuoti? ", 1, INT_MAX - 1);
			ndKiekis = ivestiIntSuValidacija("Kiek namu darbu pazymiu generuoti? ", 1, 20);

			try
			{
				generuotiStudentuFailaVector(failas, studentuKiekis, ndKiekis);
				std::cout << "Failas sugeneruotas sekmingai.\n";
			}
			catch (const std::exception& ex)
			{
				std::cout << "Klaida: " << ex.what() << "\n";
			}
			break;
		}
		case 6:
		{
			std::string failas;
			int studentuKiekis;
			int ndKiekis;

			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> failas;

			studentuKiekis = ivestiIntSuValidacija("Kiek studentu generuoti? ", 1, INT_MAX - 1);
			ndKiekis = ivestiIntSuValidacija("Kiek namu darbu pazymiu generuoti? ", 1, 20);
			try
			{
				atliktiFailoKurimoTyrimaVector(failas, studentuKiekis, ndKiekis);
			}
			catch (const std::exception& ex)
			{
				std::cout << "Klaida: " << ex.what() << "\n";
			}
			break;
		}
		case 7:
		{
			std::string failas;
			system("dir *.txt");
			std::cout << "Iveskite jau sugeneruoto failo pavadinima: ";
			std::cin >> failas;

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();
			int rusiavimoTipas = pasirinktiRusiavimoTipa();
			int kartu = ivestiIntSuValidacija("Kiek kartu kartoti testa? ", 1, 10);

			try
			{
				atliktiDuomenuApdorojimoTyrimoVidurkiVector(failas, skaiciavimoTipas, rusiavimoTipas, kartu);
			}
			catch (const std::exception& ex)
			{
				std::cout << "Klaida: " << ex.what() << "\n";
			}
			break;
		}
		case 8:
		{
			std::string failas;
			system("dir *.txt");
			std::cout << "Iveskite jau sugeneruoto failo pavadinima: ";
			std::cin >> failas;

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();
			int rusiavimoTipas = pasirinktiRusiavimoTipa();
			int kartu = ivestiIntSuValidacija("Kiek kartu kartoti testa? ", 1, 50);

			try
			{
				atliktiKonteineriuTyrimaSuVidurkiu(failas, skaiciavimoTipas, rusiavimoTipas, kartu);
			}
			catch (const std::exception& ex)
			{
				std::cout << "Klaida: " << ex.what() << "\n";
			}
			break;
		}
		case 9:
		{
			std::string failas;
			system("dir *.txt");
			std::cout << "Iveskite jau sugeneruoto failo pavadinima: ";
			std::cin >> failas;

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();
			int rusiavimoTipas = pasirinktiRusiavimoTipa();
			int kartu = ivestiIntSuValidacija("Kiek kartu kartoti testa? ", 1, 50);

			try
			{
				atliktiStrategijuTyrimaSuVidurkiu(failas, skaiciavimoTipas, rusiavimoTipas, kartu);
			}
			catch (const std::exception& ex)
			{
				std::cout << "Klaida: " << ex.what() << "\n";
			}
			break;
		}

		case 10:
			{
			testuotiStudentoKlase();
			break;
			}
		case 11:
		{
			std::string failas;
			system("dir *.txt");
			std::cout << "Iveskite jau sugeneruoto failo pavadinima: ";
			std::cin >> failas;

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();
			int rusiavimoTipas = pasirinktiRusiavimoTipa();
			int kartu = ivestiIntSuValidacija("Kiek kartu kartoti testa? ", 1, 10);

			try
			{
				atliktiDuomenuApdorojimoTyrimoVidurkiManoVector(failas, skaiciavimoTipas, rusiavimoTipas, kartu);
			}
			catch (const std::exception& ex)
			{
				std::cout << "Klaida: " << ex.what() << "\n";
			}

			break;
		}
		case 12:
			{
			std::cout << "Programa baige darba.\n";
			break;
			}
		default:
		{
			std::cout << "Neteisingas pasirinkimas";
			break;
		}
		}

	} while (pasirinkimas != 12);
	
	return 0;
}






