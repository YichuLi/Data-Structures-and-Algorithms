#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
    ListNode() : val(0), next(nullptr) {}
};

class Solution{
public:
    ListNode* reverseList_1(ListNode* head){
        ListNode* reverse = NULL;
        ListNode* next = NULL;
        while(head){
            next = head->next;
            head->next = reverse;
            reverse = head;
            head = next;
        }
        return reverse;
    }

    ListNode* reverseList_2(ListNode* head){
        ListNode temp;  // why this temp cannot be ListNode* ? gotta find out.
        ListNode* next = NULL;
        while(head){
            next = head->next;
            head->next = temp.next;
            temp.next = head;
            head = next;
        }
        return temp.next;
    }
};

void printList(ListNode* head, const char* name){
    cout << name << ": ";
    if(!head){  // head is NULL
        cout << "NULL" << endl;
    }
    else{
        while(head){
            cout << "[" << head->val << "]";
            head = head->next;
        }
        cout << endl;
    }
}

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    ListNode* head = &a;
    Solution sol;

    // printList(head, "M1: old list");
    // head = sol.reverseList_1(head);
    // printList(head, "M1: new list");

    // a.next = &b;
    // b.next = &c;
    // c.next = &d;
    // d.next = &e;
    // head = &a;

    printList(head, "M2: old list");
    head = sol.reverseList_2(head);
    printList(head, "M2: new list");

    return 0;
}