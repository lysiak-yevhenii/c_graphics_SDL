#include "../include/rtv.h"

void			trace(t_thread *arg_th)
{
	t_ray 			ray;
	t_color			colors;

	arg_th->u = (float)(arg_th->x / (float)SCREEN_W);	
	arg_th->v = (float)(arg_th->partiterstart / (float) SCREEN_H);
	ray = ft_setray(arg_th->window.camera.pos, \
	ft_add_vectors(ft_add_vectors(arg_th->window.canvas.lower_left_corner,\
	ft_multiply_scalar(arg_th->window.canvas.horizontal, arg_th->u)),\
	ft_multiply_scalar(arg_th->window.canvas.vertical, arg_th->v)));
	vector_3 color = trace_ray(ray, &arg_th->window);
	color.x = 100;
	color.y = 200;
	color.z = 10;
	colors.r = color.x * 255.99;
	colors.g = color.y * 255.99;
	colors.b = color.z * 255.99;
	ft_pixel_put(arg_th->x, arg_th->partiterstart, ft_rgb(colors.b, colors.g, colors.r), &arg_th->window);
}

void			*render(void *arg)
{
	t_thread	*arg_th;
	
	arg_th = (t_thread*)arg;
	arg_th->partiterstart = arg_th->id * arg_th->window.coreh;
	arg_th->partiterend = arg_th->partiterstart + arg_th->window.coreh;
	while (arg_th->partiterstart < arg_th->partiterend)
	{
		arg_th->x = 0;
		while (arg_th->x <= SCREEN_W)
		{
			trace(arg_th);			
			arg_th->x++;
		}	
		arg_th->partiterstart++;
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
		pthread_create(&pt[i], NULL, \
				render, (void *)&(arg[i]));
		i++;
	}
	i = wind->cores - 1;
	while (i >= 0)
	{
		pthread_join(pt[i], NULL);
		i--;
	}
}

