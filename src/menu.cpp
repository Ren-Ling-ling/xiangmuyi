#include"menu.h"
#include"student.h"
#include"teacher.h"
#include"admin.h"
#include"book.h"
#include"eresource.h"
#include"magazine.h"

#include<cstdlib>
#include<iostream>
using namespace std;
static int readInt(){
    int x;
    while(!(cin>>x)){
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"输入失效，请输入数字：";
    }
    return x;
}
static string readLine(){
    string s;
    getline(cin>>ws,s);
    return s;
}
static double readDouble(){
    double x;
    while(!(cin>>x)){
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"输入无效，请输入数字：";

    }
return x;

}
menu::menu(library& l):lib(l),current(nullptr){}
bool menu::isadmin()
{
    return current->Getrolename()=="管理员";
}
void menu::doregister(){
    cout << "注册类型（1学生 2老师 3管理员）：";
            int rt = readInt();
            string rname, rid, dept;
            cout << "姓名："; rname = readLine();
            cout << "学号/工号/编号："; rid = readLine();
            cout << "院系："; dept = readLine();
            if (rt == 1) lib.adduser(new student(rname, rid, dept, student::MAXBOOK));
            else if (rt == 2) lib.adduser(new teacher(rname, rid, dept, teacher::MAXBOOK));
            else lib.adduser(new admin(rname, rid, dept, admin::MAXBOOK));
            lib.saveUsers("users.txt");
            cout << "注册成功！请用/学号/工号/编号登录。" << endl;
}
void menu::dologin(){
      current = nullptr;
    while (current == nullptr) {
        string id;
        cout << "请输入学号/工号登录（R 注册新账号，0 退出）：";
        cin >> id;
        if(id=="0"){
            cout<<"已退出"<<endl;
            exit(0);
        }
        if(id=="R"||id=="r"){
            doregister();
            continue;
        }
        current=lib.login(id);
        if(current==nullptr) cout<<"用户不存在，登录失败"<<endl;
        else cout << "登录成功，欢迎 " << current->Getname() << "！" << endl;
}
}
void menu::showmenu(){
     cout << "\n 图书馆借阅管理系统 " << endl;
    cout << "当前用户：" << current->Getname() << endl;
    cout << "1.显示所有资源 2.显示所有用户 3.按名查找 4.按类型筛选" << endl;
    cout << "5.借书 6.还书 7.我的借阅记录 8.删除资源" << endl;
    cout << "9.手动保存 10.手动读取 11.切换用户 12.添加资源 13.添加用户 14.注销账号 0.退出" << endl;
    cout << "请选择：";
}
bool menu::handle(int choice){
    if ((choice == 8 || choice == 12 || choice == 13) && !isadmin()) {
        cout << "无权限：仅管理员可执行此操作" << endl;
        return false;
    }
    if (choice == 1) {
        lib.showall();
    } else if (choice == 2) {
        lib.showusers();
    } else if (choice == 3) {
        cout << "输入资源名称："; string name = readLine();
        lib.showByname(name);
    } else if (choice == 4) {
        cout << "选类型（1图书 2杂志 3电子资源）："; int t = readInt();
        lib.showBytype(t);
    } else if (choice == 5) {
        cout << "输入要借的资源名："; string name = readLine();
        lib.borrow(name, *current);
    } else if (choice == 6) {
        cout << "输入要还的资源名："; string name = readLine();
        lib.returnRes(name, *current);
    } else if (choice == 7) {
        current->showRecords();
    } else if (choice == 8) {
        cout << "输入要删除的资源名："; string name = readLine();
        lib.remove(name);
    } else if (choice == 9) {
        lib.savetoFile("resources.txt");
        lib.saveUsers("users.txt");
    } else if (choice == 10) {
        lib.loadFromFile("resources.txt");
        lib.loadUsers("users.txt");
    } else if (choice == 11) {
        cout << "重新登录，输入编号："; string id = readLine();
        user* u = lib.login(id);
        if (u != nullptr) { current = u; cout << "已切换为：" << current->Getname() << endl; }
        else cout << "用户不存在" << endl;
    } else if (choice == 12) {
        cout << "选类型（1图书 2杂志 3电子资源）："; int t = readInt();
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
        } else {
            cout << "网址："; string url = readLine();
            cout << "格式："; string format = readLine();
            lib.addResource(new eresource(name, pub, price, url, format));
        }
        lib.savetoFile("resources.txt");
        cout << "添加资源成功！" << endl;
    } else if (choice == 13) {
        doregister();
    } else if (choice == 14) {
        user* target = current;
        if (isadmin()) {
            cout << "输入要注销的编号（直接回车=注销自己）："; string tid = readLine();
            if (!tid.empty()) {
                target = lib.login(tid);
                if (target == nullptr) { cout << "找不到该账号" << endl; return false; }
            }
        }
        if (target->Getborrowcount() > 0) {
            cout << "注销失败：该账号还有未归还的书" << endl;
        } else if (target->Getrolename() == "管理员" && lib.admincount() <= 1) {
            cout << "注销失败：不能注销最后一个管理员" << endl;
        } else {
            bool self = (target == current);
            lib.removeuser(target);
            lib.saveUsers("users.txt");
            if (self) { cout << "账号已注销，请重新登录。" << endl; return true; }
            cout << "已注销该账号" << endl;
        }
    } else {
        cout << "无效选择，请重新输入" << endl;
    }
    return false;
}
void menu::run(){
    while(true){
   dologin();            //登录
   bool logout=false;
   while(!logout)       //  菜单循环
   {
    showmenu();
    int choice=readInt();
    if(choice==0){
        lib.saveUsers("users.txt");
        lib.savetoFile("resource.txt");
        cout << "已自动保存，再见！" << endl;
        return;
    }
    logout=handle(choice);
   }
         // logout=true → 跳出菜单 → 外层 while 再次 dologin()
   
    }
}