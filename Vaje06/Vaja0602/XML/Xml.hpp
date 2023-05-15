#pragma once

#include <string>

class Xml {
    public:
        [[nodiscard]] virtual std::string toXml() const = 0;

        virtual ~Xml() { ; };
};
