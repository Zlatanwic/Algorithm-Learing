#include<bits/stdc++.h>
using namespace std;
const int N = 10005;

struct onode {
    vector<int> child;
    int next = -1;
} otree[N];

struct bnode {
    int l, r;
} btree[N];

int n;

void buildotree(string s) {  // 建初始树
    stack<int> st;
    st.push(0);
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == 'd') {
            n++;
            otree[st.top()].child.push_back(n);
            st.push(n);
        }
        else if (s[i] == 'u') {
            int x = st.top();
            st.pop();
            if (i + 1 < int(s.size()) && s[i + 1] == 'd') {
                otree[x].next = n + 1;
            }
        }
    }
}

void buildbtree() {  // 建二叉树
    for (int i = 0; i <= n; i++) {
        if (!otree[i].child.empty())
            btree[i].l = otree[i].child[0];
        if (otree[i].next != -1)
            btree[i].r = otree[i].next;
    }
}

int calculate_otree_depth(int root) {  // 计算原始树的深度
    if (otree[root].child.empty()) return 1;
    int max_depth = 0;
    for (int child : otree[root].child) {
        max_depth = max(max_depth, calculate_otree_depth(child));
    }
    return max_depth + 1;
}

int calculate_btree_depth(int root) {  // 计算二叉树的深度
    if (root == -1) return 0;
    return 1 + max(calculate_btree_depth(btree[root].l), calculate_btree_depth(btree[root].r));
}

int main() {
    string input;
    int tree_count = 0;

    while (getline(cin, input) && input != "#") {
        tree_count++;
        n = 0;
        for (int i = 0; i < N; i++) {
            otree[i].child.clear();
            otree[i].next = -1;
            btree[i].l = btree[i].r = -1;
        }

        buildotree(input);
        buildbtree();

        int otree_depth = calculate_otree_depth(0) - 1;
        int btree_depth = calculate_btree_depth(0) - 1;

        cout << "Tree " << tree_count << ": " << otree_depth << " => " << btree_depth << endl;
    }

    return 0;
}
