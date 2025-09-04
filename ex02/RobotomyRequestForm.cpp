/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:41 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/04 17:03:42 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm();
{
	
}
RobotomyRequestForm::RobotomyRequestForm(int _grade, int _exec)
{
	
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		_grade = other._grade;
	}
	return *this;	
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	
}