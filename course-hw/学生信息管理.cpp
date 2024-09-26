#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
struct student {
    string id;
    string name;
};
 
vector<student> create_students() {
    int n = 0;
    cin >> n;
 
    // 输入验证
    if (n <= 0) {
        cerr << "Invalid number of students. Exiting." << endl;
        return {};
    }
 
    vector<student> result;
    result.reserve(n);  // 预分配内存
 
    for (int i = 0; i < n; i++) {
        string id, name;
        cin >> id >> name;
 
        // 输入验证
        if (id.empty() || name.empty()) {
            cerr << "Invalid input. Skipping this student." << endl;
            continue;
        }
 
        result.push_back({ id, name });
    }
 
    return result;
}
 
int insert_student(vector<student>& students, int position, string id, string name) {
    if (position < 1 || position > students.size() + 1) {
        return -1;
    } else {
        students.insert(students.begin() + position - 1, { id, name });
        return 0;
    }
}
 
int remove_student(vector<student>& students, int position) {
    if (position < 1 || position > students.size()) {
        return -1;
    } else {
        students.erase(students.begin() + position - 1);
        return 0;
    }
}
 
void find_student(const vector<student>& students, const string& type, const string& search_key) {
    auto it = students.end();
 
    if (type == "name") {
        it = find_if(students.begin(), students.end(), [&search_key](const student& s) {
            return s.name == search_key;
        });
    } else if (type == "no") {
        it = find_if(students.begin(), students.end(), [&search_key](const student& s) {
            return s.id == search_key;
        });
    }
 
    if (it != students.end()) {
        // 计算位置序号
        int index = distance(students.begin(), it) + 1;
        cout << index << " " << it->id << " " << it->name << endl;
    } else {
        cout << "-1" << endl;
    }
}
 
int main() {
    vector<student> students = create_students();
 
    int loop = 1;
    while (loop) {
        string operation;
        cin >> operation;
        if (operation == "end") {
            cout << students.size() << endl;
            loop = 0;
        } else if (operation == "insert") {
            int position;
            string id, name;
            cin >> position >> id >> name;
            cout << insert_student(students, position, id, name) << endl;
        } else if (operation == "remove") {
            int position;
            cin >> position;
            cout << remove_student(students, position) << endl;
        } else if (operation == "check") {
            string type, search_key;
            cin >> type >> search_key;
            find_student(students, type, search_key);
        }
    }
 
    return 0;
}

