#include <iostream>
using namespace std;

struct node{
    node *next;
    int val;
};

// check if there exists a loop
bool check(node *head){
    node *slow, *fast;
    slow = fast = head;
    if(head->next==nullptr) return false;  // no loop
    fast = head->next;
    while(fast!=nullptr && fast != slow){
        slow = slow->next;   // one step
        fast= fast->next;
        if(fast==nullptr) return false; // no loop
        else fast = fast->next;   // two step
    }
    if(fast==slow) return true; // exist loop
    else return false;  // fast==nullptr, no loop
}

int main(){
    // 创建无环链表 1->2->3->nullptr
    node *n1 = new node{nullptr, 1};
    node *n2 = new node{nullptr, 2};
    node *n3 = new node{nullptr, 3};
    n1->next = n2;
    n2->next = n3;

    cout << "无环链表: " << (check(n1) ? "有环" : "无环") << endl;

    // 创建有环链表 4->5->6->5...
    node *m1 = new node{nullptr, 4};
    node *m2 = new node{nullptr, 5};
    node *m3 = new node{nullptr, 6};
    m1->next = m2;
    m2->next = m3;
    m3->next = m2; // 构成环

    cout << "有环链表: " << (check(m1) ? "有环" : "无环") << endl;

    // 释放内存（有环链表不适合直接delete，实际测试时可忽略）
    delete n1; delete n2; delete n3;
    // m1, m2, m3 不要delete，否则死循环

    return 0;
}




