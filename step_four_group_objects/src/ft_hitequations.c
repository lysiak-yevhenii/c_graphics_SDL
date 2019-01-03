#include "../include/rtv.h"

void				sphere(t_ray ray, t_objects *object)
{
	float			tmp;
	vector_3		oc;
	square_equation	par;	

	par.a = 0;
	par.b = 0;
	par.c = 0;
	par.discriminant = 0;	
	oc = ft_subtract_vectors(ray.camera, object->pos);
	par.a = ft_dot(ray.point, ray.point);
	par.b = ft_dot(oc, ray.point);
	par.c = ft_dot(oc, oc) - pow(object->radius, 2);
	par.discriminant = pow(par.b, 2) - par.a * par.c;
   	if (par.discriminant > 0)
	{
		tmp = (-par.b - sqrt(par.discriminant))/(par.a);
		if (tmp < ray.t_max && tmp > ray.t_min)
		{
			object->hit.t = tmp;
			object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), (1 / object->radius));			
			object->hit.true_fals = 1;
			return ;
		}
		tmp = (-par.b + sqrt(par.discriminant))/(par.a);
		if (tmp < ray.t_max && tmp > ray.t_min)
		{
			object->hit.t = tmp;
			object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), (1 / object->radius));
			object->hit.true_fals = 1;
		}
	}
	else
		object->hit.true_fals = 0;
}

void				plane(t_ray ray, t_objects *object)
{
	double			t;
	vector_3		plane;
	vector_3		normal;
	square_equation par;

	par.a = 0;
	par.b = 0;
	par.c = 0;
	normal.x = 0.0;
	normal.y = 1.5;
	normal.z = 10.0;
	object->hit.t = -((ft_dot(ft_subtract_vectors(ray.camera, object->pos), normal))/(ft_dot(ray.point, normal)));
	object->hit.p = ft_point_at_parameter(object->hit.t, ray.camera, ray.point);
	object->hit.true_fals = 1;	
}

