#pragma once
#include <vector>
#include <string>
#include "Studentas.h"

void skaitytiIsFailoVector(const std::string& failoPavadinimas, std::vector<Studentas>& studentai);
void skaiciuotiRezultatusVector(std::vector<Studentas>& studentai, int skaiciavimoTipas);
void rusiuotiStudentusVector(std::vector<Studentas>& studentai, int pasirinkimas);
void isvestiRezultatusVector(const std::vector<Studentas>& studentai, int skaiciavimoTipas);
void isvestiRezultatusIFailaVector(const std::vector<Studentas>& studentai, int skaiciavimoTipas, const std::string& failoPavadinimas);

void generuotiStudentuFailaVector(const std::string& failoPavadinimas, int studentuKiekis, int ndKiekis);
void atliktiFailoKurimoTyrimaVector(const std::string& failoPavadinimas, int studentuKiekis, int ndKiekis);

void padalintiStudentus1Vector(
	const std::vector<Studentas>& studentai,
	std::vector<Studentas>& nuskriaustieji,
	std::vector<Studentas>& kietiakiai
);

void padalintiStudentus2Vector(
	std::vector<Studentas>& studentai,
	std::vector<Studentas>& nuskriaustieji
);
void padalintiStudentus3Vector(
	std::vector<Studentas>& studentai,
	std::vector<Studentas>& nuskriaustieji
);

void atliktiDuomenuApdorojimoTyrimaVector(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

void atliktiDuomenuApdorojimoTyrimoVidurkiVector(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas,
	int kartu
);