// 1Litvinova.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct Pipe {
    string name;
    float length;
    int diametr;
    bool status;
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
        switch (option) {
        case 1:
            cout << "Insert pipe name: ";
            cin >> t.name;
            cout << "Insert pipe length: ";
            cin >> t.length;
            cout << "Insert pipe diametr: ";
            cin >> t.diametr;
            cout << "Insert pipe status (0 - not under repair, 1 - under repair): ";
            cin >> t.status;
            break;
        case 2:
            cout << "Insert CS name: ";
            cin >> cs.name;
            cout << "Insert the number of CS workshops: ";
            cin >> cs.number_work;
            cout << "Insert the number of CS workshops in operation: ";
            cin >> cs.number_work_online;
            cout << "Insert CS class: ";
            cin >> cs.class_cs;
            break;
        case 3:
            cout << "\nPipe name: " << t.name;
            cout << "\n Pipe length: " << t.length;
            cout << "\nPipe diametr: " << t.diametr;
            cout << "\nPipe status (0 - not under repair, 1 - under repair): " << t.status;
            cout << "\nCS name: " << cs.name;
            cout << "\nThe number of CS workshops: " << cs.number_work;
            cout << "\nThe number of CS workshops in operation: " << cs.number_work_online;
            cout << "\nCS class: " << cs.class_cs;
            break;
        case 4:
            cout << "Insert pipe name: ";
            cin >> t.name;
            cout << "Insert pipe length: ";
            cin >> t.length;
            cout << "Insert pipe diametr: ";
            cin >> t.diametr;
            cout << "Insert pipe status (0 - not under repair, 1 - under repair): ";
            cin >> t.status;
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
