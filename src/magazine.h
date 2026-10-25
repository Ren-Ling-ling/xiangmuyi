#ifndef magazine_h
#define magazine_h
#include<string>
#include"resource.h"
using namespace std;
class magazine:public resource{
private:
int issue;
string period;
public:
magazine();
magazine(string name,string publisher,double price,int issue,string period);
void show()override;
void writetoFile(ofstream&out)override;
    int getborrowdays() override;
    double calfine(int daysBorrowed) override;
};
#endif