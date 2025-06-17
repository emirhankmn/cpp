/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:23:09 by eakman            #+#    #+#             */
/*   Updated: 2025/06/16 17:23:09 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: ./btc <input_file> <data_csv>" << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    
    if (!btc.loadDatabase(argv[2]))
    {
        std::cerr << "Error: could not load database." << std::endl;
        return 1;
    }
    
    btc.processInput(argv[1]);
    
    return 0;
}