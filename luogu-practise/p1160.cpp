#include<bits/stdc++.h>
using namespace std;
const int N = 100000+10;
struct node {
	int L, R;
	int d;
}node[N] = { 0 };

void add_stu(int i, int k, int p)
{
	if (p == 1) {
		node[i].R = node[k].R;
		node[i].L = k;
		node[node[k].R].L = i;
		node[k].R = i;
		

	}
	else if (p == 0) {
		node[i].R = k;
		node[node[k].L].R = i;
		node[i].L = node[k].L;
		node[k].L = i;
		
	}
	
}


int main() 
{
	int n;
	cin >> n;
	node[0].R = 0;
	node[0].L = 0;
	add_stu(1, 0, 1);
	for (int i = 2; i <= n; i++) {
		int k, p;
		cin >> k >> p;
		add_stu(i, k, p);
	}
	int m;
	cin >> m;
	for (int j = 0; j < m; j++) {
		int drop;
		cin >> drop;
		node[drop].d = 1;
	}
	for (int t = node[0].R;t!=0; t = node[t].R) {
		if (node[t].d != 1)
			cout << t << ' ';
	}

	return 0;
}