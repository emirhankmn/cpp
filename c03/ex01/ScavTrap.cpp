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

ScavTrap::ScavTrap() : ClapTrap("Unnamed ScavTrap") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "\033[0;32mScavTrap " << name << " created with default constructor.\033[0m\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "\033[0;32m";
    std::cout << "ScavTrap " << name << " created with name constructor.\n";
    std::cout << "Hit Points: " << hitPoints << std::endl << "Energy Points: " << energyPoints << std::endl << "Attack Damage: " << attackDamage << std::endl << "\033[0m\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "\033[0;34mScavTrap " << name << " copied with copy constructor.\033[0m\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
        std::cout << "\033[0;34mScavTrap " << name << " assigned with copy assignment operator.\033[0m\n";
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "\033[0;31mScavTrap " << name << " destroyed.\033[0m\n";
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "\033[0;33m";
        std::cout << "\033[0;33mScavTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!\n";
        std::cout << "New Energy Points: " << energyPoints << std::endl << "\033[0m\n";
    } 
    else {
        if (energyPoints == 0) {
            std::cout << "\033[0;31mScavTrap " << name << " has no energy left to attack!\033[0m\n";
        }
        else{
            std::cout << "\033[0;31mScavTrap " << name << " is dead, can't attack anymore!\033[0m\n";
        }
    }
}

void ScavTrap::guardGate() {
    std::cout << "\033[0;36mScavTrap " << name << " is now in Gate Keeper mode!\033[0m\n";
}
