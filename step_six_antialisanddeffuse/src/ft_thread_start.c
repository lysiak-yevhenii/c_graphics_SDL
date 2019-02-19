#include "../include/rtv.h"

void			trace(t_thread *arg_th, int x, int y)
{
	t_ray 			ray;
	t_color			colors;
	float 			u;
	float			v;
	vector_3		color;

	u = (float)x / SCREEN_W;
	v = (float)y / SCREEN_H;
	ray = ft_setray(arg_th->window.camera.pos, \
	ft_add_vectors(ft_add_vectors(arg_th->window.canvas.lower_left_corner,\
	ft_multiply_scalar(arg_th->window.canvas.horizontal, u)),\
	ft_multiply_scalar(arg_th->window.canvas.vertical, v)));
	color = trace_ray(ray, &arg_th->window);
	colors.r = color.x * 255.99;
	colors.g = color.y * 255.99;
	colors.b = color.z * 255.99;
	ft_pixel_put(x, y, ft_rgb(colors.b, colors.g, colors.r), &arg_th->window);
}

void			*render(t_thread *arg_th)
{
	int			yn;
	int			ys;
	int			x;

	ys = arg_th->id * arg_th->window.coreh;
	yn = ys + arg_th->window.coreh;
	printf("Start %d, id%d\n", ys, arg_th->id);
	printf("END %d, id%d\n", yn, arg_th->id);
	while (ys < yn)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			trace(arg_th, x, ys);			
			x++;
		}	
		ys++;
	}
	pthread_exit(0);
}


void		start(t_win *wind)
{	
	pthread_t	pt[wind->cores];
	t_thread	arg[wind->cores];
	int			i;

	i = 0;
	while (i < wind->cores)
	{
		arg[i].id = i;
		arg[i].window = *wind;
		arg[i].img2 = wind->img2;
		pthread_create(&pt[i], NULL, \
				((void*(*)(void*))render), (void *)&(arg[i]));
		i++;
	}
	i = wind->cores - 1;
	while (i >= 0)
	{
		pthread_join(pt[i], NULL);
		i--;
	}
}

