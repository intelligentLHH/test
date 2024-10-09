#include<iostream>
#include<vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
using namespace std;


template<class T>
class BST {
private:
    struct TreeNode {
        T val;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
public:
    BST() : root(nullptr) {}
    ~BST() { clearBST(root); }
    void clearBST(TreeNode* root) {
        if(!root) return;
        clearBST(t->left);
        clearBST(t->right);
        delete root;
    }
    TreeNode* find(TreeNode* root, T x) {
        if(!root) return nullptr;
        if(x == root->val) return root;
        if(x < root->val) return find(root->left, x);
        if(x > root->val) return find(root->right, x);
        return nullptr;
    }
    TreeNode* findMin(TreeNode* root) {
        if(!root || !root->left) return root;
        return findMin(root->left);
    }
    TreeNode* findMax(TreeNode* root) {
        if(!root || !root->right) return root;
        return findMin(root->right);
    }
    TreeNode* insertNode(TreeNode* root, T x) {
        if(!root) {
            root = new TreeNode;
            root->val = x;
            root->left = root->right = nullptr;
        } else if(x < root->val) {
            root->left = insertNode(root->left, x);
        } else if(x > root->val) {
            root->right = insertNode(root->right, x);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, T x) {
        if(!root) {
            return nullptr;
        } else if(x < root->val) {
            root->left = deleteNode(root->left, x);
        } else if(x > root->val) {
            root->right = deleteNode(root->right, x);
        } else if(root->left && root->right) {
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, root->val);
        } else {
            TreeNode* temp = root;
            if(!root->left) root = root->right;
            else if(!root->right) root = root->left;;
            delete temp;
        }
        return root;
    }
};



int main() 
{
    set<int> res = {4,2,5,7,1};
    set<int>::iterator it;
    for(it = res.begin(); it != res.end(); it++)
        cout << *it << " ";

    
    
    return 0;
}