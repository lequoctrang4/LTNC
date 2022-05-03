#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <algorithm>
#include <unistd.h>
using namespace std;
#define NUMBER_OF_CLIENT 8
#define EXPIRED_TIME_IN_SECOND 1.2
#define NUMBER_OF_TAXI 4
class TaxiNotFoundException : public exception
{
    string mess;
public:
    TaxiNotFoundException(string instruction)
    {
        mess = instruction;
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
class Taxi{
private:
    string name;
public:
    Taxi(const string& name):name(name){};
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
        Taxi taxi("Taxi " + to_string(count));
        cout << taxi.getName() + " is created\n";
        return taxi;
    }
    void waitingUntilTaxiAvailable(){
        if (waitting){
            waitting = false;
            throw TaxiNotFoundException("No taxi available");
        }
    }
    void waitting(long numberOfSecond){
        sleep(numberOfSecond);
    }
};