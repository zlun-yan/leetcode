//
// Created by ZlunYan on 2021/6/4.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode *pointA = headA, *pointB = headB;
    while (pointA->next != nullptr) {lenA ++; pointA = pointA->next;};
    while (pointB->next != nullptr) {lenB ++; pointB = pointB->next;}
    if (pointA != pointB) return nullptr;
    pointA = headA; pointB = headB;
    if (lenA > lenB) while ((lenB ++) != lenA) pointA = pointA->next;
    else while ((lenA ++) != lenB) pointB = pointB->next;
    while (true) {
        if (pointA == pointB) return pointA;
        pointA = pointA->next; pointB = pointB->next;
    }
}

 int main () {
    ListNode *headA = new ListNode(4), *headB = new ListNode(5);
    ListNode *tempA = headA, *tempB = headB;
    tempA->next = new ListNode(1); tempA = tempA->next;
    tempA->next = new ListNode(8); tempA = tempA->next;
    tempB->next = new ListNode(0); tempB = tempB->next;
    tempB->next = new ListNode(1); tempB = tempB->next;
    tempB->next = tempA;
    tempA->next = new ListNode(4); tempA = tempA->next;
    tempA->next = new ListNode(5);

    cout << getIntersectionNode(headA, headB)->val << endl;
    return 0;
 }