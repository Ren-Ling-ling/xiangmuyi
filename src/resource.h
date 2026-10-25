#ifndef resource_h
#define resource_h
#include<string>
#include<fstream>
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
    virtual void writetoFile(ofstream&out)=0;
    virtual bool borrow();
    virtual void returnItem();
    virtual ~resource();
    virtual int getborrowdays();
    virtual double calfine(int daysBorrowed);
   string Getpublisher();
    string Getname();
    double Getprice();
    bool Getavailable();

};
#endif