#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void create(int** a, int col, int row, int l, int h);
void print(int** a, int row, int col);
void change(int** a, int row, int col);
int max(int** a, int row, int j);
int min(int** a, int row, int j);


void main() {
	srand((unsigned)time(NULL));

	int k = 10;
	int n = 6;

	int l = -15;
	int h = 15;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	create(a, n, k, l, h);

	print(a, k, n);

	change(a, k, n);

	print(a, k, n);
}

void create(int** a, int col, int row, int l, int h) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = l + rand() % (h - l + 1);
}

void print(int** a, int row, int col) {
	for (int i = 0; i < row; i++) {
		cout << "|";
		for (int j = 0; j < col; j++) {
			cout << setw(4) << a[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

void change(int** a, int row, int col) {
	int i_max;
	int i_min;
	int tmp;
	for (int j = 0; j <= col / 2; j++) {
		if (j % 2 == 1) {
			i_max = max(a, row, j - 1);
			i_min = min(a, row, j);
			tmp = a[i_max][j - 1];
			a[i_max][j - 1] = a[i_min][j];
			a[i_min][j] = tmp;
		}
	}
}

int max(int** a, int row, int j) {
	int i_max = 0;
	int a_max = a[0][0];
	for (int i = 0; i < row; i++) {
		if (a[i][j] > a_max) {
			a_max = a[i][j];
			i_max = i;
		}
	}
	return i_max;
}

int min(int** a, int row, int j) {
	int i_min = 0;
	int a_min = a[0][0];
	for (int i = 0; i < row; i++) {
		if (a[i][j] < a_min) {
			a_min = a[i][j];
			i_min = i;
		}
	}
	return i_min;
}