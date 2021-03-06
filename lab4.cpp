// lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include "math.h"

using namespace std;


class Matrix
{

private:
	int **array;
	int size;
public:

	void InputMatrix();
	void OutputMatrix();
	void Sort();
	void MathmeticActions();
};

void Matrix::InputMatrix() {

	cout << "Enter size of matrix>>";
	cin >> size;
	array = new int *[size];
	for (int i = 0; i < size; i++) array[i] = new int[size];
	cout << "Enter matrix>>\n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> array[i][j];
		}
	}
}

void Matrix::OutputMatrix() {
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++)
		{
			printf("%5d", array[i][j]);
		}
		cout << endl;
	}
}

void Matrix::Sort()
{
	int i, k, j, c;
	for (j = 0; j < size; j++)
	{
		for (k = size - 1; k >= 0; k--)
		{
			for (i = 0; i < k; i++)
			{
				if (array[i][j] < array[i + 1][j])
				{
					c = array[i][j];
					array[i][j] = array[i + 1][j];
					array[i + 1][j] = c;
				}
			}
		}
	}
}

void Matrix::MathmeticActions()
{
	double sum = 0;
	double GeometricAverage;
	int j, i;
	double counter = 0;
	for (i = 0; i < size - 1; i++)
	{
		counter = 0;
		long product = 1;
		for (j = 0; j < size; j++)
		{
			if (i < j)
			{
				product *= array[i][j];
				counter++;
			}
		}
		GeometricAverage = pow(fabs(product), 1.0 / counter);
		cout << "Geometric average = " << GeometricAverage << endl;
		sum += GeometricAverage;
	}
	cout << "Sum = " << sum;
}

int _tmain(void)
{
	Matrix A;
	cout << "nInput elements of matrix A" << endl;
	A.InputMatrix();
	cout << "\nnewInput Matrix A " << endl;
	A.OutputMatrix();
	A.Sort();
	cout << "\nnewSorted Matrix A " << endl;
	A.OutputMatrix();
	A.MathmeticActions();
	_getch();
}


