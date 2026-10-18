
#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void solve(TreeNode* root, int targetSum, int sum,
               vector<int>& temp, vector<vector<int>>& ans) {

        if (root == nullptr) return;

        temp.push_back(root->val);
        sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                ans.push_back(temp);
            }
        }

        solve(root->left, targetSum, sum, temp, ans);
        solve(root->right, targetSum, sum, temp, ans);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;

        solve(root, targetSum, 0, temp, ans);

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution sol;
    vector<vector<int>> ans = sol.pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":\n";

    for (const auto& path : ans) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
