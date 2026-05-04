#pragma once
#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <windows.h>
using namespace std;

string Names[10] = { "Александр", "Дмитрий", "Максим", "Сергей", "Андрей",
                            "Алексей", "Артем", "Илья", "Кирилл", "Михаил" };
string Surnames[10] = { "Иванов", "Смирнов", "Кузнецов", "Попов", "Васильев",
                              "Петров", "Соколов", "Михайлов", "Новиков", "Федоров" };
string Patronymics[10] = { "Александрович", "Дмитриевич", "Максимович", "Сергеевич", "Андреевич",
                             "Алексеевич", "Артемович", "Ильич", "Кириллович", "Михайлович" };
int ID = (rand() * 32768 + rand()) % 900000 + 100000;
string Dates[10] = { "06.10.2002", "14.02.2004", "23.06.2020", "22.07.2010", "09.10.2007",
                  "12.09.2019", "17.12.2015", "24.12.2004", "12.02.2020", "29.05.2009" };
int RandomNumber()
{
    return rand() % 10;
}
string RandomName()
{
    return Names[RandomNumber()];
}
string RandomSurname()
{
    return Surnames[RandomNumber()];
}
string RandomPatronymic()
{
    return Patronymics[RandomNumber()];
}
int RandomID()
{
    return (rand() * 32768 + rand()) % 900000 + 100000;
}
string RandomDate()
{
    return Dates[RandomNumber()];
}