#include <iostream>
#include <string>
#include <windows.h> // Потрібно для коректного відображення української мови в консолі

using namespace std;

// Опис структури для студента
struct Student {
    string name;       // Прізвище та ім'я
    int course;        // Курс
    string group;      // Група
    int grades[4];     // Масив з 4 оцінок
};

int main() {
    // Налаштування української локалізації для консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int countStudents;
    cout << "Введіть кількість студентів для введення: ";
    cin >> countStudents;
    cin.ignore(); // Очищаємо буфер після введення числа

    // Створюємо масив структур (максимум на 100 студентів)
    Student students[100];

    // Введення даних про кожного студента
    for (int i = 0; i < countStudents; i++) {
        cout << "\n--- Введення даних студента №" << i + 1 << " ---" << endl;

        cout << "Прізвище та ім'я: ";
        getline(cin, students[i].name);

        cout << "Курс: ";
        cin >> students[i].course;

        cout << "Група: ";
        cin >> students[i].group;

        cout << "Введіть 4 оцінки (через пробіл): ";
        for (int j = 0; j < 4; j++) {
            cin >> students[i].grades[j];
        }
        cin.ignore(); // Очищаємо буфер для наступного getline
    }

    int excellentCount = 0; // Лічильник відмінників

    cout << "\n========================================" << endl;
    cout << "СПИСОК СТУДЕНТІВ-ВІДМІННИКІВ:" << endl;
    cout << "========================================" << endl;

    // Пошук відмінників
    for (int i = 0; i < countStudents; i++) {
        bool isExcellent = true; // Припускаємо, що студент відмінник

        // Перевіряємо всі 4 оцінки
        for (int j = 0; j < 4; j++) {
            // Якщо хоча б одна оцінка НЕ 5, то він не відмінник
            // (Якщо у вас 100-бальна система, замініть на: if (students[i].grades[j] < 90) )
            if (students[i].grades[j] != 5) {
                isExcellent = false;
                break; // Далі оцінки цього студента можна не перевіряти
            }
        }

        // Якщо прапорець залишився true — виводимо студента
        if (isExcellent) {
            cout << "Студент: " << students[i].name
                << " | Курс: " << students[i].course
                << " | Група: " << students[i].group << endl;
            excellentCount++; // Збільшуємо кількість відмінників
        }
    }

    // Виведення загальної кількості відмінників
    cout << "----------------------------------------" << endl;
    cout << "Загальна кількість відмінників: " << excellentCount << endl;
    cout << "========================================" << endl;

    return 0;
}