#pragma once

class Position {
    public:
        Position(float x, float y);

        void setX(float x);

        void setY(float y);

        [[nodiscard]] float getX() const;

        [[nodiscard]] float getY() const;

    private:
        float x;
        float y;
};
