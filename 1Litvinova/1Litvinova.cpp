// 1Litvinova.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
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

void AddPipe(Pipe& t) {

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Insert pipe name: ";
    getline(cin, t.name);

    cout << "Insert pipe length: ";
    cin >> t.length;
    while (t.length <= 0 || cin.fail() || (cin.peek() != '\n')) {
        cout << "Error! Please, enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> t.length;
    }

    cout << "Insert pipe diametr: ";
    cin >> t.diametr;
    while (t.diametr <= 0 || cin.fail() || (cin.peek() != '\n') && (cin.peek() != '\t')) {
        cout << "Error! Please, enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> t.diametr;
    }

    cout << "Insert pipe status (0 - not under repair, 1 - under repair): ";
    cin >> t.status;
    while ((t.status != 0 && t.status != 1) || cin.fail() || (cin.peek() != '\n')) {
        cout << "Error! Please, enter 0 or 1: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> t.status;
    }
}

void AddCS(CS& cs) {

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Insert CS name: ";
    getline(cin, cs.name);

    cout << "Insert the number of CS workshops: ";
    cin >> cs.number_work;
    while (cs.number_work <= 0 || cin.fail() || (cin.peek() != '\n') && (cin.peek() != '\t')) {
        cout << "Error! Please, enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cs.number_work;
    }

    cout << "Insert the number of CS workshops in operation: ";
    cin >> cs.number_work_online;
    while (cs.number_work_online < 0 || cin.fail() || cs.number_work_online > cs.number_work || (cin.peek() != '\n') && (cin.peek() != '\t')) {
        cout << "Error! Please, enter a positive number no more than the number of CG workshops: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cs.number_work_online;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Insert CS class: ";
    getline(cin, cs.class_cs);
}

void EditPipe(Pipe& t) {

    if (t.name.empty()) {
        cout << "No pipe exists!" << endl;
        return;
    }

    cout << "Current status: " << t.status << " (0 - not under repair, 1 - under repair)\n";
    cout << "Change status to: ";
    cin >> t.status;
    while ((t.status != 0 && t.status != 1) || cin.fail()) {
        cout << "Error! Please, enter 0 or 1: ";
        cin >> t.status;
    }
    cout << "Status changed!\n";
}

void EditCS(CS& cs) {

    if (cs.name.empty()) {
        cout << "No CS exists!" << endl;
        return;
    }
    cout << "Current number of workshops in operation: " << cs.number_work_online << cs.number_work_online << "of" << cs.number_work << endl;
    cout << "Change the number of workshops in operation: ";
    cin >> cs.number_work_online;
    while (cs.number_work_online < 0 || cin.fail() || cs.number_work_online > cs.number_work) {
        cout << "Error! Please, enter a positive number no more than the number of CS workshops: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cs.number_work_online;
    }
    cout << "Number changed!\n";
}

void ReadPipe(Pipe& t) {

    if (t.name.empty()) {
        cout << "\nNo pipe exists!" << endl;
        return;
    }
    else {
        cout << "\nPIPE \nPipe name: " << t.name << "\nPipe length: " << t.length << "\nPipe diametr: " << t.diametr << "\nPipe status: " << t.status << endl;
    }
}

void ReadCS(CS& cs) {

    if (cs.name.empty()) {
        cout << "No CS exists!" << endl;
        return;
    }
    else {
        cout << "\n CS \nCS name: " << cs.name << "\nThe number of CS workshops: " << cs.number_work << "\nThe number of CS workshops in operation: " << cs.number_work_online << "\nCS class: " << cs.class_cs << endl;
    }
}

void SaveAll(Pipe& t, CS& cs) {

    ofstream out("data.txt");
    if (out.is_open()) {
        if (t.name.empty() || cs.name.empty()) {
            cout << "Error! No pipe or CS exists!" << endl;
            return;
        }
        else {
            out << "Pipe ";
            out << t.name << endl;
            out << t.length << endl;
            out << t.diametr << endl;
            out << t.status << endl;
            out << "CS ";
            out << cs.name << endl;
            out << cs.number_work << endl;
            out << cs.number_work_online << endl;
            out << cs.class_cs << endl;
            out.close();
            cout << "All data saved to file!" << endl;
        }
    }
    else {
        cout << "Error! Couldn't save data to file!" << endl;
    }
}

void LoadAll(Pipe& t, CS& cs) {

    ifstream in("data.txt");
    if (in.is_open()) {
        string type;
        while (in >> type) {
            if (type == "Pipe") {
                getline(in, t.name);
                in >> t.length;
                in >> t.diametr;
                in >> t.status;
            }
            else if (type == "CS") {
                getline(in, cs.name);
                in >> cs.number_work;
                in >> cs.number_work_online;
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(in, cs.class_cs);
            }
        }
        in.close();
        cout << "All data loaded from file!" << endl;
    }
    else {
        cout << "Error! Couldn't load data from file!" << endl;
    }
}

void ShowMenu(Pipe& t, CS& cs) {
    int option;

    while (1) {
        cout << "\nChoose option: \n1. Add pipe; \n2. Add CS; \n3. Show all objects; \n4. Edit a pipe; \n5. Edit a CS; \n6. Save; \n7. Load; \n8. Exit; \n";
        cin >> option;
        while (option < 1 || option > 8 || cin.fail() || (cin.peek() != '\n')) {
            cout << "Error! Please, choose number from 1 to 8: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin >> option;
        }
        switch (option) {

        case 1:
            AddPipe(t);
            break;

        case 2:
            AddCS(cs);
            break;

        case 3:
            ReadPipe(t);
            ReadCS(cs);
            break;

        case 4:
            EditPipe(t);
            break;

        case 5:
            EditCS(cs);
            break;

        case 6:
            if (t.name.empty() && cs.name.empty()) {
                cout << "Error! No data to save!" << endl;
            }
            else {
                SaveAll(t, cs);
            }
            break;

        case 7:
            LoadAll(t, cs);
            break;

        case 8:
            cout << "Goodbye!" << endl;
            exit(0);
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
