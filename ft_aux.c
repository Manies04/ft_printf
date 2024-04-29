/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:01:13 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/29 02:29:26 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*@brief Prints a character to standard output.
*@param c The character to print.
*@param len: A pointer that will be used to keep track of the total length of 
*the printed output.
*@return length of the printed output.
 */
int	ft_printchar(int c, long int *len)
{
	write(1, &c, 1);
	(*len)++;
}
/*@brief Prints a string to standard output.
*@param str The string to print.
*@param len: A pointer that will be used to keep track of the total length of 
*the printed output.
*@return None.
*/
void	ft_printstr(char *str, long int *len)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_printchar(*str, len);
		str++;
	}
}

/* @brief Prints a number to standard output.
*@param num: The number to be printed.
*@param len: A pointer that will be used to keep track of the total length of 
*the printed output.
*@return None.
 */
void	ft_printnum(long int num, long int *len)
{
	if (num < 0)
	{
		ft_printchar('-', len);
		num = -num;
	}
	if (num > 9)
		ft_printnum(num / 10, len);
	ft_printchar(num % 10 + '0', len);
}
/* @brief Prints an unsigned decimal number.
*@param num: The number to be printed.
*@param len: A pointer that will be used to keep track of the total length of 
*the printed output.
*@return None.
 */
void	ft_print_unsigned_dec(unsigned int num, long int *len)
{
	if (num < 0)
		return ;
	if (num > 9)
		ft_print_unsigned_dec(num / 10, len);
	ft_printchar(num % 10 + '0', len);
}
/* @brief Prints an hexadecimal number.
*@param num: The number to be printed.
*@param is_upper: 0 for lowercase, 1 for uppercase.
*@param len: A pointer that will be used to keep track of the total length of 
*the printed output.
*@return None.
 */
void	ft_print_hex(unsigned int num, int is_upper, long int *len)
{
	char	*exchar;
	
	if (is_upper)
		exchar = "0123456789ABCDEF";
	else
		exchar = "0123456789abcdef";
	if (num >= 16)
		ft_print_hex(num / 16, is_upper, len);
	ft_printchar(exchar[num % 16], len);
}
/* @brief This function prints a hexadecimal representation of a memory address(ptr).
*@param ptr: The pointer to be printed.
*@param len: A pointer that will be used to keep track of the total length of 
*the printed output.
*@return None.
 */
void	ft_printptr(unsigned long int ptr, long int *len)
{
	char	*exchar;

	if(!ptr)
	{
		ft_printstr("(nil)", len);
		return ;
	}
	exchar = "0123456789abcdef";
	if (ptr < 16)
	{
		ft_printstr("0x", len);
		ft_printchar(exchar[ptr % 16], len);
	}
	ft_printptr(ptr / 16, len);
	ft_printchar(exchar[ptr % 16], len);
}
