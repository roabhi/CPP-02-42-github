// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/08 14:50:21 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/09 20:36:02 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"


// Constructors

Fixed::Fixed()
{
	_intVal = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_intVal = i << _bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_intVal = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}


// Destructor

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

// Overflow definitions

// Asignation

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Asignation operator called" << std::endl;
	if (this != &fixed)
		this->_intVal = fixed.getRawBits();
	return (*this);
}


// compare

bool Fixed::operator>(const Fixed &fixed) const
{
	//std::cout << "Greater than operator called" << std::endl;
	return (this->_intVal > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	//std::cout << "Lesser than operator called" << std::endl;
	return (this->_intVal < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	//std::cout << "Greater or equal than operator called" << std::endl;
	return (this->_intVal >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	//std::cout << "Lesser or equal than operator called" << std::endl;
	return (this->_intVal <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	//std::cout << "Double equal than operator called" << std::endl;
	return (this->_intVal == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	//std::cout << "Not equal than operator called" << std::endl;
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
