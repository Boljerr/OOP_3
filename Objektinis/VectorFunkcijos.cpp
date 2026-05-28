#include "VectorFunkcijos.h"
#include "Bendra.h"
#include "Vector.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include <cstdlib>

void skaitytiIsFailoVector(const std::string& failoPavadinimas, std::vector<Studentas>& studentai)
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
		Vector<int> visiPaz;

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



void skaiciuotiRezultatusVector(std::vector<Studentas>& studentai, int skaiciavimoTipas)
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

void rusiuotiStudentusVector(std::vector<Studentas>& studentai, int pasirinkimas)
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

void isvestiRezultatusVector(const std::vector<Studentas>& studentai, int skaiciavimoTipas)
{
	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";
	std::cout << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";
	std::cout << "--------------------------------------------------\n";
	for (int i = 0; i < studentai.size(); i++)
	{
		std::cout << std::setw(15) << studentai[i].getPavarde()
			<< std::setw(15) << studentai[i].getVardas()
			<< std::fixed << std::setprecision(2) << studentai[i].getRezultatas() << "\n";
	}
}

void isvestiRezultatusIFailaVector(const std::vector<Studentas>& studentai, int skaiciavimoTipas, const std::string& failoPavadinimas)
{
	std::ofstream out(failoPavadinimas);
	if (!out.is_open())
	{
		std::cout << " Nepavyko sukurti rezultatu failo.\n";
		return;
	}
	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";
	out << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";
	out << "--------------------------------------------------\n";

	for (int i = 0; i < studentai.size(); i++)
	{
		out << std::setw(15) << studentai[i].getPavarde()
			<< std::setw(15) << studentai[i].getVardas()
			<< std::fixed << std::setprecision(2) << studentai[i].getRezultatas() << "\n";
	}
	out.close();
	std::cout << "Rezultatai issaugoti faile: " << failoPavadinimas << "\n";
}

void generuotiStudentuFailaVector(const std::string& failoPavadinimas, int studentuKiekis, int ndKiekis)
{
	std::ofstream out(failoPavadinimas);

	if (!out.is_open())
	{
		throw std::runtime_error("Nepavyko sukurti failo: " + failoPavadinimas);
	}
	out << std::left << std::setw(15) << "Vardas"
		<< std::setw(15) << "Pavarde";

	for (int i = 1; i <= ndKiekis; ++i)
	{
		out << "ND" << std::to_string(i) << " ";
	}
	out << "Egz." << '\n';

	for (int i = 1; i <= studentuKiekis; i++)
	{
		out << std::left << std::setw(15) << ("Vardas" + std::to_string(i))
			<< std::setw(15) << ("Pavarde" + std::to_string(i));

		for (int j = 0; j < ndKiekis; j++)
		{
			out << (std::rand() % 10 + 1) << " ";
		}
		out << (std::rand() % 10 + 1) << "\n";
	}
	out.close();
}

void atliktiFailoKurimoTyrimaVector(const std::string& failoPavadinimas, int studentuKiekis, int ndKiekis)
{
	auto start = std::chrono::high_resolution_clock::now();
	generuotiStudentuFailaVector(failoPavadinimas, studentuKiekis, ndKiekis);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Failo " << failoPavadinimas << " kurimo laikas: " << diff.count() << " s\n";
}

void padalintiStudentus1Vector(const std::vector<Studentas>& studentai, std::vector<Studentas>& nuskriaustieji, std::vector<Studentas>& kietiakiai)
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

void padalintiStudentus2Vector(std::vector<Studentas>& studentai, std::vector<Studentas>& nuskriaustieji)
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

void padalintiStudentus3Vector(std::vector<Studentas>& studentai, std::vector<Studentas>& nuskriaustieji)
{
	nuskriaustieji.clear();

	auto riba = std::stable_partition(studentai.begin(), studentai.end(), arKietiakas);

	for (auto it = riba; it != studentai.end(); ++it)
	{
		nuskriaustieji.push_back(*it);
	}
	studentai.erase(riba, studentai.end());
}

void atliktiDuomenuApdorojimoTyrimaVector(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
	std::vector<Studentas> studentai;
	std::vector<Studentas> nuskriaustieji;
	std::vector<Studentas> kietiakiai;

	std::string pagrindinisVardas = gautiFailoVardaBePletinio(failoPavadinimas);
	std::string bloguFailas = pagrindinisVardas + "_nuskriaustieji.txt";
	std::string geruFailas = pagrindinisVardas + "_kietiakiai.txt";


	auto visoStart = std::chrono::high_resolution_clock::now();

	auto skaitymoStart = std::chrono::high_resolution_clock::now();
	skaitytiIsFailoVector(failoPavadinimas, studentai);
	auto skaitymoEnd = std::chrono::high_resolution_clock::now();

	skaiciuotiRezultatusVector(studentai, skaiciavimoTipas);

	auto skirstymoStart = std::chrono::high_resolution_clock::now();
	padalintiStudentus1Vector(studentai, nuskriaustieji, kietiakiai);
	auto skirstymoEnd = std::chrono::high_resolution_clock::now();

	auto rusiavimoStart = std::chrono::high_resolution_clock::now();
	rusiuotiStudentusVector(nuskriaustieji, rusiavimoTipas);
	rusiuotiStudentusVector(kietiakiai, rusiavimoTipas);
	auto rusiavimoEnd = std::chrono::high_resolution_clock::now();

	auto isvedimoStart = std::chrono::high_resolution_clock::now();
	isvestiRezultatusIFailaVector(nuskriaustieji, skaiciavimoTipas, bloguFailas);
	isvestiRezultatusIFailaVector(kietiakiai, skaiciavimoTipas, geruFailas);
	auto isvedimoEnd = std::chrono::high_resolution_clock::now();

	auto visoEnd = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> skaitymas = skaitymoEnd - skaitymoStart;
	std::chrono::duration<double> skirstymas = skirstymoEnd - skirstymoStart;
	std::chrono::duration<double> rusiavimas = rusiavimoEnd - rusiavimoStart;
	std::chrono::duration<double> isvedimas = isvedimoEnd - isvedimoStart;
	std::chrono::duration<double> visasLaikas = visoEnd - visoStart;

	std::cout << "\nFailas: " << failoPavadinimas << '\n';
	std::cout << "Nuskaitymas: " << skaitymas.count() << " s\n";
	std::cout << "Skirstymas: " << skirstymas.count() << " s\n";
	std::cout << "Rusiavimas: " << rusiavimas.count() << " s\n";
	std::cout << "Isvedimas: " << isvedimas.count() << " s\n";
	std::cout << "Bendras laikas: " << visasLaikas.count() << " s\n";
}

void atliktiDuomenuApdorojimoTyrimoVidurkiVector(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, int kartu)
{
	for (int i = 0; i < kartu; i++)
	{
		std::cout << "\n Bandymas Nr." << i + 1 << "\n";
		atliktiDuomenuApdorojimoTyrimaVector(failoPavadinimas, skaiciavimoTipas, rusiavimoTipas);
	}
}


//V3.0
void skaitytiIsFailoManoVector(const std::string& failoPavadinimas, Vector<Studentas>& studentai)
{
	studentai.clear();
	std::ifstream in(failoPavadinimas);

	if (!in.is_open())
	{
		throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
	}

	std::string eilute;

	std::getline(in, eilute);

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
		Vector<int> visiPaz;

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

void skaiciuotiRezultatusManoVector(Vector<Studentas>& studentai, int skaiciavimoTipas)
{
	for (std::size_t i = 0; i < studentai.size(); ++i)
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

void rusiuotiStudentusManoVector(Vector<Studentas>& studentai, int pasirinkimas)
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

void isvestiRezultatusManoVector(const Vector<Studentas>& studentai, int skaiciavimoTipas)
{
	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";

	std::cout << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";

	std::cout << "--------------------------------------------------\n";

	for (std::size_t i = 0; i < studentai.size(); ++i)
	{
		std::cout << std::setw(15) << studentai[i].getPavarde()
			<< std::setw(15) << studentai[i].getVardas()
			<< std::fixed << std::setprecision(2)
			<< studentai[i].getRezultatas() << "\n";
	}
}
void isvestiRezultatusIFailaManoVector(const Vector<Studentas>& studentai, int skaiciavimoTipas, const std::string& failoPavadinimas)
{
	std::ofstream out(failoPavadinimas);

	if (!out.is_open())
	{
		std::cout << " Nepavyko sukurti rezultatu failo.\n";
		return;
	}

	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";

	out << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";

	out << "--------------------------------------------------\n";

	for (std::size_t i = 0; i < studentai.size(); ++i)
	{
		out << std::setw(15) << studentai[i].getPavarde()
			<< std::setw(15) << studentai[i].getVardas()
			<< std::fixed << std::setprecision(2)
			<< studentai[i].getRezultatas() << "\n";
	}

	out.close();

	std::cout << "Rezultatai issaugoti faile: " << failoPavadinimas << "\n";
}

void padalintiStudentus1ManoVector(const Vector<Studentas>& studentai, Vector<Studentas>& nuskriaustieji, Vector<Studentas>& kietiakiai)
{
	nuskriaustieji.clear();
	kietiakiai.clear();

	for (std::size_t i = 0; i < studentai.size(); ++i)
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

void padalintiStudentus2ManoVector(Vector<Studentas>& studentai, Vector<Studentas>& nuskriaustieji)
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

void padalintiStudentus3ManoVector(Vector<Studentas>& studentai, Vector<Studentas>& nuskriaustieji)
{
	nuskriaustieji.clear();

	auto riba = std::stable_partition(studentai.begin(), studentai.end(), arKietiakas);

	for (auto it = riba; it != studentai.end(); ++it)
	{
		nuskriaustieji.push_back(*it);
	}

	studentai.erase(riba, studentai.end());
}

void atliktiDuomenuApdorojimoTyrimaManoVector(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
	Vector<Studentas> studentai;
	Vector<Studentas> nuskriaustieji;
	Vector<Studentas> kietiakiai;

	std::string pagrindinisVardas = gautiFailoVardaBePletinio(failoPavadinimas);
	std::string bloguFailas = pagrindinisVardas + "_mano_vector_nuskriaustieji.txt";
	std::string geruFailas = pagrindinisVardas + "_mano_vector_kietiakiai.txt";

	auto visoStart = std::chrono::high_resolution_clock::now();

	auto skaitymoStart = std::chrono::high_resolution_clock::now();
	skaitytiIsFailoManoVector(failoPavadinimas, studentai);
	auto skaitymoEnd = std::chrono::high_resolution_clock::now();

	skaiciuotiRezultatusManoVector(studentai, skaiciavimoTipas);

	auto skirstymoStart = std::chrono::high_resolution_clock::now();
	padalintiStudentus1ManoVector(studentai, nuskriaustieji, kietiakiai);
	auto skirstymoEnd = std::chrono::high_resolution_clock::now();

	auto rusiavimoStart = std::chrono::high_resolution_clock::now();
	rusiuotiStudentusManoVector(nuskriaustieji, rusiavimoTipas);
	rusiuotiStudentusManoVector(kietiakiai, rusiavimoTipas);
	auto rusiavimoEnd = std::chrono::high_resolution_clock::now();

	auto isvedimoStart = std::chrono::high_resolution_clock::now();
	isvestiRezultatusIFailaManoVector(nuskriaustieji, skaiciavimoTipas, bloguFailas);
	isvestiRezultatusIFailaManoVector(kietiakiai, skaiciavimoTipas, geruFailas);
	auto isvedimoEnd = std::chrono::high_resolution_clock::now();

	auto visoEnd = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> skaitymas = skaitymoEnd - skaitymoStart;
	std::chrono::duration<double> skirstymas = skirstymoEnd - skirstymoStart;
	std::chrono::duration<double> rusiavimas = rusiavimoEnd - rusiavimoStart;
	std::chrono::duration<double> isvedimas = isvedimoEnd - isvedimoStart;
	std::chrono::duration<double> visasLaikas = visoEnd - visoStart;

	std::cout << "\nFailas: " << failoPavadinimas << '\n';
	std::cout << "Konteineris: Mano Vector\n";
	std::cout << "Nuskaitymas: " << skaitymas.count() << " s\n";
	std::cout << "Skirstymas: " << skirstymas.count() << " s\n";
	std::cout << "Rusiavimas: " << rusiavimas.count() << " s\n";
	std::cout << "Isvedimas: " << isvedimas.count() << " s\n";
	std::cout << "Bendras laikas: " << visasLaikas.count() << " s\n";
}

void atliktiDuomenuApdorojimoTyrimoVidurkiManoVector(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, int kartu)
{
	for (int i = 0; i < kartu; ++i)
	{
		std::cout << "\n Bandymas Nr." << i + 1 << "\n";
		atliktiDuomenuApdorojimoTyrimaManoVector(failoPavadinimas, skaiciavimoTipas, rusiavimoTipas);
	}
}