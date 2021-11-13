#include "operation.h"

void init()
{
	//设置双缓冲，RGB像素格式的窗口
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//设置窗口大小
    glutInitWindowSize(1200, 1200);
	glutInitWindowPosition(20, 20);
	//创建窗口
    int window = glutCreateWindow("Ray Tracer");
    
}
//----- The procedural texturing function -------------------
//    Used for procedural generation of a texture on a sphere
//      x, y, and r are parameters of the sphere itself
//       col1, col2 and col3 are the colours to be used
//-------------------------------------------------------------

glm::vec3 proceduralTexture(Ray ray, float x, float y, float r, glm::vec3 col1, glm::vec3 col2, glm::vec3 col3)
{
	glm::vec3 col;
	if(ray.xpt.x < (x-r+(r/4)) || (ray.xpt.x >= (x-r+(3*r/4)) && ray.xpt.x < (x+r-(3*r/4))) || ray.xpt.x >= (x+r-(r/4))){
		if(ray.xpt.y < (y-r+(r/4)) || (ray.xpt.y >= (y-r+(3*r/4)) && ray.xpt.y < (y+r-(3*r/4))) || ray.xpt.y >= (y+r-(r/4))){
			return col1;
		} else {
			return col2;
		}
	} else {
		if(ray.xpt.y < (y-r+(r/4)) || (ray.xpt.y >= (y-r+(3*r/4)) && ray.xpt.y < (y+r-(3*r/4))) || ray.xpt.y >= (y+r-(r/4))){
			return col3;
		} else {
			return col1;
		}
	}
}


//---The ray tracing function ------------------------------------------------------
//   Computes the colour value obtained by tracing a ray and finding its           |
//     closest point of intersection with objects in the scene.                    |
//----------------------------------------------------------------------------------
glm::vec3 trace(Ray ray,int step)
{
	glm::vec3 backgroundCol(0);   //Colour fo the background
	glm::vec3 light(10, 40, -3);  //Lights Position
	float ambientTerm = 0.2;

	ray.closestPt(sceneObjects);		//Compute the closest point of intersetion of objects with the ray

	if(ray.xindex == -1) return backgroundCol;      //If there is no intersection return background colour

	glm::vec3 col = sceneObjects[ray.xindex]->getColor();//else return object's colour

	glm::vec3 normalVector = sceneObjects[ray.xindex]->normal(ray.xpt);   //calculating normal vector of intersection
	glm::vec3 lightVector = light - ray.xpt;   //calculating the light vector
	glm::vec3 lightNormal = glm::normalize(lightVector);   //normalizing
	float lDotn = glm::dot(lightNormal, normalVector);       //Gets the normal vector for light

	glm::vec3 reflVector = glm::reflect(-lightVector, normalVector);
	glm::vec3 reflNormal = glm::normalize(reflVector);    //calculated reflected vector then normalized
	float spec = glm::dot(reflNormal, -ray.dir);         //specular reflection

	//calculates the specular component of the position that the ray has intersected
	if(spec < 0)
	{
		spec = 0;
	}else if(ray.xindex == 1){
		spec = glm::pow(spec, 40.0);
	}else{
		spec = glm::pow(spec, 7.0);
	}

	//calulates the shadow
	Ray shadow(ray.xpt, lightNormal);
	shadow.closestPt(sceneObjects);    //creation of a shadow ray and closest intersect

	float d = glm::distance(ray.xpt, light); 	//distance between object and light source

	glm::vec3 colorSum;	//initiating colorSum

	if(ray.xindex == 0 && step < MAX_STEPS){	//creating the reflective sphere创建反射球体
		glm::vec3 reflectedDir = glm::reflect(ray.dir, normalVector);
		Ray reflectedRay(ray.xpt, reflectedDir);

		glm::vec3 reflectedCol=trace(reflectedRay, step + 1);// //Recursion!递归

		colorSum = colorSum + (0.8f * reflectedCol);
	}else if(ray.xindex == 1 && step<MAX_STEPS){ //creating the refractive, transparent sphere//创建折射的透明球体
		float eta = 1 / 1.005;
		glm::vec3 g = glm::refract(ray.dir, normalVector, eta);
		Ray refrRay1(ray.xpt, g);
		refrRay1.closestPt(sceneObjects);
		glm::vec3 m = sceneObjects[refrRay1.xindex]->normal(refrRay1.xpt);
		glm::vec3 h = glm::refract(g, -m, 1.0f / eta);
		Ray refrRay2(refrRay1.xpt, h);

		glm::vec3 refractedCol = trace(refrRay2, step);//Recursion!

		colorSum = colorSum + (0.8f * refractedCol);
	} else if (ray.xindex == 2){	//procedural generation of colours on 'red' sphere//在“红色”球体上生成颜色
		glm::vec3 col1(1, 0, 0);
		glm::vec3 col2(0, 1, 0);
		glm::vec3 col3(0, 0, 1);
		//col1 appears the most in the texture while col2 and col3 appear the least
		col = proceduralTexture(ray, 8, 0, 4, col1, col2, col3);//x, y and r from sphere
	} else if(ray.xindex == 4){//Texturing the floor plane
		float texcoordx = (ray.xpt.x + 20) / (20 - -20);
		float texcoordz = (ray.xpt.z + 0) / (-200);
		col = texture.getColorAt(texcoordx, texcoordz);
	}

	//determining if the object is in shadow or not and returning a colour value accordingly
	////确定对象是否在阴影中，并返回相应的颜色值
	if((lDotn <=0)||((shadow.xindex > -1) && (shadow.xdist < d))){
		if(shadow.xindex == 1){
			return (col * 0.67f + colorSum);
		} else {
			return (col * ambientTerm + colorSum);
		}
	} else {
		return (ambientTerm * col + lDotn * col + spec + colorSum);
	}
}

//---The main display module -----------------------------------------------------------
// 主要的显示模型
// In a ray tracing application, it just displays the ray traced image by drawing
// 在光线追踪应用程序中，它只是通过绘图来显示光线追踪的图像
// each cell as a quad.
// 每个单元格作为一个四边形。
//---------------------------------------------------------------------------------------

void display()
{
	//grid point
	float xp, yp;
	float cellX = (XMAX-XMIN)/NUMDIV;  //cell width
	float cellY = (YMAX-YMIN)/NUMDIV;  //cell height

	//The eye position (source of primary rays) is the origin
	glm::vec3 eye(0., 0., 0.);

	glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	//Each cell is a quad.
	glBegin(GL_QUADS);

	//For each grid point xp, yp
	for (int i = 0; i < NUMDIV;++i)
	{
		xp = XMIN + i * cellX;
		for (int j = 0; j < NUMDIV;++j)
		{
			yp = YMIN + j * cellY;

			//divided each square pixel into four to perform supersampling
			//将每个正方形像素分成4个进行超采样
			glm::vec3 uleft(xp+0.25*cellX, yp+0.75*cellY, -EDIST);	//direction of the primary ray
		    glm::vec3 uright(xp+0.75*cellX, yp+0.75*cellY, -EDIST);
		    glm::vec3 lleft(xp+0.25*cellX, yp+0.25*cellY, -EDIST);
		    glm::vec3 lright(xp+0.75*cellX, yp+0.25*cellY, -EDIST);

			//Create a ray originating from the camera in the direction 'dir'
			Ray ray1 = Ray(eye, uleft);
			ray1.normalize();
			Ray ray2 = Ray(eye, uright);
			ray2.normalize();
			Ray ray3 = Ray(eye, lleft);
			ray3.normalize();
			Ray ray4 = Ray(eye, lright);
			ray4.normalize();

			glm::vec3 col1 = trace (ray1, 1); //Trace the primary ray and get the colour value
		    glm::vec3 col2 = trace (ray2, 1);
		    glm::vec3 col3 = trace (ray3, 1);
		    glm::vec3 col4 = trace (ray4, 1);

			glm::vec3 col;    //finding tthe average colour of the four rays in the pixel
		    col.r = (col1.r + col2.r + col3.r + col4.r) / 4;
		    col.g = (col1.g + col2.g + col3.g + col4.g) / 4;
		    col.b = (col1.b + col2.b + col3.b + col4.b) / 4;

			glColor3f(col.r, col.g, col.b);
			glVertex2f(xp, yp);				//Draw each cell with its color value
			glVertex2f(xp+cellX, yp);
			glVertex2f(xp+cellX, yp+cellY);
			glVertex2f(xp, yp+cellY);


		}
	}

	glEnd();
    glFlush();
}




//------ This sphere creation function ------------
//    Creates instances of the sphere class to
//		be displayed in the scene
//--------------------------------------------------
void createSpheres()
{
	//-- Creating pointers to sphere objects
	Sphere *sphere1 = new Sphere(glm::vec3(-5.0, -1.0, -110.0), 20.0, glm::vec3(0, 0, 1));   //Blue Reflecting sphere
	Sphere *sphere2 = new Sphere(glm::vec3(-3, -11, -70.0), 5.0, glm::vec3(1, 0.6, 0));    //Refracted Sphere
	Sphere *sphere3 = new Sphere(glm::vec3(8.0, 0.0, -85.0), 4.0, glm::vec3(1, 0, 0));      //Textured Sphere
	Sphere *sphere4 = new Sphere(glm::vec3(-12.5, -12.5, -82.5), 4.0, glm::vec3(0, 1, 0));    //Green Sphere
	
	//--Add the above to the list of scene objects.
	sceneObjects.push_back(sphere1); 
	sceneObjects.push_back(sphere2); 
	sceneObjects.push_back(sphere3);
	sceneObjects.push_back(sphere4);  
}

//------ The floor creation function ------------
//    creates a large instance of the plane class
//		to be used in the scene as a 'floor'
//------------------------------------------------
void createFloor()
{
	//-- Create a pointer to a plane object
	Plane *plane = new Plane (glm::vec3(-20., -20, -40),     //Point A
								glm::vec3(20., -20, -40),    //Point B
								glm::vec3(20., -20, -200),   //Point C
								glm::vec3(-20., -20, -200),  //Point D
								glm::vec3(1, 1, 0));     //Colour
	
	//--Add the above to the list of scene objects.							
	sceneObjects.push_back(plane);
}

//------- The box creation function ------------
//    creates 6 instances of the plane class
//		which form a box in the scene
//--------------------------------------------
void createBox()
{
	//-- Create a pointer to 6 plane objects
	Plane *bottom = new Plane (glm::vec3(6, -15, -80),     //Point A
								glm::vec3(4, -15, -84),    //Point B
								glm::vec3(9, -15, -84),   //Point C
								glm::vec3(11, -15, -80),  //Point D
								glm::vec3(0.8, 0, 0.8));     //Colour
								
	Plane *top = new Plane (glm::vec3(6, -10, -80),     //Point A
								glm::vec3(11, -10, -80),    //Point B
								glm::vec3(9, -10, -84),   //Point C
								glm::vec3(4, -10, -84),  //Point D
								glm::vec3(0.8, 0, 0.8));     //Colour							
	
	Plane *front = new Plane (glm::vec3(6, -10, -80),     //Point A
								glm::vec3(6, -15, -80),    //Point B
								glm::vec3(11, -15, -80),   //Point C
								glm::vec3(11, -10, -80),  //Point D
								glm::vec3(0.8, 0, 0.8));     //Colour						
	
	Plane *right = new Plane (glm::vec3(11, -10, -80),     //Point A
								glm::vec3(11, -15, -80),    //Point B
								glm::vec3(9, -15, -84),   //Point C
								glm::vec3(9, -10, -84),  //Point D
								glm::vec3(0.8, 0, 0.8));     //Colour
								
	Plane *back = new Plane (glm::vec3(9, -10, -84),     //Point A
								glm::vec3(9, -15, -84),    //Point B
								glm::vec3(4, -15, -84),   //Point C
								glm::vec3(4, -10, -84),  //Point D
								glm::vec3(0.8, 0, 0.8));     //Colour										
	
	Plane *left = new Plane (glm::vec3(4, -10, -84),     //Point A
								glm::vec3(4, -15, -84),    //Point B
								glm::vec3(6, -15, -80),   //Point C
								glm::vec3(6, -10, -80),  //Point D
								glm::vec3(0.8, 0, 0.8));     //Colour							
	
	
	//--Add the above to the list of scene objects.							
	sceneObjects.push_back(bottom);
	sceneObjects.push_back(top);
	sceneObjects.push_back(front);
	sceneObjects.push_back(right);
	sceneObjects.push_back(back);
	sceneObjects.push_back(left);
}







//---This function initializes the scene ------------------------------------------- 
//   Specifically, it creates scene objects (spheres, planes, cones, cylinders etc)
//     and add them to the list of scene objects.
//   It also initializes the OpenGL orthographc projection matrix for drawing the
//     the ray traced image.
//----------------------------------------------------------------------------------
//---该函数初始化场景 ------------------------------------------- 
//   具体来说，它创建场景对象(球体，平面，圆锥，圆柱体等)
//     并将它们添加到场景对象列表中。
//   它也初始化OpenGL的正投影矩阵来绘制
//     射线跟踪图像。
//----------------------------------------------------------------------------------
void initialize()
{
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(XMIN, XMAX, YMIN, YMAX);
    glClearColor(0, 0, 0, 1);

	//create the spheres 创建一个球体
	createSpheres();
	//create the plane that is the floor 创建地板（平面）
	createFloor();
	//create a box using 6 instances of the plane object
	createBox();

	char text[] = "./src/Squares.bmp";
	//texture file to be used
	char *s = text;
	texture = TextureBMP(s);
}
