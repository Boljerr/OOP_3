#include "ListFunkcijos.h"

#include <algorithm>

#include "Bendra.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void skaitytiIsFailoList(const std::string& failoPavadinimas, std::list<Studentas>& studentai)
{
	studentai.clear();
	std::ifstream in(failoPavadinimas);


	if (!in.is_open())
	{
		throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
	}

	std::string eilute;
	std::getline(in, eilute); // praleidzia pirma eilute su antraste

	while (std::getline(in, eilute))
	{
		std::stringstream ss(eilute);
		Studentas studentas;

		std::string vardas;
		std::string pavarde;

		if (!(ss >> vardas >> pavarde))
		{
			throw std::runtime_error("Netinkamas duomenu formatas");
		}
		studentas.setVardas(vardas);
		studentas.setPavarde(pavarde);

		int paz;
		std::vector<int> visiPaz;

		while (ss >> paz)
		{
			if (paz < 0 || paz > 10)
			{
				throw std::runtime_error("Faile rastas netinkamas pazymys");
			}
			visiPaz.push_back(paz);
		}
		if (visiPaz.empty())
		{
			throw std::runtime_error("Studentui nerastas nei vienas pazymys ar egzamino rezultatas");
		}
		studentas.setEgzaminas(visiPaz.back());
		visiPaz.pop_back();
		studentas.setPazymiai(visiPaz);

		studentai.push_back(studentas);
	}
	in.close();
}

void skaiciuotiRezultatusList(std::list<Studentas>& studentai, int skaiciavimoTipas)
{
	for (auto& studentas : studentai)
	{
		double nd;
		if (skaiciavimoTipas == 1)
		{
			nd = calculateAverage(studentas.getPazymiai());
		}
		else
		{
			nd = calculateMedian(studentas.getPazymiai());
		}
		double galutinis =calculateFinal(nd, studentas.getEgzaminas());
		studentas.setRezultatas(galutinis);
	}
}

void rusiuotiStudentusList(std::list<Studentas>& studentai, int pasirinkimas)
{
	switch (pasirinkimas)
	{
	case 1:
		studentai.sort(compareByVardas);
		break;
	case 2:
		studentai.sort(compareByPavarde);
		break;
	case 3:
		studentai.sort(compareByRezultatas);
		break;
	default:
		break;
	}
}

void padalintiStudentus1List(const std::list<Studentas>& studentai, std::list<Studentas>& nuskriaustieji, std::list<Studentas>& kietiakiai)
{
	nuskriaustieji.clear();
	kietiakiai.clear();

	for (const auto& studentas : studentai)
	{
		if (studentas.getRezultatas() < 5)
		{
			nuskriaustieji.push_back(studentas);
		}
		else
		{
			kietiakiai.push_back(studentas);
		}
	}
}
void padalintiStudentus2List(std::list<Studentas>& studentai, std::list<Studentas>& nuskriaustieji)
{
	nuskriaustieji.clear();
	for (auto it = studentai.begin(); it != studentai.end();)
	{
		if (it->getRezultatas() < 5)
		{
			nuskriaustieji.push_back(*it);
			it = studentai.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void padalintiStudentus3List(std::list<Studentas>& studentai, std::list<Studentas>& nuskriaustieji)
{
	nuskriaustieji.clear();

	for (auto it = studentai.begin(); it != studentai.end();)
	{
		if (it->getRezultatas() < 5)
		{
			auto dabartinis = it;
			++it;
			nuskriaustieji.splice(nuskriaustieji.end(), studentai, dabartinis);
		}
		else
		{
			++it;
		}
	}
}
