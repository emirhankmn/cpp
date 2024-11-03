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
    
    ScavTrap scav("Guardian");
    scav.attack("enemy");
    scav.guardGate();
    scav.takeDamage(30);
    scav.beRepaired(20);
    for (int i = 0; i < 10; ++i) {
        scav.attack("another enemy");
    }
    scav.beRepaired(50);
    scav.takeDamage(100);

    return 0;
}


