Intersecting 
--------

Intersectin with plane
----
How plane can be reapresented in R^3? Let's remind to our selfs what give us result of dot product of two vectors in geometry if they perpendicular.

A * B = 0

So our ray tracer is bunch of rays thrown from camera to an object. So if our ray
aimed to plane and plane orthogonal to our ray what it give us? Okay let's talk 
about how we can represent our plane. Plane can be defined as a point which
representing how far the plane is form our camera and a normal vector which 
defining the orientation of the plane.

Here will be a picture.

Let's call our point as lacation (p0) of an object and normal (n) vector as 
direction vector. We can find comput any vector of the plane by this subtracting:
							(p - p0) * n = 0;
(p) \[this is point of the vector which possible can intersect our plane\]
(p0) \[which is start position of our normal vector\] 
In simple words what we doing here. We taking point which intersect the plane
moving it to the point which is nativly orthogonal to our plane and reviewing 
is that point still orthogonal or not. 
 


