#ifndef library_h
#define library_h
#include<vector>
#include<string>
#include"resource.h"
#include"user.h"
using namespace std;
class library{
private:
// 【实验思考：放对象 vs 放指针】
    // 1) 不能用 vector<resource> 放对象：
    //    a. resource 是抽象类（纯虚 show），无法实例化，vector<resource> 编译不过
    //    b. 即使能（非抽象基类），放对象会发生"对象切片"——只保留基类部分，
    //       派生类特有成员（isbn/url 等）被切掉
    //    c. 放对象无法多态（按值存储，没有虚函数表指针的动态绑定）
    // 2) 所以用 vector<resource*> 放指针：
    //    a. 存的是地址，对象完整保留在堆上
    //    b. 多态生效（show/borrow 按实际类型调用）
    //    c. 代价：需要 new / delete 管理内存（见析构函数）
    // 3) 基类和派生类能放同一个 vector 吗？——能！
    //    用基类指针 vector<resource*>，book/magazine/eresource 都能放进去
vector<resource*> resources;
vector<user*>users;
public:
library();
~library();
void addResource(resource*r);
void adduser(user*u);
void showall();
void showusers();
void borrow(const string& name, user& u);
resource*find(const string&name);
void returnRes(const string&name,user&u);
void remove(const string&name);
void savetoFile(const string&filename);
};
#endif
