#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int Nhap(int*&, int&, const string&);
int Xuat(int*, int, const string&);
void Interchange_sort(int[], int);

int main()
{
	for (int i = 1; i <= 13; ++i) {
		string file_name = "intdata";
		if (i < 10) {
			file_name += "0";
		}
		string num_file = to_string(i);
		string file_in = file_name + num_file + ".inp";
		string file_out = file_name + num_file + ".out";
		int* arr;
		int n;
		cout << Nhap(arr, n, file_in);
		Interchange_sort(arr, n);
		cout << Xuat(arr, n, file_out);
	}
	return 0;
}

int Nhap(int*& a, int& n, const string& file_in) {
	ifstream fi(file_in);
	if (fi.fail() == true) {
		return 0;
	}
	fi >> n;
	a = new int[n];
	for (int i = 0; i < n; ++i) {
		fi >> a[i];
	}
	return 1;
}
int Xuat(int* a, int n, const string& file_out) {
	ofstream fo(file_out);
	if (fo.fail() == true) {
		return 0;
	}
	fo << n << endl;
	for (int i = 0; i < n; ++i) {
		fo << a[i] << "   ";
	}
	delete[] a;
	return 1;
}

void Interchange_sort(int a[], int n) {
	for (int i = n - 1; i >= 1; i--)
		for (int j = 0; j <= i - 1; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
}
