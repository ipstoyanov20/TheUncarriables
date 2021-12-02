#include "pch.h"
#include "../TheUncarriables_Project/GameFunctions.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		
		TEST_METHOD(TestMethodThatTestGameOverWith0Value)
		{
			bool flag;

			flag = GameOver(0);

			Assert::IsTrue(!flag,L"Expected true");
		}
	};
}
