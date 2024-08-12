/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 00:00:27 by eakman            #+#    #+#             */
/*   Updated: 2024/08/12 00:00:27 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed{
    private:
        int value;
        stattic const int bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &opereator = (const Fixed &fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif