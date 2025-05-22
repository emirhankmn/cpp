/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 02:56:22 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 02:56:22 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Memory address of the string: " << &str << std::endl;
    std::cout << "Memory address of the stringPTR: " << &stringPTR << std::endl;
    std::cout << "Memory address of the stringREF: " << &stringREF << std::endl;
    std::cout << "String: " << str << std::endl;
    std::cout << "StringPTR: " << *stringPTR << std::endl;
    std::cout << "StringREF: " << stringREF << std::endl;

    return 0;
}