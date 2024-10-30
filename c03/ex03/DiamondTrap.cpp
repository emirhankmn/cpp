/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:22:42 by eakman            #+#    #+#             */
/*   Updated: 2024/10/24 07:22:42 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DiamondTrap.cpp
#include "DiamondTrap.hpp"

// Kurucu: Başlangıç değerleri atanıyor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    hitPoints = FragTrap::hitPoints;  // FragTrap'ten miras alıyor
    energyPoints = ScavTrap::energyPoints;  // ScavTrap'ten miras alıyor
    attackDamage = FragTrap::attackDamage;  // FragTrap'ten miras alıyor
    std::cout << "DiamondTrap " << this->name << " oluşturuldu!" << std::endl;
}

// Yok edici: Sınıf yok edildiğinde bir mesaj yazdırılır
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " yok edildi!" << std::endl;
}

// whoAmI fonksiyonu: Hem kendi adını hem de ClapTrap adını yazdırır
void DiamondTrap::whoAmI() {
    std::cout << "Benim adım: " << this->name << ", ClapTrap adım: " << ClapTrap::name << std::endl;
}
