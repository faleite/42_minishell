/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:08:35 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/08 17:42:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h> /* printf */
# include <unistd.h> /* write */
# include <sys/types.h> /* pid_t */
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h> /* getenv */
# include <limits.h>
# include <linux/limits.h>
# include <signal.h> /* */
# include <sys/ioctl.h> /* */
# include <fcntl.h> /* open */
# include <stdbool.h>
# include <sys/wait.h>

/* MINISHELL */
# include "types.h"
# include "parser.h"
# include "executor.h"

#endif // MINISHELL_H
