#ifndef eresource_h
#define eresource_h
#include<string>
#include"resource.h"
using namespace std;
class eresource:public resource{
    private:
    string url;
    string format;
    public:
    eresource();
    eresource(string name,string publisher,double price,string url,string format);
    void show()override;
    bool borrow()override;
    void returnItem()override;
} ;
#endif