
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int, int> maxSum(TreeNode* node){
        if(!node) return {-1e7,0};

        pair<int, int> maxSumResultFromLeft = maxSum(node->left);
        pair<int, int> maxSumResultFromRight = maxSum(node->right);

        int maxSumFromBranching =max(node->val,node->val + max(maxSumResultFromLeft.second, maxSumResultFromRight.second));
        int maxFromChildrenNodes = max(maxSumResultFromLeft.first, maxSumResultFromRight.first);
        int maxAtNode = max(max(maxFromChildrenNodes, maxSumFromBranching), node->val+maxSumResultFromLeft.second+maxSumResultFromRight.second);

        //cout << maxAtNode << " - " << maxSumFromBranching << endl;
        return {maxAtNode, maxSumFromBranching};
    }

    int maxPathSum(TreeNode* root) {
        return maxSum(root).first;
    }
};