#include "pch.h"
#include "CppUnitTest.h"
#include "..//Slovarik/header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(SizeCheckTest)
		{
			Dictionary slovar;
			slovar.add("banana", "banan");
			Assert::AreEqual(1, slovar.getSize());
			slovar.add("Mango", "mango");
			Assert::AreEqual(2, slovar.getSize());
		}

		TEST_METHOD(TranslateTest)
		{
			Dictionary slovar;
			slovar.add("apple", "yabloko");
			string word = slovar["apple"];
			string word_1 = "yabloko";
			Assert::AreEqual(word_1, word);
		}

		TEST_METHOD(DeleteTest)
		{
			Dictionary slovar;
			slovar.add("pine apple", "grusha");
			string word = "grusha";
			Assert::AreEqual(slovar.find("pine apple"), word);
			slovar.remove("pine apple");
			Assert::AreEqual(slovar.find("pine apple"), (string)"");
		}

		TEST_METHOD(ChangeTest)
		{
			Dictionary slovar;
			slovar.add("abergine", "kabachok");
			slovar.changeTranslation("aubergine", "baklazhan");
			Assert::IsTrue(slovar["aubergine"] == "baklazhan");
		}

		TEST_METHOD(FileTest)
		{
			Dictionary slovar;
			slovar.loadFile("C:/users/ivanm/desktop/Pernikov/Slovarik/UnitTest1/slovar.txt");
			Assert::AreEqual(slovar.find("pine-apple"), (string)"grusha");
			//Assert::AreEqual(2, slovar.getSize());
		}
	};
}
