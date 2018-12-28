#include "../include/rtv.h"

double				sphere(t_ray ray, t_objects *object)
{
	vector_3		oc;
	square_equation	par;	

	par.a = 0;
	par.b = 0;
	par.c = 0;
	par.discriminant = 0;	
	oc = ft_subtract_vectors(ray.camera, object->pos);
	par.a = ft_dot(ray.point, ray.point);
	par.b = 2.0 * ft_dot(oc, ray.point);
	par.c = ft_dot(oc, oc) - pow(object->radius, 2);
	par.discriminant = pow(par.b, 2) - 4 * par.a * par.c;
    if (par.discriminant < 0)
		return (-1.0);
	else
		return ((-par.b - sqrt(par.discriminant))/(2.0 * par.a));
}

