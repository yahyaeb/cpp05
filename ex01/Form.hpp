/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:29:43 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/06 13:34:02 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _gradetoSign;
		const int _gradetoExecute;
		bool _isSigned;
	public:
		Form();
		Form(const std::string& name, int gradetoSign, int gradetoExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
	
	
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
	class AlreadySigned : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Form already is signed";
			}	
	};
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int	getGradeToExecute() const;
	
	void beSigned(const Bureaucrat &b);
	
	
	friend std::ostream& operator<<(std::ostream& os, const Form& form);
};

#endif