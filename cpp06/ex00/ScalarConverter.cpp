/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:28:40 by eakman            #+#    #+#             */
/*   Updated: 2025/05/21 23:28:40 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

void ScalarConverter::convert(const std::string& literal) {
    
    // 1. PSEUDO LITERALS (nan, nanf, +inf, +inff, -inf, -inff)
    if (isPseudoLiteral(literal)) {
    std::string floatVal;
    std::string doubleVal;

    if (literal == "nanf") {
        floatVal = "nanf";
        doubleVal = "nan";
    }
    else if (literal == "+inff") {
        floatVal = "+inff";
        doubleVal = "+inf";
    }
    else if (literal == "-inff") {
        floatVal = "-inff";
        doubleVal = "-inf";
    }
    else if (literal == "nan") {
        floatVal = "nanf";
        doubleVal = "nan";
    }
    else if (literal == "+inf") {
        floatVal = "+inff";
        doubleVal = "+inf";
    }
    else if (literal == "-inf") {
        floatVal = "-inff";
        doubleVal = "-inf";
    }

    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << floatVal << "\n";
    std::cout << "double: " << doubleVal << "\n";
    return;
    }




    // 2. CHAR
    if (isChar(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }

    // 3. INT
    if (isInt(literal)) {
        long val = std::strtol(literal.c_str(), NULL, 10);
        if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max()) {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }

        int i = static_cast<int>(val);
        if (i >= 32 && i <= 126)
            std::cout << "char: '" << static_cast<char>(i) << "'\n";
        else
            std::cout << "char: Non displayable\n";

        std::cout << "int: " << i << "\n";
        std::cout << "float: " << static_cast<float>(i) << ".0f\n";
        std::cout << "double: " << static_cast<double>(i) << ".0\n";
        return;
    }

    // 4. FLOAT
    if (isFloat(literal)) {
        float f = std::strtof(literal.c_str(), NULL);

        if (std::isnan(f) || std::isinf(f) ||
            f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
            std::cout << "char: impossible\n";
        else if (f >= 32 && f <= 126)
            std::cout << "char: '" << static_cast<char>(f) << "'\n";
        else
            std::cout << "char: Non displayable\n";

        if (std::isnan(f) || std::isinf(f) ||
            f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(f) << "\n";

        std::cout << "float: " << f;
        if (f - static_cast<int>(f) == 0)
            std::cout << ".0f\n";
        else
            std::cout << "f\n";

        std::cout << "double: " << static_cast<double>(f);
        if (f - static_cast<int>(f) == 0)
            std::cout << ".0\n";
        else
            std::cout << "\n";
        return;
    }

    // 5. DOUBLE
    if (isDouble(literal)) {
        double d = std::strtod(literal.c_str(), NULL);

        if (std::isnan(d) || std::isinf(d) ||
            d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
            std::cout << "char: impossible\n";
        else if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        else
            std::cout << "char: Non displayable\n";

        if (std::isnan(d) || std::isinf(d) ||
            d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(d) << "\n";

        if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
            std::cout << "float: impossible\n";
        else {
            float f = static_cast<float>(d);
            std::cout << "float: " << f;
            if (f - static_cast<int>(f) == 0)
                std::cout << ".0f\n";
            else
                std::cout << "f\n";
        }

        std::cout << "double: " << d;
        if (d - static_cast<int>(d) == 0)
            std::cout << ".0\n";
        else
            std::cout << "\n";
        return;
    }

    // 6. NONE MATCHED
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

// ------------------- Helper Functions ----------------------

bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    std::strtol(literal.c_str(), &end, 10);
    return (*end == '\0');
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    char* end;
    std::strtof(literal.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    char* end;
    std::strtod(literal.c_str(), &end);
    return (*end == '\0');
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}
