Revil the sphere
--------
  Recall that the equation for a sphere centered at the origin of radius R is x^2 + y^2 + z^2 = R^2.
For any (x; y; z) on the sphere equation will as follows : x^2 + y^2 + z^2 = R^2; otherwise dot P is not on the sphere or inside the orb.
  Let's imagine that center of the sphere starts not from origin. So center of the sphere is somewhere (cx; cy; cz);
We need to change a little bit our equation form that occurrence in to the next equation: 
(x - cx)^2 + (y - cy)^2 + (z - cz) ^2 = R^2; (where R is radius).
  You might to admit that vector with center C(cx; cy; cz) to point on the sphere P(x; y; z) is ---> (P - C);
So we got the next: dot product of two vectors (radius) is:
                    dot((P - C), (P - C)) = (x - cx)^2 + (y - cy)^2 + (z - cz)^2;
  P.s. dot(v1, v2) mean dot product of two vectors;
  So the equation of the sphere in vector form is:
                    dot((P - C), (P - C)) = R^2;
   Any point of P that satisfies this equation is on the sphere. And here left to find out if our ray P(t) = A + t⚬B
  ever hits the sphere at any point. If ray hit the sphere, it's mean that there is exits some t for which P(t) 
  satisfies the sphere equation. 
                    dot((P(t) - C), (P(t) - C)) = R^2;
  Let's coloring pixels where going through our rays and which hit the sphere. So we place at -1 on z-axis somewhere an sphere. x and y (-1.0 and 0.5) ---> we relocate our sphere object to visible area for us.
  
                    Next steps are:
                    
                    1. Find out where is out sphere located?:
                    [vector.distance to our sphere] = [beginning of the ray (origin)] - [center location of the sphere];
                    2.[float A] = dot(ray direction, ray direcion);
                    3.[float B] = 2.0 * dot(vector.distance to our sphere);
                    4.[float C] = dot(vector.distance to our sphere, vector.distance to our sphere);
                    5.[float Discriminant] = B * B - 4 * A * C;
                    

Result
-----------
<img width="1199" alt="screen shot 2018-12-25 at 3 15 42 pm" src="https://user-images.githubusercontent.com/5114429/50422973-0f660800-0858-11e9-91fc-676f5d947b23.png">


