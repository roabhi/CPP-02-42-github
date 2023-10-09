// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/10/08 14:38:58 by rabril-h          #+#    #+#             //
//   Updated: 2023/10/09 20:29:35 by rabril-h         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "./classes/Fixed.hpp"

int main( void ) {


	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(5);
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "MORE TESTS" << std::endl;
	std::cout << std::endl << "++++++++++++++++++++++++" << std::endl << std::endl;
	a = 20;
	c = 900;
	std::cout << "a+b= " << a+b << std::endl;
	std::cout << "b+c= " << b+c << std::endl;
	std::cout << "c/b= " << c/b << std::endl;
	std::cout << "c/a= " << c/a << std::endl;
	std::cout << "a*b= " << a*b << std::endl;
	
	return(0);
}
