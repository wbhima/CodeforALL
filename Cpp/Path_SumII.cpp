/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(TreeNode* root, vector<int> &ds, int sum){
        if(!root) return;
        if(!root->left and !root->right){
            
            if(sum == root->val){
                ds.push_back(root->val);
                ans.push_back(ds);
                ds.pop_back();
                
            }
            return;
        }
        
        ds.push_back(root->val);
        solve(root->left, ds, sum - root->val);
        solve(root->right, ds, sum - root->val);
        ds.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ds;
        solve(root, ds, targetSum);
        return ans;
    }
};