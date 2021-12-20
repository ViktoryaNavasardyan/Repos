#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");



int main()
{
	//freopen("file.in", "r", stdin); 
	//freopen("file.out", "w", stdout);
	int count;
	//fout << "nermucel ararkaneri qanaky" << endl;
	fin >> count;
	int sumkredit = 0;
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		int kredit;
		//fout << "nermucel "<< i+1 <<"ararkayi kredity" << endl;
		fin >> kredit;
		sumkredit += kredit;
		int gnahatakan;
		//fout << "nermucel gnahatakanay" << endl;
		fin >> gnahatakan;
		sum = sum + (gnahatakan * kredit);
	}
	fout << "mogy = " << sum / sumkredit;
	return 0;
}