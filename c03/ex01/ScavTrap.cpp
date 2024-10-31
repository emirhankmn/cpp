/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:14:30 by eakman            #+#    #+#             */
/*   Updated: 2024/10/24 00:14:30 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Kurucu: Başlangıç değerleri atanıyor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " to create." << std::endl;
}

// Yok edici: Sınıf yok edildiğinde bir mesaj yazdırılır
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " is destroy." << std::endl;
}

// guardGate fonksiyonu: Kapı bekçisi moduna geçer
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << "  Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap " << name << " fiercely attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

