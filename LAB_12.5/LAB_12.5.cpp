#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

// Функція для зчитування натуральних чисел з текстового файлу і збереження їх у стек
void readFromFile(stack<int>& s, const string& filename) {
    ifstream file(filename);
    int num;
    while (file >> num) {
        if (num > 0) { // Перевірка, чи число натуральне
            s.push(num);
        }
    }
    file.close();
}

// Функція для пошуку значення елемента за заданою позицією у стеці
int getElementAtPosition(const stack<int>& s, int position) {
    stack<int> tempStack = s;
    int pos = 1;
    while (!tempStack.empty()) {
        if (pos == position) {
            return tempStack.top();
        }
        tempStack.pop();
        pos++;
    }
    return -1; // Позиція не знайдена
}

// Функція для пошуку заданого значення у стеці
bool searchValueInStack(const stack<int>& s, int value) {
    stack<int> tempStack = s;
    while (!tempStack.empty()) {
        if (tempStack.top() == value) {
            return true;
        }
        tempStack.pop();
    }
    return false; // Значення не знайдено
}

int main() {
    stack<int> myStack;
    string filename;

    // Просимо користувача ввести шлях до текстового файлу
    cout << "Введіть шлях до текстового файлу: ";
    cin >> filename;

    // Зчитуємо дані з файлу та додаємо їх у стек
    readFromFile(myStack, filename);

    // Виводимо елементи стеку
    cout << "Елементи стеку:" << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    // Пошук елемента за позицією
    int position;
    cout << "Введіть позицію для пошуку елемента: ";
    cin >> position;
    int element = getElementAtPosition(myStack, position);
    if (element != -1) {
        cout << "Елемент на позиції " << position << " у стеці: " << element << endl;
    }
    else {
        cout << "Елемент на позиції " << position << " не знайдено." << endl;
    }

    // Пошук значення у стеці
    int searchValue;
    cout << "Введіть значення для пошуку у стеці: ";
    cin >> searchValue;
    if (searchValueInStack(myStack, searchValue)) {
        cout << "Значення " << searchValue << " знайдено у стеці." << endl;
    }
    else {
        cout << "Значення " << searchValue << " не знайдено у стеці." << endl;
    }

    return 0;
}