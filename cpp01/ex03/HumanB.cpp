/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:16:58 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 03:16:58 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->name = name;
    return;
}

HumanB::~HumanB(void){
    return;
}

void HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
    return;
}

void HumanB::attack(void){
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
    return;
}