#pragma once

#include <View.hpp>
#include <string>

class ImageView : public View {
    public:
        ImageView(const Position& position, const Size& size, const std::string& imgPath);

        [[nodiscard]] const std::string &getImgPath() const;

        void setImgPath(const std::string &imgPath);

        [[nodiscard]] std::string toXml() const override;

    private:
        std::string imgPath;
};

