#pragma once
#include <string>

struct TyrimoRezultatai
{
	double nuskaitymas = 0.0;
	double rusiavimas = 0.0;
	double skirstymas = 0.0;
};

struct StrategijuRezultatai
{
	double strategija1 = 0.0;
	double strategija2 = 0.0;
	double strategija3 = 0.0;
};

TyrimoRezultatai aliktiVectorTyrima
(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

TyrimoRezultatai atliktiListTyrima
(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

TyrimoRezultatai atliktiDequeTyrima
(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

StrategijuRezultatai atliktiSkirstymoStrategijuTyrimaVector
(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

StrategijuRezultatai atliktiSkirstymoStrategijuTyrimaList
(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

StrategijuRezultatai atliktiSkirstymoStrategijuTyrimaDeque
(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

void atliktiKonteineriuTyrimaSuVidurkiu(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, int kartu);

void atliktiStrategijuTyrimaSuVidurkiu(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, int kartu);


void atliktiPushBackTyrima(unsigned int dydis);
void atliktiPushBackTyrimus();
void skaiciuotiPerskirstymus(unsigned int dydis);