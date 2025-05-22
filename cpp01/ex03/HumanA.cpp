/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:15:47 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 03:15:47 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): name(name), weapon(weapon){
    return;
}

HumanA::~HumanA(void){
    return;
}

void HumanA::attack(void){
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
    return;
}
