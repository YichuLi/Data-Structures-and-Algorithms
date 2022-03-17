
// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

#include <stdio.h>

struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
    BinaryTreeNode*        m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
    if(!pNode){
        return nullptr;
    }

    // 存在该节点的右子树
    if(pNode->m_pRight){
        while(pNode->m_pLeft){
            pNode = pNode->m_pLeft;
        }
        return pNode;
    }

    // 存在该节点的父节点
    while(pNode->m_pParent){
        // pNode不是根节点
        if(pNode == pNode->m_pParent->m_pLeft){
            return pNode->m_pParent;
        }
    }
    // 不存在该节点的父节点
    return nullptr;
}