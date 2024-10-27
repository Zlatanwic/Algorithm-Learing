#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge {
    int to, next;
} e[2010];

int head[1010], tot;
int depth[1010], fa[1010][11], lg[1010];
bool is_root[1010];  // 用于标记哪个节点是根节点

void add(int x, int y) {
    e[++tot].to = y;
    e[tot].next = head[x];
    head[x] = tot;
}

void init_lg(int n) {
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
}

void dfs(int now, int father) {
    fa[now][0] = father;
    depth[now] = depth[father] + 1;

    for (int i = 1; (1 << i) <= depth[now]; i++) {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    }

    for (int i = head[now]; i; i = e[i].next) {
        int to = e[i].to;
        if (to != father) {
            dfs(to, now);
        }
    }
}

int LCA(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);

    for (int i = lg[depth[x]]; i >= 0; i--) {
        if (depth[x] - (1 << i) >= depth[y]) {
            x = fa[x][i];
        }
    }

    if (x == y) return x;

    for (int i = lg[depth[x]]; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

int find_root(int n) {
    for (int i = 1; i <= n; i++) {
        if (is_root[i]) return i;
    }
    return 1;  // 不应该到达这里
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);

        // 初始化
        memset(head, 0, sizeof(head));
        memset(depth, 0, sizeof(depth));
        memset(fa, 0, sizeof(fa));
        memset(is_root, true, sizeof(is_root));  // 初始时假设所有节点都是根
        tot = 0;

        init_lg(n);

        // 读入边并建图
        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
            is_root[y] = false;  // y有父节点，不可能是根
        }

        // 找到根节点并预处理
        int root = find_root(n);
        dfs(root, 0);

        // 处理询问
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", LCA(x, y));
        }
    }
    return 0;
}
