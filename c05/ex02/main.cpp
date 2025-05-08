/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:49:30 by eakman            #+#    #+#             */
/*   Updated: 2025/05/08 23:49:30 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(0)); // Rastgelelik için seed

    std::cout << "=== ShrubberyCreationForm Test ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 100); // grade 100
        ShrubberyCreationForm shrub("garden");

        std::cout << shrub << std::endl;

        // Deneme: imzalamadan execute etmeye çalışalım (hata vermeli)
        alice.executeForm(shrub);

        // İmzala
        alice.signForm(shrub);
        std::cout << shrub << std::endl;

        // Yeterli grade yok: Alice'in execute grade'i 137'den düşük mü? (100 yeterli)
        alice.executeForm(shrub);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== RobotomyRequestForm Test ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 45); // grade 45
        RobotomyRequestForm robot("Bender");

        std::cout << robot << std::endl;

        // İmzala
        bob.signForm(robot);
        std::cout << robot << std::endl;

        // Execute (Bob'un grade'i tam execute grade'i 45 ➔ yeterli)
        // Birkaç kez deneyelim ki random sonuçları görelim
        for (int i = 0; i < 3; ++i) {
            bob.executeForm(robot);
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== PresidentialPardonForm Test ===" << std::endl;
    try {
        Bureaucrat carol("Carol", 5); // grade 5
        PresidentialPardonForm pardon("Marvin");

        std::cout << pardon << std::endl;

        // İmzala
        carol.signForm(pardon);
        std::cout << pardon << std::endl;

        // Execute (Carol'un grade'i tam execute grade'i 5 ➔ yeterli)
        carol.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Failure Cases Test ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 140);
        ShrubberyCreationForm shrub("backyard");

        std::cout << shrub << std::endl;

        // Dave'in imzalama derecesi yetiyor mu? Shrubbery için 145 gerek, Dave 140 ➔ yeterli.
        dave.signForm(shrub);

        // Ama execute için 137 gerek, Dave 140 ➔ YETERSİZ!
        dave.executeForm(shrub);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== High-Level Bureaucrat Test ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("T-800");
        PresidentialPardonForm pardon("Neo");

        boss.signForm(robot);
        boss.signForm(pardon);

        boss.executeForm(robot);
        boss.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    

    return 0;
}
