/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:21:50 by eakman            #+#    #+#             */
/*   Updated: 2025/06/16 17:21:50 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;
    
    bool isValidDate(const std::string& date);
    bool isValidValue(double value);
    double stringToDouble(const std::string& str);
    std::string trim(const std::string& str);
    std::string findClosestDate(const std::string& date);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    bool loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
};

#endif