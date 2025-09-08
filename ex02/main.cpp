/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:44:20 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/06 15:26:04 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>


int main()
{
    // ShrubberyCreationForm test
    std::cout << "\n=== ShrubberyCreationForm Test ===\n";
    Bureaucrat gardener("Gardener", 130);
    ShrubberyCreationForm garden("home");
    std::cout << garden << std::endl;

    gardener.executeForm(garden); // Should fail: not signed yet
    gardener.signForm(garden);    // Should succeed
    gardener.executeForm(garden); // Should succeed

    // RobotomyRequestForm test
    std::cout << "\n=== RobotomyRequestForm Test ===\n";
    Bureaucrat robotTech("Tech", 45);
    RobotomyRequestForm robot("Bender");
    std::cout << robot << std::endl;

    robotTech.executeForm(robot); // Should fail: not signed yet
    robotTech.signForm(robot);    // Should succeed
    robotTech.executeForm(robot); // Should succeed (random result)
    robotTech.executeForm(robot); // Should succeed (random result)

    // PresidentialPardonForm test
    std::cout << "\n=== PresidentialPardonForm Test ===\n";
    Bureaucrat president("President", 1);
    PresidentialPardonForm pardon("Marvin");
    std::cout << pardon << std::endl;

    president.executeForm(pardon); // Should fail: not signed yet
    president.signForm(pardon);    // Should succeed
    president.executeForm(pardon); // Should succeed


    // Try with someone who can't sign/execute
    std::cout << "\n=== Too Low Grade Test ===\n";
    Bureaucrat intern("Intern", 150);
	ShrubberyCreationForm testo("testo");
	intern.signForm(garden);
    intern.signForm(testo);       // Should fail
    intern.executeForm(testo);    // Should fail

	std::ifstream infile((garden.getTarget() + "_shrubbery").c_str());
	if (infile) {
		std::cout << "\nFile '" << garden.getTarget() << "_shrubbery' was created. Contents:\n";
		std::cout << infile.rdbuf() << std::endl;
	} else {
		std::cout << "File was NOT created!" << std::endl;
	}



    return 0;
}