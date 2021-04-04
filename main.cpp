// Shapes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include "Shape.h"
#include "ShapeImplementations.h"
#include "GLDrawer.h"

static GLDrawer* drawer;

void display()
{
    drawer->drawShapes();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{
    GLDrawer glDrawer(argc, argv);
    drawer = &glDrawer;
    
    Ellipse* ellipse = new Ellipse({ 0.1f, 0.08f });
    ellipse->set„Renter({ 0.1f, 0.2f });
    ellipse->setColor({ 1.f,0.f,0.f });
    Rectangle* rect = new Rectangle(0.2f);
    rect->set„Renter({ -0.1f, -0.2f });
    rect->setColor({ 0.f,1.f,0.f });
    Star* star = new Star(0.1f, 5);
    star->set„Renter({ -0.3f, -0.4f });
    star->setColor({ 0.f,0.f,1.f });
    Diamond* diam = new Diamond({ 0.1f, 0.2f });
    diam->set„Renter({ -0.5f, 0.4f });
    diam->setColor({ 0.f,1.f,1.f });

    glDrawer.addShapeData(ellipse);
    glDrawer.addShapeData(rect);
    glDrawer.addShapeData(star);
    glDrawer.addShapeData(diam);



    glutInitWindowSize(500, 500);   // Set the window's initial width & height
    glutCreateWindow("Shapes Output Test"); // Create a window with the given title
    glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    return 0;
}

