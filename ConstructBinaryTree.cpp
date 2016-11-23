#include <iostream>
#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *help(int *startPre, int *endPre, int *startIn, int *endIn);

TreeNode *Construct(int *preorder, int *inorder, int length) {
    if (preorder == NULL || inorder == NULL || length <= 0)
    {
        return NULL;
    }
    return help(preorder, preorder+length-1, inorder, inorder+length-1);
}

TreeNode *help(int *startPre, int *endPre, int *startIn, int *endIn) {
    TreeNode *root = new TreeNode();
    root->val = *startPre;
    root->left = NULL;
    root->right = NULL;

    int *rootInOrder = startIn;
    while (rootInOrder <= endIn) {
        if (*rootInOrder == *startPre)
        {
            break;
        }
    }

    int leftLength = rootInOrder - startIn;
    if (leftLength)
    {
        root->left = help(startPre+1, startPre+leftLength, startIn, rootInOrder-1);
    }
    if (leftLength < endPre - startPre)
    {
        root->right = help(startPre+leftLength+1, endPre, rootInOrder+1, endIn);
    }
    return root;
}


void BackOrder(TreeNode *root) {
    BackOrder(root->left);
    BackOrder(root->right);
    if (root)
    {
        printf("%d\n", root->val);
    }

}
int main(){
    TreeNode t1;
    TreeNode t2;
    TreeNode t3;
    TreeNode t4;

    t1.val = 1;
    t2.val = 2;
    t3.val = 3;
    t4.val = 4;

    t1.left = &t2;
    t1.right = &t3;
    t2.left = NULL;
    t2.right = &t4;
    t3.left = NULL;
    t3.right = NULL;
    t4.left = NULL;
    t4.right = NULL;

    int preorder[] = {1,2,4,3};
    int inorder[] = {2,4,1,3};
    TreeNode *root = Construct(preorder, inorder, 4);

    BackOrder(root);

    return 0;

}