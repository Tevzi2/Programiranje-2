#include <Printer.h>

#define NEW_LINE { std::cout << std::endl; }

int main()
{
    std::vector<std::string> to_remove = {"prog", "prog2"};
    Printer p;

    // first print no mods

    std::cout << "first print no mods" << std::endl;

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.print();

    NEW_LINE;

    // second print (remove all elemtns of lenght 1

    std::cout << "second print (remove all elemtns of lenght 1)" << std::endl;

    p.add(1, 2, 3, 4, 5, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.remove([](const std::string& el) -> bool {
        return el.length() == 1;
    });

    p.print();

    NEW_LINE;

    // third print remove all elements contained in the vecotr to_remove

    std::cout << "third print remove all elements contained in the vecotr to_remove" << std::endl;

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.remove([to_remove](const std::string& el) -> bool {
        for(const auto& el2 : to_remove)
            if(el.compare(el2) == 0) return true;

        return false;
    });

    p.print();

    NEW_LINE;

    // forth print for sorted sizes from smalest to largest

    std::cout << "forth print for sorted sizes from smalest to largest" << std::endl;

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.sort([](std::string l, std::string r) -> bool {
        return l.size() > r.size();
    });

    p.print();

    NEW_LINE;

    // fifth print for correcting all strings that start with lower case letters to upper case letters

    std::cout << "fifth print for correcting all strings that start with lower case letters to upper case letters" << std::endl;

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.checkAndCorrect([](std::string s) -> bool { return s[0] >= 97 && s[0] <= 122; }, [](std::string s) -> std::string {
        s[0] -= 32;
        return s;
    });

    p.print();

    NEW_LINE;

    // sixth print only strings that are longer the 5 characters

    std::cout << "sixth print only strings that are longer then 5 characters" << std::endl;

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    std::cout << "Selected: " << std::endl;
    p.printSelect([](std::string s) -> bool { return s.size() > 5; });

    std::cout << "Leftover: " << std::endl;
    p.print();

    NEW_LINE;

    // seventh modify everything to be between brackets then print

    std::cout << "seventh modify everything to be between brackets then print" << std::endl;

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.modoifyAll([](std::string el) -> std::string {
        return std::string("|") + el + "|";
    });

    p.print();

    NEW_LINE;

    // eight remove from queue at index/es

    std::cout << "eight remove from queue at index/es" << std::endl;

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.removeIndex(2, 1, 0);

    p.print();

    NEW_LINE;

    // nine remove from queue at index/es in reverse order

    std::cout << "eight remove from queue at index/es" << std::endl;

    p.add(1, 2, 1.2f, "lole Ha Ha!");

    p.addMultiple(std::vector<std::string>{"testing", "Testing", "shesting", "rene je", "zan ni", "prog", "prog2", "prog3"});

    p.removeIndex(0, 1, 2);

    p.print();

    NEW_LINE;
}