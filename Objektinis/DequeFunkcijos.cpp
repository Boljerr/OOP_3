#include "DequeFunkcijos.h"
#include "Bendra.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>


void skaitytiIsFailoDeque(const std::string& failoPavadinimas, std::deque<Studentas>& studentai)
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

void skaiciuotiRezultatusDeque(std::deque<Studentas>& studentai, int skaiciavimoTipas)
{
	for (int i = 0; i < studentai.size(); ++i)
	{
		double nd;
		if (skaiciavimoTipas == 1)
		{
			nd = calculateAverage(studentai[i].getPazymiai());
		}
		else
		{
			nd = calculateMedian(studentai[i].getPazymiai());
		}
		double galutinis = calculateFinal(nd, studentai[i].getEgzaminas());
		studentai[i].setRezultatas(galutinis);
	}
}

void rusiuotiStudentusDeque(std::deque<Studentas>& studentai, int pasirinkimas)
{
	switch (pasirinkimas)
	{
	case 1:
		std::sort(studentai.begin(), studentai.end(), compareByVardas);
		break;
	case 2:
		std::sort(studentai.begin(), studentai.end(), compareByPavarde);
		break;
	case 3:
		std::sort(studentai.begin(), studentai.end(), compareByRezultatas);
		break;
	default:
		break;
	}
}

void padalintiStudentus1Deque(const std::deque<Studentas>& studentai, std::deque<Studentas>& nuskriaustieji, std::deque<Studentas>& kietiakiai)
{
	nuskriaustieji.clear();
	kietiakiai.clear();
	for (int i = 0; i < studentai.size(); ++i)
	{
		if (studentai[i].getRezultatas() < 5)
		{
			nuskriaustieji.push_back(studentai[i]);
		}
		else
		{
			kietiakiai.push_back(studentai[i]);
		}
	}
}

void padalintiStudentus2Deque(std::deque<Studentas>& studentai, std::deque<Studentas>& nuskriaustieji)
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

void padalintiStudentus3Deque(std::deque<Studentas>& studentai, std::deque<Studentas>& nuskriaustieji)
{
	nuskriaustieji.clear();
	auto riba = std::stable_partition(studentai.begin(), studentai.end(), arKietiakas);

	for (auto it = riba; it != studentai.end(); ++it)
	{
		nuskriaustieji.push_back(*it);
	}

	studentai.erase(riba, studentai.end());
}
