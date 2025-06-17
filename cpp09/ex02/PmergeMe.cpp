/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 03:54:10 by eakman            #+#    #+#             */
/*   Updated: 2025/06/17 03:54:10 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidPositiveInteger(const std::string& str)
{
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    
    long num = atol(str.c_str());
    return num > 0 && num <= 2147483647;
}

bool PmergeMe::parseInput(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        if (!isValidPositiveInteger(argv[i]))
            return false;
        
        int num = atoi(argv[i]);
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
    return true;
}

void PmergeMe::printContainer(const std::string& prefix, const std::vector<int>& container)
{
    std::cout << prefix;
    for (size_t i = 0; i < container.size() && i < 5; i++)
    {
        std::cout << container[i];
        if (i < 4 && i < container.size() - 1)
            std::cout << " ";
    }
    if (container.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;
    
    // Use insertion sort for small arrays
    if (n <= 10)
    {
        insertionSortVector(arr, 0, n - 1);
        return;
    }
    
    // Ford-Johnson merge-insert algorithm
    int mid = n / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    
    mergeInsertSortVector(left);
    mergeInsertSortVector(right);
    
    // Copy back to original array
    for (size_t i = 0; i < left.size(); i++)
        arr[i] = left[i];
    for (size_t i = 0; i < right.size(); i++)
        arr[mid + i] = right[i];
    
    mergeVector(arr, 0, mid - 1, n - 1);
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right)
{
    std::deque<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::deque<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    size_t i = 0, j = 0;
    int k = left;
    
    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    
    while (i < leftArr.size())
        arr[k++] = leftArr[i++];
    while (j < rightArr.size())
        arr[k++] = rightArr[j++];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;
    
    // Use insertion sort for small arrays
    if (n <= 10)
    {
        insertionSortDeque(arr, 0, n - 1);
        return;
    }
    
    // Ford-Johnson merge-insert algorithm
    int mid = n / 2;
    std::deque<int> left(arr.begin(), arr.begin() + mid);
    std::deque<int> right(arr.begin() + mid, arr.end());
    
    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);
    
    // Copy back to original array
    for (size_t i = 0; i < left.size(); i++)
        arr[i] = left[i];
    for (size_t i = 0; i < right.size(); i++)
        arr[mid + i] = right[i];
    
    mergeDeque(arr, 0, mid - 1, n - 1);
}

void PmergeMe::sortAndTime()
{
    std::vector<int> vectorCopy = _vectorData;
    std::deque<int> dequeCopy = _dequeData;
    
    printContainer("Before: ", _vectorData);
    
    // Time vector sorting
    clock_t start = clock();
    mergeInsertSortVector(vectorCopy);
    clock_t end = clock();
    double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    printContainer("After: ", vectorCopy);
    
    // Time deque sorting
    start = clock();
    mergeInsertSortDeque(dequeCopy);
    end = clock();
    double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}