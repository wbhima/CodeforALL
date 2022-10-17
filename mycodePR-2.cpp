vector<int> sums;
void dfs(TreeNode* r, size_t lvl) {
  if (r != nullptr) {
    sums.resize(max(sums.size(), lvl));
    sums[lvl - 1] += r->val;
    dfs(r->left, lvl + 1);
    dfs(r->right, lvl + 1);
  }
}
int maxLevelSum(TreeNode* r) {
  dfs(r, 1);
  return distance(begin(sums), max_element(begin(sums), end(sums))) + 1;
}