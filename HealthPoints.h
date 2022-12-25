
#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

#include <iostream>

class HealthPoints{
    int m_currentHP;
    int m_maxHP;
    friend std::ostream& operator<<(std::ostream&, const HealthPoints&);
    friend int operator+(const int&, HealthPoints&);
    friend int operator-(const int&, HealthPoints&);
    friend bool operator==(const int ,const HealthPoints&);
    friend bool operator!=(const int ,const HealthPoints&);
    friend bool operator>=(const int ,const HealthPoints&);
    friend bool operator>(const int ,const HealthPoints&);
    friend bool operator<=(const int ,const HealthPoints&);
    friend bool operator<(const int, const HealthPoints&);

public:
    class InvalidArgument{};
    HealthPoints(int maxHP = 100);
    HealthPoints(const HealthPoints&) = default;
    ~HealthPoints() = default;
    HealthPoints& operator+=(const int&);
    HealthPoints& operator+=(const HealthPoints&) = delete;
    HealthPoints& operator-=(const int&);
    HealthPoints& operator-(const int&);
    HealthPoints& operator+(const int&);
    HealthPoints& operator=(int);
    HealthPoints& operator=(const HealthPoints&) = default;
    bool operator==(const int) const;
    bool operator==(const HealthPoints&) const;
    bool operator!=(const int) const;
    bool operator!=(const HealthPoints&) const;
    bool operator>(const HealthPoints&) const;
    bool operator>(const int) const;
    bool operator<(const HealthPoints&) const;
    bool operator<(const int) const;
    bool operator>=(const HealthPoints&) const;
    bool operator>=(const int) const;
    bool operator<=(const HealthPoints&) const;
    bool operator<=(const int) const;
};

#endif //EX3_HEALTHPOINTS_H
