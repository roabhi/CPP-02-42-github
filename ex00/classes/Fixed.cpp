// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/05 17:52:20 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/05 17:58:33 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"

Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixedp)
{
	*this = fixedp;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixedp)
{
	if (this != &fixedp)
		this->_rawBits = fixedp.getRawBits();
	std::cout << "Asignation operator called" << std::endl;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return (this->_rawBits);
	
}


void	Fixed::setRawBits(const int raw)
{
	_rawBits = raw;
	std::cout << "setRawBits called" << std::endl;
}
