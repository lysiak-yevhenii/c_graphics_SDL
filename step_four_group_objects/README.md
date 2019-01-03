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

<img width="1199" alt="screen shot 2018-12-25 at 3 15 42 pm" src="https://github.com//Jenuaz/c_graphics_SDL/blob/master/support/Screen%20Shot%202018-12-27%20at%206.jpg?raw=true">

Here you going to payattantion to new file called ft_hitequations.c. Especially on sphere() function. It was simplefied a little bit in calculation but become much harder in definition. So this function now calculate back side of our sphere and record all information needed in future to calculate shine and other stuff. We create new secton (structure) in our object called hit. Also our ray now have length, which defined inside struct of the ray (t_max and t_min). Why do we need those ? t_max indicate the closest t. So we compate t_max which variation related to closest founded point. t_max neasted in ray struct also in object struct (hit variable). 

<img width="1199" alt="screen shot 2018-12-25 at 3 15 42 pm" src="https://raw.githubusercontent.com/Jenuaz/c_graphics_SDL/master/support/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202019-01-03%20%D0%B2%2019.38.39.png">
