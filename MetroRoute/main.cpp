#include "metro.h"
#include <iostream>

using namespace std;

int main() {

    DelhiMetro dm(100);

    dm.addStation(0, "Dwarka Sec-21");
    dm.addStation(7, "Rajiv Chowk");
    dm.addStation(15, "Mandi House");
    dm.addStation(10, "Yamuna Bank");
    dm.addStation(11, "Laxmi Nagar");
    dm.addStation(13, "Karkarduma");
    dm.addStation(14, "Anand Vihar");
    dm.addStation(21, "Noida Electronic City");
    dm.addStation(24, "Kashmere Gate");
    dm.addStation(26, "New Delhi");
    dm.addStation(28, "Central Secretariat");
    dm.addStation(29, "INA");
    dm.addStation(30, "Hauz Khas");

    dm.addRoute(0, 7, 30, 50);
    dm.addRoute(7, 15, 5, 10);
    dm.addRoute(15, 10, 5, 10);
    dm.addRoute(10, 11, 4, 10);
    dm.addRoute(11, 13, 3, 10);
    dm.addRoute(13, 14, 5, 10);
    dm.addRoute(10, 21, 20, 40);
    dm.addRoute(24, 26, 8, 20);
    dm.addRoute(26, 7, 3, 10);
    dm.addRoute(15, 28, 8, 15);
    dm.addRoute(28, 29, 6, 12);
    dm.addRoute(7, 30, 25, 45);
    dm.addRoute(30, 21, 15, 30);

    dm.displayStations();

    int src, dest;
    cout << "\nEnter Source Station ID: ";
    cin >> src;
    cout << "Enter Destination Station ID: ";
    cin >> dest;

    dm.findShortestRoute(src, dest);

    return 0;
}