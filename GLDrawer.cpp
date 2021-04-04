#include "GLDrawer.h"


GLDrawer::GLDrawer(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT    
}

void GLDrawer::drawShapes()
{
    for (auto& Shape : _shapes) 
    {
        drawShape((*Shape).getDrawData());
    }
    glFlush();  // Render now
}

void GLDrawer::drawShape(const DrawData& shapeData)
{
    glBegin(shapeData.mode);              // Each set of 4 vertices form a quad
    glColor3f(shapeData.color.red, shapeData.color.green, shapeData.color.blue); // Red
    for (auto& point : shapeData.points)
    {
        glVertex2f(point.coordx, point.coordy);
    }
    glEnd();
}