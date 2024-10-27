/*#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

struct node {
	int value;
	int l, r;
	int father;
	int dp;
}tree[N];

void buildtree(int n)
{
	for (int i = 0; i < n; i++) {
		tree[i].value = i;
		cin >> tree[i].l >> tree[i].r;
		if(tree[i].l!=-1)
			tree[tree[i].l].father = i;
		if(tree[i].r!=-1)
			tree[tree[i].r].father = i;
	}
}
int cal_time;
int ans;
int vis[N];
int dfs(int start)
{
	
	if (start == -1) {
		ans=max(cal_time,ans);
		ans--;
		return -1;
	}
	if (vis[start] == 0) {
		cal_time++;
		vis[start] = 1;
		int ld = 0, rd = 0, fd = 0;
		if(start!=0)
			fd=dfs(tree[start].father);
		ld=dfs(tree[start].l);
		rd=dfs(tree[start].r);
		int d = (ld > rd) ? ld : rd;
		return (max(d, fd) + 1);
	}
	
	if (tree[start].l != -1&&vis[start]==0) {
		
		dfs(tree[start].l);
	}
	if (tree[start].r != -1 && vis[start] == 0) {
		cal_time++;
		dfs(tree[start].r);
	}
	if (tree[start].father != 0 && vis[start] == 0) {
		cal_time++;
		dfs(tree[start].father);
	}
}

int main()
{
	int n; int start;
	cin >> n >> start;
	buildtree(n);
	cout<<dfs(start)<<endl;
	cout << ans;
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct Node {
	int value;
	int l, r;
	int father;
} tree[N];

void buildTree(int n) {
	for (int i = 0; i < n; i++) {
		tree[i].value = i;
		cin >> tree[i].l >> tree[i].r;
		if (tree[i].l != -1)
			tree[tree[i].l].father = i;
		if (tree[i].r != -1)
			tree[tree[i].r].father = i;
	}
}

int bfs(int start, int n) {
	queue<int> q;
	vector<bool> infected(n, false);
	q.push(start);
	infected[start] = true;
	int time = 0;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			int node = q.front();
			q.pop();
			if (tree[node].l != -1 && !infected[tree[node].l]) {
				infected[tree[node].l] = true;
				q.push(tree[node].l);
			}
			if (tree[node].r != -1 && !infected[tree[node].r]) {
				infected[tree[node].r] = true;
				q.push(tree[node].r);
			}
			if (tree[node].father != -1 && !infected[tree[node].father]) {
				infected[tree[node].father] = true;
				q.push(tree[node].father);
			}
		}
		if (!q.empty()) {
			time++;
		}
	}

	return time;
}

int main() {
	int n, start;
	cin >> n >> start;
	buildTree(n);
	cout << bfs(start, n) << endl;
	return 0;
}
