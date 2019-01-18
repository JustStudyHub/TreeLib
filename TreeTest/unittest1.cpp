#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TreeLib\Node.h"
#include "..\TreeLib\Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDfs)
		{
			Tree testTree;
			int size = 100;
			int temp1 = 0;
			int temp2 = 0;
			for (int i = 0; i < size; ++i)
			{
				temp1 = rand() % 100;
				testTree.Add(temp1);
				temp2 = testTree.Dfs(temp1)->GetValue();
				Assert::AreEqual(temp1, temp2);
			}
		}

		TEST_METHOD(TestBfs)
		{
			Tree testTree;
			int size = 100;
			int temp1 = 0;
			int temp2 = 0;
			for (int i = 0; i < size; ++i)
			{
				temp1 = rand() % 100;
				testTree.Add(temp1);
				temp2 = testTree.Dfs(temp1)->GetValue();
				Assert::AreEqual(temp1, temp2);
			}
		}

		TEST_METHOD(TestAdd)
		{
			Tree testTree;
			int size = 100;
			int temp1 = 0;
			int temp2 = 0;
			for (int i = 0; i < size; ++i)
			{
				temp1 = rand() % 100;
				testTree.Add(temp1);
				temp2 = testTree.Dfs(temp1)->GetValue();
				Assert::AreEqual(temp1, temp2);
			}
		}

		TEST_METHOD(TestPrint)
		{
			Tree testTree;
			int size = 100;
			int temp1 = 0;
			int temp2 = 0;
			for (int i = 0; i < size; ++i)
			{
				temp1 = rand() % 100;
				testTree.Add(temp1);
				temp2 = testTree.Dfs(temp1)->GetValue();
				Assert::AreEqual(temp1, temp2);
			}
		}
	};
}