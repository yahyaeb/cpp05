/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:44:20 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/04 17:26:23 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // std::srand(std::time(0)); // Seed randomness for robotomy

    Bureaucrat alice("Alice", 1);         // Highest rank
    Bureaucrat bob("Bob", 70);            // Middle rank
    Bureaucrat charlie("Charlie", 150);   // Lowest rank

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("R2D2");
    PresidentialPardonForm pardon("Arthur Dent");

    // Try signing and executing forms with different bureaucrats
    std::cout << "\n--- ShrubberyCreationForm ---\n";
    charlie.signForm(shrubbery);   // Too low to sign (should fail)
    bob.signForm(shrubbery);       // Can sign (should succeed)
    bob.executeForm(shrubbery);    // Too low to execute (should fail)
    alice.executeForm(shrubbery);  // Should succeed, writes file

    std::cout << "\n--- RobotomyRequestForm ---\n";
    charlie.signForm(robotomy);    // Too low to sign
    bob.signForm(robotomy);        // Can sign (should succeed)
    bob.executeForm(robotomy);     // Can execute (should succeed, random result)
    alice.executeForm(robotomy);   // Also can execute

    std::cout << "\n--- PresidentialPardonForm ---\n";
    bob.signForm(pardon);          // Too low to sign
    alice.signForm(pardon);        // Should succeed
    bob.executeForm(pardon);       // Too low to execute
    alice.executeForm(pardon);     // Should succeed

    // Test: executing unsigned form
    ShrubberyCreationForm unsignedShrub("garden");
    alice.executeForm(unsignedShrub); // Should throw not signed

    // Test: polymorphism
    std::cout << "\n--- Polymorphism Test ---\n";
    AForm* forms[3] = { &shrubbery, &robotomy, &pardon };
    for (int i = 0; i < 3; ++i) {
        alice.executeForm(*forms[i]);
    }

    return 0;
}
