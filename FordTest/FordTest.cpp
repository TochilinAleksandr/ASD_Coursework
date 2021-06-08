#include "pch.h"
#include "CppUnitTest.h"
#include "..\course\Ford.h"
#include "..\course\course.cpp"
#define TEST_CASE_DIRECTORY GetDirectoryName(__FILE__)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FordTest
{
	TEST_CLASS(FordTest)
	{
		string GetDirectoryName(string path) {
			const size_t last_slash_idx = path.rfind('\\');
			if (std::string::npos != last_slash_idx)
			{
				return path.substr(0, last_slash_idx + 1);
			}
			return "";
		}
	public:

		TEST_METHOD(test1)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test1.txt";
			Ford test;
			test.inputData(fileName);
			Assert::AreEqual(test.MaxFlow(), 50);
		}
		TEST_METHOD(test2)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test2.txt";
			Ford test;
			test.inputData(fileName);
			Assert::AreEqual(test.MaxFlow(), 20);
		}
		TEST_METHOD(test3)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test3.txt";
			Ford test;
			test.inputData(fileName);
			Assert::AreEqual(test.MaxFlow(), 40);
		}
		TEST_METHOD(test4)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test4.txt";
			Ford test;
			test.inputData(fileName);
			Assert::AreEqual(test.MaxFlow(), 50);
		}
	};
}