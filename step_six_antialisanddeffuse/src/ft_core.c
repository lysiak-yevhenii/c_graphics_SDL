/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:18:18 by ylisyak           #+#    #+#             */
/*   Updated: 2019/02/19 22:21:24 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv.h"

int			ft_iter(t_ray *ray, t_objects *obj, int (*f)(t_ray, t_objects *))
{
	return ((*f)(*ray, obj));
}

int			ft_closer_obj(t_ray ray, t_win *window)
{
	hit_record	tmp_rec;
	int			obj_iter;
	double		hit;
	double		t_max;
	(void)t_max;
	(void)tmp_rec;	
	hit = 0;
	ray.t_max = 100.0;
	ray.t_min = 0.0;
	obj_iter = 0;	
	while (obj_iter < window->objects_amount - 1)
	{
		ft_iter(&ray, &window->objects[obj_iter], window->objects[obj_iter].inter_fun);
		obj_iter++;
	}
	while (obj_iter--)
	{
		if (window->objects[obj_iter].hit.t < ray.t_max && window->objects[obj_iter].hit.true_fals == 1)
		{
			ray.t_max = window->objects[obj_iter].hit.t;
			window->iter_closer = obj_iter;
			hit = 1;
		}
	}	
	return (hit);
}	

vector_3		ft_random_unit()
{
	vector_3	p;
	vector_3	tmp;
	vector_3	unit;

	p.x = 0;
	p.y = 0;
	p.z = 0;
	unit.x = 1;
	unit.y = 1;
	unit.z = 1;
	while (pow(ft_length(p), 2) > 1.0)
	{
		tmp.x = drand48();
		tmp.y = drand48();
		tmp.z = drand48();
		p =	ft_subtract_vectors(ft_multiply_scalar(tmp,  2.0), unit);
	}
	return p;
}

vector_3		trace_ray(t_ray ray, t_win	*window)
{
	//vector_3 n;
	//return (n);
	double		t;

	vector_3	point;
	vector_3	set;

	vector_3 	unit_direction;
	vector_3 	to_return;
	vector_3 	n;
	vector_3	loc;
	(void)n;
	(void)loc;
	set.x = 1.0;
	set.y = 1.0;
	set.z = 1.0;
	point.x = 0.5;
	point.y = 0.7;
	point.z = 1.0;
	if (ft_closer_obj(ray, window))
	{
		t = window->objects[window->iter_closer].hit.t;
		n = ft_unit_vector(ft_subtract_vectors(ft_point_at_parameter(t, ray.camera, ray.point), window->objects[window->iter_closer].pos));
		to_return.x = n.x + 1;
		to_return.y = n.y + 1;
		to_return.z = n.z + 1;
		n = ft_multiply_scalar(to_return, 0.5);
		return (n);
	}
	t = ray.t_max;
	unit_direction = ft_unit_vector(ray.point);
	t = 0.5 * (ray.point.y + 1.0);
	return (ft_add_vectors(ft_multiply_scalar(set, (1.0 - t)), ft_multiply_scalar(point, t)));
}


void			init_canvas(t_win *window)
{
	window->canvas.lower_left_corner.x = -1.0;
    window->canvas.lower_left_corner.y = -0.5;
   	window->canvas.lower_left_corner.z = -0.5;
	window->canvas.vertical.x = 0.0;
	window->canvas.vertical.y = 1.0;      
	window->canvas.vertical.z = 0.0;
	window->canvas.horizontal.x = 2.0;
	window->canvas.horizontal.y = 0.0;
	window->canvas.horizontal.z = 0.0;
}

void			ft_core(t_win *window)
{
	window->cores = CORES;
	window->coreh = (int)(SCREEN_H / window->cores);
	window->statement = 1;
	init_canvas(window);
	start(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);	
	mlx_loop(window->mlx);
}
