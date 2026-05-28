#include "Tyrimai.h"
#include "VectorFunkcijos.h"
#include "ListFunkcijos.h"
#include "DequeFunkcijos.h"
#include "Bendra.h"
#include "Vector.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <iomanip>

#include<fstream>
#include<string>
void isvestiStudentusIFailaVector(const std::vector<Studentas>& studentai, const std::string& failoPavadinimas)
{
    std::ofstream out(failoPavadinimas);

    if (!out.is_open())
    {
        std::cout << " Nepavyko sukurti rezultatu failo.\n";
        return;
    }

    for (int i = 0; i < studentai.size(); i++)
    {
		out << studentai[i] << "\n";
    }
}

void isvestiStudentusIFailaList(const std::list<Studentas>& studentai, const std::string& failoPavadinimas)
{
    std::ofstream out(failoPavadinimas);
    if (!out.is_open())
    {
        std::cout << " Nepavyko sukurti rezultatu failo.\n";
        return;
    }
    for (const auto& studentas : studentai)
    {
        out << studentas << "\n";
    }
}

void isvestiStudentusIFailaDeque(const std::deque<Studentas>& studentai, const std::string& failoPavadinimas)
{
    std::ofstream out(failoPavadinimas);
    if (!out.is_open())
    {
        std::cout << " Nepavyko sukurti rezultatu failo.\n";
        return;
    }
    for (const auto& studentas : studentai)
    {
        out << studentas << "\n";
    }


}


TyrimoRezultatai atliktiVectorTyrima(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
    TyrimoRezultatai rezultatai;
    std::vector<Studentas> studentai;

    auto startRead = std::chrono::high_resolution_clock::now();
    skaitytiIsFailoVector(failoPavadinimas, studentai);
    auto endRead = std::chrono::high_resolution_clock::now();

    skaiciuotiRezultatusVector(studentai, skaiciavimoTipas);

    std::vector<Studentas> studentaiRusiavimui = studentai;
    auto startSort = std::chrono::high_resolution_clock::now();
    rusiuotiStudentusVector(studentaiRusiavimui, rusiavimoTipas);
    auto endSort = std::chrono::high_resolution_clock::now();

    std::vector<Studentas> studentaiSkirstymui = studentai;
    std::vector<Studentas> nuskriaustieji;
    auto startSplit = std::chrono::high_resolution_clock::now();
    padalintiStudentus3Vector(studentaiSkirstymui, nuskriaustieji);
    auto endSplit = std::chrono::high_resolution_clock::now();

    rezultatai.nuskaitymas = std::chrono::duration<double>(endRead - startRead).count();
    rezultatai.rusiavimas = std::chrono::duration<double>(endSort - startSort).count();
    rezultatai.skirstymas = std::chrono::duration<double>(endSplit - startSplit).count();

    rusiuotiStudentusVector(studentaiSkirstymui, rusiavimoTipas);
    rusiuotiStudentusVector(nuskriaustieji, rusiavimoTipas);
    isvestiRezultatusIFailaVector(studentaiSkirstymui, skaiciavimoTipas, "rusiuoti_studentai_vector.txt");
	isvestiRezultatusIFailaVector(nuskriaustieji, skaiciavimoTipas, "nuskriaustieji_vector.txt");
    return rezultatai;
}

TyrimoRezultatai atliktiListTyrima(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
    TyrimoRezultatai rezultatai;
    std::list<Studentas> studentai;

    auto startRead = std::chrono::high_resolution_clock::now();
    skaitytiIsFailoList(failoPavadinimas, studentai);
    auto endRead = std::chrono::high_resolution_clock::now();

    skaiciuotiRezultatusList(studentai, skaiciavimoTipas);

    std::list<Studentas> studentaiRusiavimui = studentai;
    auto startSort = std::chrono::high_resolution_clock::now();
    rusiuotiStudentusList(studentaiRusiavimui, rusiavimoTipas);
    auto endSort = std::chrono::high_resolution_clock::now();
    
	std::list<Studentas> studentaiSkirstymui = studentai;
    std::list<Studentas> nuskriaustieji;
    std::list<Studentas> kietiakiai;
    auto startSplit = std::chrono::high_resolution_clock::now();
    padalintiStudentus1List(studentaiSkirstymui, nuskriaustieji, kietiakiai);
    auto endSplit = std::chrono::high_resolution_clock::now();

    rezultatai.nuskaitymas = std::chrono::duration<double>(endRead - startRead).count();
    rezultatai.rusiavimas = std::chrono::duration<double>(endSort - startSort).count();
    rezultatai.skirstymas = std::chrono::duration<double>(endSplit - startSplit).count();

    return rezultatai;
}

TyrimoRezultatai atliktiDequeTyrima(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
    TyrimoRezultatai rezultatai;
    std::deque<Studentas> studentai;

    auto startRead = std::chrono::high_resolution_clock::now();
    skaitytiIsFailoDeque(failoPavadinimas, studentai);
    auto endRead = std::chrono::high_resolution_clock::now();

    skaiciuotiRezultatusDeque(studentai, skaiciavimoTipas);

    std::deque<Studentas> studentaiRusiavimui = studentai;
    auto startSort = std::chrono::high_resolution_clock::now();
    rusiuotiStudentusDeque(studentaiRusiavimui, rusiavimoTipas);
    auto endSort = std::chrono::high_resolution_clock::now();

    std::deque<Studentas> studentaiSkirstymui = studentai;
    std::deque<Studentas> nuskriaustieji;
    std::deque<Studentas> kietiakiai;

    auto startSplit = std::chrono::high_resolution_clock::now();
    padalintiStudentus1Deque(studentaiSkirstymui, nuskriaustieji, kietiakiai);
    auto endSplit = std::chrono::high_resolution_clock::now();

    rezultatai.nuskaitymas = std::chrono::duration<double>(endRead - startRead).count();
    rezultatai.rusiavimas = std::chrono::duration<double>(endSort - startSort).count();
    rezultatai.skirstymas = std::chrono::duration<double>(endSplit - startSplit).count();

    return rezultatai;
}

StrategijuRezultatai atliktiStrategijuTyrimaVector(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, bool isvestiIFailus)
{
	StrategijuRezultatai rezultatai;

    std::vector<Studentas> pradinis;
	skaitytiIsFailoVector(failoPavadinimas, pradinis);
	skaiciuotiRezultatusVector(pradinis, skaiciavimoTipas);
    rusiuotiStudentusVector(pradinis, rusiavimoTipas);

	std::vector<Studentas> s1 = pradinis;
	std::vector<Studentas> s2 = pradinis;
	std::vector<Studentas> s3 = pradinis;

	std::vector<Studentas> nuskriaustieji1;
	std::vector<Studentas> kietiakiai1;
	std::vector<Studentas> nuskriaustieji2;
	std::vector<Studentas> nuskriaustieji3;

	auto start1 = std::chrono::high_resolution_clock::now();
	padalintiStudentus1Vector(s1, nuskriaustieji1, kietiakiai1);
	auto end1 = std::chrono::high_resolution_clock::now();

	auto start2 = std::chrono::high_resolution_clock::now();
	padalintiStudentus2Vector(s2, nuskriaustieji2);
	auto end2 = std::chrono::high_resolution_clock::now();
    
	auto start3 = std::chrono::high_resolution_clock::now();
	padalintiStudentus3Vector(s3, nuskriaustieji3);
	auto end3 = std::chrono::high_resolution_clock::now();

	rezultatai.strategija1 = std::chrono::duration<double>(end1 - start1).count();
	rezultatai.strategija2 = std::chrono::duration<double>(end2 - start2).count();
	rezultatai.strategija3 = std::chrono::duration<double>(end3 - start3).count();

    if (isvestiIFailus)
    {
		std::string failoVardas = gautiFailoVardaBePletinio(failoPavadinimas);


		isvestiStudentusIFailaVector(kietiakiai1, failoVardas + "_vector_strategija1_kietiakiai.txt");
		isvestiStudentusIFailaVector(nuskriaustieji1, failoVardas + "_vector_strategija1_nuskriaustieji.txt");

		isvestiStudentusIFailaVector(s2, failoVardas + "_vector_strategija2_kietiakiai.txt");
		isvestiStudentusIFailaVector(nuskriaustieji2, failoVardas + "_vector_strategija2_nuskriaustieji.txt");
		isvestiStudentusIFailaVector(s3, failoVardas + "_vector_strategija3_kietiakiai.txt");
		isvestiStudentusIFailaVector(nuskriaustieji3, failoVardas + "_vector_strategija3_nuskriaustieji.txt");
    }

	return rezultatai;
}

StrategijuRezultatai atliktiStrategijuTyrimaList(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, bool isvestiIFailus)
{
    StrategijuRezultatai rezultatai;

    std::list<Studentas> pradinis;
    skaitytiIsFailoList(failoPavadinimas, pradinis);
    skaiciuotiRezultatusList(pradinis, skaiciavimoTipas);
    rusiuotiStudentusList(pradinis, rusiavimoTipas);

    std::list<Studentas> s1 = pradinis;
    std::list<Studentas> s2 = pradinis;
    std::list<Studentas> s3 = pradinis;

    std::list<Studentas> nuskriaustieji1;
    std::list<Studentas> kietiakiai1;
    std::list<Studentas> nuskriaustieji2;
    std::list<Studentas> nuskriaustieji3;

    auto start1 = std::chrono::high_resolution_clock::now();
    padalintiStudentus1List(s1, nuskriaustieji1, kietiakiai1);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
   padalintiStudentus2List(s2, nuskriaustieji2);
    auto end2 = std::chrono::high_resolution_clock::now();
    
    auto start3 = std::chrono::high_resolution_clock::now();
   padalintiStudentus3List(s3, nuskriaustieji3);
    auto end3 = std::chrono::high_resolution_clock::now();

    rezultatai.strategija1 = std::chrono::duration<double>(end1 - start1).count();
    rezultatai.strategija2 = std::chrono::duration<double>(end2 - start2).count();
    rezultatai.strategija3 = std::chrono::duration<double>(end3 - start3).count();

    if (isvestiIFailus)
    {
		std::string failoVardas = gautiFailoVardaBePletinio(failoPavadinimas);

		isvestiStudentusIFailaList(kietiakiai1, failoVardas + "_list_strategija1_kietiakiai.txt");
		isvestiStudentusIFailaList(nuskriaustieji1, failoVardas + "_list_strategija1_nuskriaustieji.txt");

		isvestiStudentusIFailaList(s2, failoVardas + "_list_strategija2_kietiakiai.txt");
		isvestiStudentusIFailaList(nuskriaustieji2, failoVardas + "_list_strategija2_nuskriaustieji.txt");

		isvestiStudentusIFailaList(s3, failoVardas + "_list_strategija3_kietiakiai.txt");
		isvestiStudentusIFailaList(nuskriaustieji3, failoVardas + "_list_strategija3_nuskriaustieji.txt");
    }

    return rezultatai;
}

StrategijuRezultatai atliktiStrategijuTyrimaDeque(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, bool isvestiIFailus)
{
    StrategijuRezultatai rezultatai;

    std::deque<Studentas> pradinis;
    skaitytiIsFailoDeque(failoPavadinimas, pradinis);
    skaiciuotiRezultatusDeque(pradinis, skaiciavimoTipas);
    rusiuotiStudentusDeque(pradinis, rusiavimoTipas);

    std::deque<Studentas> s1 = pradinis;
    std::deque<Studentas> s2 = pradinis;
    std::deque<Studentas> s3 = pradinis;

    std::deque<Studentas> nuskriaustieji1;
    std::deque<Studentas> kietiakiai1;
    std::deque<Studentas> nuskriaustieji2;
    std::deque<Studentas> nuskriaustieji3;

    auto start1 = std::chrono::high_resolution_clock::now();
   padalintiStudentus1Deque(s1, nuskriaustieji1, kietiakiai1);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
   padalintiStudentus2Deque(s2, nuskriaustieji2);
    auto end2 = std::chrono::high_resolution_clock::now();
    
    auto start3 = std::chrono::high_resolution_clock::now();
   padalintiStudentus3Deque(s3, nuskriaustieji3);
    auto end3 = std::chrono::high_resolution_clock::now();

    rezultatai.strategija1 = std::chrono::duration<double>(end1 - start1).count();
    rezultatai.strategija2 = std::chrono::duration<double>(end2 - start2).count();
    rezultatai.strategija3 = std::chrono::duration<double>(end3 - start3).count();

    if (isvestiIFailus)
    {
		std::string failoVardas = gautiFailoVardaBePletinio(failoPavadinimas);

		isvestiStudentusIFailaDeque(kietiakiai1, failoVardas + "_deque_strategija1_kietiakiai.txt");
		isvestiStudentusIFailaDeque(nuskriaustieji1, failoVardas + "_deque_strategija1_nuskriaustieji.txt");

		isvestiStudentusIFailaDeque(s2, failoVardas + "_deque_strategija2_kietiakiai.txt");
		isvestiStudentusIFailaDeque(nuskriaustieji2, failoVardas + "_deque_strategija2_nuskriaustieji.txt");

		isvestiStudentusIFailaDeque(s3, failoVardas + "_deque_strategija3_kietiakiai.txt");
		isvestiStudentusIFailaDeque(nuskriaustieji3, failoVardas + "_deque_strategija3_nuskriaustieji.txt");
    }

    return rezultatai;
}

void atliktiKonteineriuTyrimaSuVidurkiu(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, int kartu)
{
    TyrimoRezultatai vectorVidurkis;
    TyrimoRezultatai listVidurkis;
    TyrimoRezultatai dequeVidurkis;

    for (int i = 0; i < kartu; i++)
    {


		TyrimoRezultatai v = atliktiVectorTyrima(failoPavadinimas, skaiciavimoTipas, rusiavimoTipas);
		TyrimoRezultatai l = atliktiListTyrima(failoPavadinimas, skaiciavimoTipas, rusiavimoTipas);
		TyrimoRezultatai d = atliktiDequeTyrima(failoPavadinimas, skaiciavimoTipas, rusiavimoTipas);
		vectorVidurkis.nuskaitymas += v.nuskaitymas;
		vectorVidurkis.rusiavimas += v.rusiavimas;
		vectorVidurkis.skirstymas += v.skirstymas;

		listVidurkis.nuskaitymas += l.nuskaitymas;
		listVidurkis.rusiavimas += l.rusiavimas;
		listVidurkis.skirstymas += l.skirstymas;

		dequeVidurkis.nuskaitymas += d.nuskaitymas;
		dequeVidurkis.rusiavimas += d.rusiavimas;
		dequeVidurkis.skirstymas += d.skirstymas;

    }
	vectorVidurkis.nuskaitymas /= kartu;
	vectorVidurkis.rusiavimas /= kartu;
	vectorVidurkis.skirstymas /= kartu;

	listVidurkis.nuskaitymas /= kartu;
	listVidurkis.rusiavimas /= kartu;
	listVidurkis.skirstymas /= kartu;

	dequeVidurkis.nuskaitymas /= kartu;
	dequeVidurkis.rusiavimas /= kartu;
	dequeVidurkis.skirstymas /= kartu;

    std::cout << "\n -------------------KONTEINERIU TYRIMO VIDURKIAI-----------------------------";

	std::cout << "\nVector:\n";
	std::cout << "Nuskaitymas: " << vectorVidurkis.nuskaitymas << " s\n";
	std::cout << "Rusiavimas: " << vectorVidurkis.rusiavimas << " s\n";
	std::cout << "Skirstymas: " << vectorVidurkis.skirstymas << " s\n";

	std::cout << "\nList:\n";
	std::cout << "Nuskaitymas: " << listVidurkis.nuskaitymas << " s\n";
	std::cout << "Rusiavimas: " << listVidurkis.rusiavimas << " s\n";
	std::cout << "Skirstymas: " << listVidurkis.skirstymas << " s\n";

	std::cout << "\nDeque:\n";
	std::cout << "Nuskaitymas: " << dequeVidurkis.nuskaitymas << " s\n";
	std::cout << "Rusiavimas: " << dequeVidurkis.rusiavimas << " s\n";
	std::cout << "Skirstymas: " << dequeVidurkis.skirstymas << " s\n";
}

void atliktiStrategijuTyrimaSuVidurkiu(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, int kartu)
{
	StrategijuRezultatai vectorVidurkis;
	StrategijuRezultatai listVidurkis;
	StrategijuRezultatai dequeVidurkis;

    for (int i = 0; i < kartu; i++)
    {
		bool isvestiIFailus = (i == kartu - 1); // Tik paskutinio bandymo metu isvesime i failus

		StrategijuRezultatai v = atliktiStrategijuTyrimaVector(failoPavadinimas, skaiciavimoTipas, rusiavimoTipas, isvestiIFailus);
		StrategijuRezultatai l = atliktiStrategijuTyrimaList(failoPavadinimas, skaiciavimoTipas, rusiavimoTipas, isvestiIFailus);
        StrategijuRezultatai d = atliktiStrategijuTyrimaDeque(failoPavadinimas, skaiciavimoTipas, rusiavimoTipas, isvestiIFailus);

		vectorVidurkis.strategija1 += v.strategija1;
		vectorVidurkis.strategija2 += v.strategija2;
		vectorVidurkis.strategija3 += v.strategija3;

		listVidurkis.strategija1 += l.strategija1;
		listVidurkis.strategija2 += l.strategija2;
		listVidurkis.strategija3 += l.strategija3;
		dequeVidurkis.strategija1 += d.strategija1;
		dequeVidurkis.strategija2 += d.strategija2;
		dequeVidurkis.strategija3 += d.strategija3;
    }
	vectorVidurkis.strategija1 /= kartu;
	vectorVidurkis.strategija2 /= kartu;
	vectorVidurkis.strategija3 /= kartu;

	listVidurkis.strategija1 /= kartu;
	listVidurkis.strategija2 /= kartu;
	listVidurkis.strategija3 /= kartu;

	dequeVidurkis.strategija1 /= kartu;
	dequeVidurkis.strategija2 /= kartu;
	dequeVidurkis.strategija3 /= kartu;

	std::cout << "\n -------------------SKIRSTYMO STRATEGIJU TYRIMO VIDURKIAI-----------------------------";
    
	std::cout << "\nVector:\n";
	std::cout << "Strategija 1: " << vectorVidurkis.strategija1 << " s\n";
	std::cout << "Strategija 2: " << vectorVidurkis.strategija2 << " s\n";
	std::cout << "Strategija 3: " << vectorVidurkis.strategija3 << " s\n";

	std::cout << "\nList:\n";
	std::cout << "Strategija 1: " << listVidurkis.strategija1 << " s\n";
	std::cout << "Strategija 2: " << listVidurkis.strategija2 << " s\n";
	std::cout << "Strategija 3: " << listVidurkis.strategija3 << " s\n";

	std::cout << "\nDeque:\n";
	std::cout << "Strategija 1: " << dequeVidurkis.strategija1 << " s\n";
	std::cout << "Strategija 2: " << dequeVidurkis.strategija2 << " s\n";
	std::cout << "Strategija 3: " << dequeVidurkis.strategija3 << " s\n";


}

void atliktiPushBackTyrima(unsigned int dydis)
{
    auto stdStart = std::chrono::high_resolution_clock::now();

    std::vector<int> v1;

    for (unsigned int i = 1; i <= dydis; ++i)
    {
        v1.push_back(i);
    }

    auto stdEnd = std::chrono::high_resolution_clock::now();

    auto manoStart = std::chrono::high_resolution_clock::now();

    Vector<int> v2;

    for (unsigned int i = 1 ; i <= dydis; ++i)
    {
        v2.push_back(i);
    }
    auto manoEnd = std::chrono::high_resolution_clock::now();


    std::chrono::duration<double> stdLaikas = stdEnd - stdStart;
    std::chrono::duration<double> manoLaikas = manoEnd - manoStart;

    std::cout << std::left << std::setw(15) << dydis
        << std::setw(20) << stdLaikas.count()
        << std::setw(20) << manoLaikas.count()
        << "\n";
}

void atliktiPushBackTyrimus()
{
    std::cout << "\nstd::vector<int> ir Vector<int> push_back tyrimas\n";
    std::cout << std::left << std::setw(15) << "Dydis"
        << std::setw(20) << "std::vector"
        << std::setw(20) << "Vector"
        << "\n";

    std::cout << "-------------------------------------------------------\n";

    atliktiPushBackTyrima(10000);
    atliktiPushBackTyrima(100000);
    atliktiPushBackTyrima(1000000);
    atliktiPushBackTyrima(10000000);
    atliktiPushBackTyrima(100000000);
}

void skaiciuotiPerskirstymus(unsigned int dydis)
{
    unsigned int stdPerskirstymai = 0;
    unsigned int manoPerskirstymai = 0;

    std::vector<int> v1;

    for (unsigned int i = 1; i <= dydis; ++i)
    {
        if (v1.capacity() == v1.size())
        {
            ++stdPerskirstymai;
        }

        v1.push_back(i);
    }

    Vector<int> v2;

    for (unsigned int i = 1; i <= dydis; ++i)
    {
        if (v2.capacity() == v2.size())
        {
            ++manoPerskirstymai;
        }

        v2.push_back(i);
    }

    std::cout << "\nPerskirstymu skaicius uzpildant " << dydis << " elementu:\n";
    std::cout << "std::vector: " << stdPerskirstymai << "\n";
    std::cout << "Vector: " << manoPerskirstymai << "\n";
}