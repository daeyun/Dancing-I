//
//  drawing_helper.h
//  CS418 MP1
//
//  Created by Daeyun Shin on 8/27/14.
//  Copyright (c) 2014 Daeyun Shin. All rights reserved.
//

#ifndef __CS418_MP1__drawing_helper__
#define __CS418_MP1__drawing_helper__

#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

void drawI(float centerX, float centerY, float scale, bool isFilled);
void drawIBorder(float centerX, float centerY, float scale);
void drawVertex(float centerX, float centerY, float scale, const float vertices[][2], bool willSetColor, int ind);

#endif /* defined(__CS418_MP1__drawing_helper__) */
