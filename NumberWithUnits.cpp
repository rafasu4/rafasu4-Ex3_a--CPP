#include "NumberWithUnits.hpp"
namespace ariel
{

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &other) const
    {
        return NumberWithUnits(this->value + other.value, this->measure);
    }

    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &other)
    {
        this->value += other.value;
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator+()
    {
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator++()
    {
        this->value++;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator++(int num)
    {
        NumberWithUnits temp(*this);
        this->value++;
        return temp;
    }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &other) const
    {
        return NumberWithUnits(this->value - other.value, this->measure);
    }

    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &other)
    {
        this->value -= other.value;
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator-()
    {
        this->value *= -1;
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator--()
    {
        this->value--;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int num)
    {
        NumberWithUnits temp(*this);
        this->value--;
        return temp;
    }

    NumberWithUnits &NumberWithUnits::operator*(double num)
    {
        this->value *= num;
        return *this;
    }

    NumberWithUnits &operator*(double num, NumberWithUnits &n)
    {
        return n * num;
    }

    bool NumberWithUnits::operator<(const NumberWithUnits &other) const
    {
        bool ans = false;
        (this->value > other.value) ? ans = true : ans;
        return ans;
    }

    bool NumberWithUnits::operator<=(const NumberWithUnits &other) const
    {
        bool ans = false;
        (this->value <= other.value) ? ans = true : ans;
        return ans;
    }

    bool NumberWithUnits::operator>(const NumberWithUnits &other) const
    {
        bool ans = false;
        (this->value > other.value) ? ans = true : ans;
        return ans;
    }

    bool NumberWithUnits::operator>=(const NumberWithUnits &other) const
    {
        bool ans = false;
        (this->value >= other.value) ? ans = true : ans;
        return ans;
    }

    bool NumberWithUnits::operator==(const NumberWithUnits &other) const
    {
        bool ans = false;
        (this->value == other.value) ? ans = true : ans;
        return ans;
    }

    bool NumberWithUnits::operator!=(const NumberWithUnits &other) const
    {
        bool ans = false;
        (this->value != other.value) ? ans = true : ans;
        return ans;
    }

    ostream &operator<<(ostream &os, const NumberWithUnits& n)
    {
        os << "value: " << n.value << "unit: " << n.measure;
        return os;
    }

    istream &operator>>(istream &is, NumberWithUnits& n)
    {
        is >> n.value;
        return is;
    }
}