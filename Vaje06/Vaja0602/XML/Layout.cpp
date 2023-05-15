//
// Created by Tevz on 08/04/2023.
//

#include <Layout.hpp>

Layout::Layout()
{
    ;
}

Layout::~Layout()
{
    for(const auto& view : views)
        delete view;
}

void Layout::addView(View* view)
{
    views.push_back(view);
}

[[nodiscard]] std::string Layout::toXml() const
{
    std::string out = "<Layout>\n";

    for(const auto& view : views)
        out += "\t" + view->toXml();

    out += "</Layout>\n";

    return out;
}
