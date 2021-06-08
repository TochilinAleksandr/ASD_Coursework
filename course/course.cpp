#include <iostream>
#include "Ford.h"
using namespace std;

int main()
{   
    setlocale(LC_ALL, "RUS");
    cout << "Пожалуйста, напишите название файла: ";
    string filename;
    cin >> filename;
    Ford test;
    test.inputData(filename);
    int res = test.MaxFlow();
    cout << "Ответ:" << res;
}