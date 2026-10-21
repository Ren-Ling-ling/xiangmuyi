#ifndef resource_h
#define resource_h
#include<string>
using namespace std;
class resource{
    protected:
    string name;
    string publisher;
    double price;
    bool available;
    public:
    resource();
    resource(string name,string publisher,double price);
    virtual void show()=0;
    virtual bool borrow();
    virtual void returnItem();
    virtual ~resource();
    string Getpublisher();
    string Getname();
    double Getprice();
    bool Getavailable();
};
#endif