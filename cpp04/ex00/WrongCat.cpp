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

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "A WrongCat is created." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    type = other.type;
    std::cout << "A WrongCat is copied." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        type = other.type;
    }
    std::cout << "WrongCat assignment operator called." << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "A WrongCat is destroyed." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow... but wrong!" << std::endl;
}


