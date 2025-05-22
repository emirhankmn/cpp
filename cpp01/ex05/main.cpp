/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 06:01:25 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 06:01:25 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
    Harl    harl;

    if(ac != 2){
        std::cout << "please provide a level of complaint" << std::endl;
        return 1;
    }
    harl.complain(av[1]);
    return 0;
}