# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 04:53:24 by letnitan          #+#    #+#              #
#    Updated: 2022/12/30 10:08:16 by letnitan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

HEADER = ft_printf.h
CC = gcc

FLAGS = -Wall -Wextra -Werror 

SRCS = ft_printf.c ft_utils.c	\

# nommage automatique des fichiers objets d'apres les noms des sources C
OBJS = ${SRCS:.c=.o}

# ----------------

${NAME} : ${OBJS}
		ar rcs $@ $^
		@echo "ft_printf compiled!"
# it means : libftprint.a est cree a partir d'OBJS, et voila avec quelle commande : ar rc NAME OBJS. 
# The ar command combines one or more named files into a single archive file written in ar archive format.
#c : Create the archive. The specified archive is always created if it did not exist, when you request an update. But a warning is issued unless you specify in advance that you expect to create it, by using this modifier.
# r : Replace. Insert the files member... into archive (with replacement). This operation differs from q in that any previously existing members are deleted if their names match those being added.
# s : Sort. Write an object-file index into the archive, or update an existing one, even if no other change is made to the archive. You may use this modifier flag either with any operation, or alone. Running "ar s" on an archive is equivalent to running ranlib on it.

all: ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}
		
re : fclean all

%.o: %.c
	$(CC) ${FLAGS} -o $@ -c $<
# $@ : produit (ou but) de la r??gle
# $< : nom de la premi??re d??pendance (ou source)
#  Le but est d??fini par un pattern, ou un joker :  %.o . 
# Cette r??gle indique que chaque fichier .o n??cessaire ?? la cr??ation du projet est obtenu ?? partir 
# du fichier .c correspondant et que la commande $(CC) -o $@ -c $< permet de cr??er le fichier objet 
# ?? partir du fichier source. Les variables automatiques permettent de retrouver le 
# nom du fichier concern?? par la r??gle.

.PHONY : all clean fclean re