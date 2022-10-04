// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
// A node can only appear in the sequence at most once. Note that the path does not need to pass through the root. 
// The path sum of a path is the sum of the node's values in the path.Given the root of a binary tree, return the maximum path sum of any non-empty path.

// solution:

class Solution {
public:
    int gmax;
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        gmax = INT_MIN;
        maxPathSumHelper(root);
        return  gmax;
    }
    
    // returns max path sum starting from root
    int maxPathSumHelper(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        // get max path sum starting from left child
        auto l = maxPathSumHelper(root->left);
        
        // get max path sum starting from right child
        auto r = maxPathSumHelper(root->right);
        
        // return value would be root value itself or greater of sum with left or right child
        int ret = max({root->val, 
                    root->val+l, 
                    root->val+r});
        
        // there is one more path which could be the max path i.e. going through this node
        int cmax = max({ret, root->val + l + r});
        
        //store the result for the root
        gmax = max(gmax, cmax);
        
        return ret;
    } 
};
