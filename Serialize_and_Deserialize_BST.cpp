/*Serialization is the process of converting a data structure or object into a sequence of 
bits so that it can be stored in a file or memory buffer, or transmitted across a network 
connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no 
restriction on how your serialization/deserialization algorithm should work. You just 
need to ensure that a binary search tree can be serialized to a string and this string 
can be deserialized to the original tree structure.
*/



//***********************************************
//              uses memcpy to convert int to string 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string order;
        inorderDFS(root, order);
        return order;
    }
    
    inline void inorderDFS(TreeNode* root, string& order) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for (int i=0; i<4; i++) order.push_back(buf[i]);
        inorderDFS(root->left, order);
        inorderDFS(root->right, order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }
    
    inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.
        
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;
        
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
};



//*******************************************************
//.        Done without recursion (little more confusing)
//.          uses to_string() and stoi




class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // preorder traversal
        string ret;
        if(!root) return ret;
        
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *r = stk.top();
            stk.pop();
            ret += to_string(r->val) + ",";
            if(r->right) stk.push(r->right);
            if(r->left) stk.push(r->left);

        }
        return ret.substr(0, ret.size()-1);
    }

    // Decodes your encoded data to tre.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        
        int id = 0;
        // take root at first
        int r = id;
        while(isdigit(data[r])) r++;
        int v = stoi(data.substr(id, r-id));
        id = r+1;

        TreeNode *root = new TreeNode(v);
        stack<TreeNode*> stk;
        stk.push(root);

        while(id < (int) data.size()) {
            int r = id;
            while(isdigit(data[r])) r++;
            int v = stoi(data.substr(id, r - id));
            id = r + 1;

            TreeNode *node = nullptr;
            while(!stk.empty() && v > stk.top()->val) {
                node = stk.top();
                stk.pop();
            }
            if(node) {
                node->right = new TreeNode(v);
                stk.push(node->right);
            } else {
                stk.top()->left = new TreeNode(v);
                stk.push(stk.top()->left);
            }
        }

        return root;
    }
    // for debug
    void f(TreeNode *root) {
        if(!root) return;
        f(root->left);
        cout << root->val << ", ";
        f(root->right);
    }
};