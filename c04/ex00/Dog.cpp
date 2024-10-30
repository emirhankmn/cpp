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

// Dog.cpp
#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
