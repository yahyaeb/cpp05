/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:14:24 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/08/31 15:27:08 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _gradetoSign(1), _gradetoExecute(1), _isSigned(false)

{
	std::cout << "Form constructor called." << std::endl;
}

Form::Form(const std::string& name, int gradetoSign, int gradetoExecute)
	: _name(name), _gradetoSign(gradetoSign), _gradetoExecute(gradetoExecute), _isSigned(false)
{}

Form::Form(const Form& other)
	: _name(other._name), _gradetoSign(other._gradetoSign), _gradetoExecute(other._gradetoExecute), _isSigned(other._isSigned)
{}
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradetoSign;
}

int	Form::getGradeToExecute() const
{
	return _gradetoExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= _gradetoSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << "Name: " << form.getName()
	<< " isSigned: " << form.getIsSigned()
	<< " SignGrade: " << form.getGradeToSign()
	<< " ExecuteGrade: " << form.getGradeToExecute()
	<< std::endl;

	return (os);
}