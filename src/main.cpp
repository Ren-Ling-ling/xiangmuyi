#include "library.h"
#include "menu.h"
#include "book.h"
#include "magazine.h"
#include "eresource.h"
using namespace std;

int main() {
    library lib;

    // 加载资源（首次建初始资源）
    lib.loadFromFile("resources.txt");
    if (!lib.hasResources()) {
        lib.addResource(new book("三国演义", "9780306406157", "人民文学出版社", 69.9, 300));
        lib.addResource(new magazine("读者", "读者出版社", 10.0, 5, "月刊"));
        lib.addResource(new eresource("c++教程", "人民邮电出版社", 20.0, "http://xxx.com", "pdf"));
        lib.savetoFile("resources.txt");
    }
    lib.loadUsers("users.txt");   // 加载用户

    menu m(lib);                  // 创建菜单对象，绑定 library
    m.run();                      // 启动

    return 0;
}