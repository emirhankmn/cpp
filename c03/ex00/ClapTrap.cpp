/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:53:55 by eakman            #+#    #+#             */
/*   Updated: 2024/10/23 17:53:55 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Kurucu: Başlangıç değerleri atanıyor
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " to create." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " is destroy." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        if (hitPoints == 0) {
            std::cout << "ClapTrap " << name << " has no life left." << std::endl;
        } 
        else {
            std::cout << "ClapTrap " << name << " does not have enough energy." << std::endl;
        }
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount; // Can 0'ın altına inmez
    std::cout << "ClapTrap " << name << " " << amount << " took damage! Current heart: " << hitPoints << std::endl;
}

// Onarma fonksiyonu: Belirtilen miktarda can kazanır
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " " << amount << " heart recover. Current heart: " << hitPoints << std::endl;
    } else {
        if (hitPoints == 0) {
            std::cout << "ClapTrap " << name << " has no life left." << std::endl;
        } 
        else {
            std::cout << "ClapTrap " << name << " does not have enough energy." << std::endl;
        }
    }
}
