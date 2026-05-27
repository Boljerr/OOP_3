#include "pch.h"
#include "CppUnitTest.h"
#include "Studentas.h"
#include <utility>
#include <sstream>
#include <string>

#include "Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorUnitTests
{
	TEST_CLASS(VectorUnitTests)
	{
	public:

		TEST_METHOD(ReserveMethodWorks)
		{
			Vector<int> v;
			v.reserve(10);
			Assert::IsTrue(v.capacity() == 10);
		}
		TEST_METHOD(PushBackMethodWorks)
		{
			Vector<int> v;
			v.push_back(5);
			Assert::IsTrue(v.size() == 1);
			Assert::IsTrue(v[0] == 5);
		}
		TEST_METHOD(PopBackMethodWorks)
		{
			Vector<int> v;
			v.push_back(5);
			v.pop_back();
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(ClearMethodWorks)
		{
			Vector<int> v;
			v.push_back(5);
			v.clear();
			Assert::IsTrue(v.size() == 0);
		}
		TEST_METHOD(VectorCopyConstructorWorks)
		{
			Vector<int> pirmas;
			pirmas.push_back(4);
			pirmas.push_back(7);

			Vector<int> antras(pirmas);

			Assert::IsTrue(antras.size() == 2);
			Assert::IsTrue(antras[0] == 4);
			Assert::IsTrue(antras[1] == 7);
		}
		TEST_METHOD(VectorCopyAssignmentOperatorWorks)
		{
			Vector<int> pirmas;
			pirmas.push_back(4);
			pirmas.push_back(7);

			Vector<int> antras;
			antras = pirmas;

			Assert::IsTrue(antras.size() == 2);
			Assert::IsTrue(antras[0] == 4);
			Assert::IsTrue(antras[1] == 7);
		}
	};
}
