#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traversal(TreeNode* root) {
        if (!root) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        traversal(root->left);
        traversal(root->right);    
    }

    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    // Print the inverted tree (inorder traversal)
    std::cout << "Inverted tree (inorder traversal): ";
    printInorder(invertedRoot);
    std::cout << std::endl;

    // TODO: Free the allocated memory for the tree nodes to avoid memory leaks

    return 0;
}

void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        std::cout << root->val << " ";
        printInorder(root->right);
    }
}


// link to the problem in leetcode: https://leetcode.com/problems/invert-binary-tree/