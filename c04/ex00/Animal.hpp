/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 07:39:50 by eakman            #+#    #+#             */
/*   Updated: 2024/10/27 07:39:50 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const;
};

#endif
