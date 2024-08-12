/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:18:56 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 03:18:56 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type){
    return;
}

Weapon::~Weapon(void){
    return;
}

const std::string& Weapon::getType(void){
    return this->type;
}

void Weapon::setType(std::string type){
    this->type = type;
    return;
}