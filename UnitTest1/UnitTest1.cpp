#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr7.2ITER/Pr7.2ITER.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourUnitTestNamespace // Замініть YourUnitTestNamespace на ваше ім'я простору імен
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCreateAndPrint)
        {
            const int n = 3; // Задайте розмір матриці для тестування
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++)
                testMatrix[i] = new int[n];

            // Викликайте функцію Create для заповнення матриці
            Create(testMatrix, n, 0, 10); // Можна задати інші межі діапазону

            // Викликайте функцію Print для виведення матриці
            Print(testMatrix, n);

            // Звільніть виділену пам'ять
            for (int i = 0; i < n; i++)
                delete[] testMatrix[i];
            delete[] testMatrix;
        }

        TEST_METHOD(TestSumOfSecondaryDiagonal)
        {
            const int n = 3; // Задайте розмір матриці для тестування
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++)
                testMatrix[i] = new int[n];

            // Заповніть тестову матрицю вручну з відомими значеннями
            testMatrix[0][0] = 1;
            testMatrix[0][1] = 2;
            testMatrix[0][2] = 3;
            testMatrix[1][0] = 4;
            testMatrix[1][1] = 5;
            testMatrix[1][2] = 6;
            testMatrix[2][0] = 7;
            testMatrix[2][1] = 8;
            testMatrix[2][2] = 9;

            // Очікуване значення суми побічної діагоналі
            int expectedSum = 15;

            // Викликайте функцію, яку ви тестуєте
            int actualSum = SumOfSecondaryDiagonal(testMatrix, n);

            // Перевірте, чи результат співпадає з очікуваним результатом
            Assert::AreEqual(expectedSum, actualSum);

            // Звільніть виділену пам'ять
            for (int i = 0; i < n; i++)
                delete[] testMatrix[i];
            delete[] testMatrix;
        }
    };
}
