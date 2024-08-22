#include<iostream>
using namespace std;

class Car {
private:
    int car_no;
    char car_model[10];

public:
    void accept_details() {
        cout << "Enter car number and car model: " << endl;
        cin >> car_no >> car_model;
    }

    void display() {
        cout << "\nThe car number is: " << car_no << endl;
        cout << "The car model is: " << car_model << endl;
    }
};

int main() {
    Car obj1;
    obj1.accept_details();
    obj1.display();
    return 0;
}
