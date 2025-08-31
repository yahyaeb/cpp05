/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:41:54 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/08/30 17:22:22 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	
	const	std::string& getName(void) const;
	int		getGrade(void) const;
	void	incrementGrade(void);
	void	decrementGrade(void);

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
	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& x);
};

class Form : public std::exception
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradetoSign;
		const int _gradetoExecute;
	public:
		Form();
		Form(const std::string& name, int gradetoSign, int gradetoExecute, bool isSigned);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
	
	
		
}