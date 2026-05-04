//#include <iostream>
//#include <cmath>  
//using namespace std;
//
//const int SIZE = 8;
//int arr[SIZE][SIZE]{};
//int attempt = 0;
//
//bool check(int row, int col)
//{
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = 0; j < SIZE; j++)
//        {
//            if (arr[i][j] == 1)
//            {
//                if (abs(row - i) == abs(col - j) || (row == i || col == j))
//                {
//                    return false;
//                }
//            }
//        }
//    }
//    return true;
//}
//void show()
//{
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = 0; j < SIZE; j++)
//        {
//            if (arr[i][j] == 1)
//            {
//                cout << "! ";
//            }
//            else if (!check(i, j))
//            {
//                cout << "# ";
//            }
//            else
//            {
//                cout << ". ";
//            }
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//bool found = false;
//void game(int row)
//{
//    if (found)
//    {
//        return;
//    }
//    if (row == SIZE)
//    {
//        found = true;
//        cout << "Полученный результат:\n\n";
//        show();
//        return;
//    }
//
//    for (int col = 0; col < SIZE; col++)
//    {
//        if (found)
//        {
//            return;
//        }
//        if (check(row, col))
//        {
//            arr[row][col] = 1;
//            show();
//            game(row + 1);
//
//            if (!found)
//            {
//                arr[row][col] = 0;
//                show();
//            }
//        }
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    game(0);
//    return 0;
//}