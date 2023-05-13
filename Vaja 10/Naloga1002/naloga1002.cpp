#include <Printer.h>

int main()
{
    std::vector<std::string> to_remove = {"prog", "prog2"};
    Printer p;

    // first print no mods

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.print();

    // second print (remove all elemtns of lenght 1

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.remove([](const std::string& el) -> bool {
        return el.size() == 1;
    });

    p.print();

    // third print remove all elements contained in the vecotr to_remove

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.remove([to_remove](const std::string& el) -> bool {
        for(const auto& el2 : to_remove)
            if(el.compare(el2) == 0) return true;

        return false;
    });

    // forth 
}