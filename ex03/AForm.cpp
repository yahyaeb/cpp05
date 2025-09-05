/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:14:24 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/05 13:21:03 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _gradetoSign(1), _gradetoExecute(1), _isSigned(false)

{
	// std::cout << "AForm constructor called." << std::endl;
}

AForm::AForm(const std::string& name, int gradetoSign, int gradetoExecute, const std::string& target)
    : _name(name),
	_gradetoSign(gradetoSign),
	_gradetoExecute(gradetoExecute),
	_isSigned(false),
	_target(target)
{}


AForm::AForm(const AForm& other)
	: _name(other._name),
	_gradetoSign(other._gradetoSign),
	_gradetoExecute(other._gradetoExecute),
	_isSigned(other._isSigned)
{}
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

const std::string& AForm::getTarget() const
{
    return _target;
}

AForm::~AForm()
{
	// std::cout << "AForm destructor called." << std::endl;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradetoSign;
}

int	AForm::getGradeToExecute() const
{
	return _gradetoExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if(_isSigned == true)
		return ;
	if (b.getGrade() <= _gradetoSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
	if(_isSigned == false)
		throw IsNotSignedException();
	if(_gradetoExecute < executor.getGrade())
		throw GradeTooLowException();

	performAction();
}

std::ostream &operator<<(std::ostream &os,  AForm const &Aform)
{
	os << "Name: " << Aform.getName()
	<< " Target: " << Aform.getTarget()
	<< " isSigned: " << Aform.getIsSigned()
	<< " SignGrade: " << Aform.getGradeToSign()
	<< " ExecuteGrade: " << Aform.getGradeToExecute()
	<< std::endl;


	return (os);
}