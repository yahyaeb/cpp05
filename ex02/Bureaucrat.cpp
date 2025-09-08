/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:41:51 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/06 12:52:30 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	// std::cout << " Bureaucrat constructor called! " << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) , _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
	// std::cout << "Name and grade constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat destructor called! " << std::endl;
}

void	Bureaucrat::incrementGrade(void)
{
	if(_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if(_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const std::string& Bureaucrat::getName(void) const
{
	return _name;
}
int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{	
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
					<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const
{
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

