/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 02:18:34 by eakman            #+#    #+#             */
/*   Updated: 2024/10/01 02:18:34 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
    std::cout << "Int constructor called" << std::endl;
    this->value = value << bits;
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed &fixed){
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed){
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    return this->value;
}

float Fixed::toFloat(void) const {
    return (float)this->value / (1 << bits);
}

int Fixed::toInt(void) const {
    return this->value >> bits;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

std::ostream & operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}