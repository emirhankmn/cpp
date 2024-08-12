/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 03:08:17 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 03:08:17 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string);
        ~Weapon(void);
        const std::string& getType(void);
        void setType(std::string);
};

#endif