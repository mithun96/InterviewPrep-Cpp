TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if (!root || !p || !q) {
        return NULL;
    }
     // find either p or q
    if (root == p || root == q) {
        return root;
    }
    
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    
    // p and q are in different subtrees
    if(l && r) return root;

    // p and q are in the same subtree
    if (l)
        return l;
    else 
        return r;

}