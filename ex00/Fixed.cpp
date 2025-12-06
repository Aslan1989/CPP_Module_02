/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:13:36 by aslan             #+#    #+#             */
/*   Updated: 2025/12/01 19:24:05 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Copy constructor: create a new object from another object.
 * @param other The source object to copy.
 *
 * We reuse the assignment operator to copy the value. This reduces code.
 * We also print a message to show that the copy constructor was called.
 *  Reuse operator= to copy fields
 */
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Copy assignment operator: assign from an existing object.
 * @param other The source object on the right-hand side.
 * @return *this (reference), so we can write a = b = c;
 *
 * We check for self-assignment (a = a). If not the same object,
 * we copy the raw value using the getter. We print a message too.
 * Protect against a = a
 * Copy using the public API
 * Return current object
 */
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

/**
 * @brief Destructor: runs when the object goes out of scope or is deleted.
 *
 * We only print a message here. There is no dynamic memory to free.
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Get raw bits
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

// Set raw bits
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
