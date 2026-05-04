#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include <vector>
using namespace std;

string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return "пусто";

    string result, word;
    bool first = true;
    while (file >> word) {
        if (!first) result += "|";
        result += word;
        first = false;
    }
    file.close();
    return result.empty() ? "пусто" : result;
}

void printState(const string& label, string f0, string f1, string f2) {
    cout << label << ":" << endl;
    cout << "F0: " << f0 << endl;
    cout << "F1: " << f1 << endl;
    cout << "F2: " << f2 << endl;
    cout << endl;
}

int splitFile(fstream& A, fstream& B, fstream& C, int iterations) {
    int segments = 1;
    int counter = 0;
    bool flag = true;

    A.close();
    A.open("A.txt", ios::in);

    B.close();
    B.open("B.txt", ios::out);

    C.close();
    C.open("C.txt", ios::out);

    int current_elem;
    while (A >> current_elem) {
        if (counter == iterations) {
            counter = 0;
            flag = !flag;
            segments++;
        }

        if (flag) {
            B << current_elem << " ";
        }
        else {
            C << current_elem << " ";
        }
        counter++;
    }

    B << endl;
    C << endl;

    A.close();
    B.close();
    C.close();

    return segments;
}

int Merge(fstream& A, fstream& B, fstream& C, int iterations) {
    A.close();
    A.open("A.txt", ios::out);

    B.close();
    B.open("B.txt", ios::in);

    C.close();
    C.open("C.txt", ios::in);

    int counterB = 0, counterC = 0;
    int elementB, elementC;
    bool flagEnd = false;
    bool flagB = static_cast<bool>(B >> elementB);
    bool flagC = static_cast<bool>(C >> elementC);

    while (!flagEnd) {
        int current_elem;
        bool flag = false;

        if (!flagB && !flagC) {
            flagEnd = true;
        }
        else if (!flagB || counterB == iterations) {
            current_elem = elementC;
            flag = false;
        }
        else if (!flagC || counterC == iterations) {
            current_elem = elementB;
            flag = true;
        }
        else {
            if (elementB < elementC) {
                current_elem = elementB;
                flag = true;
            }
            else {
                current_elem = elementC;
                flag = false;
            }
        }

        if (!flagEnd) {
            A << current_elem << " ";

            if (flag) {
                counterB++;
                flagB = static_cast<bool>(B >> elementB);
            }
            else {
                counterC++;
                flagC = static_cast<bool>(C >> elementC);
            }

            if (counterB == iterations && counterC == iterations) {
                counterB = 0;
                counterC = 0;
            }
        }
    }

    A << endl;

    B.close();
    C.close();
    A.close();

    iterations *= 2;
    return iterations;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    cout << "\nНесортированные данные" << endl;

    fstream A, B, C;
    A.close();
    A.open("A.txt", ios::out);

    for (int i = 0; i < n; ++i) {
        int elem = rand() % 100;
        cout << elem << " ";
        A << elem << " ";
    }
    A << endl;
    A.close();

    cout << endl << endl;

    int _iterations = 1, _segments = -1;

    // Показываем начальное состояние
    printState("0.Merge", readFile("A.txt"), "пусто", "пусто");

    int step = 1;
    while (_segments != 1) {
        _segments = splitFile(A, B, C, _iterations);

        cout << step++ << ".Distribution:" << endl;
        cout << "iterations = " << _iterations << endl;
        printState("", readFile("A.txt"), readFile("B.txt"), readFile("C.txt"));

        if (_segments != 1) {
            _iterations = Merge(A, B, C, _iterations);

            cout << step++ << ".Merge:" << endl;
            cout << "iterations * 2 = " << _iterations << endl;
            printState("", readFile("A.txt"), readFile("B.txt"), readFile("C.txt"));
        }
    }

    cout << "\nОтсортированные данные: ";
    A.open("A.txt", ios::in);
    string temp;
    while (A >> temp) {
        cout << temp << " ";
    }
    A.close();
    cout << endl;

    return 0;
}