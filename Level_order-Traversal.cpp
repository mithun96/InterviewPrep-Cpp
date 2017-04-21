


void LevelOrderTraversal (node * root){
  queue <node *> q;
  if (root == NULL){
      return;
  }
    
  q.push(root);
  while (1){
      if (q.empty())
          break;
      
      while (q.size() > 0) {
    
          node * cur = q.front();
          q.pop();
          cout << cur->data << " ";

          if (cur->left != NULL){
              q.push(cur->left);
          }
          if (cur->right != NULL){
              q.push(cur->right);
          }


      }
      cout << endl;
  }
}