#include <iostream>
#include <string>

using namespace std;

//функция меню проргаммы
void menu();

class Product {
private:
	int m_id;
	string m_name;
	int m_UPC;
	string m_manufacturer;
	float m_price;
	int m_shelf_life;
	int m_count;
public:
	//консутктор по умолчанию
	Product() {}

	//конструктор с параметрами
	Product(int id, string name, int UPC, string manufacturer, float price, int shelf_life, int count) :
		m_id(id), m_name(name), m_UPC(UPC), m_manufacturer(manufacturer), m_price(price), m_shelf_life(shelf_life), m_count(count) {
		cout << "обьект успешно создан!" << endl;
	}

	//сеттер
	void setProduct(int new_id, string new_name, int new_UPC, string new_manufacturer, float new_price, int new_shelf_life, int new_count) {
		m_id = new_id;
		m_name = new_name;
		m_UPC = new_UPC;
		m_manufacturer = new_manufacturer;
		m_price = new_price;
		m_shelf_life = new_shelf_life;
		m_count = new_count;
		cout << "атрибуты обьекта успешно перезаписаны!" << endl;
	}

	//геттеры для всех свойств класса
	int getId() const {
		return m_id;
	}

	string getName() const {
		return m_name;
	}

	int getUPC() const {
		return m_UPC;
	}

	string getManufacturer() const {
		return m_manufacturer;
	}

	float getPrice() const {
		return m_price;
	}

	int getShelf_life() const {
		return m_shelf_life;
	}

	int getCount() const {
		return m_count;
	}

	//метод для вывод информации о атрибутах обьекта класса
	void showInformation() const {
		cout << "id: " << m_id << endl;
		cout << "name: " << m_name << endl;
		cout << "UPC: " << m_UPC << endl;
		cout << "manufacturer: " << m_manufacturer << endl;
		cout << "price: " << m_price << endl;
		cout << "shelf_life: " << m_shelf_life << endl;
		cout << "count: " << m_count << endl;
	}
};

int main(void) {
	setlocale(LC_ALL, "RU");

	int size;

	do {
		cout << "введите размерность массива обьктов класса(1 - 10): ";
		cin >> size;
		if (size > 10 || size < 1) {
			cout << "Ошибка, вы ввели недопустимое число!" << endl;
		}
	} while (size > 10 || size < 1);

	//создание массива обьектов класса
	Product* array = new Product[size];

	int id;
	string name;
	int UPC;
	string manufacturer;
	float price;
	int shelf_life;
	int count;

	//ввод атрибутов обьектов
	for (int i = 0; i < size; i++) {
		cout << "ввод атрибутов для " << i + 1 << " обьекта." << endl;
		cout << "id: "; cin >> id;
		cout << "name: "; cin.ignore(); getline(cin, name);
		cout << "UPC: "; cin >> UPC;
		cout << "manufacturer: "; cin.ignore(); getline(cin, manufacturer);
		cout << "price: "; cin >> price;
		cout << "shelf life" << endl;  cin >> shelf_life;
		cout << "count: "; cin >> count;
		array[i].setProduct(id, name, UPC, manufacturer, price, shelf_life, count);
		cout << "Обьект " << i + 1 << " успешно создан" << endl;
	}

	int choice;

	while (true) {
		menu();

		do {
			cout << "Ваш выбор: ";
			cin >> choice;
			if (choice > 4 || choice < 1) {
				cout << "Ошибка, введите другое число";
			}
		} while (choice > 4 || choice < 1);

		switch (choice) {
		case 1: {
			//поиск товаров по наименованию
			string search_name;
			bool found = false; //переменная для проверки существует ли товар с таким наименованием
			cin.ignore(); //очищаю буфер перед вводом наименования в переменную
			cout << "Введите найменование: ";
			getline(cin, search_name);

			for (int i = 0; i < size; i++) {
				if (array[i].getName() == search_name) {
					cout << "Товар найден!" << endl;
					array[i].showInformation();
					found = true;
				}
			}

			if (found == false) {
				cout << "Товары под наименованием " << search_name << " не найдены";
			}
			break;
		}
		case 2: {
			//поиск товаров для заданного наименования, цена которых не превосходит заданную
			string search_name;
			float search_price;
			bool found = false;
			cin.ignore();
			cout << "Введите найменование: ";
			getline(cin, search_name);
			do {
				cout << "Введите цену: ";
				cin >> search_price;
				if (search_price < 0) {
					cout << "Ошибка, цена не может быть отрицательной!" << endl;
				}
			} while (search_price < 0);

			for (int i = 0; i < size; i++) {
				if (array[i].getPrice() <= search_price && array[i].getName() == search_name) {
					cout << "обьект найден" << endl;
					array[i].showInformation();
					found = true;
				}
			}

			if (found == false) {
				cout << "Товаров c найменованием - " << search_name << " и с ценой не превосходящей " << search_price << " не найдено!" << endl;
			}
			break;
		}
		case 3: {
			//поиск товаров, срок хранения которых больше заданного
			int search_shelf_life;
			bool found = false;
			do {
				cout << "Введите срок хранения: ";
				cin >> search_shelf_life;
				if (search_shelf_life < 0) {
					cout << "Ошибка! Срок хранения не может быть меньше 0!" << endl;
				}
			} while (search_shelf_life < 0);

			for (int i = 0; i < size; i++) {
				if (array[i].getShelf_life() > search_shelf_life) {
					cout << "обьект найден" << endl;
					array[i].showInformation();
					found = true;
				}
			}

			if (found == false) {
				cout << "Товаров, срок хранения которых больше " << search_shelf_life << " не найдено!" << endl;
			}
			break;
			}
		case 4:
			delete[] array;
			return 0;
		}
	}
	delete[] array;
	return 0;
}

void menu() {
	cout << "===МЕНЮ_ПРОГРАММЫ===" << endl;
	cout << "1.список товаров для заданного наименования" << endl;
	cout << "2.список товаров для заданного наименования, цена которых не превосходит заданную" << endl;
	cout << "3. список товаров, срок хранения которых больше заданного" << endl;
	cout << "4.выход из программы" << endl;

}