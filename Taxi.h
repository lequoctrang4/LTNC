#ifndef TEST_TAXI_H
#define TEST_TAXI_H
#include <string>
using namespace std;

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
    bool operator==(const Taxi& taxi){
        return (this->name == taxi.name);
    }
};

#endif
