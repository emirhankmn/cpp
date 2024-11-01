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

// Default constructor
ClapTrap::ClapTrap() : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "\033[0;32m";
    std::cout << "ClapTrap " << name << " created with default constructor.\n";
    std::cout << "Hit Points: " << hitPoints << std::endl << "Energy Points: " << energyPoints << std::endl <<"Attack Damage: " << attackDamage << std::endl << "\033[0m\n\n";
}

// Parameterized constructor 
ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "\033[0;32m";
    std::cout << "ClapTrap " << name << " created with name constructor.\n";
    std::cout << "Hit Points: " << hitPoints << std::endl << "Energy Points: " << energyPoints << std::endl << "Attack Damage: " << attackDamage << std::endl << "\033[0m\n\n";
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "\033[0;34m";
    std::cout << "ClapTrap " << name << " copied with copy constructor.\n";
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
        std::cout << "\033[0;34m";
        std::cout << "ClapTrap " << name << " assigned with copy assignment operator.\033[0m\n\n";
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "\033[0;31m";
    std::cout << "ClapTrap " << name << " destroyed.\033[0m\n";
}

// Attack function
void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "\033[0;33m";
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!\n";
        std::cout << "New Energy Points: " << energyPoints << "\033[0m\n\n";
    } 
    else {
        if (hitPoints == 0) {
            std::cout << "\033[0;31m";
            std::cout << "ClapTrap " << name << " is dead, can't attack anymore!\033[0m\n\n";
        } 
        else {
            std::cout << "\033[0;31m";
            std::cout << "ClapTrap " << name << " has no energy left to attack!\033[0m\n\n";
        }
    }
}

// TakeDamage function
void ClapTrap::takeDamage(unsigned int amount) {
    if(hitPoints == 0) {
        std::cout << "\033[0;31m";
        std::cout << "ClapTrap " << name << " is dead, don't shoot him anymore!\033[0m\n\n";
        return;
    }
    std::cout << "\033[0;33m";
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
    if (hitPoints <= amount) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " is destroyed!\033[0m\n\n";
    } else {
        hitPoints -= amount;
        std::cout << "New Hit Points: " << hitPoints << "\033[0m\n\n";
    }
}

// BeRepaired function
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "\033[0;32m";
        std::cout << "ClapTrap " << name << " repairs itself, restoring " << amount 
                  << " hit points!\n";
        std::cout << "New Hit Points: " << hitPoints << std::endl << "New Energy Points: " << energyPoints << std::endl << "\033[0m\n\n";
    } else {
        std::cout << "\033[0;31m";
        if (hitPoints == 0) {
            std::cout << "ClapTrap " << name << " is dead, can't repair him!\033[0m\n\n";
        } else {
            std::cout << "ClapTrap " << name << " has no energy left to repair itself!\033[0m\n\n";
        }
    }
}


