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
    void show();
    void borrowbook();
    void returnbook();
    string Getname();
    string Getpublisher();
    double Getprice();
    bool Getavailable();
};
#endif