#ifndef menu_h
#define menu_h
#include "library.h"
#include "user.h"
using namespace std;

class menu
{
    private:
    library&lib;
    user*current;

    bool isadmin();
    void dologin();
    void doregister();
    void showmenu();
    bool handle(int choice);
    
    public:
    menu(library& l);
    void run();
};
#endif
