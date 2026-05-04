//#include <iostream>
//#include <clocale>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//const int ROW = 50, COL = 50;
//
//void FillArray(int arr[][COL], int n, int m) {
//	srand(time(0));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			/*cin >> arr[i][j];*/
//			arr[i][j] = rand() % 10;
//			cout << arr[i][j] << '\t';
//		}
//		cout << endl;
//	}
//}
//void ShowArray(int arr[][COL], int n, int m) {
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << arr[i][j] << '\t';
//		}
//		cout << endl;
//	}
//}
//
//void SortArray(int arr[][COL], int n, int m, int row)
//{
//	for (int i = 0; i < m - 1; i++) 
//	{
//		int min = arr[row-1][i];
//		int min_i = i;
//		for (int j = i + 1; j < m; j++) 
//		{
//			if (arr[row-1][j] < min) 
//			{
//				min = arr[row-1][j];
//				min_i = j;
//			}
//		}
//		for (int k = 0; k < n; k++) 
//		{
//			int temp = arr[k][i];
//			arr[k][i] = arr[k][min_i];
//			arr[k][min_i] = temp;
//			ShowArray(arr, n, m);
//		}
//	}
//}
//int main() {
//	setlocale(LC_ALL, "ru");
//
//	int arr[ROW][COL];
//	int n, m;
//	cout << "Введите кол-во строк и колонок массива: ";
//	
//	cin >> n >> m;
//
//	int row;
//	cout << "Введите по какой строке вы хотите отсортировать массив: ";
//	cin >> row;
//
//	FillArray(arr, n, m);
//	cout << endl;
//	SortArray(arr, n, m, row);
//
//	ShowArray(arr, n, m);
//	return 0;
//}