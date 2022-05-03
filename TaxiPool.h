#ifndef TEST_TAXIPOOL_H
#define TEST_TAXIPOOL_H
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;
#define EXPIRED_TIME_IN_SECOND 1.2
#define NUMBER_OF_TAXI 4
class TaxiPool {
private:
    list<Taxi> available;
    list<Taxi> inUse;
    int count = 0;
    bool waiting = false;
public:
    Taxi getTaxi() {
        if (!available.empty()) {
            Taxi taxi = available.front();
            available.pop_front();
            inUse.push_back(taxi);
        }
        if (count == NUMBER_OF_TAXI) {
            this->waitingUntilTaxiAvailable();
            return this->getTaxi();
        }
        Taxi taxi = this->createTaxi();
        inUse.push_back(taxi);
        return taxi;
    }

    void release(Taxi taxi) {
        list<Taxi>::iterator it = inUse.begin();
        for (; it != inUse.end() ; ++it) {
            if(*it == taxi) break;
        }
        remove(inUse.begin(), inUse.end(), taxi);
        available.push_back(taxi);
        cout << taxi.getName() << " is free\n";
    }
    Taxi createTaxi() {
        sleep(0.2); // The time to create the taxi.
        Taxi taxi("Taxi " + to_string(count));
        cout << taxi.getName() + " is created\n";
        return taxi;
    }

    void waitingUntilTaxiAvailable() {
        if (waiting) {
            waiting = false;
            throw TaxiNotFoundException("No taxi available");
        }
    }
};

#endif
