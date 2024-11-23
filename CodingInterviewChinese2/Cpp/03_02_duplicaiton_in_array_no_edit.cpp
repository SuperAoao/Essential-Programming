/*鍦ㄤ竴涓暱搴︿负n+1棰濇暟缁勯噷鐨勬墍鏈夋暟瀛楅兘鍦�1~n鐨勮寖鍥村唴锛屾墍浠ユ暟缁勪腑鑷冲皯鏈変竴涓暟瀛楁槸閲嶅鐨勩€�
璇锋壘鍑烘暟缁勪腑浠绘剰涓€涓噸澶嶇殑鏁板瓧锛屼絾涓嶈兘淇敼杈撳叆鐨勬暟缁勩€備緥濡傦紝濡傛灉杈撳叆闀垮害涓�8鐨勬暟缁剓2锛�3锛�5锛�4锛�3锛�2锛�6锛�7}锛�
閭ｄ箞瀵瑰簲鐨勮緭鍑烘槸閲嶅鐨勬暟瀛�2鎴�3*/
#include <iostream>
#include <vector>

// Space complexity O(n)
int getDuplicationInArray(const std::vector<int>& vec)
{
    unsigned int ret = -1;
    std::vector<int> temp;
    temp.reserve(vec.size());
    temp.assign(vec.size(), 0);
    for (const auto&num: vec)
    {
        if (temp[num] == 0)
        {
            temp[num] = num;
        }
        else
        {
            ret = num;
            return ret;
        }
    }

    return ret;
}

void test1()
{
    std::vector<int> a = {2,3,5,4,3,2,6,7};
    int testVal = getDuplicationInArray(a);
    if (testVal == 2 || testVal == 3)
    {
       std::cout << "test1 passed." << std::endl;
    }

    else
    {
        std::cout << "test1 failed." << std::endl;
    }
    
}
int countRange(const int* array, int length, int start, int end)
{
    if (array == nullptr)
    {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] >= start && array[i] <= end)
        {
            ++count;
        }
    }
    
    return count;
}
// Space complexity O(1)
// Time complexity O(nlogn)
int getDuplication(const int* array, int length)
{
    if (array == nullptr || length <= 0)
    {
        return -1;
    }

    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        int middle = ((end - start) >> 1) + start;  // right move equals /2 but more efficient
        int count = countRange(array, length, start, middle);
        if (start == end)
        {
            if (count > 1)
            {
                return start;
            }
            else
            {
                break;
            }    
        }
        if (count > (middle - start + 1))
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }
        return -1;
}


// Test function
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
    int result = getDuplication(numbers, length);
    for(int i = 0; i < dupLength; ++i)
    {
        if(result == duplications[i])
        {
            std::cout << testName << " passed." << std::endl;
            return;
        }
    }
    std::cout << testName << " FAILED." << std::endl;
}


void test2()
{
    int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
    int duplications[] = { 4 };
    test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}


void test3()
{
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
    int duplications[] = { 1 };
    test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}


void test4()
{
    int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
    int duplications[] = { 8 };
    test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

void test5()
{
    int  numbers[] = { 1, 1 };
    int duplications[] = { 1 };
    test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

void test6()
{
    int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
    int duplications[] = { 3 };
    test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

void test7()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
    int duplications[] = { 2, 6 };
    test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

void test8()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
    int duplications[] = { 2 };
    test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

void test9()
{
    int numbers[] = { 1, 2, 6, 4, 5, 3 };
    int duplications[] = { -1 };
    test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

void test10()
{
    int* numbers = nullptr;
    int duplications[] = { -1 };
    test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

int main()
{
    int a = 10;
    int b = a >> 1;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 0;
}