#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* node)
{
    if (node == nullptr)          
    {
        return;
    }
    cout << node->val;

    dfs(node->left);            

    dfs(node->right);           

}

int main()
{
    // 手动建一棵：
    //    1
    //   / \
    //  2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    dfs(root); 

    return 0;
}
