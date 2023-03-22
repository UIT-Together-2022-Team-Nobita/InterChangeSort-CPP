#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool Input(float[], int&, string);
void InterchangeSort(float[], int);
bool Output(float[], int, string);

int main()
{
	static float a[1000000];
	int n;
	cout << "Project G2" << endl;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "floatdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Input(a, n, filenameinp) == true)
		{
			InterchangeSort(a, n);
			string filenameout = filename;
			filenameout += ".outp";
			Output(a, n, filenameout);
			cout << "\nImport	" << filenameinp << "		successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else
			cout << "\nCan't open the file" << filename << endl;
	}
	cout << endl;
	return 1206;
}

bool Input(float a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return true;
}

void InterchangeSort(float a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

bool Output(float a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i];
	return true;
}