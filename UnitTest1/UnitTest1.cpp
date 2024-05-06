#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.5/LAB_12.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestGetElementAtPosition)
        {
            stack<int> testStack;
            testStack.push(10);
            testStack.push(20);
            testStack.push(30);

            Assert::AreEqual(20, getElementAtPosition(testStack, 2)); // Перевірка, чи правильно повертається елемент за позицією
            Assert::AreEqual(-1, getElementAtPosition(testStack, 5)); // Перевірка, якщо позиція не знайдена
        }

        TEST_METHOD(TestSearchValueInStack)
        {
            stack<int> testStack;
            testStack.push(10);
            testStack.push(20);
            testStack.push(30);

            Assert::IsTrue(searchValueInStack(testStack, 20)); // Перевірка, чи правильно знаходиться значення в стеці
            Assert::IsFalse(searchValueInStack(testStack, 40)); // Перевірка, якщо значення не знайдено
        }
    };
}