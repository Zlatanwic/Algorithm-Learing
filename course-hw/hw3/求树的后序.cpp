#include <iostream>
#include <string>

using namespace std;

int error_or_not;
void judge(string in, string pre)
{
    if (in.size() == 0) {
        return;
    }
    else if (in.size() == 1 && pre.size() == 1 && in != pre) {
        //cout << "Error";
        error_or_not = 1;
        return;
    }
    // 先序遍历的第一个节点是根节点
    char root = pre[0];

    // 在中序遍历中找到根节点的位置
    int m = in.find(root);

    // 递归处理左子树
    string insubls = in.substr(0, m);
    string insubrs = in.substr(m + 1);
    string presubls = pre.substr(1, m);
    string presubrs = pre.substr(m + 1);
    if (insubls.size() != presubls.size() || insubrs.size() != presubrs.size()) {
        error_or_not = 1;
        return;
    }
    judge(insubls, presubls);

    // 递归处理右子树
    judge(insubrs, presubrs);
}

void find_postorder(string in,string pre) {
    if (in.size()==0) {
        return;
    }
    
    // 先序遍历的第一个节点是根节点
    char root = pre[0];

    // 在中序遍历中找到根节点的位置
    int m = in.find(root);

    // 递归处理左子树
    string insubls = in.substr(0, m);
    string insubrs = in.substr(m + 1);
    string presubls = pre.substr(1, m);
    string presubrs = pre.substr(m + 1);
    find_postorder(insubls, presubls);

    // 递归处理右子树
    find_postorder(insubrs, presubrs);

    // 后序遍历最后输出根节点
    cout << root;
}

int main() {
    string inorder, preorder;
    while (cin >> preorder >> inorder) {
        judge(inorder, preorder);
        if (error_or_not) {
            cout << "Error"<<endl;
            error_or_not = 0;
            continue;
        }
        
        int preIndex = 0;
        find_postorder(inorder, preorder);
        
        cout << endl;
    }
    
    return 0;
}
