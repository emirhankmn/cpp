/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:44:48 by eakman            #+#    #+#             */
/*   Updated: 2024/08/10 19:44:48 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void) {std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;}
void Zombie::setName(std::string name) {this->name = name;}
Zombie::~Zombie(void) {std::cout << this->name << " is dead." << std::endl;}