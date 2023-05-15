#pragma once

#include <Xml.hpp>
#include <vector>
#include <string>
#include <View.hpp>

class Layout : public Xml {
    public:
        Layout();

        ~Layout() override;

        void addView(View* view);

        [[nodiscard]] std::string toXml() const override;

    private:
        std::vector<View*> views{};
};
