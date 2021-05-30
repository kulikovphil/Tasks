#include <iostream>
#include <math.h>

using namespace std;

int FindLength(int number);
void cycle(string letterSet[][4], int numb, string str) ;
int RaiseToDegree(int base, int degree);
int NewNumb(int number);
int FirstDigit(int number);

int main()
    {
    setlocale(LC_ALL, "Russian");
    string letterSet[][4] = {{}, {}, {"a", "b", "c"}, {"d", "e", "f"},      {"g", "h", "i"}, {"j", "k", "l"},
                             {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}};


    int number;
    cout << "¬ведите число, содержащее не более шести цифр, \nв котором отсутствует цифра '1' (т.к. на неЄ нету букв): ";

    while (true)
        {
        cin >> number;

        if (number > 999999 || number < 2)
            {
            cout << "¬ведЄнное число не подходит под условие задачи, попробуйте ещЄ раз: ";
            }
        else break;
        }

    string str = "";

    cycle (letterSet, number, str);
    }

int FindLength(int number)
    {
    int digit = 1;
    while (number > 10)
        {
        number = number/10;
        digit++;
        }
    return digit;
    }

int RaiseToDegree(int base, int degree)
    {
    int save = 1;
    for(int i = 0; i < degree; i++)
        {
        save = save*base;
        }

    return save;
    }

int NewNumb(int number)
    {
    if (number < 10) return 0;
    else
        {
        int length = FindLength(number)-1;
        int degree = RaiseToDegree(10, length);
        return number%degree;
        }
    }

int FirstDigit(int number)
    {
    return number/RaiseToDegree(10,FindLength(number)-1);
    }

void cycle(string letterSet[][4], int numb, string str)
    {
    int size = 3;
    if (FirstDigit(numb) == 7 || FirstDigit(numb) == 9) size = 4;
    if (numb == 0)
        {
        cout << str << endl;
        }

    else
        {
        for (int i = 0; i < size; i++)
            {
            cycle(letterSet, NewNumb(numb), str + letterSet[FirstDigit(numb)][i]);
            }
        }
    }

