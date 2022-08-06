/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-08-06 14:47:25
 */
#include "myStack.hpp"
using namespace std;
#include <iostream>

int main(int argc, char const *argv[])
{
    reStack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;

    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    s.print();
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // if(!s.empty()) {
    //     cout<<s.pop()<<endl;
    //     cout<<s.size()<<endl;
    // }
        
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.empty()<<endl;
    return 0;
}
