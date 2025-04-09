#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Student {
    int rollNo;
    string name;
    float marks;
    bool occupied;

    Student() {
        rollNo = -1;
        name = "";
        marks = 0;
        occupied = false;
    }
};

class HashTable {
    Student table[TABLE_SIZE];

    int hash(int rollNo) {
        return rollNo % TABLE_SIZE;
    }

public:
    void create();
    void display();
    void addRecord(Student s);
    int search(int rollNo);
    void modify(int rollNo);
};

// a) Create database
void HashTable::create() {
    int n;
    cout << "Enter number of students to add: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Student s;
        cout << "Enter Roll No: ";
        cin >> s.rollNo;
        cout << "Enter Name: ";
        cin >> s.name;
        cout << "Enter Marks: ";
        cin >> s.marks;
        addRecord(s);
    }
}

// b) Display database
void HashTable::display() {
    cout << "\n--- Student Database ---\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i].occupied) {
            cout << "Index " << i << ": ";
            cout << "Roll No: " << table[i].rollNo
                 << ", Name: " << table[i].name
                 << ", Marks: " << table[i].marks << "\n";
        } else {
            cout << "Index " << i << ": Empty\n";
        }
    }
}

// c) Add a record (Linear Probing without Replacement)
void HashTable::addRecord(Student s) {
    int index = hash(s.rollNo);
    int start = index;
    while (table[index].occupied) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            cout << "Hash table full. Cannot insert record.\n";
            return;
        }
    }
    table[index] = s;
    table[index].occupied = true;
}

// d) Search a record
int HashTable::search(int rollNo) {
    int index = hash(rollNo);
    int start = index;
    while (table[index].occupied) {
        if (table[index].rollNo == rollNo)
            return index;
        index = (index + 1) % TABLE_SIZE;
        if (index == start)
            break;
    }
    return -1;
}

// e) Modify a record
void HashTable::modify(int rollNo) {
    int index = search(rollNo);
    if (index != -1) {
        cout << "Enter new name: ";
        cin >> table[index].name;
        cout << "Enter new marks: ";
        cin >> table[index].marks;
        cout << "Record updated.\n";
    } else {
        cout << "Record not found.\n";
    }
}

// Main menu
int main() {
    HashTable ht;
    int choice, rollNo;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Create Database\n2. Display\n3. Add Record\n4. Search\n5. Modify\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: ht.create(); break;
            case 2: ht.display(); break;
            case 3: {
                Student s;
                cout << "Enter Roll No: ";
                cin >> s.rollNo;
                cout << "Enter Name: ";
                cin >> s.name;
                cout << "Enter Marks: ";
                cin >> s.marks;
                ht.addRecord(s);
                break;
            }
            case 4:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                int index;
                index = ht.search(rollNo);
                if (index != -1)
                    cout << "Record found at index " << index << "\n";
                else
                    cout << "Record not found.\n";
                break;
            case 5:
                cout << "Enter Roll No to modify: ";
                cin >> rollNo;
                ht.modify(rollNo);
                break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
