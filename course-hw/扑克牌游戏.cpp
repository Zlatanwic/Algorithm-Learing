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
×
