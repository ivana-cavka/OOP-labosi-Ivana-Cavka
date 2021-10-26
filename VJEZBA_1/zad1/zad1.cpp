// zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//CONSOLE APP
//using namespace std;
//taskkill /F /IM ApplicationName.exe    (command prompt)
//set as a startup project

#include <iostream>
#include <iomanip>
using namespace std;
int main()
    {
        bool flag;
        cout << "unesi " << true << " - " << false << endl;
        cin >> flag;
        cout << boolalpha << flag << endl;
        int a = 200;
        cout << "hex " << hex << a << endl;
        cout << "dec " << dec << a << endl;
        cout << "oct " << oct << a << endl;
        /*double pi = 3.141592;
        std::cout << "pi = " << std::scientific << std::uppercase;
        std::cout << std::setprecision(7) << std::setw(20) << std::setfill('0');
        std::cout << pi << std::endl;*/
    }



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
