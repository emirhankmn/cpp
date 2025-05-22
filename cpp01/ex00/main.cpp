/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:39:30 by eakman            #+#    #+#             */
/*   Updated: 2024/08/10 18:39:30 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie zombie = Zombie("Foo");
    zombie.announce();
    Zombie* zombie2 = newZombie("Zoo");
    zombie2->announce();
    randomChump("Too");
    delete zombie2;
    return 0;
}
