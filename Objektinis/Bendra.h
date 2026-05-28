	#pragma once
#include "Studentas.h"
#include <string>
#include <vector>
#include "Vector.h"

double calculateAverage(const std::vector<int>& grade);
double calculateAverage(const Vector<int>& grade);
double calculateMedian(std::vector<int> grade);
double calculateMedian(Vector<int> grade);
double calculateFinal(double ndReiksme, int egzaminas);


int ivestiIntSuValidacija(const std::string& zinute, int min, int max);
std::string ivestiVardaArPavarde(const std::string& zinute);

int pasirinktiSkaiciavimoTipa();
int pasirinktiRusiavimoTipa();

std::string gautiFailoVardaBePletinio(const std::string& failoPavadinimas);

bool compareByVardas(const Studentas& a, const Studentas& b);
bool compareByPavarde(const Studentas& a, const Studentas& b);
bool compareByRezultatas(const Studentas& a, const Studentas& b);
bool arKietiakas(const Studentas& studentas);