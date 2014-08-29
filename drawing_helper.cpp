//
//  drawing_helper.cpp
//  CS418 MP1
//
//  Created by Daeyun Shin on 8/27/14.
//  Copyright (c) 2014 Daeyun Shin. All rights reserved.
//

#include "drawing_helper.h"

using namespace std;

// constants defining the shape of the I
const float I_TOP = 0.7;
const float I_INNER_TOP = 0.42;
const float I_INNER_BOTTOM = -0.42;
const float I_BOTTOM = -0.7;
const float I_LEFT = -0.4;
const float I_INNER_LEFT = -0.2;
const float I_INNER_RIGHT = 0.2;
const float I_RIGHT = 0.4;

// i%6 is the color of vertex i
const float colors[][3] = {
    {0, 0, 1},
    {0, 1, 1},
    {0, 1, 0},
    {1, 1, 0},
    {1, 0, 0},
    {1, 0, 1},
};

const float vertices[12][2] = {
    {I_LEFT, I_TOP},
    {I_RIGHT, I_TOP},
    {I_LEFT, I_INNER_TOP},
    {I_INNER_LEFT, I_INNER_TOP},
    {I_INNER_RIGHT, I_INNER_TOP},
    {I_RIGHT, I_INNER_TOP},
    {I_LEFT, I_INNER_BOTTOM},
    {I_INNER_LEFT, I_INNER_BOTTOM},
    {I_INNER_RIGHT, I_INNER_BOTTOM},
    {I_RIGHT, I_INNER_BOTTOM},
    {I_LEFT, I_BOTTOM},
    {I_RIGHT, I_BOTTOM}
};

void drawI(float centerX, float centerY, float scale, bool isFilled) {
    
    if (isFilled) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(3.0 * abs(scale));
        glColor3f(1, 1, 1);
    }
    
    glBegin(GL_TRIANGLES);
    {
        const int numVertices = 30;
        int vertexDrawingSequence[numVertices] = {
            0, 1, 3, 0, 2, 3, 1, 3, 4, 1, 4, 5,
            3, 4, 7, 4, 7, 8,
            6, 7, 10, 8, 9, 11, 7, 8, 10, 8, 10, 11,
        };
        
        for (int i = 0; i < numVertices; i++) {
            drawVertex(centerX, centerY, scale, vertices, isFilled, vertexDrawingSequence[i]);
        }
    }
    glEnd();
}

void drawIBorder(float centerX, float centerY, float scale) {
    glColor3f(1, 0.3, 0.3);
    glLineWidth(10*abs(scale));
    glBegin(GL_LINE_LOOP);
    {
        const int numVertices = 30;
        int vertexDrawingSequence[numVertices] = {
            0, 1, 5, 4, 8, 9, 11, 10, 6, 7, 3, 2
        };
        
        for (int i = 0; i < numVertices; i++) {
            drawVertex(centerX, centerY, scale, vertices, false, vertexDrawingSequence[i]);
        }
    }
    glEnd();
}

/**
 * Given an index, draw the corresponding vertex
 */
void drawVertex(float centerX, float centerY, float scale, const float vertices[][2], bool willSetColor, int ind) {
    const float *color = colors[ind % (sizeof(colors)/sizeof(colors[0]))];
    
    if (willSetColor) {
        glColor3f(color[0], color[1], color[2]);
    }
    
    glVertex2f(vertices[ind][0] * scale + centerX, vertices[ind][1] * scale + centerY);
}