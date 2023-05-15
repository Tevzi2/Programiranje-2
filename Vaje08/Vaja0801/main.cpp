#include <LinearQueue.hpp>
#include <Time.hpp>

int main()
{
    LinearQueue<Time> t1;
    t1.add(Time::parse("13:12:13"));
    t1.add(Time::parse("16:12:13"));
    t1.add(Time::parse("21:12:13"));
    t1.add(Time::parse("00:12:13"));
    t1.add(Time::parse("00:12:17"));

    std::cout << "Times to string: " << std::endl;
    print(t1);

    std::cout << "\nMax time in queue: " << std::endl;
    std::cout << getMax(t1).toString() << std::endl;

    reverse(t1);

    std::cout << "\nValues of time queue after inverting it: " << std::endl;
    print(t1);

    LinearQueue<float> f1;
    f1.add(1.2f);
    f1.add(1.5f);
    f1.add(7);
    f1.add(19.5f);
    f1.add(20.5f);

    std::cout << "\nFloats to string" << std::endl;
    print(f1);

    LinearQueue<int> q1;
    q1.add(1);
    q1.add(2);
    q1.add(3);
    q1.add(4);
    q1.add(5);
    q1.add(6);
    q1.add(7);
    q1.add(8);
    q1.add(9);

    std::cout << "\nBeginning state of q1: " << std::endl;
    print(q1);

    std::cout << "\nCurrent first element in queue: " << std::endl;
    std::cout << *q1.element() << std::endl;
    q1.remove();

    std::cout << "\nNext element after removing first: " << std::endl;
    std::cout << *q1.element() << std::endl;

    reverse(q1);
    std::cout << "\nStatus in queue after reversing: " << std::endl;
    print(q1);

    std::cout << "\nFirst element after reversing the queue: " << std::endl;
    std::cout << *q1.element() << std::endl;

    std::cout << "\nMax value in queue: " << getMax(q1) << std::endl;

    LinearQueue<int> q2;

    std::cout << "\nIs queue empty before adding all elements: " << std::endl;
    std::cout << q2.is_empty() << std::endl;

    q2.add(1);
    q2.add(1);
    q2.add(1);
    q2.add(4);
    q2.add(5);
    q2.add(6);
    q2.add(7);
    q2.add(8);
    q2.add(9);
    q2.add(10);

    std::cout << "\nIs queue empty after adding: " << std::endl;
    std::cout << q2.is_empty() << std::endl;

    std::cout << "\nStatus of q2: " << std::endl;
    print(q2);

    half(q2);

    std::cout << "\nStatus of q2 after halfing it: " << std::endl;
    print(q2);

    removeDuplicates(q2);

    std::cout << "\nStatus of q2 after removing duplicates: " << std::endl;
    print(q2);

    std::cout << "\nState of q2 after changing capacity to 2: " << std::endl;
    q2.change_capacity(2);
    print(q2);

    return 0;
}