//
// Created by ZlunYan on 2021/5/22.
//

#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != nullptr) {
        temp->next = temp1;
    } else if (temp2 != nullptr) {
        temp->next = temp2;
    }
    return dummyHead->next;
}

ListNode* sortList(ListNode* head, ListNode* tail) {
    if (head == nullptr) {
        return head;
    }
    if (head->next == tail) {
        head->next = nullptr;
        return head;
    }
    ListNode* slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    ListNode* mid = slow;
    // 这个求 链表中间节点的方法可以学习学习
    return merge(sortList(head, mid), sortList(mid, tail));
}

ListNode* sortList(ListNode* head) {
    return sortList(head, nullptr);
}

ListNode* sortListTemp(ListNode* head) {
    // 基数排序 因为有负数 所以基数排序实现不了
    if (head == nullptr) return head;
    ListNode *list[15], *ptr[15];
    for (int i = 0; i < 10; i++) list[i] = new ListNode();
    bool doit = true;
    int cardinal = 1;

    while (doit) {
        doit = false;
        cardinal *= 10;
        ListNode *temp = head->next, *nxtTemp;
        for (int i = 0; i < 10; i++) ptr[i] = list[i];
        while (temp != nullptr) {
            int judge = temp->val % cardinal * 10 / cardinal;  // 负数
            nxtTemp = temp->next;
            ptr[judge]->next = temp; ptr[judge] = ptr[judge]->next; ptr[judge]->next = nullptr;

            if (temp->val >= cardinal * 10) doit = true;
            temp = nxtTemp;
        }

        temp = head;
        for (int i = 0; i < 10; i++) {
            ptr[i] = list[i]->next;
            while (ptr[i] != nullptr) {
                temp->next = ptr[i];
                ptr[i] = ptr[i]->next;
                temp = temp->next;
            }
        }
    }

    return head;
}

ListNode* createList(int array[], int len) {
    ListNode *head = new ListNode();
    ListNode *temp = head;
    for (int i = 0; i < len; i++) {
        temp->next = new ListNode(array[i]); temp = temp->next;
    }

    return head;
}

int main() {
    // [-1,5,3,4,0]

    int array[] = {-1,5,3,4,0};
    ListNode *head = createList(array, 5);

    printf("pre\n");
    ListNode *temp = head->next;
    while (temp != nullptr) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    printf("\nafter\n");
    temp = sortList(head->next);
    while (temp != nullptr) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}