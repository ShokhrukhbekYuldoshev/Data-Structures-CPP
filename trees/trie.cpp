#include <iostream>
#include <unordered_map>

class TrieNode
{
private:
    std::unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

public:
    TrieNode()
    {
        isEndOfWord = false;
    }

    void insert(const std::string &word)
    {
        TrieNode *current = this;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string &word)
    {
        TrieNode *current = this;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const std::string &prefix)
    {
        TrieNode *current = this;
        for (char ch : prefix)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

int main()
{
    TrieNode trie;

    trie.insert("apple");
    trie.insert("banana");
    trie.insert("orange");

    std::cout << trie.search("apple") << std::endl;  // Output: 1 (true)
    std::cout << trie.search("banana") << std::endl; // Output: 1 (true)
    std::cout << trie.search("orange") << std::endl; // Output: 1 (true)
    std::cout << trie.search("grape") << std::endl;  // Output: 0 (false)

    std::cout << trie.startsWith("app") << std::endl; // Output: 1 (true)
    std::cout << trie.startsWith("ban") << std::endl; // Output: 1 (true)
    std::cout << trie.startsWith("ora") << std::endl; // Output: 1 (true)
    std::cout << trie.startsWith("gr") << std::endl;  // Output: 0 (false)

    return 0;
}
