// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/08 14:50:21 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/08 19:51:08 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"


// Constructors

Fixed::Fixed()
{
	_intVal = 0;
	return ;
}

Fixed::Fixed(const int i)
{
	this->_intVal = i << _bits;
}

Fixed::Fixed(const float f)
{
	this->_intVal = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}


// Destructor

Fixed::~Fixed()
{
	return ;
}

// Overflow definitions

// Asignation

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_intVal = fixed.getRawBits();
	return (*this);
}


// compare

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->_intVal > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->_intVal < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_intVal >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_intVal <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->_intVal == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_intVal != fixed.getRawBits());
}

// Operations

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

// Increments

Fixed	Fixed::operator++(int)
{
	Fixed pre(*this);
	operator++();
	return (pre);
}

Fixed	Fixed::operator++(void)
{
	++this->_intVal;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed pre(*this);
	operator--();
	return (pre);
}

Fixed	Fixed::operator--(void)
{
	--this->_intVal;
	return (*this);
}


// Public functions

void Fixed::setRawBits(const int raw)
{
	this->_intVal = raw;
}

int Fixed::getRawBits(void) const
{
	return (this->_intVal);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(this->getRawBits()) >> _bits);
}


Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}


// Overflow

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}
