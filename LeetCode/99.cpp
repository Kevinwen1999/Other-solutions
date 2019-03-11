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
    bool triggered = false;
    TreeNode *last = NULL, *maxx = NULL;
    void rotat(TreeNode* root) {
        if (root->left != NULL) {
            rotat(root->left);
        }
        if (maxx != NULL) {
            if (maxx->val <= root->val) {
                if (triggered) {
                    swap(last->val, maxx->val);
                    triggered = false;
                    return;
                }
            } else {
                triggered = true;
            }
        }
        if (maxx == NULL) maxx = root;
        maxx = (root->val) > (maxx->val) ? root : maxx;
        last = root;
        if (root->right != NULL) rotat(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        rotat(root);
        if (triggered)
            swap(last->val, maxx->val);
    }
};
