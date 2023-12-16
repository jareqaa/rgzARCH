#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    int n;
    cin >> n;
    int **natrix1 = new int *[n];
    int **natrix2 = new int *[n];
    int **natrix3 = new int *[n];
    for (int i = 0; i < n; i++)
    {
        natrix1[i] = new int[n];
        natrix2[i] = new int[n];
        natrix3[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            natrix1[i][j] = rand() % 100;
            natrix2[i][j] = rand() % 100;
        }
    //длинное умножение матриц
    auto t1 = steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int a = 0; a < n; a++)
            {
                sum += natrix1[i][a] * natrix2[a][j];
            }
            natrix3[i][j] = sum;
        }
    }
    auto t2 = steady_clock::now();
    auto time = duration<double>(t2 - t1).count();
    cout << "Time slow: " << time << " sec." << endl;

    //быстрое умножение матриц
    t1 = steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int a = 0; a < n; a++)
            {
                sum += natrix1[i][a] * natrix2[j][a];
            }
            natrix3[i][j] = sum;
        }
    }
    t2 = steady_clock::now();
    time = duration<double>(t2 - t1).count();
    cout << "Time fast: " << time << " sec." << endl;
}