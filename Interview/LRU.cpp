// LRU.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//实现LRU缓存
//运用你所掌握的数据结构，设计和实现一个 LRU(最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
//
//获取数据 get(key)：
//
//如果关键字(key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 - 1
//
//写入数据 put(key, value)：
//
//如果关键字已经存在，则变更其数据值
//
//如果关键字不存在，则插入该组「关键字 / 值」
//
//当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间
//
//示例：
//
//```java
//LRUCache cache = new LRUCache(2 * 缓存容量*);
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1); // 返回 1
//cache.put(3, 3); // 该操作会使得关键字 2 作废
//cache.get(2); // 返回 -1 (未找到)
//cache.put(4, 4); // 该操作会使得关键字 1 作废
//cache.get(1); // 返回 -1 (未找到)
//cache.get(3); // 返回 3
//cache.get(4); // 返回 4

#include <iostream>
#include <map>
#include <vector>

// LRU缓存类, 先考虑特化情况<unsigned int,unsigned int>，测试通过后再考虑泛型实现
// <int,int>插入的value为-1时无法判断是否存在
// 设计思路：数据保持存储顺序，且按照使用频率有序
// 一种可能实现：map<key,key-frequency> 记录key和key的使用频率，但频率相同还要比较插入顺序
// 
class LRUCache
{
public:
    LRUCache() = delete;
    LRUCache(size_t maxSize);
    // 拷贝构造函数
    // 移动构造函数
    // 赋值构造函数
    ~LRUCache();
    void put(std::pair<unsigned int, unsigned int> data);
    // 获取valve，如果该key不存在则返回-1
    // 返回值int会导致范围变小
    int get(int key);

    // 获取当前缓存容量
    size_t getSize();

    // 获取最大缓存容量
    size_t getMaxSize();
private:
    std::map<unsigned int, unsigned int> m_mapData;           //  数据map
    std::vector<unsigned int> m_vec;    //  记录数据访问频率数组
    size_t _maxSize;
};

LRUCache::LRUCache(size_t maxSize):_maxSize(maxSize)
{

}

LRUCache::~LRUCache()
{
}

void LRUCache::put(std::pair<unsigned int, unsigned int> data)
{
    m_mapData[data.first] = data.second;
}

int LRUCache::get(int key)
{
    auto iter = m_mapData.find(key);
    if (iter == m_mapData.end())
    {
        return -1;
    }
    else
    {
        return (*iter).second;
    }
}

size_t LRUCache::getSize()
{
    return false;
}

size_t LRUCache::getMaxSize()
{
    return _maxSize;
}

namespace test000
{
    // 特殊测试0
    void test0()
    {
        LRUCache cache(2);
        cache.put(std::make_pair<unsigned int, unsigned int>(1, 1));
        cache.put(std::make_pair<unsigned int, unsigned int>(2, 2));
        int result1 = cache.get(1);
        if (result1 != 1)
        {
            std::cout << "[test0 failed] cache.get(1) return: " << result1 << std::endl;
        }
        cache.put(std::make_pair<unsigned int, unsigned int>(3, 3));
        int sizeResult1 = cache.getSize();
        if (sizeResult1 != 2)
        {
            std::cout << "[test0 failed] cache.getSize() return: " << sizeResult1 << std::endl;
        }
        int result2 = cache.get(2);
        if (result2 != -1)
        {
            std::cout << "[test0 failed] cache.get(2) return: " << result2 << std::endl;
        }
    }
}


int main()
{
    std::cout << "Hello World!\n";

    test000::test0();

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


