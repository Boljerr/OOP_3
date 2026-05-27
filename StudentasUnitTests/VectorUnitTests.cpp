#include "pch.h"
#include "CppUnitTest.h"
#include "Studentas.h"
#include <utility>
#include <sstream>
#include <string>
#include <algorithm>

#include "Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorUnitTests
{
	TEST_CLASS(VectorUnitTests)
	{
	public:

		TEST_METHOD(VectorReserveIncreasesCapacity)
		{
			Vector<int> v;

			v.reserve(10);

			Assert::IsTrue(v.capacity() >= 10);
			Assert::IsTrue(v.size() == 0);
			Assert::IsTrue(v.empty());
		}

		TEST_METHOD(VectorReserveKeepsExistingElements)
		{
			Vector<int> v = { 1, 2, 3 };

			v.reserve(20);

			Assert::IsTrue(v.capacity() >= 20);
			Assert::IsTrue(v.size() == 3);
			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 2);
			Assert::IsTrue(v[2] == 3);
		}

		TEST_METHOD(VectorReserveDoesNotShrink)
		{
			Vector<int> v;

			v.reserve(10);
			v.reserve(5);

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

		TEST_METHOD(VectorEmptyWorks)
		{
			Vector<int> v;

			Assert::IsTrue(v.empty());
			Assert::IsTrue(v.size() == 0);

			v.push_back(5);

			Assert::IsFalse(v.empty());
			Assert::IsTrue(v.size() == 1);
		}

		TEST_METHOD(VectorDataWorks)
		{
			Vector<int> v;
			v.push_back(10);
			v.push_back(20);

			int* duomenys = v.data();

			Assert::IsTrue(duomenys[0] == 10);
			Assert::IsTrue(duomenys[1] == 20);

			duomenys[0] = 99;

			Assert::IsTrue(v[0] == 99);
		}

		TEST_METHOD(VectorFrontBackWork)
		{
			Vector<int> v;
			v.push_back(3);
			v.push_back(7);
			v.push_back(9);

			Assert::IsTrue(v.front() == 3);
			Assert::IsTrue(v.back() == 9);

			v.front() = 100;
			v.back() = 200;

			Assert::IsTrue(v[0] == 100);
			Assert::IsTrue(v[2] == 200);
		}

		TEST_METHOD(VectorFrontBackThrowWhenEmpty)
		{
			Vector<int> v;

			Assert::ExpectException<std::out_of_range>([&v]()
				{
					v.front();
				});

			Assert::ExpectException<std::out_of_range>([&v]()
				{
					v.back();
				});
		}
		TEST_METHOD(VectorAtWorks)
		{
			Vector<int> v = { 4, 5, 6 };

			Assert::IsTrue(v.at(0) == 4);
			Assert::IsTrue(v.at(1) == 5);
			Assert::IsTrue(v.at(2) == 6);

			v.at(1) = 50;

			Assert::IsTrue(v[1] == 50);
		}

		TEST_METHOD(VectorAtThrowsWhenIndexInvalid)
		{
			Vector<int> v = { 4, 5, 6 };

			Assert::ExpectException<std::out_of_range>([&v]()
				{
					v.at(3);
				});
		}
		TEST_METHOD(VectorCopyConstructorWorks)
		{
			Vector<int> pirmas = { 1, 2, 3 };

			Vector<int> antras(pirmas);

			Assert::IsTrue(antras.size() == 3);
			Assert::IsTrue(antras[0] == 1);
			Assert::IsTrue(antras[1] == 2);
			Assert::IsTrue(antras[2] == 3);

			pirmas[0] = 99;

			Assert::IsTrue(antras[0] == 1);
		}

		TEST_METHOD(VectorCopyAssignmentWorks)
		{
			Vector<int> pirmas = { 4, 5, 6 };
			Vector<int> antras;

			antras = pirmas;

			Assert::IsTrue(antras.size() == 3);
			Assert::IsTrue(antras[0] == 4);
			Assert::IsTrue(antras[1] == 5);
			Assert::IsTrue(antras[2] == 6);

			pirmas[0] = 99;

			Assert::IsTrue(antras[0] == 4);
		}

		TEST_METHOD(VectorMoveConstructorWorks)
		{
			Vector<int> pirmas = { 7, 8, 9 };

			Vector<int> antras(std::move(pirmas));

			Assert::IsTrue(antras.size() == 3);
			Assert::IsTrue(antras[0] == 7);
			Assert::IsTrue(antras[1] == 8);
			Assert::IsTrue(antras[2] == 9);

			Assert::IsTrue(pirmas.size() == 0);
			Assert::IsTrue(pirmas.capacity() == 0);
		}

		TEST_METHOD(VectorMoveAssignmentWorks)
		{
			Vector<int> pirmas = { 10, 11, 12 };
			Vector<int> antras;

			antras = std::move(pirmas);

			Assert::IsTrue(antras.size() == 3);
			Assert::IsTrue(antras[0] == 10);
			Assert::IsTrue(antras[1] == 11);
			Assert::IsTrue(antras[2] == 12);

			Assert::IsTrue(pirmas.size() == 0);
			Assert::IsTrue(pirmas.capacity() == 0);
		}
		TEST_METHOD(VectorDefaultConstructorWorks)
		{
			Vector<int> v;
			Assert::IsTrue(v.size() == 0);
			Assert::IsTrue(v.capacity() == 0);
		}
		TEST_METHOD(VectorSizeConstructorWorks)
		{
			Vector<int> v(5);
			Assert::IsTrue(v.size() == 5);
			Assert::IsTrue(v.capacity() == 5);
		}

		TEST_METHOD(VectorSizeAndValueConstructorWorks)
		{
			Vector<int> v(5, 10);
			Assert::IsTrue(v.size() == 5);
			Assert::IsTrue(v.capacity() == 5);

			for (std::size_t i = 0; i < v.size(); ++i)
			{
				Assert::IsTrue(v[i] == 10);
			}
		}
		TEST_METHOD(VectorInitializerListConstructorWorks)
		{
			Vector<int> v = { 1, 2, 3, 4, 5 };
			Assert::IsTrue(v.size() == 5);
			Assert::IsTrue(v.capacity() == 5);

			for (std::size_t i = 0; i < v.size(); ++i)
			{
				Assert::IsTrue(v[i] == i + 1);
			}
		}
		TEST_METHOD(VectorResizeMethodWorks)
		{
			Vector<int> v;

			v.resize(5);

			Assert::IsTrue(v.size() == 5);
			Assert::IsTrue(v.capacity() == 5);
		}
		TEST_METHOD(VectorResizeWithValueMethodWorks)
		{
			Vector<int> v;

			v.resize(5, 10);

			Assert::IsTrue(v.size() == 5);
			Assert::IsTrue(v.capacity() == 5);

			for (std::size_t i = 0; i < v.size(); ++i)
			{
				Assert::IsTrue(v[i] == 10);
			}
		}
		TEST_METHOD(VectorShrinkToFitMethodWorks)
		{
			Vector<int> v;

			v.reserve(10);

			v.push_back(5);
			v.push_back(10);

			v.shrink_to_fit();

			Assert::IsTrue(v.capacity() == 2);
		}
		
		TEST_METHOD(VectorInsertMethodWorks)
		{
			Vector<int> v;
			v.push_back(5);
			v.push_back(10);
			v.push_back(15);

			auto pozicija = v.insert(v.begin() + 1, 7);

			Assert::IsTrue(*pozicija == 7);
			Assert::IsTrue(v.size() == 4);
			Assert::IsTrue(v[1] == 7);
		}
		TEST_METHOD(VectorInsertMultipleElementsWorks)
		{
			Vector<int> v = { 1, 4 };

			auto it = v.insert(v.begin() + 1, 2, 9);

			Assert::IsTrue(v.size() == 4);
			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 9);
			Assert::IsTrue(v[2] == 9);
			Assert::IsTrue(v[3] == 4);
			Assert::IsTrue(*it == 9);
		}
		TEST_METHOD(VectorEraseOneElementWorks)
		{
			Vector<int> v = { 1, 2, 3, 4 };

			auto it = v.erase(v.begin() + 1);

			Assert::IsTrue(v.size() == 3);
			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 3);
			Assert::IsTrue(v[2] == 4);
			Assert::IsTrue(*it == 3);
		}

		TEST_METHOD(VectorEraseRangeWorks)
		{
			Vector<int> v = { 1, 2, 3, 4, 5 };

			auto it = v.erase(v.begin() + 1, v.begin() + 4);

			Assert::IsTrue(v.size() == 2);
			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 5);
			Assert::IsTrue(*it == 5);
		}
		TEST_METHOD(VectorSwapMethodWorks)
		{
			Vector<int> v1 = { 1, 2, 3 };
			Vector<int> v2 = { 4, 5, 6 };

			v1.swap(v2);

			Assert::IsTrue(v1.size() == 3);
			Assert::IsTrue(v1[0] == 4);
			Assert::IsTrue(v1[1] == 5);
			Assert::IsTrue(v1[2] == 6);

			Assert::IsTrue(v2.size() == 3);
			Assert::IsTrue(v2[0] == 1);
			Assert::IsTrue(v2[1] == 2);
			Assert::IsTrue(v2[2] == 3);
		}
		TEST_METHOD(VectorComparisonOperatorsWork)
		{
			Vector<int> pirmas = { 1, 2, 3 };
			Vector<int> antras = { 1, 2, 3 };
			Vector<int> trecias = { 1, 2, 4 };

			Assert::IsTrue(pirmas == antras);
			Assert::IsFalse(pirmas != antras);

			Assert::IsTrue(pirmas != trecias);
			Assert::IsFalse(pirmas == trecias);
		}
		TEST_METHOD(VectorAssignCountValueWorks)
		{
			Vector<int> v = { 1, 2, 3 };

			v.assign(4, 9);

			Assert::IsTrue(v.size() == 4);
			Assert::IsTrue(v[0] == 9);
			Assert::IsTrue(v[1] == 9);
			Assert::IsTrue(v[2] == 9);
			Assert::IsTrue(v[3] == 9);
		}

		TEST_METHOD(VectorAssignInitializerListWorks)
		{
			Vector<int> v = { 1, 2, 3 };

			v.assign({ 5, 6 });

			Assert::IsTrue(v.size() == 2);
			Assert::IsTrue(v[0] == 5);
			Assert::IsTrue(v[1] == 6);
		}
		TEST_METHOD(VectorInsertInitializerListWorks)
		{
			Vector<int> v = { 1, 4 };

			auto it = v.insert(v.begin() + 1, { 2, 3 });

			Assert::IsTrue(v.size() == 4);
			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 2);
			Assert::IsTrue(v[2] == 3);
			Assert::IsTrue(v[3] == 4);
			Assert::IsTrue(*it == 2);
		}
		TEST_METHOD(VectorPushBackMoveWorks)
		{
			Vector<std::string> v;
			std::string tekstas = "Jonas";

			v.push_back(std::move(tekstas));

			Assert::IsTrue(v.size() == 1);
			Assert::IsTrue(v[0] == "Jonas");
		}
		TEST_METHOD(VectorEmplaceBackWorks)
		{
			Vector<std::string> v;
			
			std::string& tekstas = v.emplace_back(5, 'a');

			Assert::IsTrue(v.size() == 1);
			Assert::IsTrue(v[0] == "aaaaa");
			Assert::IsTrue(tekstas == "aaaaa");
		}
		TEST_METHOD(VectorEmplaceWorks)
		{
			Vector<std::string> v;
			v.push_back("Jonas");
			v.push_back("Petras");

			auto it = v.emplace(v.begin() + 1, 3, 'x');

			Assert::IsTrue(v.size() == 3);
			Assert::IsTrue(v[0] == "Jonas");
			Assert::IsTrue(v[1] == "xxx");
			Assert::IsTrue(v[2] == "Petras");
			Assert::IsTrue(*it == "xxx");
		}

		TEST_METHOD(VectorInitializerListAssignmentWorks)
		{
			Vector<int> v;
			v.push_back(10);

			v = { 1, 2, 3 };

			Assert::IsTrue(v.size() == 3);
			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 2);
			Assert::IsTrue(v[2] == 3);
		}
		TEST_METHOD(VectorMaxSizeWorks)
		{
			Vector<int> v;

			Assert::IsTrue(v.max_size() > 0);
			Assert::IsTrue(v.max_size() >= v.capacity());
		}
		TEST_METHOD(VectorReserveTooLargeThrows)
		{
			Vector<int> v;

			Assert::ExpectException<std::length_error>([&v]()
				{
					v.reserve(v.max_size() + 1);
				});
		}
		TEST_METHOD(VectorBeginEndWork)
		{
			Vector<int> v = { 1, 2, 3 };

			auto it = v.begin();

			Assert::IsTrue(*it == 1);

			++it;
			Assert::IsTrue(*it == 2);

			++it;
			Assert::IsTrue(*it == 3);

			++it;
			Assert::IsTrue(it == v.end());
		}

		TEST_METHOD(VectorConstBeginEndWork)
		{
			const Vector<int> v = { 4, 5, 6 };

			auto it = v.cbegin();

			Assert::IsTrue(*it == 4);

			++it;
			Assert::IsTrue(*it == 5);

			++it;
			Assert::IsTrue(*it == 6);

			++it;
			Assert::IsTrue(it == v.cend());
		}

		TEST_METHOD(VectorWorksWithStdSort)
		{
			Vector<int> v = { 3, 1, 2 };

			std::sort(v.begin(), v.end());

			Assert::IsTrue(v[0] == 1);
			Assert::IsTrue(v[1] == 2);
			Assert::IsTrue(v[2] == 3);
		}
	};
}