#pragma once

#include <View.hpp>
#include <InputType.hpp>

class EditText : public View {
    public:
        EditText(const Position& position, const Size& size, InputType);

        [[nodiscard]] InputType getInputType() const;

        void setInputType(InputType inputType);

        [[nodiscard]] std::string toXml() const override;

    private:
        InputType inputType;
};
