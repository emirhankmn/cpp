/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:35:15 by eakman            #+#    #+#             */
/*   Updated: 2024/10/27 08:35:15 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "A Cat is created." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    type = other.type;
    std::cout << "A Cat is copied." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        type = other.type;
    }
    std::cout << "Cat assignment operator called." << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "A Cat is destroyed." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
