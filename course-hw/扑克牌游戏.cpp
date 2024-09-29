#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
struct Card {
    string suit;
    string rank;
 
    bool operator<(const Card &other) const {
        // 定义比较规则，先按花色排序，再按编号排序
        static const string suits[] = {"Spade", "Heart", "Club", "Diamond"};
        static const string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
 
        int suit_index1 = distance(begin(suits), find(begin(suits), end(suits), suit));
        int suit_index2 = distance(begin(suits), find(begin(suits), end(suits), other.suit));
        if (suit_index1 != suit_index2) return suit_index1 < suit_index2;
 
        int rank_index1 = distance(begin(ranks), find(begin(ranks), end(ranks), rank));
        int rank_index2 = distance(begin(ranks), find(begin(ranks), end(ranks), other.rank));
        return rank_index1 < rank_index2;
    }
};
 
list<Card> deck;
 
// 添加一张牌到牌堆的底部
void append(const string &suit, const string &rank) {
    deck.push_back({suit, rank});
}
 
// 抽取某种花色的所有牌，排序后放到牌堆的顶部
void extract(const string &suit) {
    vector<Card> extracted;
    auto it = deck.begin();
    while (it != deck.end()) {
        if (it->suit == suit) {
            extracted.push_back(*it);
            it = deck.erase(it);
        } else {
            ++it;
        }
    }
    sort(extracted.begin(), extracted.end());
    deck.insert(deck.begin(), extracted.begin(), extracted.end());
}
 
// 反转整个牌堆
void revert() {
    deck.reverse();
}
 
// 弹出牌堆顶部的第一张牌，并打印该牌的花色和数字
void pop() {
    if (deck.empty()) {
        cout << "NULL" << endl;
    } else {
        cout << deck.front().suit << " " << deck.front().rank << endl;
        deck.pop_front();
    }
}
 
// 打印牌堆中的所有牌
void print_deck() {
    if (deck.empty()) {
        cout << "NULL" << endl;
    } else {
        for (const auto &card : deck) {
            cout << card.suit << " " << card.rank << endl;
        }
    }
}
 
int main() {
    int n;
    string command, suit, rank;
 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "Append") {
            cin >> suit >> rank;
            append(suit, rank);
        } else if (command == "Extract") {
            cin >> suit;
            extract(suit);
        } else if (command == "Revert") {
            revert();
        } else if (command == "Pop") {
            pop();
        }
    }
 
    print_deck();
 
    return 0;
}
\\c方式
#include <iostream>
#include <cstring>
 
using namespace std;
 
struct student {
    char id[100];
    char name[100];
};
 
student* create_students(int& n) {
    cin >> n;
 
    // 输入验证
    if (n <= 0) {
        cerr << "Invalid number of students. Exiting." << endl;
        return nullptr;
    }
 
    student* result = new student[n];
 
    for (int i = 0; i < n; i++) {
        cin >> result[i].id >> result[i].name;
 
        // 输入验证
        if (strlen(result[i].id) == 0 || strlen(result[i].name) == 0) {
            cerr << "Invalid input. Skipping this student." << endl;
            i--;
        }
    }
 
    return result;
}
 
int insert_student(student*& students, int& n, int position, const char* id, const char* name) {
    if (position < 1 || position > n + 1) {
        return -1;
    }
 
    student* new_students = new student[n + 1];
 
    for (int i = 0; i < position - 1; i++) {
        new_students[i] = students[i];
    }
 
    strcpy(new_students[position - 1].id, id);
    strcpy(new_students[position - 1].name, name);
 
    for (int i = position - 1; i < n; i++) {
        new_students[i + 1] = students[i];
    }
 
    delete[] students;
    students = new_students;
    n++;
 
    return 0;
}
 
int remove_student(student*& students, int& n, int position) {
    if (position < 1 || position > n) {
        return -1;
    }
 
    student* new_students = new student[n - 1];
 
    for (int i = 0; i < position - 1; i++) {
        new_students[i] = students[i];
    }
 
    for (int i = position; i < n; i++) {
        new_students[i - 1] = students[i];
    }
 
    delete[] students;
    students = new_students;
    n--;
 
    return 0;
}
 
void find_student(const student* students, int n, const string& type, const string& search_key) {
    for (int i = 0; i < n; i++) {
        if ((type == "name" && strcmp(students[i].name, search_key.c_str()) == 0) ||
            (type == "no" && strcmp(students[i].id, search_key.c_str()) == 0)) {
            cout << i + 1 << " " << students[i].id << " " << students[i].name << endl;
            return;
        }
    }
    cout << "-1" << endl;
}
 
int main() {
    int n = 0;
    student* students = create_students(n);
 
    if (students == nullptr) {
        return 1;
    }
 
    int loop = 1;
    while (loop) {
        string operation;
        cin >> operation;
        if (operation == "end") {
            cout << n << endl;
            loop = 0;
        }
        else if (operation == "insert") {
            int position;
            char id[100], name[100];
            cin >> position >> id >> name;
            cout << insert_student(students, n, position, id, name) << endl;
        }
        else if (operation == "remove") {
            int position;
            cin >> position;
            cout << remove_student(students, n, position) << endl;
        }
        else if (operation == "check") {
            string type, search_key;
            cin >> type >> search_key;
            find_student(students, n, type, search_key);
        }
    }
 
    delete[] students;
    return 0;
}
