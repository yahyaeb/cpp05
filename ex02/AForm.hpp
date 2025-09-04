/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:29:43 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/04 16:43:51 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

class AForm
{
	protected:
		const std::string   _name;
		const int           _gradetoSign;
		const int           _gradetoExecute;
		bool                _isSigned;
		const std::string   _target;
		virtual void performAction() const = 0;
	public:
		AForm();
		AForm(const std::string& name, int gradetoSign, int gradetoExecute, const std::string& target);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();
	
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade Too High";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade Too Low";
			}
	};
	class IsNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Form is not signed";
			}
	};

	// Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;

	// Business logic
	void beSigned(const Bureaucrat& b);
	void execute(const Bureaucrat& executor) const;
	
	friend std::ostream& operator<<(std::ostream& os, const AForm& form);
};

#endif