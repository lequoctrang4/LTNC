#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <algorithm>
#include <unistd.h>
using namespace std;
#define NUMBER_OF_CLIENT 8
#define EXPIRED_TIME_IN_MILISECOND 1200
#define NUMBER_OF_TAXI 4

class Taxi{
private:
    string name;
public:
    Taxi(string name):name(name){};
    string getName() {
        return name;
    }
    void setName(string name){
        this->name = name;
    }
    string toString(){
        return "Taxi [name=" + name + "]";
    }
    Taxi operator=(const Taxi& taxi){
        return taxi;
    }
};

class TaxiPool{
private:
    list<Taxi> available;
    list<Taxi> inUse;
    int count = 0;
    bool waitting = false;
public:
    Taxi getTaxi(){
        if(!available.empty()){
            Taxi taxi = available.front();
            available.pop_front();
            inUse.push_back(taxi);
        }
        if (count == NUMBER_OF_TAXI){
            this->waitingUntilTaxiAvailable();
            return this->getTaxi();
        }
        Taxi taxi = this->createTaxi();
        inUse.push_back(taxi);
        return taxi;
    }
    void release(Taxi taxi){
        remove(inUse.begin(), inUse.end(), taxi);
        available.push_back(taxi);
        cout << taxi.getName() << " is free\n";
    }
    Taxi createTaxi(){
        sleep(0.2); // The time to create the taxi.
        

    }
    void waitingUntilTaxiAvailable(){

    }
};

class bar {
public:
    void foo() {
        std::cout << "hello from member function" << std::endl;
    }
};

int main()
{
    thread t(&bar::foo, bar());
    t.join();
}