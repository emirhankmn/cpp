/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:21:51 by eakman            #+#    #+#             */
/*   Updated: 2024/06/11 22:21:51 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <limits>
#include <iostream>

void Contact::set_first_name(std::string first_name) {this->First_Name = first_name;}
void Contact::set_surname(std::string surname) {this->Surname = surname;}
void Contact::set_nickname(std::string nickname) {this->Nickname = nickname;}
void Contact::set_phone_number(std::string phone_number) {this->Phone_Number = phone_number;}
void Contact::set_darkest_secret(std::string darkest_secret) {this->Darkest_Secret = darkest_secret;}

std::string Contact::get_first_name(void) {return this->First_Name;}
std::string Contact::get_surname(void) {return this->Surname;}
std::string Contact::get_nickname(void) {return this->Nickname;}
std::string Contact::get_phone_number(void) {return this->Phone_Number;}
std::string Contact::get_darkest_secret(void) {return this->Darkest_Secret;}

bool is_not_empty(const std::string& str) {
    return str.find_first_not_of(" \t\n\r\f\v") != std::string::npos;
}

void PhoneBook::ADD(void) {
    std::cout << "Adding a new contact..." << std::endl;
    if(index < 8) {
        std::cout << "Enter first name: ";
        std::string first_name = getstring();
        std::cout << "Enter surname: ";
        std::string surname = getstring();
        std::cout << "Enter nickname: ";
        std::string nickname = getstring();
        std::cout << "Enter phone number: ";
        std::string phone_number = getstring();
        std::cout << "Enter darkest secret: ";
        std::string darkest_secret = getstring();

        if(!is_not_empty(first_name) || !is_not_empty(surname) ||
           !is_not_empty(nickname) || !is_not_empty(phone_number) ||
           !is_not_empty(darkest_secret)) {
            std::cout << "Contact not added! because of empty field" << std::endl;
            return;
        }

        contacts[index].set_first_name(first_name);
        contacts[index].set_surname(surname);
        contacts[index].set_nickname(nickname);
        contacts[index].set_phone_number(phone_number);
        contacts[index].set_darkest_secret(darkest_secret);

        index++;
        if(fixed <= 7)
            fixed++;
        if (index == 8)
            index = 0;
    }
    std::cout << "Contact added!" << std::endl;
}

std::string setspace(std::string str) {
    if (str.length() > 10) {
        str.resize(9);
        str += ".";
    }
    else {
        while (str.length() < 10)
            str = " " + str;
    }
    return str;
}

void PhoneBook::SEARCH(void) {
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << " ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯" << std::endl;
    for (int i =0; i < fixed; i++) {
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|         " << i << "|" << setspace(contacts[i].get_first_name()) << "|" << setspace(contacts[i].get_surname()) << "|" << setspace(contacts[i].get_nickname()) << "|" << std::endl;
    std::cout << " ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯" << std::endl;
    }
    std::cout << "Enter index: ";
    int i; 
    std::cin >> i;
    if (std::cin.fail() || i < 0 || i >= fixed)
        std::cout << "Invalid index" << std::endl;
    else {
        std::cout << "First name: " << contacts[i].get_first_name() << std::endl;
        std::cout << "Surname: " << contacts[i].get_surname() << std::endl;
        std::cout << "Nickname: " << contacts[i].get_nickname() << std::endl;
        std::cout << "Phone number: " << contacts[i].get_phone_number() << std::endl;
        std::cout << "Darkest secret: " << contacts[i].get_darkest_secret() << std::endl;
    }
}

void PhoneBook::EXIT(void) {
    std::cout << "Exiting..." << std::endl;
}

std::string PhoneBook::getstring(void) {
    std::string str;
    std::cin.clear(); // std::cin durumunu temizler
    fflush(stdin); // Giriş akışındaki kalan karakterleri temizler
    std::getline(std::cin, str); // std::cin'den bir satır okur ve str'ye atar
    return str; // str'yi döndürür
}

int main(void) {
    PhoneBook phonebook;
    phonebook.index = 0;
    phonebook.fixed = 0;
    std::cout << "Welcome to the phonebook ;)" << std::endl;
    std::cout << "Enter a command (ADD, SEARCH, EXIT)"<< std::endl;
    while (1)
    {
        std::string command = phonebook.getstring();
        if (command == "ADD")
            phonebook.ADD();
        else if (command == "SEARCH")
            phonebook.SEARCH();
        else if (command == "EXIT")
        {
            phonebook.EXIT();
            break;
        }
    }
    return 0;
}