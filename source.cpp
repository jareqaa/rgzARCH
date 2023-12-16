#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    system("chcp 1251");
    int n;
    cin >> n;
    int **matrix1 = new int *[n];
    int **matrix2 = new int *[n];
    int **matrix3 = new int *[n];
    int **matrixTransp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrixTransp[i] = new int[n];
        matrix1[i] = new int[n];
        matrix2[i] = new int[n];
        matrix3[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }

    // длинное кмножение матриц
    auto t1 = steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int a = 0; a < n; a++)
            {
                sum += matrix1[i][a] * matrix2[a][j];
            }
            matrix3[i][j] = sum;
        }
    }
    auto t2 = steady_clock::now();
    auto time = duration<double>(t2 - t1).count();
    cout << "Time slow: " << time << " sec." << endl;

    // транспонирование матрицы
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrixTransp[j][i] = matrix2[i][j];

    // быстрое умножение матриц
    t1 = steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int a = 0; a < n; a++)
            {
                sum += matrix1[i][a] * matrix2[j][a];
            }
            matrix3[i][j] = sum;
        }
    }
    t2 = steady_clock::now();
    time = duration<double>(t2 - t1).count();
    cout << "Time fast: " << time << " sec." << endl;
}