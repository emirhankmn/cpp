/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:22:24 by eakman            #+#    #+#             */
/*   Updated: 2025/06/16 17:22:24 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

double BitcoinExchange::stringToDouble(const std::string& str)
{
    std::stringstream ss(str);
    double value;
    ss >> value;
    if (ss.fail() || !ss.eof())
        return -1;
    return value;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i)
        if ((i != 4 && i != 7) && !isdigit(date[i]))
            return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 1000 || year > 9999 || month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 31, (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28,
                          31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return day >= 1 && day <= daysInMonth[month - 1];
}


bool BitcoinExchange::isValidValue(double value)
{
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string& date)
{
    std::map<std::string, double>::iterator it = _database.lower_bound(date);
    
    if (it == _database.begin())
        return it->first;
    
    if (it == _database.end() || it->first != date)
        --it;
    
    return it->first;
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));
        
        if (isValidDate(date))
        {
            double value = stringToDouble(valueStr);
            if (value >= 0)
                _database[date] = value;
        }
    }
    
    file.close();
    return true;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        
        size_t pos = line.find(" | ");
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 3));
        
        if (!isValidDate(date)) {
            std::cerr << "Error: invalid date format => " << date << std::endl;
        continue;
        }
        
        double value = stringToDouble(valueStr);
        if (value == -1)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::string closestDate = findClosestDate(date);
        double rate = _database[closestDate];
        double result = value * rate;
        
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
}