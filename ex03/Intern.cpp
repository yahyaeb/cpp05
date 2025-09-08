/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:44:30 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/06 15:38:16 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	// std::cout << "default constructor called." << std::endl;
}
Intern::Intern(const Intern& other)
{
	(void) other;
}
Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return *this;
}
Intern::~Intern()
{
	// std::cout << "destructor called." << std::endl;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	int i = 0;
	std::string available_forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 3 && formName != available_forms[i])
		i++;
	
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm (target));
		default:
			std::cout << "Form is not existing" << std::endl;
			return NULL;
	}
}