#include <iostream>
#include <unordered_map>
#include <list>

// Node to Store Data in LinkedList
class Node
{
public:
    std::string key;
    int val;
    Node(std::string key, int val) : key(key), val(val) {}
};

// LRU Cache Data Structure
class LRUCache
{
public:
    int maxSize{0};
    std::list<Node> l;
    std::unordered_map<std::string, std::list<Node>::iterator> m;

    LRUCache(int maxSize)
    {
        this->maxSize = maxSize > 1 ? maxSize : 1;
    }

    void insertKeyValue(std::string key, int val)
    {
        // update the already store value
        if (m.count(key) != 0)
        {
            auto it = m[key];
            it->val = val;
        }
        else // if not present in hashmap
        {
            if (l.size() == maxSize) // check for lrucache is full or not
            {
                Node last = l.back();
                m.erase(last.key);
                l.pop_back();
            }

            // create new node if all coditon fail
            Node n(key, val);
            l.push_front(n);
            m[key] = l.begin();
        }
    }

    int *getValue(std::string key)
    {
        if (m.count(key) != 0)
        {
            auto it = m[key];

            int value = it->val;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return &l.begin()->val;
        }

        return NULL;
    }

    std::string mostRecentKey()
    {
        return l.front().key;
    }
};

int main()
{

    LRUCache lru(3);

    lru.insertKeyValue("🥭", 10);
    lru.insertKeyValue("🍎", 20);
    lru.insertKeyValue("🍇", 30);

    std::cout << "Most Recently Used: " << lru.mostRecentKey() << std::endl;

    lru.insertKeyValue("🥭", 40);
    std::cout << "Most Recently Used: " << lru.mostRecentKey() << std::endl;

    lru.insertKeyValue("🍌", 20);

    if (lru.getValue("🍎") == NULL)
    {
        std::cout << "Apple doesn't exists" << std::endl;
    }

    if (lru.getValue("🥭") == NULL)
    {
        std::cout << "Mango doesn't exists" << std::endl;
    }

    if (lru.getValue("🍇") == NULL)
    {
        std::cout << "Grages doesn't exists" << std::endl;
    }

    if (lru.getValue("🍌") == NULL)
    {
        std::cout << "Banana doesn't exists" << std::endl;
    }

    return 0;
}