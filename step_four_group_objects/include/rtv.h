/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:02:11 by ylisyak           #+#    #+#             */
/*   Updated: 2018/12/27 20:45:55 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	RTV_H
#	define	RTV_H
#	include <libft.h>
#	include	<stdio.h>
#	include <math.h>
#	include "SDL.h"
#	include "SDL_image.h"
#	include "SDL_timer.h"
#	include "SDL_ttf.h"
#	include "SDL_mixer.h"

#define	SCREEN_W 1200
#define	SCREEN_H 780

typedef struct
{
	double			x;
	double			y;
	double			z;
	uint32_t		color;
}					vector_3;

typedef struct
{
	double			x;
	double			y;
	double			d;
}					vector_2;

typedef struct
{
	double			t;
	vector_3		p;
	vector_3		n;
}					hit_record;

typedef struct		s_object
{
	char			*name;
	vector_3		pos; //object location 
	vector_3		dir; //for camera and plane
	double			radius;
	int				reflaction;
	int				angle; // in degree
	unsigned int	color;	

	hit_record		hit;
}					t_objects;

typedef struct		s_ray
{
	vector_3		camera;
	vector_3		point;
}					t_ray;

typedef struct		s_win
{
	SDL_Window		*window;
	SDL_Surface		*main_surface;
	SDL_Surface		*operate_surface;
	t_objects		*objects;
	uint32_t		*operate_pix;
}					t_win;

int				ft_parsing(t_win *window, char *input);
int				ft_count_objects(char *input);
int				ft_create_objects(t_win *window, int mount);
void			ft_core(t_win *window);

//SDL initialize connection with CPU and allocate window
//initialize main_surface 
int					ft_init_sdl(t_win *window);
//SDL fill pixels of surface;
void				ft_draw_bpx(int x, int y, size_t color, SDL_Surface *img);
unsigned int		ft_rgb(int r, int g, int b);

//Vector lib function

double				ft_atoi_double(char *strnbr);
double              ft_length(vector_3 v);
double				ft_degree_to_radian(int input_degree);
double				ft_dot(vector_3 v1, vector_3 v2);
vector_3			ft_point_at_parameter(double t, vector_3 c, vector_3 p);
vector_3			ft_get_point(double t, vector_3 c, vector_3 p);
vector_3			ft_add_vectors(vector_3 v1, vector_3 v2);
vector_3            ft_multiply_scalar(vector_3 v1, double scalar);
vector_3            ft_subtract_vectors(vector_3 v1, vector_3 v2);
vector_3            ft_unit_vector(vector_3 v);
vector_3            ft_mag_dir_vector(int magnitude, int angle_xy, int angle_xz);


void				ft_error_init_window(void);
void				ft_error_render_quality(void);
#endif
