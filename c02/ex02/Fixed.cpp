/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:52:06 by eakman            #+#    #+#             */
/*   Updated: 2024/10/08 10:52:06 by eakman           ###   ########.fr       */
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

bool Fixed::operator>(const Fixed &fixed) const {
    return this->value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
    return this->value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return this->value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return this->value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
    return this->value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return this->value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

int Fixed::getRawBits(void) const {
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
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

