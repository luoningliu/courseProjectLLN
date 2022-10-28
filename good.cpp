#include<istream>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class good
{
private:
	int ID;
	string name;
	double price;
	int num;
};

void testByChar()
{
    fstream testByCharFile;
    char c;
    testByCharFile.open("good.txt", ios::in);
    while (!testByCharFile.eof())
    {
        testByCharFile >> c;
        cout << c;
    }
    testByCharFile.close();
}


int main()
{
    testByChar();
}