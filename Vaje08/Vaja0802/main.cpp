#include <LinkedList.hpp>

int main()
{
    LinkedList<int> list;

    std::cout << "Is list empty before inserting: " << list.is_empty() << std::endl;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Size of list after inserting: " << list.get_size() << std::endl;
    std::cout << "Is list empty after inserting: " << list.is_empty() << std::endl;

    std::cout << "Element at index 0: " << *list.at(0) << std::endl;
    std::cout << "Element at index 4: " << *list.at(4) << std::endl;
    std::cout << "Trying to access element 5 returns nullptr: " << (list.at(5) == nullptr) << std::endl;

    list.insert_at(7, 3);

    std::cout << "Inserting new element at index 3: " << *list.at(3) << std::endl;
    std::cout << "Element at index 5 is now: " << *list.at(5) << std::endl;
}