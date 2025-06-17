/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 03:54:26 by eakman            #+#    #+#             */
/*   Updated: 2025/06/17 03:54:26 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "ERROR!! Usage: " << argv[0] << " <positive integers>" << std::endl;
        std::cerr << "Example: " << argv[0] << " 42 23 17 8 15" << std::endl;
        return 1;
    }
    
    PmergeMe sorter;
    
    if (!sorter.parseInput(argv))
    {
        std::cerr << "ERROR!! Invalid input." << std::endl;
        return 1;
    }
    
    sorter.sortAndTime();
    
    return 0;
}