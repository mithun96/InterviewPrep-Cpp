

/*
          InOrder Traversal = (Left, root, right)
          PreOrder Traversal = (Root, left, right)
          PostOrder Traversal = (Left, right, root)

*/


void printInorder(struct node* node)
{
     if (node == NULL)
          return;
 
     printInorder(node->left);
 
     printf("%d ", node->data);  
 
     printInorder(node->right);
}
 
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
 
     printf("%d ", node->data);  
 
     printPreorder(node->left);  
 
     printPreorder(node->right);
}    

void printPostorder(struct node* node)
{
     if (node == NULL)
        return;
 
     printPostorder(node->left);
 
     printPostorder(node->right);
 
     printf("%d ", node->data);
}