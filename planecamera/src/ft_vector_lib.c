#include "../include/rtv.h"

// R3 vectors

double				ft_degree_to_radian(int input_degree)
{
	int		radian;

	radian = input_degree * M_PI / 180;
	return (radian);
}

vector_3			ft_add_vectors(vector_3 v1, vector_3 v2)
{
	vector_3	result_vector;

	result_vector.x = v1.x + v2.x;
	result_vector.y = v1.y + v2.y;
	result_vector.z = v1.z + v2.z;
	return (result_vector);
}

vector_3			ft_multiply_scalar(vector_3 v1, double scalar)
{
	vector_3	result_vector;

	result_vector.x = v1.x * scalar;
	result_vector.y = v1.y * scalar;
	result_vector.z = v1.z * scalar;
	return (result_vector);
}

vector_3			ft_subtract_vectors(vector_3 v1, vector_3 v2)
{
	vector_3	result_vector;

	result_vector.x = v1.x - v2.x;
	result_vector.y = v1.y - v2.y;
	result_vector.z = v1.z - v2.z;
	return (result_vector);
}

vector_3			ft_unit_vector(vector_3 v)
{
	vector_3	unit_vector;

	unit_vector.x = (v.x / (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2))));
	unit_vector.y = (v.y / (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2))));
	unit_vector.z = (v.z / (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2))));	
	return (unit_vector);
}

//if we have only 2 angles between axes in R3 different dimentions
// and we have length of vector ||v|| it's magnitude. We can find 
// what unit coordinats that vector have.
vector_3			ft_mag_dir_vector(int magnitude, int angle_xy, int	angle_xz)
{
	vector_3	result_vector;

	result_vector.y = magnitude * sin(ft_degree_to_radian(angle_xy));
	result_vector.x = (magnitude * cos(ft_degree_to_radian(angle_xy))) * cos(ft_degree_to_radian(angle_xz));
	result_vector.z = (magnitude * cos(ft_degree_to_radian(angle_xy))) * sin(ft_degree_to_radian(angle_xz));
	return (result_vector);
}

double				ft_length(vector_3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}



