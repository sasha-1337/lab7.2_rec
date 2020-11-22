#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2_rec/lab7_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;
			const int rowCount = 4;
			const int colCount = 4;

			int** a = new int* [rowCount];
			for (int i = 0; i < colCount; i++)
				a[i] = new int[colCount];

			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					a[i][j] = 0;

			t = Min(a, rowCount, colCount, 0, 0, 0, 0);
			Assert::AreEqual(t, 0);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;

		}
	};
}
