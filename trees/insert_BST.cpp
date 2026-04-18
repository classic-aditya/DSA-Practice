// LEETCODE-701 : Insert into a binary search tree
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// LEETCODE - SOLUTION
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *ptr = root;

        if(ptr == NULL){
            return new TreeNode(val);
        }
        else if(val > ptr->val){
            if(ptr->right == NULL){
                TreeNode* node = new TreeNode(val);
                ptr->right = node;
                return root;
            }
            else{
                insertIntoBST(ptr->right, val);
            }
        }
        else{
            if(ptr->left == NULL){
                TreeNode* node = new TreeNode(val);
                ptr->left = node;
                return root;
            }
            else{
                insertIntoBST(ptr->left, val);
            }
        }

        return root;
    }
};

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution obj;

    TreeNode* root = NULL;

    root = obj.insertIntoBST(root, 4);
    root = obj.insertIntoBST(root, 2);
    root = obj.insertIntoBST(root, 7);
    root = obj.insertIntoBST(root, 1);
    root = obj.insertIntoBST(root, 3);
    root = obj.insertIntoBST(root, 6);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}