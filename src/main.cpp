#include "book.h"
#include "magazine.h"
#include "eresource.h"
#include "student.h"
#include "teacher.h"
#include "library.h"
#include"admin.h"
#include <iostream>
using namespace std;
int readInt(){
    int x;
    while(!(cin>>x)){
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"输入失效，请输入数字：";
    }
    return x;
}
string readLine(){
    string s;
    getline(cin>>ws,s);
    return s;
}
double readDouble(){
    double x;
    while(!(cin>>x)){
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"输入无效，请输入数字：";

    }
return x;

}
bool isAdmin(user*u)
{
    return u->Getrolename()=="管理员";
}
int main() {
    library lib;
 
    // 启动：自动加载 

    lib.loadFromFile("resources.txt");
    if (!lib.hasResources()) {
        lib.addResource(new book("三国演义", "9780306406157", "人民文学出版社", 69.9, 300));
        lib.addResource(new magazine("读者", "读者出版社", 10.0, 5, "月刊"));
        lib.addResource(new eresource("c++教程", "人民邮电出版社", 20.0, "http://xxx.com", "pdf"));
        lib.savetoFile("resources.txt");
    }
          lib.savetoFile("users.txt");
          while (true) {       
    //强制登录 
       user* current = nullptr;
    while (current == nullptr) {
        string id;
        cout << "请输入学号/工号登录（R 注册新账号，0 退出）：";
        cin >> id;

        if (id == "0") { cout << "已退出。" << endl; return 0; }

                if (id == "R" || id == "r") {
            cout << "注册类型（1学生 2老师 3管理员）：";
            int rt = readInt();
            string rname, rid, dept;
            cout << "姓名："; rname = readLine();
            cout << "学号/工号/编号："; rid = readLine();
            cout << "院系："; dept = readLine();
            cout << "最大借阅量："; int maxb = readInt();
            if (rt == 1) lib.adduser(new student(rname, rid, dept, maxb));
            else if (rt == 2) lib.adduser(new teacher(rname, rid, dept, maxb));
            else lib.adduser(new admin(rname, rid, dept, maxb));
            lib.saveUsers("users.txt");
            cout << "注册成功！请用编号登录。" << endl;
            continue;
        }
              
        current = lib.login(id);
        if (current == nullptr)
            cout << "用户不存在，登录失败，请重试。" << endl;
        else
            cout << "登录成功，欢迎 " << current->Getname() << "！" << endl;
    }
    // 主菜单
     while (true) {
        cout<<"\n图书馆借阅管理系统 " << endl;
        cout << "当前用户：" << current->Getname() << endl;
        cout << "1. 显示所有资源" << endl;
        cout << "2. 显示所有用户" << endl;
        cout << "3. 按名称查找资源" << endl;
        cout << "4. 按类型筛选资源" << endl;
        cout << "5. 借书" << endl;
        cout << "6. 还书" << endl;
        cout << "7. 查看我的借阅记录" << endl;
        cout << "8. 删除资源" << endl;
        cout << "9. 保存到文件（手动）" << endl;
        cout << "10. 从文件读取（手动）" << endl;
        cout << "11. 切换用户（重新登录）" << endl;
        cout << "12. 添加资源" << endl;
        cout << "13. 添加用户" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择：";
        int choice=readInt();
              if ((choice == 8 || choice == 12 || choice == 13) && !isAdmin(current)) {
            cout << "无权限：仅管理员可执行此操作" << endl;
            continue;
        }
        bool logout = false;       // 标记：是否注销自己
        if (choice == 0) {
            // 退出前自动保存
            lib.saveUsers("users.txt");
            lib.savetoFile("resources.txt");
            cout << "已自动保存，再见！" << endl;
            return 0;
        }       
         if ((choice == 8 || choice == 12) && !isAdmin(current)) {
            cout << "无权限：仅教师（管理员）可执行此操作" << endl;
            continue;
        }

        if (choice == 1) {
            lib.showall();
        } else if (choice == 2) {
            lib.showusers();
        } else if (choice == 3) {
           cout << "输入资源名称："; 
     string name = readLine();
            lib.showByname(name);
        } else if (choice == 4) {
            int t=readInt();
            cout << "选类型（1图书 2杂志 3电子资源）：";
            lib.showBytype(t);
        } else if (choice == 5) {
            cout << "输入要借的资源名："; 
            string name = readLine();
            lib.borrow(name, *current);
        } else if (choice == 6) {
            cout << "输入要还的资源名："; 
            string name = readLine();
            lib.returnRes(name, *current);
        } else if (choice == 7) {
            current->showRecords();
        } else if (choice == 8) {
            cout << "输入要删除的资源名："; 
            string name = readLine();
            lib.remove(name);
        } else if (choice == 9) {
            lib.savetoFile("resources.txt");
            lib.saveUsers("users.txt");
        } else if (choice == 10) {
            lib.loadFromFile("resources.txt");
            lib.loadUsers("users.txt");
        } else if (choice == 11) {
            string id;
            cout << "重新登录，输入学号/工号："; cin >> id;
            user* u = lib.login(id);
            if (u != nullptr) { current = u; cout << "已切换为：" << current->Getname() << endl; }
            else cout << "用户不存在，切换失败" << endl;
        } 
            else if (choice == 12) {
            cout << "选类型（1图书 2杂志 3电子资源）：";
            int t = readInt();
            string name, pub;
            cout << "名称："; name = readLine();
            cout << "出版社："; pub = readLine();
            cout << "价格："; double price = readDouble();
            if (t == 1) {
                cout << "ISBN："; string isbn = readLine();
                cout << "页数："; int page = readInt();
                lib.addResource(new book(name, isbn, pub, price, page));
            } else if (t == 2) {
                cout << "期号："; int issue = readInt();
                cout << "出版周期："; string period = readLine();
                lib.addResource(new magazine(name, pub, price, issue, period));
            } else if (t == 3) {
                cout << "网址："; string url = readLine();
                cout << "格式："; string format = readLine();
                lib.addResource(new eresource(name, pub, price, url, format));
            }
            cout << "添加资源成功！" << endl;
         } 
                     
                     
                    else if (choice == 13) {
            cout << "选类型（1学生 2教师 3管理员）：";
            int t = readInt();
            string name, id, dept;
            cout << "姓名："; name = readLine();
            cout << "学号/工号/编号："; id = readLine();
            cout << "院系："; dept = readLine();
            cout << "最大借阅量："; int maxb = readInt();
            if (t == 1) lib.adduser(new student(name, id, dept, maxb));
            else if (t == 2) lib.adduser(new teacher(name, id, dept, maxb));
            else lib.adduser(new admin(name, id, dept, maxb));
            lib.saveUsers("users.txt");
            cout << "添加成功！" << endl;
        }
               
                else if (choice == 14) {
            user* target = current;
            if (isAdmin(current)) {          // 管理员可注销任意
                cout << "输入要注销的账号编号（直接回车=注销自己）：";
                string tid = readLine();
                if (!tid.empty()) {
                    target = lib.login(tid);
                    if (target == nullptr) { cout << "找不到该账号" << endl; break; }
                    if (tid == current->Getname()) target = current;
                }
            }
            // 未还书检查
            if (target->Getborrowcount() > 0) {
                cout << "注销失败：该账号还有未归还的书" << endl;
            } else if (dynamic_cast<admin*>(target) != nullptr && lib.admincount() <= 1) {
                cout << "注销失败：不能注销最后一个管理员" << endl;
            } else {
                bool self = (target == current);
                lib.removeuser(target);
                lib.saveUsers("users.txt");
                if (self) { current = nullptr; cout << "账号已注销，请重新登录" << endl; break; }
                else cout << "已注销该账号" << endl;
            }
        } else {
      
            cout << "无效选择，请重新输入" << endl;
        }

    
}
     }
    return 0;
}