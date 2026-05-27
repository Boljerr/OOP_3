
#include "Zmogus.h"


Zmogus::Zmogus()
{
	vardas_ = "";
	pavarde_ = "";
}

Zmogus::Zmogus(const std::string& vardas, const std::string& pavarde)
{
	vardas_ = vardas;
	pavarde_ = pavarde;
}

Zmogus::~Zmogus()
{
}


std::string Zmogus::getVardas() const
{
	return vardas_;
}

std::string Zmogus::getPavarde() const
{
	return pavarde_;
}

void Zmogus::setVardas(const std::string& vardas)
{
	vardas_ = vardas;
}

void Zmogus::setPavarde(const std::string& pavarde)
{
	pavarde_ = pavarde;
}