#include "pch.h"
#include "CppUnitTest.h"
#include "Studentas.h"
#include <utility>
#include <sstream>
#include <string>
#include <algorithm>

#include "Bendra.h"
#include "Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentasUnitTests
{
	bool compareStudentasByVardasTest(const Studentas& a, const Studentas& b)
	{
		return a.getVardas() < b.getVardas();
	}

	bool arKietiakasTest(const Studentas& studentas)
	{
		return studentas.getRezultatas() >= 5.0;
	}


	TEST_CLASS(StudentasUnitTests)
	{
	public:
		
		TEST_METHOD(DefaultConstructorCreatesObject)
		{
			Studentas studentas;
			Assert::IsTrue(true);
		}

		TEST_METHOD(CopyConstructorWorks)
		{
			Studentas pirmas("Jonas", "Jonaitis", {8, 9, 10}, 9);
			
			Studentas antras(pirmas);
			
			Assert::IsTrue(antras.getVardas() == "Jonas");
			Assert::IsTrue(antras.getPavarde() == "Jonaitis");
			Assert::IsTrue(antras.getEgzaminas() == 9);
			Assert::IsTrue(antras.getPazymiai().size() == 3);

			Assert::IsTrue(antras.getPazymiai()[0] == 8);
			Assert::IsTrue(antras.getPazymiai()[1] == 9);
			Assert::IsTrue(antras.getPazymiai()[2] == 10);
		}
		TEST_METHOD(CopyAssignmentOperatorWorks)
		{
			Studentas pirmas("Jonas", "Jonaitis", {8, 9, 10}, 9);
			Studentas antras;

			antras = pirmas;

			Assert::IsTrue(antras.getVardas() == "Jonas");
			Assert::IsTrue(antras.getPavarde() == "Jonaitis");
			Assert::IsTrue(antras.getEgzaminas() == 9);
			Assert::IsTrue(antras.getPazymiai().size() == 3);

			Assert::IsTrue(antras.getPazymiai()[0] == 8);
			Assert::IsTrue(antras.getPazymiai()[1] == 9);
			Assert::IsTrue(antras.getPazymiai()[2] == 10);
		}
		TEST_METHOD(MoveConstructorWorks)
		{
			Studentas pirmas("Jonas", "Jonaitis", {8, 9, 10}, 9);
			
			Studentas antras(std::move(pirmas));

			Assert::IsTrue(antras.getVardas() == "Jonas");
			Assert::IsTrue(antras.getPavarde() == "Jonaitis");
			Assert::IsTrue(antras.getEgzaminas() == 9);
			Assert::IsTrue(antras.getPazymiai().size() == 3);

			Assert::IsTrue(antras.getPazymiai()[0] == 8);
			Assert::IsTrue(antras.getPazymiai()[1] == 9);
			Assert::IsTrue(antras.getPazymiai()[2] == 10);
		}
		TEST_METHOD(MoveAssignmentOperatorWorks)
		{
			Studentas pirmas("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
			Studentas antras;

			antras = std::move(pirmas);

			Assert::IsTrue(antras.getVardas() == "Jonas");
			Assert::IsTrue(antras.getPavarde() == "Jonaitis");
			Assert::IsTrue(antras.getEgzaminas() == 9);
			Assert::IsTrue(antras.getPazymiai().size() == 3);

			Assert::IsTrue(antras.getPazymiai()[0] == 8);
			Assert::IsTrue(antras.getPazymiai()[1] == 9);
			Assert::IsTrue(antras.getPazymiai()[2] == 10);
		}
		TEST_METHOD(InputOperatorWorks)
		{
			std::stringstream input("Jonas Jonaitis 8 9 10 9");
			Studentas studentas;

			input >> studentas;

			Assert::IsTrue(studentas.getVardas() == "Jonas");
			Assert::IsTrue(studentas.getPavarde() == "Jonaitis");
			Assert::IsTrue(studentas.getEgzaminas() == 9);

			Assert::IsTrue(studentas.getPazymiai().size() == 3);
			Assert::IsTrue(studentas.getPazymiai()[0] == 8);
			Assert::IsTrue(studentas.getPazymiai()[1] == 9);
			Assert::IsTrue(studentas.getPazymiai()[2] == 10);
		}
		TEST_METHOD(OutputOperatorWorks)
		{
			Studentas studentas("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
			std::stringstream output;

			output << studentas;

			std::string tekstas = output.str();

			Assert::IsTrue(tekstas.find("Jonas") != std::string::npos);
			Assert::IsTrue(tekstas.find("Jonaitis") != std::string::npos);


		}

		TEST_METHOD(VectorCanStoreStudentasObjects)
		{
			Vector<Studentas> studentai;

			Studentas pirmas("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
			Studentas antras("Petras", "Petraitis", { 7, 8, 9 }, 8);

			studentai.push_back(pirmas);
			studentai.push_back(antras);

			Assert::IsTrue(studentai.size() == 2);

			Assert::IsTrue(studentai[0].getVardas() == "Jonas");
			Assert::IsTrue(studentai[0].getPavarde() == "Jonaitis");
			Assert::IsTrue(studentai[0].getPazymiai().size() == 3);
			Assert::IsTrue(studentai[0].getPazymiai()[0] == 8);
			Assert::IsTrue(studentai[1].getVardas() == "Petras");
			Assert::IsTrue(studentai[1].getPavarde() == "Petraitis");
			Assert::IsTrue(studentai[1].getPazymiai().size() == 3);
			Assert::IsTrue(studentai[1].getPazymiai()[0] == 7);
		}

		TEST_METHOD(VectorStudentasSortAndEraseWork)
		{
			Vector<Studentas> studentai;

			Studentas pirmas("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
			Studentas antras("Petras", "Petraitis", { 4, 5, 4 }, 4);
			Studentas trecias("Austeja", "Austejiene", { 10, 10, 9 }, 10);

			pirmas.setRezultatas(9.0);
			antras.setRezultatas(4.0);
			trecias.setRezultatas(10.0);

			studentai.push_back(pirmas);
			studentai.push_back(antras);
			studentai.push_back(trecias);

			std::sort(studentai.begin(), studentai.end(), compareStudentasByVardasTest);

			Assert::IsTrue(studentai[0].getVardas() == "Austeja");
			Assert::IsTrue(studentai[1].getVardas() == "Jonas");
			Assert::IsTrue(studentai[2].getVardas() == "Petras");

			auto it = studentai.erase(studentai.begin() + 1);

			Assert::IsTrue(studentai.size() == 2);
			Assert::IsTrue(studentai[0].getVardas() == "Austeja");
			Assert::IsTrue(studentai[1].getVardas() == "Petras");
		}

		TEST_METHOD(VectorStudentasStablePartitionWorks)
		{
			Vector<Studentas> studentai;

			Studentas pirmas("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
			Studentas antras("Petras", "Petraitis", { 4, 5, 4 }, 4);
			Studentas trecias("Austeja", "Austejiene", { 10, 10, 9 }, 10);

			pirmas.setRezultatas(9.0);
			antras.setRezultatas(4.0);
			trecias.setRezultatas(10.0);

			studentai.push_back(pirmas);
			studentai.push_back(antras);
			studentai.push_back(trecias);

			auto riba = std::stable_partition(studentai.begin(), studentai.end(), arKietiakasTest);

			Assert::IsTrue(riba == studentai.begin() + 2);
			Assert::IsTrue(studentai[0].getRezultatas() >= 5.0);
			Assert::IsTrue(studentai[1].getRezultatas() >= 5.0);
			Assert::IsTrue(studentai[2].getRezultatas() < 5.0);
		}

		TEST_METHOD(VectorStudentasCopyWorks)
		{
			Vector<Studentas> pirmas;

			Studentas jonas("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
			Studentas petras("Petras", "Petraitis", { 7, 8, 9 }, 8);

			pirmas.push_back(jonas);
			pirmas.push_back(petras);

			Vector<Studentas> antras = pirmas;

			Assert::IsTrue(antras.size() == 2);
			Assert::IsTrue(antras[0].getVardas() == "Jonas");
			Assert::IsTrue(antras[1].getVardas() == "Petras");

			pirmas[0].setVardas("Pakeistas");

			Assert::IsTrue(antras[0].getVardas() == "Jonas");
		}
	};
}
