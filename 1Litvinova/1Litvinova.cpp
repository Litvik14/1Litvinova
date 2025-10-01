// 1Litvinova.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Pipe {
    string name;
    float length;
    int diametr;
    int status;
};

struct CS {
    string name;
    int number_work;
    int number_work_online;
    string class_cs;
};

void ShowMenu(Pipe t, CS cs) {
    int option;
    while (1) {
        cout << "\nChoose option: \n1. Add pipe; \n2. Add CS; \n3. Show all objects; \n4. Edit a pipe; \n5. Edit a CS; \n6. Save; \n7. Load; \n8. Exit; \n";
        cin >> option;
        while (option < 1 || option > 8) {
            cout << "Error! Please, choose number from 1 to 8: ";
            cin >> option;
        }
        switch (option) {
        case 1:
            cin.clear();
            cin.ignore();
            cout << "Insert pipe name: ";
            getline(cin, t.name);

            cout << "Insert pipe length: ";
            cin >> t.length;
            while (t.length <= 0) {
                cout << "Error! Please, enter a positive number: ";
                cin >> t.length;
            }

            cout << "Insert pipe diametr: ";
            cin >> t.diametr;
            while (t.diametr <= 0) {
                cout << "Error! Please, enter a positive integer: ";
                cin >> t.diametr;
            }

            cout << "Insert pipe status (0 - not under repair, 1 - under repair): ";
            cin >> t.status;
            while (t.status != 0 && t.status != 1) {
                cout << "Error! Please, enter 0 or 1: ";
                cin >> t.status;
            }
            break;
        case 2:
            cin.clear();
            cin.ignore();
            cout << "Insert CS name: ";
            getline(cin, cs.name);
            cout << "Insert the number of CS workshops: ";
            cin >> cs.number_work;
            cout << "Insert the number of CS workshops in operation: ";
            cin >> cs.number_work_online;
            while (cs.number_work_online > cs.number_work) {
                cout << "Error! The number of CS workshops in operation can`t be more than the number of CS workshops: ";
                cin >> cs.number_work_online;
            }
            cin.clear();
            cin.ignore();
            cout << "Insert CS class: ";
            getline(cin, cs.class_cs);
            break;
        case 3:
            cout << "\nPipe name: " << t.name;
            cout << "\nPipe length: " << t.length;
            cout << "\nPipe diametr: " << t.diametr;
            cout << "\nPipe status (0 - not under repair, 1 - under repair): " << t.status;
            cout << "\nCS name: " << cs.name;
            cout << "\nThe number of CS workshops: " << cs.number_work;
            cout << "\nThe number of CS workshops in operation: " << cs.number_work_online;
            cout << "\nCS class: " << cs.class_cs;
            break;
        case 4:
            cout << "Current status: " << t.status << " (0 - not under repair, 1 - under repair)\n";
            cout << "Change status to: ";
            cin >> t.status;
            while (t.status != 0 && t.status != 1) {
                cout << "Error! Please, enter 0 or 1: ";
                cin >> t.status;
            }
            cout << "Status changed!\n";
            break;
        case 5:
            cout << "Insert CS name: ";
            cin >> cs.name;
            cout << "Insert the number of CS workshops: ";
            cin >> cs.number_work;
            cout << "Insert the number of CS workshops in operation: ";
            cin >> cs.number_work_online;
            cout << "Insert CS class: ";
            cin >> cs.class_cs;
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        }
    }
}

int main()
{
    cout << "Hello World!\n";
    Pipe truba;
    CS comp_station;
    ShowMenu(truba, comp_station);
    return 1;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
