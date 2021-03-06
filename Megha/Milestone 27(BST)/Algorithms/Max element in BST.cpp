#include <iostream>
using namespace std;

//to create structure of binary search tree
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* root;

//to create a note
Node* GetNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//To insert a node
Node* Insert(Node* root,int data){
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;
}

//to search if the number is present or not in binary tree
bool Search(Node* root,int data){
    if(root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data <= root->data){
        return Search(root->left,data);
    }
    else
    return Search(root->right,data);
}

//Iterative solution to find maximum element
int maxIterative(Node* root){
    if(root == NULL){
        cout<<"The tree is empty"<<endl;
        return -1;
    }

     Node* current = root;
     while(current->right){
         current = current->right;
     }
     return current->data;
}

//Recursive solution to find maximum element
int maxRecursive(Node* root){
    if(root == NULL){
        cout<<"The tree is empty"<<endl;
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return maxRecursive(root->right);
}

int main() {
    root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    int number;
    cin>>number;
    cout<<"Enter no. to be searched "<<number<<endl;
    if(Search(root,number) == true){
        cout<<"Found"<<endl;
    }
    else{
      cout<<" Not Found"<<endl;
    }

    cout<<"Iterative solution maximum element is "<<maxIterative(root)<<endl;
    cout<<"Recursive solution maximum element is "<<maxRecursive(root);

}
