#include "linkedList.h"

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr){
        return;
    }

    ListNode* pToBeDeleted = nullptr;
    // When the first node is the one to be deleted
    if((*pHead)->m_nValue == value){
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else{
        ListNode* pNode = *pHead;
        // When next is exsist and next's value is not equal to value
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value){
            pNode = pNode->m_pNext;
        }
        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value){
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    if(pToBeDeleted != nullptr){
        delete pToBeDeleted;

        pToBeDeleted = nullptr; // why need this operation?
        // delete p后，只是释放了指针中存放的地址中的内存空间。
        // 但是指针变量p仍然存在（即指针p本身所占有的内存），且p中存放的地址还是原来的地址
        // 在删除一个指针之后，一定要将该指针设置成空指针，即在delete p之后，要加上： p = NULL
    }
}