#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq,nlines = 0;
	DWORD nread = 1;
	char str[4096];
	
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	HANDLE f = CreateFile(L"a.txt", 0, 0, 0, OPEN_EXISTING, 0, 0);
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	bool bresult = true;
	while (!(bresult && nread == 0)){
		bresult = ReadFile(f, str, 4096, &nread, 0);
		for(DWORD i = 0; i < nread; i++){
			if (str[i] == '\n')
				nlines++;
		}
	}
	cout << fixed;
	cout.precision(3);

	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла
	CloseHandle(f);
	cout << "Time spent:" << (t2-t1)/(1.*freq) << "\nFile has " << nlines << " lines\n";
	return 0;
}