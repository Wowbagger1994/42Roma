/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminfo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:59:26 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:27:45 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINFO_H
# define TERMINFO_H

int			control_init_struct(t_control *control);
void		control_free_struct(t_control *control);

t_list		*input_root(t_control *control);

int			input_read_line(t_term *term);

int			termios_enable_raw_mode(t_control *control, struct termios *old);
int			termios_reset_cooked_mode(t_control *control, struct termios *cpy);

void		read_root(t_control *control);

#endif
