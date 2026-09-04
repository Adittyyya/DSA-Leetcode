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

    bool isIdentical(TreeNode* p, TreeNode* q){
        //base case
        if(p == NULL || q == NULL){
            return p == q;
        }

        bool isLeft = isIdentical(p->left, q->left);
        bool isRight = isIdentical(p->right, q->right);

        return isLeft && isRight && p->val == q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //base case
        if(root == NULL || subRoot == NULL){
            return root == subRoot;
        }

        if(root->val == subRoot->val && isIdentical(root, subRoot)){//for 1st or upper
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};