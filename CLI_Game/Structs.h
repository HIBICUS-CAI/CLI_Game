#pragma once

struct POSITION_2D
{
    int posX;
    int posY;

    POSITION_2D(int _x, int _y)
    {
        posX = _x;
        posY = _y;
    }

    int operator==(const POSITION_2D other) const
    {
        return (this->posX == other.posX) && (this->posY == other.posY);
    }

    int operator!=(const POSITION_2D other) const
    {
        return (this->posX != other.posX) || (this->posY != other.posY);
    }

    POSITION_2D operator+(const POSITION_2D other) const
    {
        POSITION_2D temp(0, 0);
        temp.posX = this->posX + other.posX;
        temp.posY = this->posY + other.posY;
        return temp;
    }

    POSITION_2D operator-(const POSITION_2D other) const
    {
        POSITION_2D temp(0, 0);
        temp.posX = this->posX - other.posX;
        temp.posY = this->posY - other.posY;
        return temp;
    }

    POSITION_2D operator*(const int value) const
    {
        POSITION_2D temp(0, 0);
        temp.posX = this->posX * value;
        temp.posY = this->posY * value;
        return temp;
    }

    POSITION_2D operator/(const int value) const
    {
        POSITION_2D temp(0, 0);
        temp.posX = this->posX / value;
        temp.posY = this->posY / value;
        return temp;
    }
};
