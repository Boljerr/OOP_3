#pragma once
#include <vector>
#include <string>
#include "Studentas.h"
#include "Vector.h"

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

void skaitytiIsFailoManoVector(const std::string& failoPavadinimas, Vector<Studentas>& studentai);
void skaiciuotiRezultatusManoVector(Vector<Studentas>& studentai, int skaiciavimoTipas);
void rusiuotiStudentusManoVector(Vector<Studentas>& studentai, int pasirinkimas);
void isvestiRezultatusManoVector(const Vector<Studentas>& studentai, int skaiciavimoTipas);
void isvestiRezultatusIFailaManoVector(const Vector<Studentas>& studentai, int skaiciavimoTipas, const std::string& failoPavadinimas);

void padalintiStudentus1ManoVector(
	const Vector<Studentas>& studentai,
	Vector<Studentas>& nuskriaustieji,
	Vector<Studentas>& kietiakiai
);

void padalintiStudentus2ManoVector(
	Vector<Studentas>& studentai,
	Vector<Studentas>& nuskriaustieji
);

void padalintiStudentus3ManoVector(
	Vector<Studentas>& studentai,
	Vector<Studentas>& nuskriaustieji
);

void atliktiDuomenuApdorojimoTyrimaManoVector(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

void atliktiDuomenuApdorojimoTyrimoVidurkiManoVector(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas,
	int kartu
);