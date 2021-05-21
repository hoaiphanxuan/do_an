#include<iostream>
#include<fstream>
#pragma warning(disable : 4996)
using namespace std;
int main()
{
    char t[50];
    cin >> t;
    char* a = new char[50];
    strcpy(a, t);
    char* b = a;
    cout << b;
    return 0;
}