// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

#include "..\Utilities\BinaryTree.h"
#include <exception>
#include <cstdio>

#include <unordered_map>
using namespace std;

class Solution{
public:
    unordered_map<int,int> pos;
    BinaryTreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0; i<n; i++){
            pos[inorder[i]] = i;
        }

        return dfs(preorder, inorder, 0, n-1, 0, n-1);
    }

    BinaryTreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        // preorder: root, left, right
        // inorder: left, root, right
        if(pl > pr){    // empty tree
            return NULL;
        }
        // find the root node
        BinaryTreeNode* root = new BinaryTreeNode();
        root->m_nValue = preorder[pl];
        // size of left tree: k
        int k = pos[root->m_nValue];
        
        root->m_pLeft = dfs(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
        root->m_pRight = dfs(preorder, inorder, pl + k + 1, pr, il + k + 1, ir);
    }
};