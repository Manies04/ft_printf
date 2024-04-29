/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:39:51 by tiade-al          #+#    #+#             */
/*   Updated: 2024/04/28 23:39:32 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "Libft/libft.h"

int		ft_printchar(int c, long int *len);
void	ft_printstr(char *str, long int *len);
void	ft_printnum(long int num, long int *len);
void	ft_print_unsigned_dec(unsigned int num, long int *len);
void	ft_print_hex(unsigned int num, int is_upper, long int *len);
void	ft_printptr(unsigned long int ptr, long int *len);

#endif