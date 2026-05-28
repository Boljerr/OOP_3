#include "Testai.h"
#include "Studentas.h"
#include "Zmogus.h"
#include "Vector.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <utility>



void spausdintiTestoRezultata(bool pavyko, std::string testoPavadinimas)
{
	if (pavyko)
	{
		std::cout << testoPavadinimas << " - Pavyko\n";
	}
	else
			{
		std::cout << testoPavadinimas << " - Nepavyko\n";
	}
}


void testuotiStudentoKlase()
{
	std::cout << "Studento klases testavimas\n";

	Studentas tusciasStudentas;

	bool tusciasKonstruktoriusPavyko =
		tusciasStudentas.getVardas() == "" &&
		tusciasStudentas.getPavarde() == "" &&
		tusciasStudentas.getEgzaminas() == 0 &&
		tusciasStudentas.getPazymiai().empty();
	spausdintiTestoRezultata(tusciasKonstruktoriusPavyko, "Studento klases tuscias konstruktorius");

	Vector<int> pazymiai = { 8, 9, 10 };

	Studentas s1("Jonas", "Jonaitis", pazymiai, 7);
	s1.setRezultatas(8.2);

	Zmogus* zmogus = &s1;

	bool paveldimumasPavyko =
		zmogus->getVardas() == "Jonas" &&
		zmogus->getPavarde() == "Jonaitis";

	spausdintiTestoRezultata(paveldimumasPavyko, "Studentas paveldi is Zmogus klases");

	bool konstruktoriaiPavyko = 
		s1.getVardas() == "Jonas" &&
		s1.getPavarde() == "Jonaitis" &&
		s1.getEgzaminas() == 7 &&
		s1.getPazymiai().size() == pazymiai.size();

	spausdintiTestoRezultata(konstruktoriaiPavyko, "Studento klases konstruktoriai");

	Studentas s2(s1);

	bool kopijavimoKonstruktoriusPavyko =
		s2.getVardas() == s1.getVardas() &&
		s2.getPavarde() == s1.getPavarde() &&
		s2.getEgzaminas() == s1.getEgzaminas() &&
		s2.getPazymiai().size() == s1.getPazymiai().size();

	spausdintiTestoRezultata(kopijavimoKonstruktoriusPavyko, "Studento klases kopijavimo konstruktorius");

	Studentas s3;
	s3 = s1;

	bool kopijavimoOperatoriusPavyko =
		s3.getVardas() == s1.getVardas() &&
		s3.getPavarde() == s1.getPavarde() &&
		s3.getEgzaminas() == s1.getEgzaminas() &&
		s3.getPazymiai().size() == s1.getPazymiai().size();

	spausdintiTestoRezultata(kopijavimoOperatoriusPavyko, "Studento klases kopijavimo operatorius");

	Studentas s4(std::move(s2));

	bool perkelimoKonstruktoriusPavyko =
		s4.getVardas() == "Jonas" &&
		s4.getPavarde() == "Jonaitis" &&
		s4.getEgzaminas() == 7 &&
		s4.getPazymiai().size() == pazymiai.size();

	spausdintiTestoRezultata(perkelimoKonstruktoriusPavyko, "Studento klases perkelimo konstruktorius");

	Studentas s5;
	s5 = std::move(s3);

	bool perkelimoOperatoriusPavyko =
		s5.getVardas() == "Jonas" &&
		s5.getPavarde() == "Jonaitis" &&
		s5.getEgzaminas() == 7 &&
		s5.getPazymiai().size() == pazymiai.size();

	spausdintiTestoRezultata(perkelimoOperatoriusPavyko, "Studento klases perkelimo operatorius");
	
	std::stringstream ivestis("Petras Petraitis 6 7 8 9");

	Studentas s6;
	ivestis >> s6;

	bool ivestisOperatoriusPavyko =
		s6.getVardas() == "Petras" &&
		s6.getPavarde() == "Petraitis" &&
		s6.getEgzaminas() == 9 &&
		s6.getPazymiai().size() == 3;
	spausdintiTestoRezultata(ivestisOperatoriusPavyko, "Studento klases ivestis operatorius");

	s6.setRezultatas(7.85);

	std::stringstream isvestis;
	isvestis << s6;

	bool isvestisOperatoriusPavyko =
		isvestis.str() == "Petras Petraitis 6 7 8 9 7.85";
	spausdintiTestoRezultata(isvestisOperatoriusPavyko, "Studento klases isvestis operatorius");

	int kiekisPries = Studentas::getSunaikintuObjektuKiekis();

	{
		Studentas laikinas("Testas", "Destruktorius");
		laikinas.setEgzaminas(10);
	}

	int kiekisPo = Studentas::getSunaikintuObjektuKiekis();

	bool destruktoriusPavyko = kiekisPo == kiekisPries + 1;

	spausdintiTestoRezultata(destruktoriusPavyko, "Studento klases destruktorius");

	std::cout << "Studento klases testavimas baigtas\n";
}