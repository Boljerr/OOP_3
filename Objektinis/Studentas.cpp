#include "Studentas.h"
#include <utility>
#include <sstream>
#include <iomanip>

int Studentas::sunaikintuObjektuKiekis_ = 0;

Studentas::Studentas() : Zmogus()
{
	egzaminas_ = 0;
	rezultatas_ = 0.0;
}



Studentas::Studentas(const std::string& vardas, const std::string& pavarde) : Zmogus(vardas, pavarde)
{
	pazymiai_.clear();
	egzaminas_ = 0;
	rezultatas_ = 0.0;
}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde, const Vector<int>& pazymiai, int egzaminas) : Zmogus(vardas, pavarde)
{
	pazymiai_ = pazymiai;
	egzaminas_ = egzaminas;
	rezultatas_ = 0.0;
}


Studentas::Studentas(const Studentas& kitas) : Zmogus(kitas.vardas_, kitas.pavarde_)
{
	pazymiai_ = kitas.pazymiai_;
	egzaminas_ = kitas.egzaminas_;
	rezultatas_ = kitas.rezultatas_;
}
Studentas& Studentas::operator=(const Studentas& kitas)
{
	if (this != &kitas)
	{
		vardas_ = kitas.vardas_;
		pavarde_ = kitas.pavarde_;
		pazymiai_ = kitas.pazymiai_;
		egzaminas_ = kitas.egzaminas_;
		rezultatas_ = kitas.rezultatas_;
	}
	return *this;
}

Studentas::Studentas(Studentas&& kitas) noexcept
{
	vardas_ = std::move(kitas.vardas_);
	pavarde_ = std::move(kitas.pavarde_);
	pazymiai_ = std::move(kitas.pazymiai_);
	egzaminas_ = kitas.egzaminas_;
	rezultatas_ = kitas.rezultatas_;

	kitas.egzaminas_ = 0;
	kitas.rezultatas_ = 0.0;
}

Studentas& Studentas::operator=(Studentas&& kitas) noexcept
{
	if (this != &kitas)
	{
		vardas_ = std::move(kitas.vardas_);
		pavarde_ = std::move(kitas.pavarde_);
		pazymiai_ = std::move(kitas.pazymiai_);
		egzaminas_ = kitas.egzaminas_;
		rezultatas_ = kitas.rezultatas_;

		kitas.egzaminas_ = 0;
		kitas.rezultatas_ = 0.0;
	}
	return *this;
}


const Vector<int>& Studentas::getPazymiai() const
{
	return pazymiai_;
}

int Studentas::getEgzaminas() const
{
	return egzaminas_;
}

double Studentas::getRezultatas() const
{
	return rezultatas_;
}

int Studentas::getSunaikintuObjektuKiekis()
{
	return sunaikintuObjektuKiekis_;
}

void Studentas::setPazymiai(const Vector<int>& pazymiai)
{
	pazymiai_ = pazymiai;
}

void Studentas::setEgzaminas(int egzaminas)
{
	egzaminas_ = egzaminas;
}

void Studentas::setRezultatas(double rezultatas)
{
	rezultatas_ = rezultatas;
}

void Studentas::pridetiPazymi(int pazymys)
{
	pazymiai_.push_back(pazymys);
}

void Studentas::read(std::istream& in)
{
	std::string eilute;

	if (!std::getline(in >> std::ws, eilute))
	{
		return;
	}

	std::stringstream ss(eilute);

	std::string vardas;
	std::string pavarde;
	Vector<int> pazymiai;
	int skaicius;

	ss >> vardas >> pavarde;

	if (vardas.empty() || pavarde.empty())
	{
		in.setstate(std::ios::failbit);
		return;
	}

	while (ss >> skaicius)
	{
		pazymiai.push_back(skaicius);
	}

	if (pazymiai.empty())
	{
		in.setstate(std::ios::failbit);
		return;
	}

	vardas_ = vardas;
	pavarde_ = pavarde;

	egzaminas_ = pazymiai.back();
	pazymiai.pop_back();

	pazymiai_ = pazymiai;
	rezultatas_ = 0.0;
}

void Studentas::print(std::ostream& out) const
{
	out << vardas_ << " " << pavarde_ << " ";

	for (int i = 0; i < pazymiai_.size(); ++i)
	{
		out << pazymiai_[i] << " ";
	}

	out << egzaminas_<< " ";
	out << std::fixed << std::setprecision(2) << rezultatas_;
}

std::istream& operator>>(std::istream& in, Studentas& studentas)
{
	studentas.read(in);
	return in;
}
std::ostream& operator<<(std::ostream& out, const Studentas& studentas)
{
	studentas.print(out);
	return out;
}





