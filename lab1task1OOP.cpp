#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//функция меню выбора методов класса
void menu();
//функция сравнения корней квадратных уравненй
void CompareThreeEquations();

//квадратное уравнение вида ax^2 + bx + c = d
class QuadraticEquation {
private:
    float m_a;
    float m_b;
    float m_c;
    float m_d;
public:
    //базовый конструктор
    QuadraticEquation() : m_a(0), m_b(0), m_c(0), m_d(0) {
        cout << "Пустой объект создан." << endl;
    }

    //конструктор с параметрами
    QuadraticEquation(float a, float b, float c, float d) : m_a(a), m_b(b), m_c(c), m_d(d) {
        cout << "a: " << a << "\nb: " << b << "\nc: " << c << "\nd: " << d << endl;
    }

    //конструктор копирования
    QuadraticEquation(const QuadraticEquation& other) : m_a(other.m_a), m_b(other.m_b), m_c(other.m_c), m_d(other.m_d) {
        cout << "обьект успешно скопирован" << endl;
    }

    //сеттер для изменения атрибутов обьекта класса
    void SetEquationAttributes(float a, float b, float c, float d) {
        m_a = a;
        m_b = b;
        m_c = c;
        m_d = d;
        cout << "атрибуты успешно изменены! " << endl;
    }

    //метод нахождения корней квадратного уравнения и их сравнения между собой
    void FindRootsEquation() const {
        float x1, x2;
        float discriminant = pow(m_b, 2) - (4 * m_a * (m_c - m_d));
        if (discriminant > 0) {
            x1 = (-m_b + sqrt(discriminant)) / (2 * m_a);
            x2 = (-m_b - sqrt(discriminant)) / (2 * m_a);

            cout << "x1: " << x1 << "\nx2: " << x2 << endl;
            if (x1 > x2) {
                cout << "x1 > x2" << endl;
            }
            else {
                cout << "x2 > x1" << endl;
            }
        }
        else if (discriminant == 0) {
            x1 = -m_b / (2 * m_a);
            x2 = x1;
            cout << "x1 = x2" << endl;
        }
        else {
            cout << "в данном уравнении нет корней" << endl;
        }
    }

    //геттер для того чтобы корни уравнения остались в памяти
    int GetRoots(float& out_x1, float& out_x2) const {
        float discriminant = pow(m_b, 2) - (4 * m_a * (m_c - m_d));
        if (discriminant > 0) {
            out_x1 = (-m_b + sqrt(discriminant)) / (2 * m_a);
            out_x2 = (-m_b - sqrt(discriminant)) / (2 * m_a);
            return 2;
        }
        else if (discriminant == 0) {
            out_x1 = -m_b / (2 * m_a);
            out_x2 = out_x1;
            return 1;
        }
        return 0;
    }

    //метод нахождения экстремумов функции
    void FindExtremumEquation() const {
        bool position;
        if (m_a > 0) {
            cout << "функция имеет мининмум" << endl;
            position = true;
        }
        else {
            cout << "Функция имеет максимум" << endl;
            position = false;
        }
        //нахождение абсциссы вершины параболы
        float x0 = -m_b / (2 * m_a);
        //вычисление ординаты вершины
        float y0 = m_a * pow(x0, 2) + m_b * x0 + (m_c - m_d);
        cout << "паррабола направлена ";
        if (position == true) {
            cout << "вверх ";
        }
        else {
            cout << "вниз ";
        }
        cout << "\nкоординаты экстремума(x0,y0): ( " << x0 << ", " << y0 << " )" << endl;
    }

    //нахождение интервалов убывания/возрастания функции
    void FindIntervalEquation() const {
        bool position;
        if (m_a > 0) {
            cout << "ветви парраболы направлены вверх" << endl;
            position = true;
        }
        else {
            cout << "ветви парраболы направлены вниз" << endl;
            position = false;
        }
        float x0 = -m_b / (2 * m_a);

        if (position == true) {
            cout << "функция убывает на промежутке ( -∞, " << x0 << " )" << endl;
            cout << "функция возростает на промежутке ( " << x0 << " , +∞ )" << endl;
        }
        else {
            cout << "функция возростает на промежутке ( -∞, " << x0 << " )" << endl;
            cout << "функция убывает на промежутке ( " << x0 << " , +∞ )" << endl;
        }
    }

    //деструктор
    ~QuadraticEquation() {
        cout << "Обьект удален" << endl;
    }
};

int main(void) {
    setlocale(LC_ALL, "RU");

    float a, b, c, d;
    int choice;

    cout << "Введите переменные(a,b,c,d) в уравнени вида ax^2 + bx + c = d: ";
    do {
        cout << "a = ";
        cin >> a;
        if (a == 0) {
            cout << "a не может быть 0, введите другое число!" << endl;
        }
    } while (a == 0);
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "d = "; cin >> d;

    //создание обьекта класса QuadraticEquation
    QuadraticEquation equation1(a, b, c, d);

    //основной цикл программы
    while (true) {
        menu();

        do {
            cout << "Ваш выбор: ";
            cin >> choice;
            if (choice > 5 || choice < 1) {
                cout << "Ошибка, введите дургое число" << endl;
            }
        } while (choice > 5 || choice < 1);

        system("cls");

        switch (choice) {
        case 1:
            equation1.FindRootsEquation();
            break;
        case 2:
            equation1.FindExtremumEquation();
            break;
        case 3:
            equation1.FindIntervalEquation();
            break;
        case 4:
            CompareThreeEquations();
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}

void menu() {
    cout << "===МЕНЮ_ВЫБОРА_КОНСТРУКТОРОВ_КЛАССА===" << endl;
    cout << "1.найти корни квадратного уравнения" << endl;
    cout << "2.найти экстремумы функции" << endl;
    cout << "3.найти интервалы убывания/возрастания функции" << endl;
    cout << "4.сравнение корней 3-х функций" << endl;
    cout << "5.выход из программы" << endl;
}

void CompareThreeEquations() {

    QuadraticEquation Equations[3]; //массив для всех обьектов класса
    float roots[6]; //массив для всех корней уравнений
    int total_roots = 0; //счетчик найденных корней

    float a, b, c, d;

    for (int i = 0; i < 3; i++) {
        cout << "Введите переменные " << i + 1 << " уравнения: ";
        do {
            cin >> a;
            if (a == 0) {
                cout << "a не должно = 0!" << endl;
            }
        } while (a == 0);
        cin >> b;
        cin >> c;
        cin >> d;

        Equations[i].SetEquationAttributes(a, b, c, d); //меяем аттрибуты в обьектах класса

        float x1, x2;
        int count = Equations[i].GetRoots(x1, x2);

        if (count == 1) {
            roots[total_roots] = x1;
            total_roots++;
        }
        else if (count == 2) {
            roots[total_roots] = x1;
            total_roots++;
            roots[total_roots] = x2;
            total_roots++;
        }
    }
    if (total_roots == 0) {
        cout << "Ни в 1 уравнении нет корней" << endl;
    }
    else {
        //сортировка пузырьком
        for (int i = 0; i < total_roots - 1; i++) {
            for (int j = 0; j < total_roots - 1 - i; j++) {
                if (roots[j] > roots[j + 1]) {
                    swap(roots[j], roots[j + 1]);
                }
            }
        }
        //вывод результата
        cout << "самый большой корень: " << roots[total_roots - 1] << endl;
        cout << "самый маленький корень: " << roots[0] << endl;
    }
}