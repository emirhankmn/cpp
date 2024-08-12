/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:47:32 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 04:47:32 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readfile.hpp"
#include <iostream>
#include <fstream>
#include <string>

std::string ReadFile::replace(std::string line, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
    return line;
}

void read_and_write_file(char **av){
    ReadFile a;
    std::string filename(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);

    std::ifstream originalFile(filename);
    std::ofstream copyFile((filename + ".replace"));
    std::string line;

    if (!originalFile.is_open()) {
        std::cerr << "Unable to open original file" << std::endl;
        return;
    }

    if (!copyFile.is_open()) {
        std::cerr << "Unable to create or open replacement file" << std::endl;
        return;
    }

    while (getline(originalFile, line)) {
        copyFile << a.replace(line, s1, s2) << std::endl;
    }

    originalFile.close();
    copyFile.close();
}

int main(int ac, char **av){
    if(ac != 4){
        std::cout << "plase enter a FILENAME and two STRINGS thanks" << std::endl;
        return(0);
    }
    read_and_write_file(av);
}