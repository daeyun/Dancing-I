//
//  main.cpp
//  CS418 MP1
//
//  Created by Daeyun Shin on 8/27/14.
//  Copyright (c) 2014 Daeyun Shin. All rights reserved.
//

#include "drawing_helper.h"
#include "time.h"
#include "math.h"

using namespace std;

const int FPS = 30;
const int WINDOW_SIZE = 500;
const char *WINDOW_TITLE = "CS 418 MP1";

float theta = 0;
float t_prev;

void displayFunc() {
    // Clear frame buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    float scale = sin(sin(cos(theta*0.2) + theta/2) + sin(theta)/3) - cos(cos(theta) + 1)/3;
    float x = (sin(cos(theta*0.7) + sin(theta*0.5))) * (0.5*(1-(scale+1)/2));
    float y = (2*cos(cos(sin(theta*0.6)) + sin(sin(cos(theta*0.6))))-1)  * (0.5*(1-(scale+1)/2));
    
    drawI(x, y, scale, true);
    drawI(x, y, scale, false);
    drawIBorder(x, y, scale);
    
    theta = fmod((theta + 0.1), (64 * 3.1415));
    
    glutSwapBuffers();
}

void idleFunc() {
    clock_t t = clock();
    
    // Check the system clock and draw after a frame clock tick.
    if (t - t_prev > CLOCKS_PER_SEC/FPS) {
        displayFunc();
        t_prev = t;
    }
}

void initializeWindow() {
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
    
    // Create a double buffered window with a depth buffer.
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow(WINDOW_TITLE);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    initializeWindow();
    
    glutDisplayFunc (displayFunc);
    glutIdleFunc(idleFunc);
    
    glutMainLoop();
}