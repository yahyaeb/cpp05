/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:44:20 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/06 15:37:14 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "\n=== Intern and makeForm() TESTS ===\n" << std::endl;

    Bureaucrat shrubGuy("Shrubber", 130);
    Bureaucrat roboGuy("Roboteer", 45);
    Bureaucrat presGuy("President", 1);

    Intern someRandomIntern;
    AForm *form;

    // 1. Try to make an unknown form
    std::cout << "[Test] Unknown form type:" << std::endl;
    form = someRandomIntern.makeForm("unknown form", "Nobody");
    if (!form)
        std::cout << "Returned NULL as expected for unknown form.\n" << std::endl;
    else
        delete form;

    // 2. ShrubberyCreationForm
    std::cout << "[Test] ShrubberyCreationForm:" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "forest");
    if (form)
    {
        std::cout << *form << std::endl;
        shrubGuy.signForm(*form);
        shrubGuy.executeForm(*form);
        delete form;
    }

    // 3. RobotomyRequestForm
    std::cout << "[Test] RobotomyRequestForm:" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << *form << std::endl;
        roboGuy.signForm(*form);
        roboGuy.executeForm(*form);
        delete form;
    }

    // 4. PresidentialPardonForm
    std::cout << "[Test] PresidentialPardonForm:" << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (form)
    {
        std::cout << *form << std::endl;
        presGuy.signForm(*form);
        presGuy.executeForm(*form);
        delete form;
    }

    std::cout << "\n=== End of tests ===\n" << std::endl;
    return 0;
}
