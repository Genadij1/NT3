#include "Reservoir.h"

int main() {
    const int initialCapacity = 5;
    Reservoir** reservoirs = new Reservoir * [initialCapacity];
    int size = 0;

    char choice;
    do {
        string name;
        string type;
        double width, length, maxDepth;

        cout << "Enter reservoir name: ";
        cin >> name;
        cout << "Enter reservoir type: ";
        cin >> type;
        cout << "Enter width: ";
        cin >> width;
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter max depth: ";
        cin >> maxDepth;

        reservoirs[size] = new Reservoir(name, type, width, length, maxDepth);
        size++;

        cout << "Do you want to add another reservoir? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    for (int i = 0; i < size; i++) {
        reservoirs[i]->displayInfo();
        cout << "\n";
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (reservoirs[i]->SameArea(*reservoirs[j])) {
                cout << "Reservoir " << i + 1 << " has the same area as reservoir " << j + 1 << endl;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (reservoirs[i]->SameType(*reservoirs[j])) {
                cout << "Reservoir " << i + 1 << " has the same type as reservoir " << j + 1 << endl;
            }
        }
    }

    Reservoir copiedReservoir = reservoirs[0]->copy();
    cout << "Copied reservoir's info: \n";
    copiedReservoir.displayInfo();

    for (int i = 0; i < size; i++) {
        delete reservoirs[i];
    }

    return 0;
}