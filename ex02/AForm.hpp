/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:29:43 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/04 14:31:28 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_gradetoSign;
		const int			_gradetoExecute;
		bool				_isSigned;
		virtual void		performAction() const = 0;
	public:
		AForm();
		AForm(const std::string& name, int gradetoSign, int gradetoExecute);
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
	}

	const	std::string& getName() const;
	bool	getIsSigned() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;
	void	beSigned(const Bureaucrat &b);
	void	execute(const Bureaucrat &executor) const;
	
	
	friend std::ostream& operator<<(std::ostream& os, const Form& form);
};

#endif