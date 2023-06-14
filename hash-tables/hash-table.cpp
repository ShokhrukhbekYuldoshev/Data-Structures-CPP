#include <iostream>
#include <vector>
#include <list>
#include <utility>

template <typename K, typename V>
class HashTable
{
private:
    std::vector<std::list<std::pair<K, V>>> data;
    size_t size;

public:
    explicit HashTable(size_t tableSize) : data(tableSize), size(tableSize) {}

    void insert(const K &key, const V &value)
    {
        size_t index = std::hash<K>{}(key) % size;
        for (auto &pair : data[index])
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }
        data[index].emplace_back(key, value);
    }

    bool contains(const K &key) const
    {
        size_t index = std::hash<K>{}(key) % size;
        for (const auto &pair : data[index])
        {
            if (pair.first == key)
            {
                return true;
            }
        }
        return false;
    }

    const V &get(const K &key) const
    {
        size_t index = std::hash<K>{}(key) % size;
        for (const auto &pair : data[index])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    void remove(const K &key)
    {
        size_t index = std::hash<K>{}(key) % size;
        for (auto it = data[index].begin(); it != data[index].end(); ++it)
        {
            if (it->first == key)
            {
                data[index].erase(it);
                return;
            }
        }
    }

    void print() const
    {
        for (const auto &bucket : data)
        {
            for (const auto &pair : bucket)
            {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
        }
    }
};

int main()
{
    // Create a hash table with a size of 10
    HashTable<std::string, int> hashTable(10);

    // Insert key-value pairs
    hashTable.insert("apple", 5);
    hashTable.insert("banana", 7);
    hashTable.insert("orange", 3);

    // Print the hash table
    std::cout << "Hash Table:" << std::endl;
    hashTable.print();

    // Retrieve values using keys
    std::cout << "Value of 'apple': " << hashTable.get("apple") << std::endl;
    std::cout << "Value of 'banana': " << hashTable.get("banana") << std::endl;
    std::cout << "Value of 'orange': " << hashTable.get("orange") << std::endl;

    // Check if a key exists
    std::cout << "Contains key 'apple': " << (hashTable.contains("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Contains key 'grape': " << (hashTable.contains("grape") ? "Yes" : "No") << std::endl;

    // Remove a key-value pair
    hashTable.remove("banana");

    // Print the hash table after removal
    std::cout << "Hash Table after removal:" << std::endl;
    hashTable.print();

    return 0;
}
