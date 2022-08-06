/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-08-06 13:58:43
 */
#include<iostream>
#include<stdlib.h>
using namespace std;
template<typename T>
class myStack
{
private:
    /* data */
    struct Node
    {
        /* data */
        T elem;
        Node* next;
    };
    Node* head;
    Node* curP;
    int length;
    
public:
    myStack(/* args */){
        head = nullptr;
        length = 0;
    };
    ~myStack(){

    };
    void push(T data) {
        Node* q = new Node;
        q->elem = data;
        if (head == nullptr) {
            q->next = head;
            head = q;
            curP = q;
        }
        else {
            q->next = curP; 
            curP = q;
        }
        length++;
    }
    T pop() {
        if (length <= 0) {
            exit(1);
        }
        T data = curP->elem;
        Node* q = curP;
        curP = curP->next;
        delete q;
        length--;
        return data;
    }
    int size() {
        return length;
    }
    T top() {
        return curP->elem;
    }
    bool empty() {
        return length > 0;
    };
    void clear() {
        while (length > 0) {
            pop();
        }
    }
};
template<typename T> // 扩容麻烦
class arrayStack
{
private:
    T* nums;
    int maxSize;
    int cur;
public:
    arrayStack(/* args */) {
        maxSize = 10000;
        nums = new T[maxSize];
        cur = 0;
    }
    ~arrayStack() {
        delete[] nums;
    }
    void push(T data) {
        nums[cur] = data;
        cur++;
    }
    T top() {
        return nums[0];
    }
    T pop() {
        if(cur > 0)
            cur--;
        else
            exit(1);
        T ans = nums[cur];
        return ans;
    }
    int size() {
        return cur;
    }
};

// 二维数组
template<typename T>
class reStack
{
private:
    int mpSize;
    int bufSize;
    int node;
    int cur; // end == bufSize
    T** base;
    T* curBuf;
public:
    reStack(/* args */) {
        bufSize = 2;
        curBuf = new T[bufSize];
        *base = curBuf;
        cur = 0; // 下一个要插入的位置
        node = 0; // 当前所在buf
        mpSize = 1;
    };
    ~reStack() {
        // int a = 3;
        // cout<<a<<endl;
        // cout<<cur<<endl;
        // printf("%d",mpSize);
        // for(int i = 0; i < 3; i++) {
        // }
    };
    void push(T data) {
        if (cur == bufSize) {
            if (node + 1 == mpSize) {
                T** tmp = base;
                node++;
                mpSize++;
                base = new T*[mpSize];
                for (int i = 0; i < mpSize - 1; i++) {
                    base[i] = tmp[i];
                }
                cur = 0;
                curBuf = new T[bufSize];
                base[node] = curBuf;
            }
            else {
                node++;
                cur = 0;
                curBuf = base[node];
            }
            
        }
        curBuf[cur] = data;
        cur++;
    }
    T pop() {
        T data;
        cur--;
        if (cur < 0) {
            node--;
            cur = bufSize - 1;
            data = base[node][cur];
            curBuf = base[node];
        }
        else
            data = curBuf[cur];
        return data;
    }
    T top() {
        T data;
        if (cur - 1 < 0) {
            data = base[node - 1][bufSize - 1];
        }
        else
            data = curBuf[cur - 1];
        return data;
    }
    int size() {
        return node * bufSize + cur;
    }
    bool empty() {
        return this->size()==0;
    }
    void print() {
        // printf("%d\n",base[0][0]);
        // printf("%d\n",base[1][0]);
        // printf("%d\n",base[2][0]);
        for(int i = 0; i < 3; i++) {
            printf("%d\n",base[i][0]);
        }
    }
    
};
