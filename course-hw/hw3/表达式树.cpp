#include <iostream>
#include <cctype>
#include <cstring>
 
using namespace std;
 
struct TreeNode {
    char value;
    int height; // 添加 height 字段
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : value(val), height(1), left(nullptr), right(nullptr) {}
};
 
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
 
void apply_operator(TreeNode** nodes, int& node_top, char* operators, int& op_top) {
    char op = operators[op_top--];
    TreeNode* right = nodes[node_top--];
    TreeNode* left = nodes[node_top--];
    TreeNode* newNode = new TreeNode(op);
    newNode->left = left;
    newNode->right = right;
    newNode->height = max(left->height, right->height) + 1; // 计算高度
    nodes[++node_top] = newNode;
}
 
TreeNode* build_expression_tree(const char* expression) {
    TreeNode* nodes[100];
    char operators[100];
    int node_top = -1, op_top = -1;
 
    for (int i = 0; expression[i]; ++i) {
        char ch = expression[i];
        if (isalpha(ch)) {
            nodes[++node_top] = new TreeNode(ch);
        }
        else if (ch == '(') {
            operators[++op_top] = ch;
        }
        else if (ch == ')') {
            while (op_top >= 0 && operators[op_top] != '(') {
                apply_operator(nodes, node_top, operators, op_top);
            }
            --op_top; // Pop '('
        }
        else {
            while (op_top >= 0 && precedence(operators[op_top]) >= precedence(ch)) {
                apply_operator(nodes, node_top, operators, op_top);
            }
            operators[++op_top] = ch;
        }
    }
 
    while (op_top >= 0) {
        apply_operator(nodes, node_top, operators, op_top);
    }
 
    return nodes[0];
}
 
void postorder_traversal(TreeNode* root, char* result, int& index) {
    if (root == nullptr) return;
    postorder_traversal(root->left, result, index);
    postorder_traversal(root->right, result, index);
    result[index++] = root->value;
}
 
int calculate_expression(TreeNode* root, const int* values) {
    if (root == nullptr) return 0;
    if (isalpha(root->value)) {
        return values[root->value - 'a'];
    }
 
    int left_val = calculate_expression(root->left, values);
    int right_val = calculate_expression(root->right, values);
 
    if (root->value == '+') return left_val + right_val;
    if (root->value == '-') return left_val - right_val;
    if (root->value == '*') return left_val * right_val;
    if (root->value == '/') return left_val / right_val;
 
    return 0;
}
 
void print_tree(TreeNode* root, int level, int pos, char** lines, int& max_level) {
    if (root == nullptr) return;
 
    // 确保 lines 数组有足够的行数
    if (level > max_level) max_level = level;
 
    // 确保当前行的长度足够
    while (strlen(lines[level]) < pos) {
        strcat(lines[level], " ");
    }
 
    // 添加当前节点的值
    char temp[2];
    temp[0] = root->value;
    temp[1] = '\0';
    strcat(lines[level], temp);
 
    // 递归打印左子树和右子树
    if (root->left) {
        // 添加左子树的连接线
        if (level + 1 > max_level) max_level = level + 1;
        while (strlen(lines[level + 1]) < pos - 1) {
            strcat(lines[level + 1], " ");
        }
        strcat(lines[level + 1], "/");
 
        // 递归打印左子树
        print_tree(root->left, level + 2, pos - (1 << (root->height - 2)), lines, max_level);
    }
 
    if (root->right) {
        // 添加右子树的连接线
        if (level + 1 > max_level) max_level = level + 1;
        while (strlen(lines[level + 1]) < pos + 1) {
            strcat(lines[level + 1], " ");
        }
        strcat(lines[level + 1], "\\");
 
        // 递归打印右子树
        print_tree(root->right, level + 2, pos + (1 << (root->height - 2)), lines, max_level);
    }
}
 
int main() {
    char expression[100];
    int n;
    int values[26] = {0};
 
    cin >> expression;
    cin >> n;
 
    for (int i = 0; i < n; ++i) {
        char var;
        int val;
        cin >> var >> val;
        values[var - 'a'] = val;
    }
 
    TreeNode* root = build_expression_tree(expression);
 
    char postfix[100];
    int index = 0;
    postorder_traversal(root, postfix, index);
    postfix[index] = '\0';
    cout << postfix << endl;
 
    char* lines[100];
    for (int i = 0; i < 100; ++i) {
        lines[i] = new char[1000];
        lines[i][0] = '\0';
    }
    int max_level = 0;
    print_tree(root, 0, (1 << (root->height - 1)) - 1, lines, max_level);
    for (int i = 0; i <= max_level; ++i) {
        cout << lines[i] << endl;
        delete[] lines[i];
    }
 
    int result = calculate_expression(root, values);
    cout << result << endl;
 
    return 0;
}
×
