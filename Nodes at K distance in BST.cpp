class Solution
{
public:
  vector<int> ans;

  void helper1(TreeNode *root, int k)
  {

    if (root == NULL)
    {
      return;
    }

    if (k == 0)
    {
      ans.push_back(root->val);
    }

    helper1(root->left, k - 1);
    helper1(root->right, k - 1);
    return;
  }

  int helper(TreeNode *root, TreeNode *target, int k)
  {
    if (root == NULL)
    {
      return -1;
    }
    if (root == target)
    {
      helper1(root, k);
      return 0;
    }
    int ld = helper(root->left, target, k);
    // target in LST
    // ld will be the distance of the target node from the root of the LST(eg:ld==0 if the LST node itself is the target node)
    if (ld != -1)
    {
      if (ld + 1 == k)
      {
        ans.push_back(root->val);
      }
      else
      {
        helper1(root->right, k - 2 - ld);
      }
      return ld + 1;
    }

    int rd = helper(root->right, target, k);

    // target in RST
    if (rd != -1)
    {
      if (rd + 1 == k)
      {
        ans.push_back(root->val);
      }
      else
      {
        helper1(root->left, k - 2 - rd);
      }
      return rd + 1;
    }
    return -1; // target not found
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
  {

    helper(root, target, K);
    return ans;
  }
};
