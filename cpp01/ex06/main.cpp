/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:46:58 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 18:46:58 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "Usage: ./complain [debug/info/warning/error]" << std::endl;
        return 1;
    }
    Harl    harl;
    harl.complain(av[1]);
    return 0;
}