/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:02:11 by ylisyak           #+#    #+#             */
/*   Updated: 2019/02/19 19:28:35 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	RTV_H
#	define	RTV_H
#	include <libft.h>
#	include	<stdio.h>
#	include <math.h>
#	include <pthread.h>
# 	include "../libft/libft.h"
# 	include </usr/local/include/mlx.h>

#define CORE	 8
#define	SCREEN_W 1200
#define	SCREEN_H 780

typedef	struct
{
	double			a;
	double			b;
	double			c;
	double			discriminant;
}					square_equation;

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
	int				true_fals;
	double			t;
	vector_3		p;
	vector_3		n;
}					hit_record;

typedef struct		s_object
{
	char			*name;
	void			*inter_fun;
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
	double			t_max;
	double			t_min;
	vector_3		camera;
	vector_3		point;
}					t_ray;

typedef struct		s_canvas
{
	vector_3		origin;
	vector_3		vertical;
	vector_3		horizontal;
	vector_3		lower_left_corner;
}					t_canvas;

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;

}					t_color;

typedef struct		s_win
{
	//MLX
	int				endian;
	int				size;
	int				bps;
	void			*mlx;
	void			*win;
	void			*img;
	void			*img2;	
	//////////////////////
	t_objects		camera;
	t_objects		*objects;
	t_canvas		canvas;	
	
	int				iter_closer;
	int				statement;
	int				objects_amount;
	//Thread core part
	int				cores;
	int				coreh;
	
}					t_win;

typedef struct		s_thread
{
	int				dy;
	float			u;
	float			v;
	int				x;
	int				y;
	int				id;
	int				partiterstart;
	int				partiterend;
	t_win			window;
}					t_thread;


int				ft_parsing(t_win *window, char *input);
int				ft_count_objects(char *input);
int				ft_create_objects(t_win *window);
void			ft_core(t_win *window);

//MLX initialize connection with CPU and allocate window
int				ft_init_mlx(t_win *wind);
//initialize main_surface 
int					ft_init_sdl(t_win *window);
//Fill pixels of surface;
void				ft_pixel_put(int x, int y, size_t color, t_win *wind);
unsigned int		ft_rgb(int r, int g, int b);

//Vector lib function

double				ft_atoi_double(char *strnbr);
double              ft_length(vector_3 v);
double				ft_degree_to_radian(int input_degree);
double				ft_dot(vector_3 v1, vector_3 v2);

//Send ray
vector_3			trace_ray(t_ray ray, t_win *window);

//intersection functions
void				cylinder(t_ray ray, t_objects *object);
void				sphere(t_ray ray, t_objects *object);
void				plane(t_ray ray, t_objects *object);
void				cone(t_ray ray, t_objects *object);
//vector and rays lib
t_ray 				ft_setray(vector_3 camera, vector_3 point);
vector_3			ft_vector_normal(vector_3 v);
vector_3			ft_point_at_parameter(double t, vector_3 c, vector_3 p);
vector_3			ft_get_point(double t, vector_3 c, vector_3 p);
vector_3			ft_add_vectors(vector_3 v1, vector_3 v2);
vector_3            ft_multiply_scalar(vector_3 v1, double scalar);
vector_3            ft_subtract_vectors(vector_3 v1, vector_3 v2);
vector_3            ft_unit_vector(vector_3 v);
vector_3            ft_mag_dir_vector(int magnitude, int angle_xy, int angle_xz);
//Actions	


//Controller
void				ft_keyboard(t_win *window);
void				ft_keyevent_up(t_win *widnow);
void				ft_keyevent_down(t_win *window);

//Core
void				start(t_win *window);

void				ft_error_init_window(void);
void				ft_error_render_quality(void);
#endif
