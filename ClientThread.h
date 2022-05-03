#ifndef TEST_CLIENTTHREAD_H
#define TEST_CLIENTTHREAD_H
#include <iostream>
using namespace std;

class ClientThread{
private:
    TaxiPool taxiPool;
public:
    ClientThread(const TaxiPool& taxiPool): taxiPool(taxiPool){};
    void run(){

    }
    void takeATaxi(){
        /*try {
            cout << "New client: ";
        }*/
    }
};
#endif
