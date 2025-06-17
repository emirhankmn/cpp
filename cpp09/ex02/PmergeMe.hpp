/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 03:53:41 by eakman            #+#    #+#             */
/*   Updated: 2025/06/17 03:53:41 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>

class PmergeMe
{
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    // Ford-Johnson algorithm for vector
    void mergeInsertSortVector(std::vector<int>& arr);
    void insertionSortVector(std::vector<int>& arr, int left, int right);
    void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    
    // Ford-Johnson algorithm for deque
    void mergeInsertSortDeque(std::deque<int>& arr);
    void insertionSortDeque(std::deque<int>& arr, int left, int right);
    void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
    
    bool isValidPositiveInteger(const std::string& str);
    void printContainer(const std::string& prefix, const std::vector<int>& container);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    bool parseInput(char **argv);
    void sortAndTime();
};

#endif