#include <iostream>

/*
Accepted: 0.152s
Category: string processing, data structures - tries
Algorithm: use a trie with a fail condition to stop processing
immediately following a match. (when one number is a prefix of another)
*/

using namespace std;

#define NALPHA 26
#define CHAR_TO_INT(c) (c - '0')

typedef struct TrieNode TrieNode;
typedef struct Trie Trie;

struct TrieNode {
    int value;
    TrieNode *children[NALPHA];
};

struct Trie {
    TrieNode *root;
    int trieSize;
};

TrieNode *newTrieNode() {
    TrieNode *newNode = new TrieNode;
    newNode->value = 0;
    for (int i = 0; i < NALPHA; i++)
        newNode->children[i] = NULL;
    return newNode;
}

void initTrie(Trie *t) {
    t->root = newTrieNode();
    t->trieSize = 0;
}

bool insertAndCheckPrefix(Trie *t, string &key) {
    int index, value = 0;
    bool isMatch = true;
    TrieNode *crawl = t->root;
    t->trieSize++;

    for (int i = 0; key[i]; i++) {
        if (crawl->value != 0) /* the case of a shorter string inserted before a longer string */
            return true;
        value++;
        index = CHAR_TO_INT(key[i]);
        if (crawl->children[index] == NULL) {
            crawl->children[index] = newTrieNode();
            isMatch = false; /* if no node exists, then of course it doesn't match */
        }
        crawl = crawl->children[index];
    }
    if (!isMatch)
        crawl->value = value;
    return isMatch;
}

int main() {
	int ncases, nnums;
	string line;

	cin >>ncases;
	while (ncases--) {
        cin >> nnums;
        bool foundMatch = false;
        Trie t;
        initTrie(&t);
        for (int i = 0; i < nnums; i++) {
            cin >> line;
            if (!foundMatch and insertAndCheckPrefix(&t, line)) { /* if we found a match, stop processing */
                foundMatch = true;
            }
        }
        if (!foundMatch)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
	}
    return 0;
}
