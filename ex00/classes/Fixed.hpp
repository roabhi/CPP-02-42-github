// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/05 17:50:05 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/05 17:52:07 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_HPP
# define FIXED_HPP

# include "../Fixed.h"

class Fixed {

	public:
		Fixed();
		Fixed(const Fixed &fixedp);
		~Fixed();
		Fixed	&operator=(const Fixed &fixedp);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

private:
	int	_rawBits;
		static const int _bits = 8;


};

#endif
