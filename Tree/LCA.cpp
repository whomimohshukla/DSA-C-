
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // Base case
    if (root == nullptr)
        return nullptr;

    // If current node is p or q
    if (root == p || root == q)
        return root;

    // Search in left and right subtrees
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // Neither target found
    if (left == nullptr && right == nullptr)
        return nullptr;

    // Target found on the left
    else if (left != nullptr && right == nullptr)
        return left;

    // Target found on the right
    else if (left == nullptr && right != nullptr)
        return right;

    // Targets found on both sides
    else
        return root;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;  // Node 5
    TreeNode *q = root->right; // Node 1

    TreeNode *ans = lowestCommonAncestor(root, p, q);

    if (ans != nullptr)
        cout << "LCA: " << ans->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
