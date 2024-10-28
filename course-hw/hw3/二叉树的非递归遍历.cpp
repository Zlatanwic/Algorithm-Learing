
/*#include<bits/stdc++.h>
using namespace std;
const int N = 100;
struct node {
	char value;
	node* l;
	node* r;
	node(char x) { value = x; l = NULL; r = NULL; }
};

node* buildtree(int n,string* operation)
{
	stack<node*>st;
	node* root = NULL;
	node* cr = NULL;
	for (int i = 0; i < 2 * n; i++) {
		string op = operation[i];
		if (op[1] == 'u') {
			char value = op[op.size()-1];
			node* newnode = new node(value);
			if (root == NULL) {
				root = newnode;
			}
			else {
				if (cr->l == NULL) {
					cr->l = newnode;
				}
				else {
					cr->r = newnode;
				}
			}
			st.push(newnode);
			cr = newnode;
		}
		else {
			cr = st.top();
			st.pop();
		}
		
	}
	return root;
}

void post_print(node* root)
{
	if (root == NULL)
		return;
	else{
		post_print(root->l);
		post_print(root->r);
		cout << root->value;
	}
}

int main()
{
	int n;
	cin >> n;
	string* operation = new string[2 * n];
	
	for (int i = 0; i < 2 * n; i++) {
		cin >> operation[i];
	}
	
	node* root = buildtree(n, operation);
	post_print(root);
	delete[]operation;
	return 0;
}*/


#include <bits/stdc++.h>
#include<string>
using namespace std;

const int N = 100;
string operation[200];
struct node {
	char value;
	node* l;
	node* r;
	node(char x) : value(x), l(NULL), r(NULL) {}
};

node* buildtree(int n, string* operation) {
	stack<node*> st;
	node* root = NULL;
	node* cr = NULL;

	for (int i = 0; i < 2 * n; i++) {
		string op = operation[i];
		if (op[1] == 'u') { // push X
			char value = op[op.length()-1];
			node* newnode = new node(value);
			if (root == NULL) {
				root = newnode;
			}
			else {
				if (cr->l == NULL) {
					cr->l = newnode;
				}
				else {
					cr->r = newnode;
				}
			}
			st.push(newnode);
			cr = newnode;
		}
		else { // pop
			if (!st.empty()) {
				cr = st.top();
				st.pop();
			}
			/*else {
				cerr << "Error: pop called on empty stack" << endl;
				exit(1);
			}*/
		}
	}
	return root;
}

void post_print(node* root) {
	if (root == NULL)
		return;
	post_print(root->l);
	post_print(root->r);
	cout << root->value;
}

int main() {
	int n;
	cin >> n;
	//cout << endl;
	for (int i = 0; i < 2 * n; i++) {
		cin>>operation[i];
		if (operation[i][1] == 'u') {
			char ch;
			cin >> ch;
			operation[i] += ch;
		}
		//cout << operation[i];
	}

	node* root = buildtree(n, operation);
	post_print(root);
	//cout << endl;

	
	delete[] root;
	return 0;
}
