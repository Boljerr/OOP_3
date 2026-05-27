#pragma once

#include <list>
#include <string>
#include "Studentas.h"

void skaitytiIsFailoList(const std::string& failoPavadinimas, std::list<Studentas>& studentai);
void skaiciuotiRezultatusList(std::list<Studentas>& studentai, int skaiciavimoTipas);
void rusiuotiStudentusList(std::list<Studentas>& studentai, int pasirinkimas);


void padalintiStudentus1List(
	const std::list<Studentas>& studentai,
	std::list<Studentas>& nuskriaustieji,
	std::list<Studentas>& kietiakiai
);
void padalintiStudentus2List(
	std::list<Studentas>& studentai,
	std::list<Studentas>& nuskriaustieji
);
void padalintiStudentus3List(
	std::list<Studentas>& studentai,
	std::list<Studentas>& nuskriaustieji
);