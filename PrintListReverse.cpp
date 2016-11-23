#include <iostream>
#include "stdio.h"
#include <stack>
using namespace std;

struct ListNode{
    int m_val;
    ListNode *m_pNext;
};

void PrintListReverse(ListNode *pHead){
    if (pHead)
    {
        if (pHead->m_pNext)
            PrintListReverse(pHead->m_pNext);
        printf("%d\t", pHead->m_val);
    }
}

void PrintListReverseStack(ListNode *pHead) {
    stack<int> nodeval;
    while (pHead) {
        nodeval.push(pHead->m_val);
        pHead = pHead->m_pNext;
    }
    while (!nodeval.empty()) {
        printf("%d\t", nodeval.top());
        nodeval.pop();
    }
}

int main(){
    ListNode n1, n2, n3, n4;
    n1.m_val = 1;
    n2.m_val = 2;
    n3.m_val = 3;
    n4.m_val = 4;
    n1.m_pNext = &n2;
    n2.m_pNext = &n3;
    n3.m_pNext = &n4;
    n4.m_pNext = NULL;
    PrintListReverse(&n1);
    printf("\n");
    PrintListReverseStack(&n1);

    return 0;
}