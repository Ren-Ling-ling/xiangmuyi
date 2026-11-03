# 图书馆借阅管理系统

面向对象程序设计（C++）课程综合项目。一个基于控制台的图书馆借阅管理系统，综合运用了类与对象、组合/依赖、继承派生、多态、模板与 STL、文件输入输出等 C++ 面向对象核心知识。

## 功能特性

- **资源管理**：管理一般图书、杂志、电子资源三类资源，支持添加、删除、按名称查找、按类型筛选、显示全部
- **用户管理**：管理学生、教师两类用户
- **用户登录**：凭学号/工号登录，非注册用户无法操作
- **借阅归还**：借书、还书，自动记录借阅时间
- **借阅记录**：查看当前用户借了哪些资源、借阅时间
- **逾期罚款**：按借阅天数与类型计算逾期罚款（图书 0.5 元/天、杂志 0.3 元/天、电子资源无罚款）
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

## 初始账号

| 角色 | 姓名 | 登录 ID |
|---|---|---|
| 学生 | 张三 | 20258967 |
| 教师 | 李老师 | T1001 |
| 学生 | 李四 | 20250001 |

> 首次运行会自动创建上述用户，之后从 `users.txt` 加载。

## 项目结构

```
src/
├── resource.h / resource.cpp   资源基类（抽象类，含纯虚函数）
├── book.h / book.cpp           一般图书（继承 resource）
├── magazine.h / magazine.cpp   杂志（继承 resource）
├── eresource.h / eresource.cpp 电子资源（继承 resource）
├── user.h / user.cpp           用户基类（含借阅记录、借还功能）
├── student.h / student.cpp     学生（继承 user）
├── teacher.h / teacher.cpp     教师（继承 user）
├── library.h / library.cpp     图书馆管理类（组合资源与用户）
├── utility.h                   函数模板 printAll<T>（迭代器遍历）
└── main.cpp                    主程序（登录 + 交互式菜单）
```

## 设计说明

### 类关系

- **继承**：`book`/`magazine`/`eresource` 继承抽象基类 `resource`；`student`/`teacher` 继承 `user`
- **组合**：`library` 通过 `vector<resource*>`、`vector<user*>` 拥有资源与用户
- **依赖**：`user::borrowbook(resource&)` 借阅时使用资源；`library::borrow(name, user&)` 使用用户

### 面向对象特性

- **封装**：成员变量私有/保护，通过公有接口访问
- **抽象**：`resource` 为抽象类，`show()`、`writetoFile()` 为纯虚函数
- **继承与多态**：通过虚函数（`show`/`borrow`/`returnItem`/`writetoFile`/`calfine` 等）实现动态联编；虚析构保证正确释放
- **模板（泛型）**：`printAll<T>` 一份代码同时打印资源与用户，体现模板复用
- **STL 与迭代器**：使用 `vector` 组织对象，`printAll` 用迭代器遍历
- **文件 I/O**：`ofstream`/`ifstream` 实现对象的保存与读取；通过"类型标识 + 虚函数 + 按类型重建"实现多态序列化

## 技术栈

- 语言：C++17
- 构建：CMake + MinGW-w64 (g++)
- 版本控制：Git（托管于 GitHub）
