#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class MaxPathSumFinder {
public:
    int findMaxPathSum(TreeNode* root) {
        maxSum = numeric_limits<int>::min();
        findMaxPathSumFromNode(root);
        return maxSum;
    }

private:
    int maxSum;

    int findMaxPathSumFromNode(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftMaxPath = max(0, findMaxPathSumFromNode(node->left));
        int rightMaxPath = max(0, findMaxPathSumFromNode(node->right));

        maxSum = max(maxSum, leftMaxPath + rightMaxPath + node->data);

        return max(leftMaxPath, rightMaxPath) + node->data;
    }
};

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    MaxPathSumFinder pathSumFinder;
    int maxPathSumResult = pathSumFinder.findMaxPathSum(root);

    cout << "The Maximum Path Sum for this tree is " << maxPathSumResult << endl;

    // Clean up allocated memory to prevent memory leaks
    deleteTree(root);

    return 0;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
