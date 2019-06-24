#include<bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode(int key)
    {
        this->val = key;
        this->left = this->right = NULL;
    }
};


// deepest node is with maximum level
int mxValue = 0, mxlevel = 0;

void deepest(TreeNode* root, int level){
    if(root == NULL){
        return;
    }
    deepest(root->left, level+1);
    deepest(root->right, level+1);
    if(level > mxlevel){
        mxlevel = level;
        mxValue = root->val;
    }
}

int main(){
	TreeNode* root = NULL;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    deepest(root,0);

}