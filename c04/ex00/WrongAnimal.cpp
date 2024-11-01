/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:47:09 by eakman            #+#    #+#             */
/*   Updated: 2024/11/01 18:47:09 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "An WrongAnimal is created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "An WrongAnimal is copied." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "WrongAnimal assignment operator called." << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "A WrongAnimal is destroyed." << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some generic wrong animal sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

