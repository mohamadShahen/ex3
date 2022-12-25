#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxHP)
{
    if (maxHP <= 0){
        throw InvalidArgument();
    }
    else{
        m_maxHP = maxHP;
        m_currentHP = m_maxHP;
    }
}

HealthPoints& HealthPoints::operator=(const int value){
    m_maxHP = 100;
    if(value <= m_maxHP && value >= 0){
        m_currentHP = value;
    }
    else if(value < 0){
        m_currentHP = 0;
    }
    else if(value > m_maxHP){
        m_currentHP = m_maxHP;
    }

    return *this;
}

bool operator==(const int value,const HealthPoints& hp)
{
    return (value == hp.m_currentHP);
}

bool HealthPoints::operator==(const int hp) const
{
    return (m_currentHP == hp);
}

bool HealthPoints::operator==(const HealthPoints& hp) const
{
    return (hp.m_currentHP == m_currentHP);
}

bool operator!=(const int value,const HealthPoints& hp)
{
    return(hp.m_currentHP != value);
}

bool HealthPoints::operator!=(const int hp) const
{
    return (hp != m_currentHP);
}

bool HealthPoints::operator!=(const HealthPoints& hp) const
{
    return (hp.m_currentHP != m_currentHP);
}

bool HealthPoints::operator>=(const HealthPoints& hp) const
{
    return (m_currentHP >= hp.m_currentHP);
}

bool HealthPoints::operator>=(const int value) const
{
    return (m_currentHP >= value);
}

bool operator>=(const int value,const HealthPoints& hp)
{
    return (value <= hp.m_currentHP);
}

bool HealthPoints::operator>(const HealthPoints& hp) const
{
    return (m_currentHP > hp.m_currentHP);
}

bool HealthPoints::operator>(const int value) const
{
    return (m_currentHP > value);
}

bool operator>(const int value,const HealthPoints& hp){
    return (value > hp.m_currentHP);
}

bool HealthPoints::operator<(const HealthPoints& hp) const
{
    return (m_currentHP < hp.m_currentHP);
}

bool HealthPoints::operator<(const int value) const
{
    return (m_currentHP < value);
}

bool operator<(const int value, const HealthPoints& hp)
{
    return (value < hp.m_currentHP);
}

bool HealthPoints::operator<=(const HealthPoints& hp) const
{
    return (m_currentHP <= hp.m_currentHP);
}

bool HealthPoints::operator<=(const int value) const
{
    return (m_currentHP <= value);
}

bool operator<=(const int value,const HealthPoints& hp)
{
    return (value <= hp.m_currentHP);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    os << hp.m_currentHP << '(' << hp.m_maxHP << ')';
    return os;
}

HealthPoints& HealthPoints::operator+=(const int& value)
{
    m_currentHP += value;
    if (m_currentHP > m_maxHP){
        m_currentHP = m_maxHP;
        return *this;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(const int& value)
{
    m_currentHP -= value;
    if (m_currentHP < 0){
        m_currentHP = 0;
        return *this;
    }
    return *this;
}


HealthPoints& HealthPoints::operator+(const int& value)
{
    m_currentHP += value;
    if (m_currentHP > m_maxHP){
        m_currentHP = m_maxHP;
    }
    return *this;
}

int operator+(const int& value, HealthPoints& health)
{
    int temp = value + health.m_currentHP;
    return temp;
}

HealthPoints& HealthPoints::operator-(const int& value)
{
    m_currentHP -= value;
    if (m_currentHP < 0){
        m_currentHP = 0;
    }
    return *this;
}

int operator-(const int& value, HealthPoints& health) {
    int temp = value - health.m_currentHP;
    return temp;
}
