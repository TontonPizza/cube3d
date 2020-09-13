/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 02:35:23 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/12 02:35:23 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <pthread.h>
# include <time.h>
# include "keys.h"
# include <math.h>
# include <bsd/string.h>
# include <stddef.h>
# include "mlx.h"
# include "libft.h"
# include "mlx_int.h"
# include <fcntl.h>
# include "/usr/include/X11/Xlib.h"

# define HEADER_SIZE 54

# define MAP_SIZE 60
# define CELL 64
# define WALL_COEFF 150
# define TETA 40
# define OMEGA 80

# define SPEED 12
# define ANGULAR_SPEED 5
# define WALL_DIST 5
# define BOSS_SPEED 6

# define FRAME_COUNT 17
# define FRAME_COUNT_2 17
# define FRAME_COUNT_3 31
# define FRAME_COUNT_4 7
# define COOL_DOWN	800000
# define MOVE_COOLDOWN 2000
# define ROTATE_COOLDOWN 40000
# define SKY_W 1024
# define SKY_H 64
# define SHADOW_MODE 1
# define SHADOW_MAX_DIST 3500

# define VALID_CHAR "NSWE012"
# define VALID_B	"NSWE012345B6"

# define RAD  0.0174f

# define MAX_RES_X 1920
# define MAX_RES_Y 1020

# define SWORD_SPRITE '4'
# define TRIANGLE_SPRITE '3'
# define CRYSTAL_SPRITE '2'
# define FLOOR_SPRITE '0'
# define HP_MAX 10
# define HP_BOSS_MAX 8

# define GAME_STATE_INTRO 1
# define GAME_STATE_MAZE 2
# define GAME_STATE_DEATH 3
# define GAME_STATE_WIN 4

# define ROOM 1
# define BONUS_COUNT 3

# define SCREEN_DELTA 2000
# define SCREEN_1 "./textures/bonus/title_screen.xpm"
# define SCREEN_D "./textures/bonus/death_screen.xpm"
# define SCREEN_W "textures/bonus/win_screen.xpm"
# define SLAB "./textures/bonus/sprite/step0"

typedef struct	s_tuple
{
	int			x;
	int			y;
	int			hit;
	float		dist;
	float		teta;
	float		range;
	char		type;
}				t_tuple;

typedef struct	s_ray_data
{
	float		dist;
	int			hy;
	int			hx;
	float		t;
	int			txt;
	int			valid;
}				t_ray;

typedef struct	s_texture
{
	void		*img;
	char		*data;
	int			bpp;
	int			endian;
	int			size;
}				t_texture;

typedef struct	s_game
{
	void			*mlx;
	void			*window;
	void			*image;
	void			*data;
	int				screen_x;
	int				screen_y;
	char			*t_frame[256];
	char			*t_north;
	char			*t_south;
	char			*t_east;
	char			*t_west;
	char			*t_floor;
	char			*t_sprite;
	char			*t_sky;
	char			cs;
	t_texture		txt[14];
	t_texture		spr[256][60];
	int				frc[256];
	unsigned char	floor[4];
	unsigned char	ceiling[4];
	int				map_size_x;
	int				map_size_y;
	char			**map;
	int				p_x;
	int				p_y;
	int				p_t;
	int				p_tmax;
	int				p_tmin;
	int				p_h;
	int				ceil_color;
	int				floor_color;
	float			fr;
	float			frgun;
	int				bonus;
	clock_t			last_frame_time;
	clock_t			current_frame_time;
	double			delta_time;
	pthread_t		audio;
	int				boss_x;
	int				boss_y;
	int				boss_hp;
	int				player_hp;
	int				player_gun;
	clock_t			last_hit;
	short			is_shooting;
	clock_t			last_attack;
	char			game_state;
	int				bonus_count;
	clock_t			last_move;
	clock_t			last_rotate;
	clock_t			ending_screen;
	int				ef;
	int				move_forward;
	int				move_straffe;
	int				move_rotate;
	char			room;
	pthread_t		thread;
}				t_game;

void			destroy_game_data_full(t_game *g, int mode);
void			destroy_game_data(t_game *gd);
int				read_map(t_game *gd, char *m);
void			init_game(t_game *game, char *m);
int				error_message(char *message, t_game *g, int mode);
void			display_map(t_game *map);
int				map_validator(t_game *g);
int				map_validator_2(t_game *game, int mapsize);

void			set_boss_position(t_game *g, t_tuple *sxy);
void			render_sprites(t_game *g, float *dists);
void			render_sprites_2(t_game *g, float *ds, t_tuple *sxy, int index);
void			render_sprites_3(t_game *g, float *ds, t_tuple *sxy, int item);

int				raycast_x(t_game *gd, t_ray *r, int c, char object);
int				raycast_y(t_game *gd, t_ray *r, int c, char object);
int				render_scene(t_game *g);
int				render_scene_bonus(t_game *g);
void			render_bitmap(t_game *g);

void			floor_cast(t_game *gd, t_ray *r, t_tuple *t, int delta);
void			put_txt_to_img(t_game *g, t_tuple *img_xy, t_ray *ray);

int				controls(int keycode, void *params);
int				controls_bonus(int key, void *params);

int				move(t_game *g, int dir);
int				straffe(t_game *g, int dir);

void			write_bmp(char *file_name, t_game *g);
void			set_time_variables(t_game *g);
int				update_player(t_game *g);
void			load_frames_type(t_game *g, char type, int frame_count);

void			set_boss_prite_info(t_game *g, t_tuple *sxy);
void			move_boss(t_game *g);

void			check_damage(t_game *g);
void			render_gui(t_game *g);
void			grab_gun(t_game *g);
void			reset_attack(t_game *g);
void			knockback(t_game *g);
int				attack(t_game *g);
int				straffe(t_game *g, int dir);
int				move(t_game *g, int dir);
void			init_boss(t_game *g);
int				game_routine(t_game *g);
void			render_intro(t_game *g, int scene);
void			grab_bonus(t_game *g);
void			shadow(char *color, float dist, char *shade);

void			set_hooks(t_game *g);
int				smooth_move(t_game *g);
int				smooth_rotate(t_game *g);
void			set_hookers(t_game *g);
void			*play_sound(void *arg);
int				put_image_and_destroy(t_game *g);
void			play_sound_1(t_game *g, char *sound);
void			render_outro(t_game *g, int scene);

#endif
