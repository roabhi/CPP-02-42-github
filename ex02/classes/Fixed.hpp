// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/08 14:41:42 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/08 18:38:37 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> 

class Fixed {

public:

	Fixed();
	~Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &fixed);
	
	// Overflow definitions
	
	// Assignation
	Fixed &operator=(const Fixed &fixed);

	// Compare
	
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	// Operations

	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	// Increments

	Fixed operator++(int);
	Fixed operator++(void);
	Fixed operator--(int);
	Fixed operator--(void);

	static Fixed max(Fixed &a, Fixed &b);
	static const Fixed max(const Fixed &a, const Fixed &b);
	static Fixed min(Fixed &a, Fixed &b);
	static const Fixed min(const Fixed &a, const Fixed &b);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	

private:

	int _rawBits;
	static const int _bits = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
