// depth of a binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

class BST{
    private:
        struct TreeNode{
            TreeNode* left;
            TreeNode* right;
            int val;
            TreeNode(int x):val(x),left(NULL),right(NULL){}
        };
        TreeNode *root;

    public:
        BST(){
            root = NULL;
        }
        BST(int d){
            root->val = d;
            root->left = NULL;
            root->right = NULL;
        }

        ~BST(){

        }
        bool isEmpty() const {
            return root==NULL;
        }
        void printInorder(TreeNode*);
        void printInorder();
        void printPreorder(TreeNode*);
        void printPostorder(TreeNode*);
        void printPostorder();
        TreeNode* insert(TreeNode*, int);
        void insert(int);
        void remove(int);
        int countNodes(TreeNode*);
        int lookup(TreeNode*,int);
};


int BST::countNodes(BST::TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int cnt=1;
    cnt += BST::countNodes(root->left);
    cnt += BST::countNodes(root->right);
    return cnt;
}

void BST::printPreorder(BST::TreeNode* root){
    //root left right
    if(root != NULL){
        cout << root->val << " ";
        BST::printPreorder(root->left);
        BST::printPreorder(root->right);
    }
}

void BST::printPostorder(BST::TreeNode* root){
    //root left right
    if(root != NULL){
        BST::printPostorder(root->left);
        BST::printPostorder(root->right);
        cout << root->val << " ";
    }
}

void BST::printPostorder(){
    BST::printPostorder(root);
    cout << endl;
}

void BST::printInorder(BST::TreeNode* root){
    //root left right
    if(root != NULL){
        BST::printInorder(root->left);
        cout << root->val << " ";
        BST::printInorder(root->right);
    }
}

void BST::printInorder(){
    BST::printInorder(root);
    cout << endl;
}

BST::TreeNode* BST::insert(BST::TreeNode* t, int k){
    if(t==NULL){
        t = new BST::TreeNode(k);
    }
    else{
        if(k <= t->val){
            t->left = BST::insert(t->left,k);
        }
        else{
            t->right = BST::insert(t->right,k);
        }
    }   
    return (t);
}

void BST::insert(int k){
    root = BST::insert(root,k);
}

int BST::lookup(BST::TreeNode* t, int tar){
    if(t==NULL){
        return 0;
    }
    else{
        if(tar == t->val){
            return 1;
        }
        else{
            if(tar < t->val) return BST::lookup(t->left,tar);
            else return BST::lookup(t->right,tar);
        }
    }
}


//depth first search
int maxDepth(TreeNode* root) {
    return root==NULL? 0 : max( maxDepth(root->left) , maxDepth(root->right) ) + 1;
}

int main(){
    BST* bst = new BST(2);
    // bst->insert(2);
    // bst->insert(1);
    // bst->insert(3);
    // bst->printInorder();
    /*root -> left = new BST::TreeNode(1);
    root -> right = new BST::TreeNode(3);
    BST::printPreorder(root);*/
}
