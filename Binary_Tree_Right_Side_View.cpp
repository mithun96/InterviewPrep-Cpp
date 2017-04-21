/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        int level = 0;
        
        dfs(root, ans, level);
        
        
        return ans;

    }
    
    void dfs(TreeNode *root, vector<int> &ans, int level){
        
        if(root == NULL){
            return;
        }
        
        if(ans.size() == level){
            ans.push_back(root->val);
        }
        
        if (root->right != NULL){
            dfs(root->right, ans, level+1);
        }
        if (root->left != NULL){
            dfs(root->left, ans, level+1);
        }
    }
    
    
    
    
    
    
    
};