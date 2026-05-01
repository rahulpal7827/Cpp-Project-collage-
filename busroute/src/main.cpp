#include "../include/BusSystem.h"
#include <iostream>
using namespace std;

void menu(BusSystem &bs) {
    while(true) {
        cout << "\n===== 🚌 BUS SYSTEM MENU =====\n";
        cout << "1. Show Cities\n";
        cout << "2. Find Route\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        if(ch == 3) break;

        if(ch == 1) {
            bs.showCities();
        }

        else if(ch == 2) {
            int s, d;
            cout << "Enter source index: ";
            cin >> s;
            cout << "Enter destination index: ";
            cin >> d;

            bs.findRoute(s, d);
        }
    }
}

int main() {
    BusSystem bs(5);

    // 🌆 SET CITY NAMES
    bs.setCity(0, "Delhi");
    bs.setCity(1, "Noida");
    bs.setCity(2, "Ghaziabad");
    bs.setCity(3, "Meerut");
    bs.setCity(4, "Haridwar");

    // 🛣️ ROUTES
    bs.addRoute(0,1,4);
    bs.addRoute(1,2,3);
    bs.addRoute(2,3,2);
    bs.addRoute(3,4,5);
    bs.addRoute(0,2,10);

    menu(bs);

    return 0;
}