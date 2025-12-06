/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:19:04 by aslan             #+#    #+#             */
/*   Updated: 2025/11/08 19:19:32 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ------------------------ Constructors ------------------------

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int intValue) {
    _value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    _value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _value = other._value;
    return *this;
}

Fixed::~Fixed() {}

// ------------------------ Conversion ------------------------

float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// ------------------------ Raw bits ------------------------

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// ------------------------ Comparison operators ------------------------

bool Fixed::operator>(const Fixed& other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed& other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return _value != other._value; }

// ------------------------ Arithmetic operators ------------------------

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed res;
    res.setRawBits(_value + other._value);
    return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed res;
    res.setRawBits(_value - other._value);
    return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed res;
    // Умножаем как float и возвращаем fixed
    res.setRawBits((_value * other._value) >> _fractionalBits);
    return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed res;
    // Деление (может быть деление на 0 — это ок по заданию)
    res.setRawBits((_value << _fractionalBits) / other._value);
    return res;
}

// ------------------------ Increment/Decrement ------------------------

Fixed& Fixed::operator++() {
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed& Fixed::operator--() {
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _value--;
    return temp;
}

// ------------------------ Min / Max ------------------------

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// ------------------------ Output stream ------------------------

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
