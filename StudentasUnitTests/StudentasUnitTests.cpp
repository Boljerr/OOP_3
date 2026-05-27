#include "pch.h"
#include "CppUnitTest.h"
#include "Studentas.h"
#include <utility>
#include <sstream>
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentasUnitTests
{
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
	};
}
