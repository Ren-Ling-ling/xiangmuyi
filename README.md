# 图书馆借阅管理系统

面向对象程序设计（C++）课程综合项目。一个基于控制台的图书馆借阅管理系统，综合运用了类与对象、组合/依赖、继承派生、多态与虚函数、模板与 STL、文件输入输出等 C++ 面向对象核心知识，并采用 Menu 类对界面进行封装，实现界面与业务分层。

## 功能特性

- **资源管理**：管理一般图书、杂志、电子资源三类资源，支持添加、删除、按名称查找、按类型筛选、显示全部
- **用户管理**：管理学生、教师、管理员三类用户
- **注册与登录**：登录界面输入 `R` 可自助注册（可选学生/老师/管理员），之后凭编号登录；未注册用户无法操作
- **权限控制**：仅管理员可增删资源、添加用户；学生与老师仅可借还、查询
- **借阅归还**：借书、还书，自动记录借阅时间与期限
- **借阅记录**：查看当前用户借了哪些资源、借阅时间，并标出是否逾期
- **逾期罚款**：按借阅天数与类型计算逾期罚款（图书 0.5 元/天、杂志 0.3 元/天、电子资源无罚款）
- **账号注销**：学生/老师只能注销自己，管理员可注销任意账号；有未归还的书不能注销；不能注销最后一个管理员
- **数据持久化**：启动自动加载、退出自动保存，数据存于 `resources.txt` 与 `users.txt`
- **交互式菜单**：通过菜单选择各项操作

## 如何编译运行

### 方式一：VS Code + CMake（推荐）

1. 用 VS Code 打开项目文件夹
2. 按 `F5`（构建并调试）或 `Ctrl+Shift+B`（仅构建）
3. 生成的程序位于 `build/xiangmuyi.exe`

### 方式二：命令行 g++

```bash
g++ -std=c++17 src/*.cpp -o xiangmuyi
./xiangmuyi
```

> 提示：程序采用 GBK 输出以匹配中文控制台。若在 VS Code 调试控制台（F5）出现乱码，请在集成终端直接运行 `build/xiangmuyi.exe`，或使用 `Ctrl+F5`。

## 首次使用（账号）

本项目不内置固定账号，全部通过注册创建：

1. 运行程序后，在登录提示处输入 `R`，选择注册类型（学生/老师/管理员）并填写信息；
2. 注册成功后，凭**学号/工号/管理员编号**登录；
3. 建议先注册一个**管理员**账号，以便增删资源、添加用户。

## 项目结构

```
src/
├── resource.h / resource.cpp   资源抽象基类（纯虚 show/writetoFile，借还/期限/罚款）
├── book.h / book.cpp           一般图书（继承 resource，ISBN 校验）
├── magazine.h / magazine.cpp   杂志（继承 resource）
├── eresource.h / eresource.cpp 电子资源（继承 resource，可多人借阅）
├── user.h / user.cpp           用户抽象基类（借阅记录、借还、纯虚 GetuserId/Getrolename）
├── student.h / student.cpp     学生（继承 user）
├── teacher.h / teacher.cpp     教师（继承 user）
├── admin.h / admin.cpp         管理员（继承 user）
├── library.h / library.cpp     图书馆管理类（组合管理资源与用户、存读文件、登录、注销）
├── menu.h / menu.cpp           界面类（登录/注册/菜单显示/操作分发）
├── utility.h                   函数模板 printAll<T>（迭代器遍历）
└── main.cpp                    主程序（创建库、加载数据、启动菜单）
```

## 设计说明

### 类关系

- **继承**：`book`/`magazine`/`eresource` 继承抽象基类 `resource`；`student`/`teacher`/`admin` 继承 `user`
- **组合**：`library` 通过 `vector<resource*>`、`vector<user*>` 拥有资源与用户集合
- **依赖**：`user::borrowbook(resource&)` 借阅时使用资源；`library::borrow(name, user&)` 使用用户

### 面向对象特性

- **封装**：成员变量私有/保护，通过公有接口访问；界面逻辑封装在 `menu` 类
- **抽象**：`resource`、`user` 为抽象类（含纯虚函数）
- **继承与多态**：通过虚函数（`show`/`borrow`/`returnItem`/`writetoFile`/`calfine`/`getborrowdays`/`GetuserId`/`Getrolename` 等）实现动态联编；虚析构保证正确释放
- **模板（泛型）**：`printAll<T>` 一份代码同时打印资源与用户
- **STL 与迭代器**：使用 `vector` 组织对象，`printAll` 用迭代器遍历
- **文件 I/O**：`ofstream`/`ifstream` 实现对象的保存与读取；通过“类型标识 + 虚函数 + 按类型重建”实现多态序列化
- **常量化**：借阅期限、罚款、最大借阅量提取为类静态常量，修改只需一处

### 分层结构

- `main`：搭架子（创建 library、加载数据、启动菜单）
- `menu`：界面/交互（登录、注册、显示、分发）
- `library`：数据/业务（资源、用户、文件读写）
- `resource`/`user` 体系：各类自身的数据与行为

## 技术栈

- 语言：C++17
- 构建：CMake + MinGW-w64 (g++)
- 版本控制：Git（托管于 GitHub）
