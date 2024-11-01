/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:59:44 by eakman            #+#    #+#             */
/*   Updated: 2024/10/23 17:59:44 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    // ScavTrap nesnesi oluşturma ve temel testler
    ScavTrap scav("Guardian");

    // ScavTrap ile saldırı
    scav.attack("enemy");

    // ScavTrap'in Gate Keeper modunu test etme
    scav.guardGate();

    // Hasar alma ve onarma işlemleri
    scav.takeDamage(30);
    scav.beRepaired(20);

    // Enerji bitene kadar saldırı denemeleri
    for (int i = 0; i < 10; ++i) {
        scav.attack("another enemy");
    }

    // Hasar alma ve onarım testi tekrar
    scav.beRepaired(50);
    scav.takeDamage(100);

    return 0;
}


