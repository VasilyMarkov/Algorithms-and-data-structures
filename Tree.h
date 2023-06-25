#ifndef TREE_H
#define TREE_H
#include <vector>
#include <stack>
#include <list>
#include <queue>
namespace my {

struct TreeNode {
    TreeNode(int val): val(val) {left = right = nullptr;}
    TreeNode():val(0) {left = right = nullptr;}
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode* newTreeNode(int val) {
        TreeNode* node = new TreeNode(val);
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

    void postOrder(TreeNode* root, std::vector<int>& out) {
        if(root == nullptr) return;
        postOrder(root->left, out);
        postOrder(root->right, out);
        out.push_back(root->val);
    }

    void inOrder(TreeNode* root, std::vector<int>& out) {
        if(root == nullptr) return;
        inOrder(root->left, out);
        out.push_back(root->val);
        inOrder(root->right, out);
    }
    void preOrder(TreeNode* root, std::vector<int>& out) {
        if(root == nullptr) return;
        out.push_back(root->val);
        preOrder(root->left, out);
        preOrder(root->right, out);
    }
    void stackInOrder(TreeNode* root, std::vector<int>& out) {
        std::stack<TreeNode*> stack;
        TreeNode* curr = root;

        while(curr != nullptr || !stack.empty()) {
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            out.push_back(curr->val);
            curr = curr->right;
         }
    }
    TreeNode* levelOrder(TreeNode* root, std::vector<int>& out) {
        std::stack<TreeNode*> stack;
        std::queue<TreeNode*> queue;
        TreeNode* curr = root;
        queue.push(curr);
        while(!queue.empty()) {
            curr = queue.front();
            out.push_back(curr->val);
            queue.pop();
            if(curr->left != nullptr) queue.push(curr->left);
            if(curr->right != nullptr) queue.push(curr->right);
        }
    }
    TreeNode* search(TreeNode* root, int val) {
        if(root == nullptr || root->val == val) return root;
        if(root->val < root->left->val)
            return search(root->left, val);
        else
            return search(root->right, val);
    }
    TreeNode* findMin(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* curr = root;
        while(curr != nullptr) {
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* insert(TreeNode* root, int val){
        TreeNode* curr = root;
        if(curr == nullptr) return new TreeNode(val);
        if(val > curr->val) curr->right = insert(curr->right, val);
        else curr->left = insert(curr->left, val);
        return curr;
    }
    TreeNode* remove(TreeNode* root, TreeNode* element) {

    }
};

}
#endif // TREE_H
