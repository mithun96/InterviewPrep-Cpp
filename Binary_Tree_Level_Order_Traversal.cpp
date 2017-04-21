
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).


 
class Solution {

    
public:


    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (!root)
            return ans;

        buildAns(root, 0, ans);
        return ans;
    }
    
    void buildAns(TreeNode* s, int level, vector<vector<int>> &ans){
        
        if (s == NULL){
            return;
        }
        
        if (ans.size() == level){
            ans.push_back(vector<int>());
        }
        
        ans[level].push_back(s->val);
        buildAns(s->left, level+1, ans);
        buildAns(s->right, level+1, ans);
    }
    
};


// Second solution= with bfs search. has QUEUES and no recursion



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) { return {}; }
        vector<int> row;
        vector<vector<int> > result;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;

            while (!q.empty()) {
            if (q.front()->left) { 
                q.push(q.front()->left); 
            }

            if (q.front()->right) { 
                q.push(q.front()->right); 
            }
            row.push_back(q.front()->val), q.pop();
            if (--count == 0) {
                result.emplace_back(row), row.clear();
                count = q.size();
            }
        }
        return result;
    }
};
