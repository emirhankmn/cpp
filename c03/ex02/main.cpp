/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:16:15 by eakman            #+#    #+#             */
/*   Updated: 2024/10/24 07:16:15 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    // FragTrap nesnesi oluşturma ve temel testler
    FragTrap frag("Warrior");

    // FragTrap ile saldırı
    frag.attack("enemy");

    // FragTrap'in High Five işlevini test etme
    frag.highFivesGuys();

    // Hasar alma ve onarma işlemleri
    frag.takeDamage(30);
    frag.beRepaired(20);

    // Enerji bitene kadar saldırı denemeleri
    for (int i = 0; i < 10; ++i) {
        frag.attack("another enemy");
    }

    // Hasar alma ve onarım testi tekrar
    frag.takeDamage(100);
    frag.beRepaired(50);

    return 0;
}

