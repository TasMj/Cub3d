/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:12:24 by aclement          #+#    #+#             */
/*   Updated: 2023/10/05 14:48:16 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# define CONVERTS "diucspxX%"
# define BG "0123456789ABCDEF"
# define BP "0123456789abcdef"

typedef struct s_env_printf
{
	va_list	ap;
	char	*str;
	int		ret;
	int		i;
}				t_env_printf;

void	*ft_calloc(size_t nbelem, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

//printf

int		ft_printf(const char *str, ...);
void	ft_firstparse(t_env_printf *var);
void	ft_parsemodulo(t_env_printf *var);
void	ft_choose_conv(t_env_printf *var);
void	ft_putchar(char c);
int		ft_c_in_str(char *str, char c);
int		ft_strlen_printf(char *str);
void	ft_putstr(char *str);
int		ft_nblen(long int nb);
void	ft_mod_c(t_env_printf *var);
void	ft_mod_id(t_env_printf *var, int nb);
void	ft_mod_s(t_env_printf *var);
int		ft_unsigned_nblen(unsigned int nb);
void	ft_putnbr(int nb);
void	ft_unsigned_putnbr(unsigned int nb);
int		ft_convert_ui_in_hex(unsigned int nb, char *base);
void	ft_convert_ulli_in_hex(t_env_printf *var, unsigned long long int nb,
			char *base);
void	ft_mod_xx(t_env_printf *var, unsigned int nb);
void	ft_mod_u(t_env_printf *var, unsigned int nb);
void	ft_mod_p(t_env_printf *var, unsigned long long int nb);

#endif
