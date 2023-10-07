// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FixedTwo.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/07 20:45:09 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/07 21:04:13 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &fixedp);
		~Fixed();
		Fixed	&operator=(const Fixed &fixedp);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	 const;
	
	private:
		int	_rawBits;
		static const int _bits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixedp);

#endif
