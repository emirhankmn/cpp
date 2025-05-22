/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:06:04 by eakman            #+#    #+#             */
/*   Updated: 2025/05/09 01:06:04 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::srand(std::time(0));  // Rastgelelik için seed

    std::cout << "=== INTERN TESTS ===" << std::endl;

    Intern intern;
    Bureaucrat boss("Boss", 1); // Her şeyi yapabilecek en güçlü bürokrat

    // Test 1: ShrubberyCreationForm üretme
    AForm* form1 = intern.makeForm("shrubbery creation", "MyGarden");
    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;  // Heap'te oluşturulduğu için delete etmeliyiz
    }

    std::cout << "\n----------------------------------------\n";

    // Test 2: RobotomyRequestForm üretme
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    std::cout << "\n----------------------------------------\n";

    // Test 3: PresidentialPardonForm üretme
    AForm* form3 = intern.makeForm("presidential pardon", "Marvin");
    if (form3) {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    std::cout << "\n----------------------------------------\n";

    // Test 4: Geçersiz form ismi ile deneme
    AForm* form4 = intern.makeForm("ultra mega form", "TestTarget");
    if (!form4) {
        std::cout << "As expected, the form type was invalid and no form was created." << std::endl;
    }

    std::cout << "\n----------------------------------------\n";

    // Test 5: Birden fazla kez form üretmek ve farklı bürokratlarla denemek
    Bureaucrat midLevel("MidLevel", 70);  // Orta seviyede bir bürokrat
    Bureaucrat lowLevel("LowLevel", 150); // En düşük seviyede bir bürokrat

    AForm* form5 = intern.makeForm("robotomy request", "Wall-E");
    if (form5) {
        midLevel.signForm(*form5);
        midLevel.executeForm(*form5); // Bakalım yeterli mi?

        std::cout << "\nLowLevel bürokrat deniyor:\n";
        lowLevel.signForm(*form5);    // Zaten imzalandı mı, deniyor
        lowLevel.executeForm(*form5); // Yetersiz execute denemesi

        delete form5;
    }

    std::cout << "\n=== INTERN TESTS COMPLETE ===" << std::endl;

    return 0;
}
