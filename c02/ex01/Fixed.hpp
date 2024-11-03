/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 02:18:31 by eakman            #+#    #+#             */
/*   Updated: 2024/10/01 02:18:31 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int value;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(int const value);
        Fixed(float const value);
        Fixed(const Fixed &fixed);
        Fixed& operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        ~Fixed();
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);

#endif