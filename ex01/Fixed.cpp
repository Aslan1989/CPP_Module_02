/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:16:14 by aslan             #+#    #+#             */
/*   Updated: 2025/11/08 19:16:53 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _fractionalBits; // умножаем на 2^8
}

// Float constructor
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Get raw bits
int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

// Set raw bits
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// Convert to float
float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

// Convert to int
int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// Overload <<
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
