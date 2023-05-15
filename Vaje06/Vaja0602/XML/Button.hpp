#pragma once

#include <View.hpp>
#include <string>

class Button : public View {
    public:
        Button(const Position& position, const Size& size, const std::string &text);

        [[nodiscard]] const std::string &getText() const;

        void setText(const std::string &text);

        [[nodiscard]] std::string toXml() const override;

    private:
        std::string text;
};