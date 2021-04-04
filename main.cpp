
#include <iostream>
#include "Shape.h"
#include "Ellipse.h"
#include "Star.h"
#include "ShapeImplementations.h"
#include "GLDrawer.h"

static GLDrawer* drawer;

void display()
{
    drawer->drawShapes();
}

int main(int argc, char** argv)
{
    GLDrawer glDrawer(argc, argv);
    drawer = &glDrawer;
    
    Ellipse* ellipse = new Ellipse({ 0.1f, 0.08f });
    ellipse->setСenter({ 0.1f, 0.2f });
    ellipse->setColor({ 1.f,0.f,0.f });
    Rectangle* rect = new Rectangle(0.2f);
    rect->setСenter({ -0.1f, -0.2f });
    rect->setColor({ 0.f,1.f,0.f });
    Star* star = new Star(0.1f, 5);
    star->setСenter({ -0.3f, -0.4f });
    star->setColor({ 0.f,0.f,1.f });
    Diamond* diam = new Diamond({ 0.1f, 0.2f });
    diam->setСenter({ -0.5f, 0.4f });
    diam->setColor({ 0.f,1.f,1.f });

    glDrawer.addShapeData(ellipse);
    glDrawer.addShapeData(rect);
    glDrawer.addShapeData(star);
    glDrawer.addShapeData(diam);

    //Инициализация GLUT
    glutInitWindowSize(500, 500);   
    glutCreateWindow("Shapes Output Test"); 
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display); 
    glutMainLoop();           
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);        

    return 0;
}

