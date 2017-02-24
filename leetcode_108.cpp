// convert sorted array to binary tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *buildTree(vector<int> &num, int start, int end) {
  if (start > end) {
    return NULL;
  }
  if (start == end) {
    return new TreeNode(num[start]);
  }
  int mid = (start + end) / 2;
  TreeNode *node = new TreeNode(num[mid]);
  node->left = buildTree(num, start, mid - 1);
  node->right = buildTree(num, mid + 1, end);
  return node;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
  if (nums.empty()) {
    return nullprt;
  }
  return buildTree(nums, 0, nums.size() - 1);
}
