#include "Bendra.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <cctype>


double calculateAverage(const std::vector<int>& grade)
{
	if (grade.empty()) return 0.0;
	int suma = 0;
	for (int i = 0; i < grade.size(); i++)
	{
		suma += grade[i];
	}
	return (double)suma / grade.size();
}

double calculateAverage(const Vector<int>& grade)
{
	if (grade.empty()) return 0.0;

	double suma = 0.0;

	for (std::size_t i = 0; i < grade.size(); i++)
	{
		suma += grade[i];
	}
	return suma / grade.size();
}

double calculateMedian(std::vector<int> grade) // cia kopija nes tipo sortini
{
	if (grade.empty()) return 0.0;

	std::sort(grade.begin(), grade.end());

	int n = grade.size();

	if (n % 2 == 1)
	{
		return grade[n / 2];
	}
	else
	{
		return (grade[n / 2 - 1] + grade[n / 2]) / 2.0;
	}
}

double calculateMedian(Vector<int> grade)
{
	if (grade.empty()) return 0.0;
	
	std::sort(grade.begin(), grade.end());

	std::size_t dydis = grade.size();

	if (dydis % 2 == 0)
	{
		return grade[dydis / 2 - 1] + grade[dydis / 2] / 2.0;
	}
	return grade[dydis / 2];

}

double calculateFinal(double ndReiksme, int egzaminas)
{
	return 0.4 * ndReiksme + 0.6 * egzaminas;
}

int ivestiIntSuValidacija(const std::string& zinute, int min, int max)
{
	int value;
	while (true)
	{
		std::cout << zinute;
		std::cin >> value;
		if (std::cin.fail())
		{
			std::cout << "Ivestis turi buti skaicius, bandykite dar karta\n";
			std::cin.clear(); // isvalo klaidos busena
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoruoja netinkama ivesti iki naujos eilutes
			continue;
		}
		else if (value < min || value > max)
		{
			std::cout << "Ivestis turi buti tarp " << min << " ir " << max << ", bandykite dar karta\n";
			continue;
		}
		else
		{
			return value;
		}
	}
}

std::string ivestiVardaArPavarde(const std::string& zinute)
{
	std::string tekstas;
	while (true)
	{
		std::cout << zinute;
		std::cin >> tekstas;
		if (tekstas.empty())
		{
			std::cout << "Ivestis negali buti tuscia, bandykite dar karta\n";
			continue;
		}
		bool teisingas = true;

		for (char c : tekstas)
		{
			if (!std::isalpha(static_cast<unsigned char>(c)))
			{
				teisingas = false;
				break;
			}
		}
		if (!teisingas)
		{
			std::cout << "Ivestis turi buti sudaryta tik is raidziu, bandykite dar karta\n";
			continue;
		}
		return tekstas;

	}
}

int pasirinktiSkaiciavimoTipa()
{
	std::cout << "Ar rezultata skaiciuojama su mediana ar su vidurkiu\n";
	std::cout << "1 - vidurkis\n";
	std::cout << "2 - mediana\n";
	return ivestiIntSuValidacija("Pasirinkite: ", 1, 2);
}
int pasirinktiRusiavimoTipa()
{
	std::cout << "Pasirinkite rusiavimo tipa:\n";
	std::cout << "1 - pagal varda\n";
	std::cout << "2 - pagal pavarde\n";
	std::cout << "3 - pagal rezultata\n";
	return ivestiIntSuValidacija("Pasirinkite: ", 1, 3);
}

std::string gautiFailoVardaBePletinio(const std::string& failoPavadinimas)
{
	size_t lastDot = failoPavadinimas.find_last_of('.');
	if (lastDot == std::string::npos)
	{
		return failoPavadinimas; // Nera pletinio
	}
	return failoPavadinimas.substr(0, lastDot);
}

bool compareByVardas(const Studentas& a, const Studentas& b)
{
	return a.getVardas() < b.getVardas();
}
bool compareByPavarde(const Studentas& a, const Studentas& b)
{
	return a.getPavarde() < b.getPavarde();
}
bool compareByRezultatas(const Studentas& a, const Studentas& b)
{
	return a.getRezultatas() < b.getRezultatas();
}

bool arKietiakas(const Studentas& studentas)
{
	return studentas.getRezultatas() >= 5.0;
}