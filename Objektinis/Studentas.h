#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H
#include "Zmogus.h"
#include "Vector.h"

#include <string>
#include <vector>
#include <iostream>

/**
 *@class Studentas
 *@brief Klase skirta saugoti studento duomenis.
 *
 *Studentas klase paveldi is Zmogus klases. Ji saugo studento
 *namu darbu pazymius, egzamino pazymi ir galutini rezultata.
 *
 *Klase turi Rule of Five metodus, kad objektus butu galima
 *teisingai kopijuoti, priskirti ir perkelti.
 *
 *Taip pat yra statinis kintamasis, kuris seka kiek Studentas klases objektu buvo sunaikinta,
 *Kad butu galima atlikti dekonstruktoriaus testavima ir stebeti atminties valymus.
 
*
 */
class Studentas : public Zmogus
{
private:
	/**
	 * @brief Studento namu darbu pazymiai.
	 */
	Vector<int> pazymiai_;
	/**
	 * @brief Studento egzamino pazymys.
	 */
	int egzaminas_;
	/**
	 * @brief Studento galutinis rezultatas.
	 */
	double rezultatas_;
	/**
	 * @brief Statinis kintamasis, kuris seka kiek Studentas klases objektu buvo sunaikinta.
	 */
	static int sunaikintuObjektuKiekis_;

public:
	/**
	 * @brief Tuscias konstruktorius, kuris sukuria Studentas objekta su numatytomis reiksmemis.
	 */
	Studentas();

	/**
	 * @brief Konstruktorius su studento vardu ir pavarde.
	 * @param vardas Studento vardas.
	 * @param pavarde Studento pavarde.
	 */
	Studentas(const std::string& vardas, const std::string& pavarde);

	/**
	 * @brief Konstruktorius su studento vardu, pavarde, namu darbu pazymiais ir egzamino pazymiu.
	 * @param vardas Studento vardas.
	 * @param pavarde Studento pavarde.
	 * @param pazymiai Studento namu darbu pazymiai.
	 * @param egzaminas Studento egzamino pazymys.
	 */
	Studentas(const std::string& vardas, const std::string& pavarde, const Vector<int>& pazymiai, int egzaminas);

	/**
	 * @brief Destruktorius.
	 *
	 */
	~Studentas()
	{
		pazymiai_.clear();
		egzaminas_ = 0;
		rezultatas_ = 0.0;
		sunaikintuObjektuKiekis_++;

	}

	/**
	 * @brief Grazina sunaikintu Studentas objektu kieki.
	 * @return Sunaikintu Studentas objektu kiekis.
	 */
	static int getSunaikintuObjektuKiekis();

	/**
	 * @brief Kopijavimo konstruktorius.
	 * @param kitas Kitas Studentas objektas, kurio duomenys bus kopijuojami.
	 */
	Studentas(const Studentas& kitas);

	/**
	 * @brief Kopijavimo priskyrimo operatorius.
	 * @param kitas Kitas Studentas objektas, kurio duomenys bus kopijuojami.
	 * @return Nuoroda i esama Studentas objektą.
	 */
	Studentas& operator=(const Studentas& kitas);

	/**
	 * @brief Perkėlimo konstruktorius.
	 * @param kitas Kitas Studentas objektas, kurio duomenys bus perkelti.
	 */
	Studentas(Studentas&& kitas) noexcept;
	
	/**
	 * @brief Perkėlimo priskyrimo operatorius.
	 * @param kitas Kitas Studentas objektas, kurio duomenys bus perkelti.
	 * @return Nuoroda i esama Studentas objektą.
	 */
	Studentas& operator=(Studentas&& kitas) noexcept;

	/**
	 * @brief Grazina studento namu darbu pazymius.
	 * @return Studento namu darbu pazymiai.
	 */
	const Vector<int>& getPazymiai() const;
	
	/**
	 * @brief Grazina studento egzamino pazymi.
	 * @return Studento egzamino pazymys.
	 */
	int getEgzaminas() const;
	
	/**
	 * @brief Grazina studento galutini rezultata.
	 * @return Studento galutinis rezultatas.
	 */
	double getRezultatas() const;

	/**
	 * @brief Nustato studento namu darbu pazymius.
	 * @param namuDarbai Studento namu darbu pazymiai.
	 */
	void setPazymiai(const Vector<int>& namuDarbai);
	
	/**
	 * @brief Nustato studento egzamino pazymi.
	 * @param egzaminas Studento egzamino pazymys.
	 */
	void setEgzaminas(int egzaminas);
	
	/**
	 * @brief Nustato studento galutini rezultata.
	 * @param rezultatas Studento galutinis rezultatas.
	 */
	void setRezultatas(double rezultatas);

	/**
	 * @brief Prideda nauja pazymi prie studento namu darbu pazymiu.
	 * @param pazymys Naujas pazymys.
	 */
	void pridetiPazymi(int pazymys);

	/**
	 * @brief Nuskaito studento duomenis is srauto.
	 * @param in Ivesties srautas, is kurio bus nuskaitomi studento duomenys.
	 */
	void read(std::istream& in) override;

	/**
	 * @brief Isveda studento duomenis i srauta.
	 * @param out Isvesties srautas, i kuri bus isvedami studento duomenys.
	 */
	void print(std::ostream& out) const override;

	/**
	 * @brief Ivesties operatorius, kuris leidzia nuskaityti studento duomenis is srauto.
	 * @param in Ivesties srautas, is kurio bus nuskaitomi studento duomenys.
	 * @param studentas Studentas objektas, i kuri bus saugomi nuskaitomi duomenys.
	 * @return Nuoroda i ivesties srauta.
	 */
	friend std::istream& operator>>(std::istream& in, Studentas& studentas);
	
	/**
	 * @brief Isvesties operatorius, kuris leidzia isvesti studento duomenis i srauta.
	 * @param out Isvesties srautas, i kuri bus isvedami studento duomenys.
	 * @param studentas Studentas objektas, kurio duomenys bus isvedami.
	 * @return Nuoroda i isvesties srauta.
	 */
	friend std::ostream& operator<<(std::ostream& out, const Studentas& studentas);
	
};

#endif // STUDENTAS_H