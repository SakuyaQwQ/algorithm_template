#include<vector>
#include<iostream>

using namespace std;

struct trie {

    struct node {
        node* next[26] { nullptr };
        int cnt {0};
    };

    node* root;

    trie() :root(new node {}) {}

    void insert(string& str) {
        auto temp = root;
        for (auto& ch : str) {
            if (temp->next[ch - 'a'] == nullptr) {
                temp->next[ch - 'a'] = new node;
            }
            temp = temp->next[ch - 'a'];
        }
        ++temp->cnt;
    }

    int get_cnt(string& str) {
        auto temp = root;
        for (auto& ch : str) {
            if (temp->next[ch - 'a'] == nullptr)return 0;
            temp = temp->next[ch - 'a'];
        }
        return temp->cnt;
    }
};

int main() {
    int n;
    trie t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string op, str;
        cin >> op >> str;
        if (op == "I") {
            t.insert(str);
        }
        else {
            cout << t.get_cnt(str) << endl;
        }
    }
    return 0;
}
