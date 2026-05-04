#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void upperFib(int n, int& a, int& b) {
    while (a + b < n) {
        int temp = a;
        a = a + b;
        b = temp;
    }
    cout << "Числа Фибоначчи для " << n << " серий: a=" << a << ", b=" << b << endl;
}

int countSeries(fstream& A) {
    A.close(); A.open("A.txt", ios::in);
    long long INF = 1e18;
    int current_elem, ret = 0;
    long long last = -INF;
    bool flagRead = static_cast<bool>(A >> current_elem);

    cout << "\n=== ПОДСЧЁТ СЕРИЙ ===" << endl;
    cout << "Исходный файл A: ";

    // Сохраняем позицию для повторного чтения
    streampos pos = A.tellg();

    while (flagRead) {
        cout << "[";
        while (flagRead && current_elem >= last) {
            cout << current_elem << " ";
            last = current_elem;
            flagRead = static_cast<bool>(A >> current_elem);
        }
        cout << "] ";
        last = -INF;
        ret++;
    }
    cout << "\nНайдено серий: " << ret << endl;

    return ret;
}

void splitFile(fstream& A, fstream& B, fstream& C, int first) {
    long long INF = 1e18;
    int counter = 0;
    bool flag = true;
    A.close(); A.open("A.txt", ios::in);
    B.close(); B.open("B.txt", ios::out);
    C.close(); C.open("C.txt", ios::out);
    int current_elem;
    long long last = -INF;
    bool flagRead = static_cast<bool>(A >> current_elem);

    cout << "\n=== РАСПРЕДЕЛЕНИЕ СЕРИЙ ===" << endl;
    cout << "Первые " << first << " серий идут в файл B, остальные в C" << endl;
    cout << "Файл B: ";
    int countB = 0, countC = 0;

    while (flagRead) {
        if (counter == first && first != 0) {
            first = 0;
            counter = 0;
            flag = !flag;
            cout << "\nФайл C: ";
        }
        if (flag) {
            cout << "[";
            while (flagRead && current_elem >= last) {
                cout << current_elem << " ";
                last = current_elem;
                B << current_elem << ' ';
                flagRead = static_cast<bool>(A >> current_elem);
            }
            cout << "] ";
            last = -INF;
            B << '/' << ' ';
            countB++;
        }
        else {
            cout << "[";
            while (flagRead && current_elem >= last) {
                cout << current_elem << " ";
                last = current_elem;
                C << current_elem << ' ';
                flagRead = static_cast<bool>(A >> current_elem);
            }
            cout << "] ";
            last = -INF;
            C << '/' << ' ';
            countC++;
        }
        counter++;
    }
    cout << "\nВ файле B: " << countB << " серий, в файле C: " << countC << " серий" << endl;
}

streampos Merge(fstream& A, fstream& B, fstream& C, string& big, string& lower, string& empty, int& a, int& b, int real_b, streampos s) {
    A.close(); B.close(); C.close();
    A.open(empty, ios::out);
    B.open(big, ios::in);
    C.open(lower, ios::in);
    C.seekg(s);

    cout << "\n=== ФАЗА СЛИЯНИЯ ===" << endl;
    cout << "Слияние " << big << " и " << lower << " в " << empty << endl;
    cout << "Сливаем " << real_b << " серий(и)" << endl;
    cout << "Числа Фибоначчи: a=" << a << ", b=" << b << endl;
    cout << "Результат слияния: ";

    string elementB, elementC;
    bool flagB;
    bool flagC;
    int count = 0;
    bool flagEnd = false;

    while (count < real_b && !flagEnd) {
        flagB = static_cast<bool>(B >> elementB);
        flagC = static_cast<bool>(C >> elementC);

        if (!flagB && !flagC) {
            flagEnd = true;
        }

        if (!flagEnd) cout << "[";

        while ((flagB && elementB != "/") || (flagC && elementC != "/")) {
            int current_elem = 0;
            bool flag = false;

            if (!flagB || elementB == "/") {
                current_elem = stoi(elementC);
            }
            else if (!flagC || elementC == "/") {
                current_elem = stoi(elementB);
                flag = true;
            }
            else {
                if (stoi(elementB) < stoi(elementC)) {
                    current_elem = stoi(elementB);
                    flag = true;
                }
                else {
                    current_elem = stoi(elementC);
                }
            }

            if (!flagEnd) {
                cout << current_elem << " ";
                A << current_elem << ' ';
                if (flag) {
                    flagB = static_cast<bool>(B >> elementB);
                }
                else {
                    flagC = static_cast<bool>(C >> elementC);
                }
            }
        }

        if (!flagEnd) {
            cout << "] ";
            A << '/' << ' ';
            count++;
        }
    }

    cout << "\nСлито серий: " << count << endl;

    int temp = a;
    a = b;
    b = temp - b;

    cout << "Новые числа Фибоначчи: a=" << a << ", b=" << b << endl;
    cout << "Файлы меняются ролями: " << big << " -> empty, " << empty << " -> big, " << lower << " -> empty" << endl;

    string temp_name = big;
    big = empty;
    empty = lower;
    lower = temp_name;

    streampos new_pos = B.tellg();
    cout << "Новая позиция в файле " << big << ": " << new_pos << endl;

    return new_pos;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    fstream A, B, C;

    // Создание исходного файла
    A.open("A.txt", ios::out);
    cout << "Сгенерированная последовательность: ";
    for (int i = 0; i < n; ++i) {
        int elem = rand() % 101;
        cout << elem << ' ';
        A << elem << ' ';
    }
    A.close();
    cout << '\n';

    // Подсчёт серий
    int series = countSeries(A);

    // Вычисление чисел Фибоначчи
    int a = 1, b = 0;
    upperFib(series, a, b);

    int first = a - (a + b - series) / 2;
    cout << "\nПервое распределение: " << first << " серий в файл B" << endl;

    // Инициализация имён файлов
    string name1 = "B.txt", name2 = "C.txt", name3 = "A.txt";

    // Распределение серий
    splitFile(A, B, C, first);

    streampos s = 0;
    int real_b = -1;
    int phase = 0;

    while (a != 1 || b != 0) {
        phase++;
        cout << "\n==========================================" << endl;
        cout << "ФАЗА " << phase << endl;
        cout << "==========================================" << endl;

        real_b = (real_b == -1 ? series - first : b);
        s = Merge(A, B, C, name1, name2, name3, a, b, real_b, s);
    }

    // Вывод отсортированного файла
    A.close(); B.close(); C.close();
    fstream result;
    result.open("A.txt", ios::in);

    cout << "\n=== РЕЗУЛЬТАТ СОРТИРОВКИ ===" << endl;
    cout << "Отсортированная последовательность: ";
    string elem;
    while (result >> elem) {
        if (elem != "/") {
            cout << elem << " ";
        }
    }
    cout << endl;

    result.close();

   return 0;
}