/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslan <aslan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:16:23 by aslan             #+#    #+#             */
/*   Updated: 2025/11/08 19:16:41 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int                 _value;                 // "сырая" форма фиксированного числа
	static const int    _fractionalBits = 8;    // 8 дробных бит

public:
	// Orthodox Canonical Form
	Fixed();                                // Default constructor
	Fixed(const Fixed& other);              // Copy constructor
	Fixed& operator=(const Fixed& other);   // Copy assignment operator
	~Fixed();                               // Destructor

	// New constructors
	Fixed(const int intValue);              // Construct from int
	Fixed(const float floatValue);          // Construct from float

	// Member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;              // Convert to float
	int toInt(void) const;                  // Convert to int
};

// Overload << operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
