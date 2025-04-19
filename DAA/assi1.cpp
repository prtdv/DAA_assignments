//searching and sorting.
#include <iostream>

using namespace std;

class user {
    long mobNo;
    string name;
    float billAmount;
public:
    user() {
        mobNo = 0;
        name = "default";
        billAmount = 0;
    }
    friend class record;
};

class record {
    int n;
    user u[10];
public:
    record(int n1) {
        n = n1;
    }

    void accept() {                  //ACCEPTS DATA FROM USER
        for (int i = 0; i < n; i++) {
            cout << "Enter Name: ";
            cin >> u[i].name;
            cout << "Enter Mobile No.: ";
            cin >> u[i].mobNo;
            cout << "Enter bill amount: ";
            cin >> u[i].billAmount;
        }
    }

    void display() {                        //DISPLAYS   ACCEPTED RECORD
        for (int i = 0; i < n; i++) {
            cout << "\nDetails of user " << i + 1 << endl;
            cout << "Name: " << u[i].name << endl;
            cout << "Mobile No.: " << u[i].mobNo << endl;
            cout << "Bill Amount: " << u[i].billAmount << endl;
        }
    }

    int linearSearch() {                     //LINEAR SEARCH
        long number;
        cout << "Enter the number to be searched\n";
        cin >> number;
        for (int i = 0; i < n; i++) {
            if (u[i].mobNo == number)
                return i;
        }
        return -1; 
    }

    int binarySearch() {                   //RECURSIVE BINARY SEARCH  
        long no;
        cout << "Enter the number\n";
        cin >> no;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (u[mid].mobNo == no) {
                return mid;
            } else if (u[mid].mobNo < no) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;  
    }

    void adjust(int n, int i) {
        while (2 * i + 1 < n) {
            int j = 2 * i + 1;
            if ((j + 1 < n) && (u[j + 1].billAmount > u[j].billAmount)) j++;
            if (u[i].billAmount >= u[j].billAmount) break;
            else swap(u[i], u[j]);
            i = j;
        }
    }

    void heapSort() {                       //HEAP SORT
        int m = n;
        for (int i = (m / 2) - 1; i >= 0; i--) {
            adjust(m, i);  
        }
        while (m > 0) {
            swap(u[0], u[m - 1]);
            m--;
            adjust(m, 0);  
        }
    }

    void quickSort(int p, int r) {               //QUICK SORT
        if (p < r) {
            int q = partition(p, r);
            quickSort(p, q - 1);
            quickSort(q + 1, r);
        }
    }

    int partition(int p, int r) {
        int x = u[r].mobNo;
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (u[j].mobNo <= x) {
                i++;
                swap(u[i], u[j]);
            }
        }
        swap(u[i + 1], u[r]);
        return i + 1;
    }

    void printUser(int i) {                             //INDEX FOR LINEAR & BINARY SRCH IN AN ARRAY
        if (i == -1) cout << "No user found\n\n";
        else {
            cout << "Name: " << u[i].name << endl;
            cout << "Mobile No: " << u[i].mobNo << endl;
            cout << "Bill Amount: " << u[i].billAmount << endl;
        }
        cout << endl;
    }
};

int main() {
    int n, choice;
    cout << "Enter no. of users: ";
    cin >> n;
    record r(n);

    while (1) {
        cout << " 1. Accept \n 2. Display \n 3.HeapSort\n";
        cout << " 4. Quick Sort\n 5. Linear Search\n 6. Binary search\n 7. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                r.accept();
                break;
            case 2:
                r.display();
                break;
            case 3:
                r.heapSort();
                r.display();  
                break;
            case 4:
                r.quickSort(0, n - 1);
                r.display();  
                break;
            case 5:
                {
                    int index = r.linearSearch();
                    r.printUser(index);  
                }
                break;
            case 6:
                {
                    
                    r.quickSort(0, n - 1); 
                    int index = r.binarySearch();
                    r.printUser(index);
                }
                break;
            case 7:
                cout << "exited\n";
                return 0;
            default:
            cout<<"wrong choice" ;
            break;
        }
    }
}
