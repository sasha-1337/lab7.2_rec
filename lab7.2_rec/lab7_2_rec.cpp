#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int row, const int col, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < col - 1)
		Create(a, row, col, Low, High, i, j+1);
	else 
		if (i < row - 1)
			Create(a, row, col, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int Min(int** a, const int rowCount, const int colCount,int imin,int min,int i, int j)
{
	if ((j % 2) && a[i][j] < min) 
	{
		min = a[i][j];
		imin = j;
	}
	if (i < rowCount - 1)
		Min(a, rowCount, colCount, imin, min, i + 1, j);
	else
		if (j < colCount - 1) {
			min = a[0][j];
			Min(a, rowCount, colCount, imin, min, 0, j + 1);
		}
		else
			return imin;
}

int Max(int** a, const int rowCount, const int colCount, int imax, int max, int i, int j) 
{
	if (!(j % 2) && a[i][j] < max)
	{
		max = a[i][j];
		imax = j;
	}
	if (i < rowCount - 1)
		Max(a, rowCount, colCount, imax, max, i + 1, j);
	else
		if (j < colCount - 1) {
			max = a[0][j];
			Max(a, rowCount, colCount, imax, max, 0, j + 1);
		}
		else
			return imax;
}

void change(int** a, const int rowCount, int imax, int imin, int i) 
{
	int tmp = a[i][imin];
	a[i][imin] = a[i][imax];
	a[i][imax] = tmp;
	if (i < rowCount - 1)
		change(a, rowCount, imax, imin, i + 1);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = -5;
	int High = 5;

	int k;
	cout << " k = "; cin >> k; // row
	int n;
	cout << " n = "; cin >> n; // col

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	cout << " Створений масив: " << endl;
	Create(a, k, n, Low, High, 0, 0);
	Print(a, k, n, 0, 0);  

	int imin = Min(a, k, n,0,0,0,0);
	int imax = Max(a, k, n,0,0,0,0);

	cout << " Mодифікований: " << endl;
	change(a, k, imax, imin, 0);
	Print(a, k, n, 0, 0);

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
