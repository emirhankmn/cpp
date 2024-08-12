/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:03:15 by eakman            #+#    #+#             */
/*   Updated: 2024/08/12 00:03:15 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::opereator=(const Fixed &fixed){
    
}