/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:21:32 by eakman            #+#    #+#             */
/*   Updated: 2024/10/27 08:21:32 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.cpp
#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
    std::cout << "Animal created." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destroyed." << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Animal sound!" << std::endl;
}
