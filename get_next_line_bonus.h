/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai <fmai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:55:45 by fmai              #+#    #+#             */
/*   Updated: 2020/12/21 01:48:33 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

int			make_line(char **save, int fd, char **line, int index);
int			make_save(char **save, int fd, int index);
int			handle_save(char **save, int fd, char **line);
int			get_next_line(int fd, char **line);
void		free_all(char *buf, char *save);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *src);
char		*ft_strnjoin(char *s1, char const *s2, int n);
int			newline_index(char *str);
#endif
