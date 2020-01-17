#include <iostream>
#include "HashTable.hpp"

using namespace std;

int h(string s){
	int hash = 0;
	int p = 10;
	for (int i = 0; i < s.length(); i++)
		hash = hash * p + s[i] - '0'; 
	return hash;
}

int main(){
	HashTable<string, int> hashtable(6, h);

	string key;
	int value;
	int *result;

	int item; // выбираемый пункт меню

    do {
        system("cls"); // очищаем экран
        // выводим меню
        cout << "What do you want to do?" << endl;
        cout << "1. Print" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Find" << endl;
        cout << "4. Quit" << endl;
        cout << ">";
        cin >> item; // считываем пункт меню

        // обрабатываем некорректный ввод
        while(item < 1 || item > 4) {
            cout << "Incorrect item. Try again: ";
            cin >> item; // считываем пункт меню заново
        }

        // в зависимости от выбранного пункта выполняем действие
        switch (item) {
            case 1:
                hashtable.Print();
                break;

            case 2:
            	cout << "Enter key, value: ";
            	cin >> key >> value;

                hashtable.Insert(key, value);
                break;

            case 3:
            	cout << "Enter key: ";
            	cin >> key;
                result = hashtable.Find(key);

                if (result) {
                	cout << "Find: " << *result << endl;
                }
                else {
                	cout << "Not found" << endl;
                }
                break;
        }

        if (item != 4) {
            system("pause"); // задерживаем экран
        }
    } while (item != 4); // повторяем, пока не решим выйти

    return 0;
}