/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:30:45 by eakman            #+#    #+#             */
/*   Updated: 2024/10/27 08:30:45 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "A Dog is created." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    type = other.type;
    std::cout << "A Dog is copied." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        type = other.type;
    }
    std::cout << "Dog assignment operator called." << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "A Dog is destroyed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
