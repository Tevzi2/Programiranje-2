#include <VectorUtil.hpp>

int main()
{
    std::vector<Point> list;
    std::cout << "Default generator of 3 objects" << std::endl;
    fillDefault(list, 10);
    print(list);

    std::vector<float> list2 = {1.1f, 1.2f, 1.3f};
    std::vector<float> list3 = reverse(list2);
    std::cout << "Reverse:" << std::endl;
    print(list3);

    std::vector<std::vector<float>> listOfLists = {list2, list3};
    std::cout << "Merge vectors:" << std::endl;
    print(mergeVectors(listOfLists));

    std::vector<int> listInt;
    std::cout << "Default generator of 3 objects" << std::endl;
    fillDefault(listInt, 10);
    print(listInt);
    return 0;
}