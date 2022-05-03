#ifndef TEST_SYMAPHORE_H
#define TEST_SYMAPHORE_H
#include <mutex>
#include <condition_variable>
#include <iostream>
using namespace std;
class Semaphore {
public:
    Semaphore(int count_ = 0):count(count_){};
    inline void notify(int tid){
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cout << "thread " << tid <<  " notify" << endl;
        cv.notify_one();
    }
    inline void wait(int tid){
        std::unique_lock<std::mutex> lock(mtx);
        while(count == 0){
            cout << "thread " << tid << " wait" << endl;
            cv.wait(lock);
            cout << "thread " << tid << " run" << endl;
        }
        count--;
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};
#endif
