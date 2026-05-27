#pragma once
#ifndef ZMOGUS_H
#define ZMOGUS_H
#include <iostream>
#include <string>

/**
 * @class Zmogus
 * @brief Abstrakti bazine klase, skirta saugoti bendrus duomenis apie zmogu.
 * 
 * 
 * Sioje klaseje saugomas vardas ir pavarde.
 * Klase naudojama kaip bazine klase Studentas klasei.
 */
class Zmogus
{
protected:
    /**
     * @brief Zmogaus vardas.
	 */
    std::string vardas_;
    /**
     * @brief Zmogaus pavarde.
	 */
    std::string pavarde_;

public:
    /**
     * @brief Numatytasis konstruktorius
    */
    Zmogus();

    /**
     * @brief Konstruktorius su zmogaus vardu ir pavarde.
     * @param vardas Zmogaus vardas.
     * @param pavarde Zmogaus pavarde.
	 */
    Zmogus(const std::string& vardas, const std::string& pavarde);
    
    /**
     * @brief Virtualus Destruktorius.
	 */
	virtual ~Zmogus();

    /**
     * @brief Grazina zmogaus varda.
	 * @return Zmogaus vardas.
	*/
    std::string getVardas() const;
    
	/**
     * @brief Grazina zmogaus pavarde.
     * @return Zmogaus pavarde.
	 */
	std::string getPavarde() const;
    
	/**
     * @brief Nustato zmogaus varda.
	 * @param vardas Naujas vardas.
	*/
    void setVardas(const std::string& vardas);
    
	/**
     * @brief Nustato zmogaus pavarde.
     * @param pavarde Nauja pavarde.
     */
    void setPavarde(const std::string& pavarde);

    /**
     * @brief Virtuali funkcija, skirta skaityti zmogaus duomenis is srauto.
     * @param in Ivesties srautas, is kurio bus skaitomi duomenys.
	 */
    virtual void read(std::istream& in) = 0;

    /**
     * @brief Virtuali funkcija, skirta spausdinti zmogaus duomenis i srauta.
     * @param out Isvesties srautas, i kuri bus spausdinami duomenys.
	 */
	virtual void print(std::ostream& out) const = 0;
};

#endif // ZMOGUS_H
