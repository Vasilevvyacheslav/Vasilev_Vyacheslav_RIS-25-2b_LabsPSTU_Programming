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

void printState(int num, const string& phase, string f0, string f1, string f2) {
    cout << num << "." << phase << ":" << endl;
    cout << "F0: " << f0 << endl;
    cout << "F1: " << f1 << endl;
    cout << "F2: " << f2 << endl;
    cout << endl;
}

void Distribution(string path1, string path2, string main_path) {
    ofstream f1(path1, ios::trunc);
    ofstream f2(path2, ios::trunc);
    ifstream mainf(main_path);
    string temp, cur;
    int itemp, icur;

    if (!f1.is_open() || !f2.is_open()) {
        cout << "Error" << endl;
        return;
    }

    bool firstfile = true;
    mainf >> cur;
    while (!mainf.eof()) {
        if (firstfile) {
            f1 << cur << "\n";
            temp = cur;
            mainf >> cur;
            if (mainf.eof()) {
                f1 << "/" << "\n";
                break;
            }
            itemp = stoi(temp);
            icur = stoi(cur);
            while (itemp <= icur) {
                f1 << cur << "\n";
                temp = cur;
                mainf >> cur;
                if (mainf.eof()) {
                    f1 << "/" << "\n";
                    break;
                }
                itemp = stoi(temp);
                icur = stoi(cur);
            }
            f1 << "/" << "\n";
            firstfile = false;
        }
        else {
            f2 << cur << "\n";
            temp = cur;
            mainf >> cur;
            if (mainf.eof()) {
                f2 << "/" << "\n";
                break;
            }
            itemp = stoi(temp);
            icur = stoi(cur);
            while (itemp <= icur) {
                f2 << cur << "\n";
                temp = cur;
                mainf >> cur;
                if (mainf.eof()) {
                    f2 << "/" << "\n";
                    break;
                }
                itemp = stoi(temp);
                icur = stoi(cur);
            }
            f2 << "/" << "\n";
            firstfile = true;
        }
    }

    f1.close();
    f2.close();
    mainf.close();
}

void MergePass(string path1, string path2, string main_path) {
    ifstream f1(path1);
    ifstream f2(path2);
    ofstream mainf(main_path, ios::trunc);
    string temp1, temp2;
    int itemp1, itemp2;

    if (!f1.is_open() || !f2.is_open()) {
        cout << "Error" << endl;
        return;
    }

    while (!f1.eof()) {
        f1 >> temp1;
        f2 >> temp2;
        if (temp2 == "" || f2.eof()) return;

        while (temp1 != "/" || temp2 != "/") {
            if (temp1 == "/") {
                mainf << temp2 << "\n";
                f2 >> temp2;
                if (f2.eof()) break;
            }
            else if (temp2 == "/") {
                mainf << temp1 << "\n";
                f1 >> temp1;
                if (f1.eof()) break;
            }
            else {
                itemp1 = stoi(temp1);
                itemp2 = stoi(temp2);
                if (itemp1 <= itemp2) {
                    mainf << temp1 << "\n";
                    f1 >> temp1;
                    if (f1.eof()) break;
                }
                else {
                    mainf << temp2 << "\n";
                    f2 >> temp2;
                    if (f2.eof()) break;
                }
            }
        }
    }

    f1.close();
    f2.close();
    mainf.close();
}

bool isSorted(const string& filename) {
    ifstream file(filename);
    string num;
    vector<int> data;

    while (file >> num && num != "/") {
        data.push_back(stoi(num));
    }
    file.close();

    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

int main() {

    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int size, current;
    string result = "RESULT.txt", buff = "buffer.txt", datafile = "data.txt", temp;
    ifstream res;
    ofstream data;

    cout << "Введите размер массива: ";
    cin >> size;
    cout << endl << "Несортированные данные" << endl;

    data.open(datafile);
    for (int i = 0; i < size; i++) {
        current = rand() % 100;
        cout << current << " ";
        data << current << "\n";
    }
    data.close();

    cout << endl << endl;

    static int step = 0;
    printState(step++, "Merge", readFile(datafile), "пусто", "пусто");

    int maxIterations = 20;
    while (maxIterations-- > 0) {
        Distribution(buff, result, datafile);
        printState(step++, "Distribution",
            readFile(datafile), readFile(buff), readFile(result));

        MergePass(buff, result, datafile);
        printState(step++, "Merge",
            readFile(datafile), readFile(buff), readFile(result));

        if (isSorted(datafile)) break;
    }

    cout << "Отсортированные данные" << endl;
    res.open(datafile);

    int count = 0;
    while (res >> temp && count < size) {
        if (temp != "/") {
            cout << temp << " ";
            count++;
        }
    }

    res.close();
    cout << endl;

    return 0;
}
