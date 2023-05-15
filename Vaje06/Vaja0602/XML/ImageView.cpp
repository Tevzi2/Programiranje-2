#include <ImageView.hpp>

ImageView::ImageView(const Position& position, const Size& size, const std::string& imgPath)
    : View(size, position), imgPath(imgPath)
{
    ;
}

[[nodiscard]] const std::string &ImageView::getImgPath() const
{
    return imgPath;
}

void ImageView::setImgPath(const std::string &imgPath) {
    ImageView::imgPath = imgPath;
}

[[nodiscard]] std::string ImageView::toXml() const
{
    std::string out = "<Button\n";
    out += "\t\twidth=\"" + std::to_string(size.getWidth()) + "px\"\n" +
           "\t\theight=\"" + std::to_string(size.getHeight()) + "px\"\n" +
           "\t\timgPath=\"" + imgPath + "\"\n" +
           "\t\tvisible=\"true\"/>\n";

    return out;
}
