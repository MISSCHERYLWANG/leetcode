#include <iostream>
#include <vector>

#define R 26

class TrieNode {
public:
    TrieNode() {
        isWord = false;
        memset(links, 0, sizeof(links));
    }
    bool containsKey(char ch) {
        return links[ch-'a'] != nullptr;
    }
    TrieNode* get(char ch) {
        return links[ch-'a'];
    }
    void put(char ch, TrieNode* node) {
        links[ch-'a'] = node;
    }
    void setEnd() {
        isWord = true;
    }
    bool isEnd() {
        return isWord;
    }
private:
    TrieNode *links[R];
    bool isWord;
};

class Trie{
public:
    Trie() {
        root = new TrieNode();
    }

    // insert a word into the trie
    void insert(std::string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); ++i) {
            char currentChar = word.at(i);
            if (!node->containsKey(currentChar)) {
                node->put(currentChar, new TrieNode());
            }
            node = node->get(currentChar);
        }
        node->setEnd();
    }

    // search a prefix or whole key in trie and
    // returns the node where search ends
    TrieNode* searchPrefix(std::string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); ++i) {
            char currentChar = word.at(i);
            if (node->containsKey(currentChar)) {
                node = node->get(currentChar);
            } else {
                return nullptr;
            }
        }
        return node;
    }

    // Returns if the word is in the trie.
    bool search(std::string word) {
        TrieNode *node = searchPrefix(word);
        return (node != nullptr && node->isEnd());
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(std::string prefix) {
        TrieNode *node = searchPrefix(prefix);
        return (node != nullptr);
    }

private:
    TrieNode *root;
};

int main()
{
    Trie tr = Trie();
    tr.insert("apple");
    std::cout << tr.search("app") << std::endl;
    std::cout << tr.search("apple") << std::endl;
    std::cout << tr.startsWith("app") << std::endl;
}