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

Animal::Animal() : type("Animal") {
    std::cout << "An Animal is created." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "An Animal is copied." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal assignment operator called." << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "An Animal is destroyed." << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound!" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
