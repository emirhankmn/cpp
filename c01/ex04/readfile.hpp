/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 05:03:48 by eakman            #+#    #+#             */
/*   Updated: 2024/08/11 05:03:48 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READFILE_HPP
#define READFILE_HPP

#include <fstream>
#include <iostream>
#include <string>

class ReadFile
{
    private:
    public:
        void read_and_write_file(char **av);
        std::string replace(std::string line, const std::string& s1, const std::string& s2);
};

#endif