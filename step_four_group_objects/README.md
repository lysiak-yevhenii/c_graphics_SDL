Intersecting at scene with bunch of Objects
--------


To implement new bunch of objects we need to know which exactly object we intersected. 
So when we intersect a ray with the scene we must find only closest intersected object
point relativly the camera along the ray. Main idea that we going to review all objects
for intersection. If we intersect all of them or few of them we need to compare that 
objects to find closest intersection (smallest t value); When we got that smallest value
we can draw the pixel on the screen in right color (color of object).
	
	Pseudo code: (interval t in (t0, t1))
	hit = 0;
	for each OBJECT int the GROUP do
		if (OBJECT hited by ray at ray parameter t and t in interval[t0, t1]) then
			hit = 1;
			objecthited = OBJECT;
			t1 = t;					// here we find distance to hited object;
	return hit;


Idea the next: our structure has all information about objects. We can store information about distance
from camera to the object and compare those between group of objects. Then we need to return needed hit infomation which nested (location of intersaction - P, normal vector - N, t - value). This hit info must have lowest t value.
Once the nearest to the camera object is found, a shading computation uses the intersection P, N, T and other information to determine the color of the pixel. 

 
