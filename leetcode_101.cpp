// symmetric tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive
bool isSymmetric(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  return leftRight(root->left, root->right);
}

bool leftRight(TreeNode *p, TreeNode *q) {
  if (p == nullptr && q == nullptr) {
    return true;
  }
  if (p == nullptr || q == nullptr) {
    return false;
  }
  return p->val == q->val && leftRight(p->left, q->right) &&
         leftRight(p->right, q->left);
}

// iteration with two queue
bool isSymmetric(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  TreeNode *left, TreeNode *right;
  queue<TreeNode *> q1, q2;
  q1.push(root->left);
  q2.push(root->right);
  while (!q1.empty() && !q2.empty()) {
    left = q1.front();
    q1.pop();
    right = q2.front();
    q2.pop();
    if (left == nullptr && right == nullptr) {
      continue;
    }
    if (left == nullptr || right == nullptr) {
      return false;
    }
    if (left->val != right->val) {
      return false;
    }
    q1.push(left->left);
    q1.push(left->right);
    q2.push(right - right);
    q2.push(right->left);
  }
  return true;
}

// iteration with one queue
bool isSymmetric(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }
  queue<TreeNode *> q;
  q.push(root->left);
  q.push(root->right);
  while (!q.empty()) {
    TreeNode *t1 = q.front();
    q.pop();
    TreeNode *t2 = q.front();
    q.pop();
    if (t1 == nullptr && t2 == nullptr) {
      continue;
    }
    if (t1 == nullptr || t2 == nullptr) {
      return false;
    }
    if (t1->val != t2->val) {
      return false;
    }
    q.push(t1->left);
    q.push(t2->right);
    q.push(t1->right);
    q.push(t2->left);
  }
  return true;
}