NAME = cube3D

LIBCUB = libcub.a

LIBFT = libft.a

DIR_LIBFT = ./libft/

DIR_MLX = ./minilibx/

INCL = ____includes

COMPILE = gcc

CFLAGS = -Wall -Wextra -Werror

MINI_OBS =  ./minilibx/mlx_clear_window.o \
            ./minilibx/mlx_destroy_image.o \
            ./minilibx/mlx_destroy_window.o  \
            ./minilibx/mlx_expose_hook.o  \
            ./minilibx/mlx_flush_event.o  \
            ./minilibx/mlx_get_color_value.o \
            ./minilibx/mlx_get_data_addr.o  \
            ./minilibx/mlx_hook.o \
            ./minilibx/mlx_init.o  \
            ./minilibx/mlx_int_anti_resize_win.o \
            ./minilibx/mlx_int_do_nothing.o  \
            ./minilibx/mlx_int_get_visual.o \
            ./minilibx/mlx_int_param_event.o \
            ./minilibx/mlx_int_set_win_event_mask.o \
            ./minilibx/mlx_int_str_to_wordtab.o \
            ./minilibx/mlx_int_wait_first_expose.o \
            ./minilibx/mlx_key_hook.o \
            ./minilibx/mlx_loop.o  \
            ./minilibx/mlx_loop_hook.o \
            ./minilibx/mlx_mouse_hook.o \
            ./minilibx/mlx_new_image.o \
            ./minilibx/mlx_new_window.o \
            ./minilibx/mlx_pixel_put.o \
            ./minilibx/mlx_put_image_to_window.o \
            ./minilibx/mlx_rgb.o \
            ./minilibx/mlx_string_put.o \
            ./minilibx/mlx_xpm.o \

SRC =		__resources/_game_setup/destroy_game_data.c \
			__resources/_game_setup/map_parsing.c \
			__resources/_game_setup/map_validation.c \
			__resources/_game_setup/player_initialization.c  \
			__resources/_game_setup/sprite_setup.c  \
			__resources/_messages/error_message.c \
			__resources/_game_setup/display_map.c \
			__resources/_raycast/raycast.c \
			__resources/_rendering/render.c \
			__resources/_rendering/render_menus.c \
			__resources/_rendering/render_sprites.c \
			__resources/_rendering/render_sprite_2.c \
			__resources/_rendering/render_bonus.c \
			__resources/_rendering/render_gui.c \
			__resources/_rendering/shadow.c \
			__resources/_movement/movement.c \
			__resources/_movement/movement2.c \
			__resources/_movement/attack.c \
			__resources/_movement/smooth_controls.c \
			__resources/_bitmap/bitmap.c \
			__resources/_time/time.c \
			__resources/_rendering/boss_management.c \
			__resources/_routine/routine.c \
			__resources/_routine/routine2.c \
			__resources/_sound/play_sound.c \



OBJ = $(SRC:.c=.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) __resources/main.c
		rm -rf $(NAME)
		make -C $(DIR_MLX)
		make -C $(DIR_LIBFT)
		cp $(DIR_LIBFT)$(LIBFT) ./$(LIBCUB)
		ar rc $(LIBCUB) $(OBJ)
		/bin/rm -f $(LIBFT)
		ranlib $(LIBCUB)
		$(COMPILE) -g3 -fsanitize=address -o $(NAME) __resources/main.c $(MINI_OBS) $(LIBCUB) -I$(INCL) -lm  -lXext -lX11 -lbsd

bonus : $(OBJ) __resources/main_bonus.c
		rm -rf $(NAME)
		make -C $(DIR_MLX)
		make -C $(DIR_LIBFT)
		cp $(DIR_LIBFT)$(LIBFT) ./$(LIBCUB)
		ar rc $(LIBCUB) $(OBJ)
		/bin/rm -f $(LIBFT)
		ranlib $(LIBCUB)
		$(COMPILE) -g3 -fsanitize=address -o $(NAME) __resources/main_bonus.c $(MINI_OBS) $(LIBCUB) -I$(INCL) -lm  -lXext -lX11 -lbsd

clean:
	rm -rf $(OBJ)
	rm -rf objects
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_MLX)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(LIBCUB)
	make fclean -C $(DIR_LIBFT)

re: fclean all

.PHONY: clean fclean all re cub3D

test :
		 make fclean && make bonus && make clean && clear
		./cube3D maps/map_bonus.cub