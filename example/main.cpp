#include <iostream>
#include "host.h"
#include "scenes.h"
#include "render/render.h"
#include "objects/GameObject.hpp"
#include "FreeCam.hpp"

class Cube : public GameObject {
private:

public:
  Cube()
  {

  }

  void update()
  {
      glBegin(GL_QUADS);		// Рисуем куб

    	glColor3f(0.0f, 1.0f, 0.0f);		// Синяя сторона (Верхняя)
    	glVertex3f( 1.0f, 1.0f, -1.0f);		// Верхний правый угол квадрата
    	glVertex3f(-1.0f, 1.0f, -1.0f);		// Верхний левый
    	glVertex3f(-1.0f, 1.0f,  1.0f);		// Нижний левый
    	glVertex3f( 1.0f, 1.0f,  1.0f);		// Нижний правый

    	glColor3f(1.0f, 0.5f, 0.0f);		// Оранжевая сторона (Нижняя)
    	glVertex3f( 1.0f, -1.0f,  1.0f);	// Верхний правый угол квадрата
    	glVertex3f(-1.0f, -1.0f,  1.0f);	// Верхний левый
    	glVertex3f(-1.0f, -1.0f, -1.0f);	// Нижний левый
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Нижний правый

    	glColor3f(1.0f, 0.0f, 0.0f);		// Красная сторона (Передняя)
    	glVertex3f( 1.0f,  1.0f, 1.0f);		// Верхний правый угол квадрата
    	glVertex3f(-1.0f,  1.0f, 1.0f);		// Верхний левый
    	glVertex3f(-1.0f, -1.0f, 1.0f);		// Нижний левый
    	glVertex3f( 1.0f, -1.0f, 1.0f);		// Нижний правый

    	glColor3f(1.0f,1.0f,0.0f);			// Желтая сторона (Задняя)
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Верхний правый угол квадрата
    	glVertex3f(-1.0f, -1.0f, -1.0f);	// Верхний левый
    	glVertex3f(-1.0f,  1.0f, -1.0f);	// Нижний левый
    	glVertex3f( 1.0f,  1.0f, -1.0f);	// Нижний правый

    	glColor3f(0.0f,0.0f,1.0f);			// Синяя сторона (Левая)
    	glVertex3f(-1.0f,  1.0f,  1.0f);	// Верхний правый угол квадрата
    	glVertex3f(-1.0f,  1.0f, -1.0f);	// Верхний левый
    	glVertex3f(-1.0f, -1.0f, -1.0f);	// Нижний левый
    	glVertex3f(-1.0f, -1.0f,  1.0f);	// Нижний правый

    	glColor3f(1.0f,0.0f,1.0f);			// Фиолетовая сторона (Правая)
    	glVertex3f( 1.0f,  1.0f, -1.0f);	// Верхний правый угол квадрата
    	glVertex3f( 1.0f,  1.0f,  1.0f);	// Верхний левый
    	glVertex3f( 1.0f, -1.0f,  1.0f);	// Нижний левый
    	glVertex3f( 1.0f, -1.0f, -1.0f);	// Нижний правый

    	glEnd();	// Закончили квадраты
  }
};

class MyGame : public Scene {
private:
  Cube *cube;
  FreeCam *cc;
public:
  MyGame()
  {
    render::cam = new Camera();
    cc = new FreeCam();
    render::cam->parent = cc;
    cube = new Cube();
  }

   void update()
  {
    cc->update();
    cube->update();
  }
};

int main()
{
    initEngine();
    startEngine();
    loadScene(new MyGame());
    while(frame()) {
      postFrame();
    }
    return 0;
}
