/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:09:41 by eakman            #+#    #+#             */
/*   Updated: 2024/10/24 07:09:41 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FragTrap.cpp
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed FragTrap") {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "\033[0;32mFragTrap " << name << " created with default constructor.\033[0m\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "\033[0;32m";
    std::cout << "\033[0;32mFragTrap " << name << " created with name constructor.\n";
    std::cout << "Hit Points: " << hitPoints << std::endl << "Energy Points: " << energyPoints << std::endl << "Attack Damage: " << attackDamage << std::endl << "\033[0m\n\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "\033[0;34mFragTrap " << name << " copied with copy constructor.\033[0m\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
        std::cout << "\033[0;34mFragTrap " << name << " assigned with copy assignment operator.\033[0m\n";
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "\033[0;31mFragTrap " << name << " destroyed.\033[0m\n";
}

void FragTrap::highFivesGuys() {
    std::cout << "\033[0;36mFragTrap " << name << " requests high fives from everyone!\033[0m\n";
}
