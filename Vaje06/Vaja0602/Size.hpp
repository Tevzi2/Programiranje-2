#pragma once

class Size {
    public:
        Size(float width, float height);

        void setWidth(float width);

        void setHeight(float height);

        [[nodiscard]] float getWidth() const;

        [[nodiscard]] float getHeight() const;

    private:
        float width;
        float height;
};
