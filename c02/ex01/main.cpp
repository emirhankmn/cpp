/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 02:18:22 by eakman            #+#    #+#             */
/*   Updated: 2024/10/01 02:18:22 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed const b( 10 );
    std::cout << "b is " << b << std::endl;
    Fixed const d( b );
    std::cout << "d is " << d << std::endl;

    return 0;
}