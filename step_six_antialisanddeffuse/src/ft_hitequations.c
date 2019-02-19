#include "../include/rtv.h"

void				sphere(t_ray ray, t_objects *object, hit_record *tmp_hit)
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
			tmp_hit->t = tmp;
			tmp_hit->p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			tmp_hit->n = ft_multiply_scalar(ft_subtract_vectors(tmp_hit->p, object->pos), (1 / object->radius));			
			tmp_hit->true_fals = 1;
			return ;
		}
		tmp = (-par.b + sqrt(par.discriminant))/(par.a);
		if (tmp < ray.t_max && tmp > ray.t_min)
		{
			tmp_hit->t = tmp;
			tmp_hit->p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			tmp_hit->n = ft_multiply_scalar(ft_subtract_vectors(tmp_hit->p, object->pos), (1 / object->radius));
			tmp_hit->true_fals = 1;
		}
	}
	else
		tmp_hit->true_fals = 0;
}

void				plane(t_ray ray, t_objects *object, hit_record *tmp_hit)
{
//	vector_3		plane;
//	vector_3		normal;
	square_equation par;

	par.a = 0;
	par.b = 0;
	par.c = 0;
	tmp_hit->t = -((ft_dot(ft_subtract_vectors(ray.camera, object->pos), object->dir))/(ft_dot(ray.point, object->dir)));
	tmp_hit->p = ft_point_at_parameter(tmp_hit->t, ray.camera, ray.point);
	if (tmp_hit->t >= 0)
		tmp_hit->true_fals = 1;
	else
		tmp_hit->true_fals = 0;	
}


void				cylinder(t_ray ray, t_objects *object, hit_record *tmp_hit)
{
	double			height; 
//	double			tmp;
//	double			tmpcov;
//	vector_3		axis;
	vector_3		tip;
//	vector_3 		oc;
//	vector_3		cp;
//	square_equation	par;

	tip.x = object->pos.x;
	tip.y = object->pos.y + 0.6;
	tip.z = object->pos.z;
	height = ft_length(ft_subtract_vectors(object->pos, tip));
	float A = ray.camera.x - object->pos.x;
    float B = ray.camera.z - object->pos.z;
 //   float D = height - ray.camera.y + object->pos.y;
    
    float a = (ray.point.x * ray.point.x) + (ray.point.z * ray.point.z);
    float b = (2*A*ray.point.x) + (2*B*ray.point.z);
    float c = (A*A) + (B*B) - 0.2;
    
    float delta = b*b - 4*(a*c);	
    if(delta < 0.0) 
	{
		tmp_hit->true_fals = 0;
		return;	
	}
    
    float t1 = (-b - sqrt(delta))/(2*a);
    float t2 = (-b + sqrt(delta))/(2*a);
    float t;
    
    if (t1>t2) t = t2;
    else t = t1;
    
    float r = ray.camera.y + t*ray.point.y;
    
    if ((r > object->pos.y) && (r < (object->pos.y + height)))
	{
		tmp_hit->t = t;
		tmp_hit->p = ft_point_at_parameter(tmp_hit->t, ray.camera, ray.point);
		tmp_hit->true_fals = 1;
		return ;
	}
	else
	{		
		tmp_hit->true_fals = 0;
		return ;
	}

}

void				cone(t_ray ray, t_objects *object, hit_record *tmp_hit)
{
	double			height; 
//	double			tmp;
//	double			tmpcov;
//	vector_3		axis;
	vector_3		tip;
//	vector_3 		oc;
//	vector_3		cp;
//	square_equation	par;

	tip.x = object->pos.x;
	tip.y = object->pos.y + 0.6;
	tip.z = object->pos.z;
	height = ft_length(ft_subtract_vectors(object->pos, tip));
	float A = ray.camera.x - object->pos.x;
    float B = ray.camera.z - object->pos.z;
    float D = height - ray.camera.y + object->pos.y;
    float tan = (0.2 / height) * (0.2 / height);
    
    float a = (ray.point.x * ray.point.x) + (ray.point.z * ray.point.z) - (tan*(ray.point.y * ray.point.y));
    float b = (2*A*ray.point.x) + (2*B*ray.point.z) + (2*tan*D*ray.point.y);
    float c = (A*A) + (B*B) - (tan*(D*D));
    
    float delta = b*b - 4*(a*c);
	if(fabs(delta) < 0.001)
	{
		tmp_hit->true_fals = 0;
		return;
	}	
    if(delta < 0.0)
	{
		tmp_hit->true_fals = 0;
		return;	
	}
    
    float t1 = (-b - sqrt(delta))/(2*a);
    float t2 = (-b + sqrt(delta))/(2*a);
    float t;
    
    if (t1>t2) t = t2;
    else t = t1;
    
    float r = ray.camera.y + t*ray.point.y;
    
    if ((r > object->pos.y) && (r < object->pos.y + height))
	{
		tmp_hit->t = t;
		tmp_hit->p = ft_point_at_parameter(tmp_hit->t, ray.camera, ray.point);
		tmp_hit->true_fals = 1;
		return ;
	}
    else
	{
		tmp_hit->true_fals = 0;
		return ;
	}



/*	oc = ft_subtract_vectors(ray.point, tip);   //dist
	axis = ft_subtract_vectors(object->pos, tip);
	tmpcov = ft_dot(oc, axis);
	tmp = pow(cos(0.95), 2);
	par.a = pow(ft_dot(ray.point, axis), 2) - tmp;
	par.b = 2.0 * (ft_dot(ray.point, axis) * tmpcov - ft_dot(ray.point, oc) * tmp);
	par.c = pow(tmpcov, 2) - ft_dot(oc, oc) * tmp; 
	par.discriminant = pow(par.b, 2) - par.a * par.c;
	if (par.discriminant > 0)
	{
		tmp = (-par.b - sqrt(par.discriminant)) / (2.0 * par.a);
		if (tmp < ray.t_max && tmp > ray.t_min)
		{
				cp = ft_subtract_vectors(ft_add_vectors(ray.point, (ft_multiply_scalar(ray.point, tmp))), tip);
				height = ft_dot(cp, axis);
				if (height < 0.)
				{
					object->hit.true_fals = 0;
					return ;
				}
				object->hit.t = tmp;
				object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
				object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), 1);
				object->hit.true_fals = 1;	
				return ;
		}
		tmp = (-par.b + sqrt(par.discriminant)) / (2.0 * par.a);
	    if (tmp < ray.t_max && tmp > ray.t_min)
		{
				cp = ft_subtract_vectors(ft_add_vectors(ray.camera, (ft_multiply_scalar(ray.point, tmp))), tip);
				height = ft_dot(cp, axis);
				if (height < 0.)
				{
					object->hit.true_fals = 0;
					return ;
				}
			object->hit.t = tmp;
			object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), 1);
			object->hit.true_fals = 1;
			return ;	
		}
	}
	else if (par.discriminant == 0)
	{
			tmp = -par.b / (2.0 * par.a);
			object->hit.t = tmp;
			object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), 1);
			object->hit.true_fals = 1;
			return ;	
	}
	else
		object->hit.true_fals = 0;
	*/
}


/*
	axis = ft_subtract_vectors(object->pos, tip);
	theta = ft_unit_vector(axis);
	m = pow(0.3, 2)/pow(ft_length(axis), 2);
	w = ft_subtract_vectors(ray.camera, tip);

	par.a = ft_dot(ray.point, ray.point) - m * (pow(ft_dot(ray.point, theta), 2)) - pow(ft_dot(ray.point, theta), 2);
	par.b = 2.0 * (ft_dot(ray.point, w) - m * ft_dot(ray.point, theta) * ft_dot(w, theta) - ft_dot(ray.point, theta) * ft_dot(w, theta));
	par.c = ft_dot(w, w) - m * pow(ft_dot(w, theta), 2) - pow(ft_dot(w, theta), 2);
	par.discriminant = pow(par.b, 2) - 4.0 * (par.a * par.b);
	if (par.discriminant > 0)
	{
		object->hit.t = (-par.b - sqrt(par.discriminant))/(2 * par.a);
		object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
		object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), (1 / object->radius));
		object->hit.true_fals = 1;
		return ;
	}
	else if (par.discriminant == 0)
	{
		object->hit.t = (-par.b)/(2 * par.a);
	
		object->hit.true_fals = 1;
	}
	else
		object->hit.true_fals = 0;
}
*/
/*std::array<glm::vec3,2> getLine2ConeIntersection(const glm::vec3 &ap_,const glm::vec3 &ad_ , const glm::vec3 &coneBaseCntr_,const glm::vec3 &coneVertex_,float coneRadius_) const
{
    glm::vec3 axis = (coneBaseCntr_-coneVertex_);
    glm::vec3 theta = (axis/glm::length(axis));
    float m = pow(coneRadius_,2)/pow(glm::length(axis),2);
    glm::vec3 w = (ap_-coneVertex_);

    float a = glm::dot(ad_,ad_) - m*(pow(glm::dot(ad_,theta),2)) - pow(glm::dot(ad_,theta),2);
    float b = 2.f*( glm::dot(ad_,w) - m*glm::dot(ad_,theta)*glm::dot(w,theta) - glm::dot(ad_,theta)*glm::dot(w,theta) );
    float c = glm::dot(w,w) - m*pow(glm::dot(w,theta),2) - pow(glm::dot(w,theta),2);

    float Discriminant = pow(b,2) - (4.f*a*c);

    if (Discriminant >= 0)
        return std::array<glm::vec3,2>{{
                                        (ap_+static_cast<float>(((-b) - sqrt(Discriminant))/(2.f*a))*ad_),
                                        (ap_+static_cast<float>(((-b) + sqrt(Discriminant))/(2.f*a))*ad_)
                                      }};

    return glm::vec3(0,0,0);
}i*/
/*	oc = ft_subtract_vectors(ray.camera, object->pos);   //dist
	tmpcov = ft_dot(oc, height);
 	tmp = (1.0 + cos(ft_degree_in_radian(2 * 50))) / 2.0;
	par.a = pow(ft_dot(ray.point, height), 2) - tmp;
	par.b = (ft_dot(ray.point, height) * tmpcov - ft_dot(ray.point, oc) * tmp);
	par.c = pow(tmpcov, 2) - ft_dot(oc, oc) * tmp; 
	par.discriminant = pow(par.b, 2) - par.a * par.c;
	if (par.discriminant > 0)
	{
		tmp = (-par.b - sqrt(par.discriminant)) / (par.a);
		if (tmp < ray.t_max && tmp > ray.t_min)
		{
			object->hit.t = tmp;
			object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), 1);
			object->hit.true_fals = 1;	
			return ;
		}
		tmp = (-par.b + sqrt(par.discriminant)) / (par.a);
	    if (tmp < ray.t_max && tmp > ray.t_min)
		{
			object->hit.t = tmp;
			object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), 1);
			object->hit.true_fals = 1;
			return ;	
		}
	}
	else if (par.discriminant == 0)
	{
			tmp = -par.b / 2 * par.a;
			object->hit.t = tmp;
			object->hit.p = ft_point_at_parameter(tmp, ray.camera, ray.point);
			object->hit.n = ft_multiply_scalar(ft_subtract_vectors(object->hit.p, object->pos), 1);
			object->hit.true_fals = 1;
			return ;	
	}
	else
		object->hit.true_fals = 0;
*/

