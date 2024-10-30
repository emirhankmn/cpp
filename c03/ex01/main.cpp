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
    // ClapTrap'i test ediyoruz
    ClapTrap clap("Jhonwick");
    clap.attack("dogkiller");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // ScavTrap'i test ediyoruz
    ScavTrap scav("OPTIMUS");
    scav.attack("megatron");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();  // Özel ScavTrap fonksiyonunu çağırıyoruz

    return 0;
}

