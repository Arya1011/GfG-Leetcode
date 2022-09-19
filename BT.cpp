
// Binary Tree
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node *right;
  node *left;

  node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

node *createTree()
{
  int d;
  cin >> d;

  if (d == -1)
  {
    return NULL;
  }

  node *root = new node(d);
  root->left = createTree();
  root->right = createTree();
  return root;
}

// Preorder Traversal(Root->Left->Right)
void printTree(node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  printTree(root->left);
  printTree(root->right);
}

// Inorder Traversal(Left->Root->Right)
void printIn(node *root)
{
  if (root == NULL)
  {
    return;
  }
  printIn(root->left);
  cout << root->data << " ";
  printIn(root->right);
}

// Postorder Traversal(Left->Right->Root)
void printPo(node *root)
{
  if (root == NULL)
  {
    return;
  }
  printPo(root->left);
  printPo(root->right);
  cout << root->data << " ";
}

int height(node *root)
{
  if (root = NULL)
  {
    return 0;
  }
  int ls = height(root->left);
  int rs = height(root->right);
  int h = max(ls, rs) + 1;
  return h;
}

// Printing kth level of a tree
void printKthLevel(node *root, int k)
{
  if (root == NULL)
  {
    return;
  }
  if (k == 1)
  {
    cout << root->data << " ";
    return;
  }
  printKthLevel(root->left, k - 1);
  printKthLevel(root->right, k - 1);
  return; // This is the last case in which root is not null and k value has become 0(ie. we have reached the bottom level)
}

int printAtDistanceK(node *root, node *target, int k)
{

  if (root == NULL)
  {
    return -1;
  }
  // Check if we are at target node
  if (root == target)
  {
    // print at level k waala call
    printKthLevel(root, k);
    return 0;
  }

  // Checking for target in LST
  int left_dist = printAtDistanceK(root->left, target, k);
  // Now check if calling node is at dist of k
  if (left_dist != -1)
  {
    if (left_dist + 1 == k)
    {
      // The current root is at distance k
      cout << root->data << " ";
    }
    else
    {
      // call on right side of the current root with remaining dist
      printKthLevel(root->right, target, k - left_dist - 2)
    }
    return left_dist + 1;
  }
  // Checking for target in the RST
  int right_dist = printAtDistanceK(root->right, target, k);
  if (right_dist != -1)
  {
    if (right_dist + 1 == k)
    {
      cout << root->data << " ";
    }
    else
    {
      // call on left side
      printAtKthLevel(root->left, k - 2 - right_dist);
    }
    return right_dist + 1;
  }
  return -1; // Node was not present in any LSt and RST
}

// Printing all levels of a tree(Basically calculate height and call function on each level)
// This recursive approach take time complexity of O(N^2)
void printAllLevels(node *root)
{
  int H = height(root);
  for (int i = 1; i <= H; i++)
  {
    printKthLevel(root, i);
    cout << endl;
  }
  return;
}

void sumOfKthLevel(node *root, int k, int sum)
{
  if (root == NULL)
  {
    return;
  }
  if (k == 1)
  {
    sum += root->data;
    return;
  }
  sumOfKthLevel(root->left, k - 1, sum);
  sumOfKthLevel(root->right, k - 1, sum);
  return;
}

int noOfNodes(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  return 1 + noOfNodes(root->left) + noOfNodes(root->right);
}

int sumOfNodes(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int diameter(node *root)
{ // O(n^2)
  if (root == NULL)
  {
    return 0;
  }
  int h1 = height(root->left);
  int h2 = height(root->right);
  int op1 = h1 + h2;
  int op2 = diameter(root->left);
  int op3 = diameter(root->right);
  return max(op1, max(op2, op3));
}

class Pair
{
public:
  int diameter;
  int height;
};

Pair fastDiameter(node *root)
{ // uses bottom up approach O(n) we are calculating height and diameter at every node
  Pair p;
  if (root == NULL)
  {
    p.height = p.diameter = 0;
    return p;
  }

  // Otherwise
  Pair left = fastDiameter(root->left);
  Pair right = fastDiameter(root->right);
  p.height = max(left.height, right.height) + 1;
  p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
  return p;
}

node *treeFromInoPre(int *pre, int *ino, int s, int e)
{
  static int i = 0;
  // Base case
  if (s > e)
  {
    return NULL;
  }
  // Recursive Case
  node *root = new node(pre[i]);
  int index = -1;
  for (int j = s; j <= e; j++)
  {
    if (pre[i] == ino[j])
    {
      index = j;
      break;
    }
  }
  i++;
  root->left = treeFromInoPre(pre, ino, s, index - 1);
  root->right = treeFromInoPre(pre, ino, index + 1, e);
  return root;
}

// int global_max = INT_MIN;

// int maxSumNode2Node(node *root)
// {
//   //Base Case
//   if (root == NULL)
//   {
//     return 0;
//   }

//   //Recursive work
//   int ls = maxSumNode2Node(root->left);
//   int rs = maxSumNode2Node(root->right);

//   //Self work
//   int op1 = root->data;
//   int op2 = root->data + ls;
//   int op3 = root->data + rs;
//   int op4 = root->data + rs + ls;

//   //Update value of the global maximum
//   global_max = max(op1, max(op2, max(op3, op4)));

//   return max(ls, max(rs, 0))+root->data;
// }

// Max sum node to node
class Pair
{
public:
  int pathSum, branchSum;
  Pair()
  {
    pathSum = 0;
    branchSum = 0;
  }
};

pair max_sum_path(node *root)
{

  Pair p;
  if (root == NULL)
  {
    return p
  }

  Pair ls = max_sum_path(root->left);
  Pair rs = max_sum_path(root->right);

  int op1 = root->data;
  int op2 = root->data + ls.branchSum;
  int op3 = root->data + rs.branchSum;
  int op4 = root->data + ls.branchSum + rs.branchSum;

  int curr_answer_through_root = max(op1, max(op2, max(op3, op4)));

  p.branchSum = max(l.branchSum, max(0, r.branchSum)) + root->data;
  p.pathSum = max(l.pathSum, max(curr_answer_through_root, r.pathSum));
  return p
}

// Balanced tree
node *buildTreeFromArray(int *a, int s, int e)
{
  // Base Case
  if (s > e)
  { // Stopping case since this would mean that we have reached the last node
    return NULL;
  }
  // Recursive Case
  int mid = (s + e) / 2;
  node *root = new node(a[mid]);
  root->left = buildTreeFromArray(a, s, mid - 1);
  root->right = buildTreeFromArray(a, mid + 1, e);
  return root;
}

// We can also print the entire tree in linear time ie.,O(n)(BFS)
void printAllLevelsBFS(node *root)
{
  queue<node *> q;
  q.push(root);
  while (!q.empty())
  {
    node *f = q.front();
    cout << f->data << " ";
    q.pop();

    if (f->left)
    {
      q.push(f->left);
    }

    if (f->right)
    {
      q.push(f->right);
    }
  }
}

// replacing nodes with sum of greater value nodes
int replaceSum(node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  if (root->left == NULL && root->right == NULL)
  {
    return root->data;
  }
  int temp = root->data; // We first need to update the root data so it doesnt get lost
  root->data = replaceSum(root->left) + replaceSum(root->right);
  return root->data + temp;
}

class HBPair
{
public:
  int height;
  bool balance;
};

// O(n)
HBPair isHeightBalancedTree(node *root)
{
  HBPair p;
  if (root == NULL)
  { // NULL tree will always be a balanced tree
    p.height = 0;
    p.balance = true;
    return p;
  }
  // Recursive Case
  HBPair left = isHeightBalancedTree(root->left);
  HBPair right = isHeightBalancedTree(root->right);

  if (abs(left.height - right.height) <= 1 && (left.balance && right.balance))
  {
    p.height = max(left.height, right.height) + 1;
    p.balance = true;
  }
  else
  {
    p.balance = false;
  }
  return p;
}

// void verticalOrderPrint(node *root, int d, map<int, vector<int>> &m)
// {
//   if (root == NULL)
//   {
//     return;
//   }
//   m[d].push_back(root->val);
//   verticalOrderPrint(root->left, d - 1, m);
//   verticalOrderPrint(root->right, d + 1, m);
//   return;
// }

// right side view
class Solution
{

public:
  vector<int> v;
  int max_level = -1;

  void helper(node *root, int level)
  {
    if (root == NULL)
      return;
    if (level > max_level)
    {
      max_level = level;
      v.push_back(root->data);
    }
    helper(root->right, level + 1);
    helper(root->left, level + 1);
  }

  vector<int> rightSideView(node *root)
  {
    helper(root, 0);
    return v;
  }
};

// LCA
class Solution
{
public:
  TreeNode *helper(TreeNode *root, int p, int q)
  {

    if (root == NULL)
    {

      return NULL;
    }

    if (root->val == p || root->val == q)
    {
      return root;
    }

    TreeNode *l = helper(root->left, p, q);
    TreeNode *r = helper(root->right, p, q);

    if (l != NULL && r != NULL)
    {

      return root;
    }

    if (l != NULL)
    {
      return l;
    }

    return r;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    TreeNode *ans = helper(root, p->val, q->val);
    return ans;
  }
};

// nodes at a distance k from a given node
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

// dist bwn two nodes of a tree
// this function returns the distance of a node from the root node in any given recursive call(basically we are looking for the level of our target node)
int search(TreeNode *root, int key, int level)
{
  if (root == NULL)
  {
    return -1;
  }
  if (root->data == target)
  {
    return level;
  }
  int l = search(root->left, key, level + 1);
  if (l != -1)
  {
    return l;
  }
  return search(root->right, target, level + 1);
}

int min_sum_path(TreeNode *root, TreeNode *a, TreeNode *b)
{

  TreeNode *lca = lowestCommonAncestor(root, a->val, b->val);
  int l1 = search(lca, a->val, 0);
  int l2 = search(lca, b->val, 0);
  return l1 + l2;
}

// Flatten the BT into a Doubly Linked List
class Solution2
{
public:
  node *prev = NULL;
  node *head = NULL;
  void b2LL(node *root)
  {
    if (root == NULL)
    { // Base case which will be used to find the head of the LL
      return;
    }
    b2LL(root->left);
    if (prev == NULL)
    {
      head = root;
    }
    else
    {
      root->left = prev;
      prev->right = root;
    }
    prev = root;
    b2LL(root->right);
  }
};

node *buildFromPreo()
{
  int d;
  cin >> d;
  if (d == -1)
  {
    return NULL;
  }
  node *root = new node(d);
  root->left = buildFromPreo();
  root->right = buildFromPreo();
  return root;
}

// Level order traversal in different lines(Can also be implemented by using a queue<pair<node*root,int>> increment count of int after insertion of nodes of onr level indicating level change)
// BFS
void levelTraversal(node *root)
{
  queue<node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    node *f = q.front();
    if (f == NULL)
    {
      cout << endl;
      q.pop();
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << f->data << " ";
      q.pop();
      if (f->left)
      {
        q.push(f->left);
      }
      if (f->right)
      {
        q.push(f->right);
      }
    }
  }
}

// max path sum
class Solution
{
public:
  int ans = INT_MIN;

  int helper(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    // can be negative so we need to compare it with 0
    int l = max(0, helper(root->left));
    int r = max(0, helper(root->right));
    ans = max(ans, root->val + l + r);
    return root->val + max(l, r);
  }

  int maxPathSum(TreeNode *root)
  {
    helper(root);
    return ans;
  }
};

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  node *root = createTree();
  // printTree(root);
  // cout<<endl;
  // printIn(root);
  // cout<<endl;
  // printPo(root);
  // int h=height(root);
  // cout<<h<<endl;
  // printAllLevelsBFS(root);
  // cout<<endl;
  // levelTraversal(root);
  //  int pre[]={1,2,3,4,8,5,6,7};
  // int ino[]={3,2,8,4,1,6,7,5};

  // int n=sizeof(ino)/sizeof(int);

  // node*root=treeFromInoPre(pre,ino,0,n-1);

  levelTraversal(root);

  // cout<<endl;

  // Solution rv;
  // vector<int> rightView=rv.rightSideView(root);
  // vector<int>::iterator it;

  // for(it=rightView.begin();it!=rightView.end();it++){
  //  cout<<*it<<" ";
  // }

  // levelTraversal(root);
  // cout<<endl;

  // replaceSum(root);
  // levelTraversal(root);/

  // Solution2 BT2LL;

  // BT2LL.b2LL(root);

  // levelTraversal(root);
  // node *root = buildFromPreo();
  // levelTraversal(root);

  // node*value=LCA(root,6,14);
  // cout<<value->data;
  return 0;
}

//////////////////////
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void bfs(map<ll, list<ll>> gr, ll n, ll m, ll src)
{
  map<ll, ll> dist;
  queue<ll> q;
  for (ll i = 1; i <= n; i++)
  {
    dist[i] = INT_MAX;
  }
  dist[src] = 0;
  q.push(src);
  while (!q.empty())
  {
    ll curr = q.front();
    q.pop();
    for (auto nbrs : gr[curr])
    {
      // not visited
      if (dist[nbrs] == INT_MAX)
      {
        dist[nbrs] = dist[src] + 6;
        q.push(nbrs);
      }
    }
  }

  for (auto it : dist)
  {
    ll to = it.first;
    ll d = it.second;
    if (to == src)
    {
      continue;
    }
    else if (d == INT_MAX)
    {
      cout << -1 << " ";
      continue;
    }
    else
    {
      cout << d << " ";
    }
  }
  return;
}

int main()
{

  ll t;
  cin >> t;
  while (t--)
  {
    ll n, m;
    cin >> n >> m;
    map<ll, list<ll>> gr;
    for (ll i = 0; i < m; i++)
    {
      ll u, v;
      cin >> u >> v;
      gr[u].push_back(v);
      gr[v].push_back(u);
    }
    ll src;
    cin >> src;
    bfs(gr, n, m, src);
    cout << endl;
  }
  return 0;
}
