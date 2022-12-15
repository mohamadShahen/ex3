
#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

#include <iostream>

class HealthPoints{
    int m_currentHP;
    int m_maxHP;
    friend std::ostream& operator<<(std::ostream&, const HealthPoints&);
public:
    HealthPoints(int maxHP = 100);
    HealthPoints(HealthPoints&) = default;
    ~HealthPoints() = default;

    HealthPoints& operator=(int);
    HealthPoints& operator=(const HealthPoints&) = default;
    bool operator==(HealthPoints&) const;
    bool operator>(HealthPoints&) const;
    bool operator<(HealthPoints&) const;
    bool operator>=(HealthPoints&) const;
    bool operator<=(HealthPoints&) const;
};

#endif //EX3_HEALTHPOINTS_H
