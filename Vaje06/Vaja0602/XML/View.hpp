#pragma once

#include <Xml.hpp>
#include <Size.hpp>
#include <Position.hpp>

class View : public Xml {
    public:
        View(const Size& size, const Position& position);

        virtual ~View() override { ; };

        [[nodiscard]] const Size &getSize() const;

        void setSize(const Size &size);

        [[nodiscard]] const Position &getPosition() const;

        void setPosition(const Position &position);

protected:
        Size size;
        Position position;
};
