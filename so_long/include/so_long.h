/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:55:06 by jde-orma          #+#    #+#             */
/*   Updated: 2023/07/29 06:55:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/include/libft.h"

typedef struct Mapa{
	int		error;
	char	*line;
	size_t	longitud_linea;
	int		numero_de_lineas;
	int		numero_movimientos;
	int		collective;
	int		exit;
	int		start;
} Mapa;

int		dbl_free_ptr(Mapa *mapa1, char **ptr);
int		ft_strrepeatchr(char *s, char c, int len);
int		ft_str_illegal_chr(char *s, Mapa *mapa1, int i);
int		first_line_error_check(char *line, Mapa *mapa1, int error);
int		last_line_error_check(char	*line, Mapa *mapa1, int error);
int		middle_line_error_check(char *line, Mapa *mapa1);
int		error_check(char *line, Mapa *mapa1, int i);
void	is_valid_map(char *s, char *extension);
