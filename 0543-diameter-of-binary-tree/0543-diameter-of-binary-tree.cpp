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
    int maxdepth(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int lft=maxdepth(node->left);
        int rgt=maxdepth(node->right);
        return 1+max(lft,rgt);
    }
    int help( TreeNode* root){
        if(root == nullptr) return 0;
        int dia = maxdepth(root->left)+maxdepth(root->right);

        int maxi = max(help(root->left),max(help(root->right),dia));
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        return help(root);
        

    }
};