/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:00:18 by eakman            #+#    #+#             */
/*   Updated: 2024/06/11 23:00:18 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class   Contact{
    private:
    std::string First_Name;
    std::string Surname;
    std::string Nickname;
    std::string Phone_Number;
    std::string Darkest_Secret;
    
    public:
    void set_first_name(std::string);
    void set_surname(std::string);
    void set_nickname(std::string);
    void set_phone_number(std::string);
    void set_darkest_secret(std::string);

    std::string get_first_name(void);
    std::string get_surname(void);
    std::string get_nickname(void);
    std::string get_phone_number(void);
    std::string get_darkest_secret(void);
};

class   PhoneBook{
    private:
    
    public:
    Contact contacts[8];
    int index;
    int fixed;

    void ADD(void);
    void SEARCH(void);
    void EXIT(void);

    std::string getstring(void);
};

#endif