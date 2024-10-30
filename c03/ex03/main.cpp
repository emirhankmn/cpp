/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:15:46 by eakman            #+#    #+#             */
/*   Updated: 2024/10/24 23:15:46 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamondTrap("DiamondTrap");

    diamondTrap.attack("enemy");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(5);
    diamondTrap.whoAmI();
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    return 0;
}