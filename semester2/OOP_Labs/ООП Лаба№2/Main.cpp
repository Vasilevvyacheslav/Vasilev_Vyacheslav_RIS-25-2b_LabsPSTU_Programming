#include "Book.h"

Book make_book()
{
	string Name;
	string Author;
	int Date;
	cout << "\nВведите название книги: ";
	getline(cin, Name);

	cout << "Введите автора книги: ";
	getline(cin, Author);

	cout << "Введите год издания: ";
	cin >> Date;

	Book b(Name, Author, Date);
	return b;
}
void print_book(Book b)
{
	b.Show();
}
int main()
{
	setlocale(LC_ALL, "ru");
	Book book1;
	book1.Show();
	cout << "----------------------------------------------" << endl;

	Book book2("The Lord of the Rings", "J.R.R. Tolkien", 1954);
	book2.Show();
	cout << "----------------------------------------------" << endl;

	cout << "Первый способ копирования: Инициализация копированием" << endl;
	Book book3 = book2;
	book3.Show();
	cout << "----------------------------------------------" << endl;

	cout << "Второй способ копирования: Передача по значению" << endl;
	book3.setName("Harry Potter and the Philosopher's Stone");
	book3.setAuthor("J.K. Rowling");
	book3.setDate(1997);
	print_book(book3);
	cout << "----------------------------------------------" << endl;

	cout << "Третий способ копирования: Возврат объекта из функции" << endl;
	book1 = make_book();
	book1.Show();
	return 0;
}