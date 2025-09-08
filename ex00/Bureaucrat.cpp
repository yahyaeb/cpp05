/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:41:51 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/06 13:04:12 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << " Bureaucrat constructor called! " << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) , _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
	std::cout << "Name and grade constructor called." << std::endl;
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
	std::cout << "Bureaucrat destructor called! " << std::endl;
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

int main()
{
	try
	{
		Bureaucrat test("DS-160", 5);
		std::cout << "Current name is => " << test.getName() << "\n" << std::endl;
		std::cout << "current grade is => " << test.getGrade() << "\n"<< std::endl;
		std::cout << "then we increment twice => " << "\n"<< std::endl;
		test.incrementGrade();
		test.incrementGrade();
		std::cout << "Current name is => " << test.getName() << "\n" << std::endl;
		std::cout << "current grade is => " << test.getGrade() << "\n"<< std::endl;
		std::cout << "then we increment once => " << "\n"<< std::endl;
		test.incrementGrade();
		std::cout << "Current name is => " << test.getName() << "\n" << std::endl;
		std::cout << "current grade is => " << test.getGrade() << "\n"<< std::endl;
		std::cout << "then we increment once => " << "\n"<< std::endl;
		test.incrementGrade();
		std::cout << "Current name is => " << test.getName() << "\n" << std::endl;
		std::cout << "current grade is => " << test.getGrade() << "\n"<< std::endl;
		std::cout << "then we decrement once => " << "\n"<< std::endl;
		test.decrementGrade();
		std::cout << "Current name is => " << test.getName() << "\n" << std::endl;
		std::cout << "current grade is => " << test.getGrade() << "\n"<< std::endl;
		std::cout << "then we twice once => " << "\n"<< std::endl;
		test.incrementGrade();
		test.incrementGrade();
		std::cout << "Current name is => " << test.getName() << "\n" << std::endl;
		std::cout << "current grade is => " << test.getGrade() << "\n"<< std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
}