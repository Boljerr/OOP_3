#pragma once
#include "Studentas.h"
#include <deque>
#include <string>

void skaitytiIsFailoDeque(const std::string& failoPavadinimas, std::deque<Studentas>& studentai);
void skaiciuotiRezultatusDeque(std::deque<Studentas>& studentai, int skaiciavimoTipas);
void rusiuotiStudentusDeque(std::deque<Studentas>& studentai, int pasirinkimas);

void padalintiStudentus1Deque(
	const std::deque<Studentas>& studentai,
	std::deque<Studentas>& nuskriaustieji,
	std::deque<Studentas>& kietiakiai
);

void padalintiStudentus2Deque(
	std::deque<Studentas>& studentai,
	std::deque<Studentas>& nuskriaustieji
);

void padalintiStudentus3Deque(
	std::deque<Studentas>& studentai,
	std::deque<Studentas>& nuskriaustieji
);