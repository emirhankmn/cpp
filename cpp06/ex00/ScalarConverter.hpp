/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:31:13 by eakman            #+#    #+#             */
/*   Updated: 2025/05/09 17:31:13 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter {
    public:
        static void convert(const std::string& literal);
    
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
    
        static bool isChar(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
        static bool isPseudoLiteral(const std::string& literal);
};

#endif
