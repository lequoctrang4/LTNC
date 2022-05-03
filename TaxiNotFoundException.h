#ifndef TEST_TAXINOTFOUNDEXCEPTION_H
#define TEST_TAXINOTFOUNDEXCEPTION_H
#include <string>
using namespace std;
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
#endif
