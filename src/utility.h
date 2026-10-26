#ifndef utility_h
#define utility_h
#include<vector>
using namespace std;

template <typename T>
void printAll(const vector<T*>& v){
    for(auto it=v.begin();it!=v.end();++it){
       (*it)->show();
    }
}
#endif