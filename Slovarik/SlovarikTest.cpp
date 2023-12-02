
#include "CppUnitTest.h"
#include "..//Slovarik/slovarik.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SlovarikTest
{
	TEST_CLASS(SlovarikTest)
	{
	public:
		
		TEST_METHOD(SizeCheckTest)
		{
			Slovarik slovar;
			slovar.add("banana", "banan");
			Assert::AreEqual(1, slovar.getSize());
			slovar.add("Mango", "mango");
			Assert::AreEqual(2, slovar.getSize());
		}

		TEST_METHOD(TranslateTest)
		{
			Slovarik slovar;
			slovar.add("apple", "yabloko");
			string word = slovar["apple"];
			string word_1 = "yabloko";
			Assert::AreEqual(word_1, word);
		}

		TEST_METHOD(DeleteTest)
		{
			Slovarik slovar;
			slovar.add("pine apple", "grusha");
			string word = "grusha";
			Assert::AreEqual(slovar.find("pine apple"), word);
			slovar.remove("pine apple");
			Assert::AreEqual(slovar.find("pine apple"), (string)"");
		}

		TEST_METHOD(ChangeTest)
		{
			Slovarik slovar;
			slovar.add("abergine", "kabachok");
			slovar.changeTranslation("aubergine", "baklazhan");
			Assert::IsTrue(slovar["aubergine"] == "baklazhan");
		}

		TEST_METHOD(FileTest)
		{
			Slovarik slovar;
			slovar.loadFile("C:/users/ivanm/desktop/Pernikov/Slovarik/UnitTest1/slovar.txt");
			Assert::AreEqual(slovar.find("pine-apple"), (string)"grusha");
		}
	};
}
