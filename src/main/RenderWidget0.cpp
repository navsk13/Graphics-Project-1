#include "RenderWidget0.h"
#include "Vector3.h"
#include "Camera.h"
#include "GLWidget.h"
#include "GLRenderContext.h"
#include "VertexData.h"
#include <iostream>
#include <QtOpenGL>


RenderWidget0::RenderWidget0()
{
    RenderContext *rs = new GLRenderContext();
    sceneManager = 0;
}

RenderWidget0::~RenderWidget0()
{
    if(sceneManager)
    {
        delete sceneManager;
        delete cubeShape;
    }
}

void RenderWidget0::initSceneEvent()
{
    sceneManager = new SceneManager();

    // Camera
    camera = sceneManager->createCamera();

    cubeShape = createCube();
    cube = drawShape(cubeShape);
    Matrix4 translateLeft(
        1, 0, 0, 2,
        0, 1, 0, 0,
        0, 0, 1, 2,
        0, 0, 0, 1
        );
    cube->setTransformation(translateLeft);

    sphereShape = createSphere(1);
    sphere = drawShape(sphereShape);

    // Trigger timer event every 5ms.
    timerId = startTimer(5);
}

void RenderWidget0::renderSceneEvent()
{
    sceneManager->renderScene();
}

void RenderWidget0::resizeRenderWidgetEvent(const QSize &s)
{
}

void RenderWidget0::timerEvent(QTimerEvent *t)
{
    Matrix4 m(
        cos(0.01), -sin(0.01), 0, 0,
        sin(0.01), cos(0.01), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
        );
    Matrix4 m2(
        1, 0, 0, 0,
        0, cos(0.01), -sin(0.01), 0,
        0, sin(0.01), cos(0.01), 0,
        0, 0, 0, 1
        );
    cube->setTransformation(m2*m*cube->getTransformation());
    sphere->setTransformation(m2*m*sphere->getTransformation());
    updateScene();
}

void RenderWidget0::mousePressEvent(QMouseEvent *e)
{
}

void RenderWidget0::mouseMoveEvent(QMouseEvent *e)
{
}

void RenderWidget0::mouseReleaseEvent(QMouseEvent *e)
{
}

void RenderWidget0::startAnimation()
{
    if(!timerId)
    {
        timerId = startTimer(5);
    }
}

void RenderWidget0::stopAnimation()
{
    if(timerId)
    {
        killTimer(timerId);
        timerId = 0;
    }
}

Shape3D * RenderWidget0::createCube()
{
    // A cube
    int nVerts = 8;

    //initializes a local array with desired vertices
    float v [] = {
        -1,-1,1, 1,-1,1, 1,1,1, -1,1,1,
        -1,1,-1, 1,1,-1, 1,-1,-1, -1,-1,-1
    };

    //the # of elements in v
    int v_elem_num = nVerts*3;

    //allocates memory on heap for vertices array
    float * vertices = new float[v_elem_num + 1];

    //set the first element of the array to the number of elements
    vertices[0] = v_elem_num;

    //copies local array values to heap array
    memmove(vertices + sizeof(float), v, sizeof(v));


    //puts colors array on heap
    float c [] = {
        1,0,0, 0,1,0, 0,0,1, 1,1,0,
        0,1,1, 1,0,1, 1,1,1, 0.5,0.5,0.5
    };
    int c_elem_num = nVerts*3;
    float * colors = new float[c_elem_num + 1];
    colors[0] = c_elem_num;
    memmove(colors + sizeof(float), c, sizeof(c));

    // The index data that stores the connectivity of the triangles
    int i[] = {
        0,2,3, 0,1,2,    // front face
        7,3,4, 7,0,3,    // left face
        6,4,5, 6,7,4,    // back face
        1,5,2, 1,6,5,    // right face
        2,4,3, 2,5,4,    // top face
        0,6,1, 0,7,6     // bottom face
    };
    int i_elem_num = sizeof(i)/sizeof(i[0]);
    int * indices= new int[i_elem_num + 1];
    indices[0] = i_elem_num;

    //not dependent on nVerts so we have to find using sizeof
    memmove(indices + sizeof(int), i, sizeof(i));

    return (new Shape3D(nVerts, vertices, colors, indices));
}

Shape3D * RenderWidget0::createSphere(int depth)
{
    float * v = subdivideVertices();

    c = subdivideColor();
    int c_elem_num = sizeof(c)/sizeof(c[0]);
    float * colors = new float[c_elem_num + 1];
    colors[0] = c_elem_num;
    memmove(colors + sizeof(float), c, sizeof(c));

    i = subdivideIndices();
    int i_elem_num = sizeof(i)/sizeof(i[0]);
    int * indices= new int[i_elem_num + 1];
    indices[0] = i_elem_num;
    memmove(indices + sizeof(int), i, sizeof(i));

    int nVerts = 24;
    return (new Shape3D(nVerts, vertices, colors, indices));
}

Object * RenderWidget0::drawShape(Shape3D * s)
{
    Object * temp = sceneManager->createObject();
    // Set up the vertex data
    VertexData& vertexData = temp->vertexData;

    // Specify the elements of the vertex data:
    // - one element for vertex positions
    vertexData.vertexDeclaration.addElement(
        0, 0, 3, 3*sizeof(float), RE330::VES_POSITION);
    // - one element for vertex colors
    vertexData.vertexDeclaration.addElement(
        1, 0, 3, 3*sizeof(int), RE330::VES_DIFFUSE);

    float * v = s->getVertices();
    // Create the buffers and load the data
    vertexData.createVertexBuffer(
        0, v[0]*sizeof(s[0]), (unsigned char*)(v+sizeof(float)));

    float * c = s->getColors();
    vertexData.createVertexBuffer(
        1, c[0]*sizeof(c[0]), (unsigned char*)(c+sizeof(float)));

    int * indices (s->getIndices());
        vertexData.createIndexBuffer(indices[0], (indices+sizeof(int)));

    return temp;
}

float * subdivideColors(int depth)
{
    ;
}
float * subdivideVertices(int depth)
{
    //new float [] v;
    int v_elem_num = pow(2, 2*depth + 3);

    Vector3 vTop(0, 1, 0);          //top vertex
    Vector3 vFrontLeft(-1, 0, 1);   //front left vertex
    Vector3 vFrontRight(1, 0, 1);   //front right vertex
    Vector3 vBackRight(1, 0, -1);   //back right vertex
    Vector3 vBackLeft(-1, 0, -1);   //back left vertex
    Vector3 vBottom(0, -1, 0);      //bottom vertex

    v1 = subdivide(vFrontLeft, vFrontRight, vTop, depth, v);
    v2 = subdivide(vBackLeft, vFrontLeft, vTop, depth, v);
    v3 = subdivide(vBackRight, vBackLeft, vTop, depth, v);
    v4 = subdivide(vFrontRight, vBackRight, vTop, depth, v);
    v5 = subdivide(vFrontLeft, vBottom, vFrontRight, depth, v);
    v6 = subdivide(vBackLeft, vBottom, vFrontLeft, depth, v);
    v7 = subdivide(vBackRight, vBottom, vBackLeft, depth, v);
    v8 = subdivide(vFrontRight, vBottom, vBackRight, depth, v);

    // float * vertices = new float[v_elem_num + 1];
    // vertices[0] = v_elem_num;
    // memmove(vertices + sizeof(float), v, sizeof(v));

    new float[] final = numElements, v1, ..., v8;
}

float [] RenderWidget0::subdivide(Vector3 v1, Vector3 v2, Vector3 v3,
                              int depth)
{
    if (depth == 0)
    {
        new float * baseArray;
        baseArray[0] = v1.getX();
        baseArray[1] = v1.getY();
        baseArray[2] = v1.getZ();
        baseArray[3] =  v2.getX();
            v2.getY(),
            v2.getZ(),
            v3.getX(),
            v3.getY(),
            v3.getZ()
        }
      return baseArray;
    }

    Vector3 v12 = (v1 + v2)*0.5;
    float v12Mag = v12->magnitude();
    v12->normalize(v12Mag);
    Vector3 v23 = (v2 + v3)*0.5;
    float v23Mag = v23->magnitude();
    v23->normalize(v23Mag);
    Vector3 v31 = (v3 + v1)*0.5;
    float v31Mag = v31->magnitude();
    v31->normalize(v31Mag);

    int newDepth = depth - 1;
    float []m1 = subdivide(v1, v12, v31, newDepth, v);
    float []m2 = subdivide(v2, v23, v12, newDepth, v);
    float []m3 = subdivide(v3, v31, v23, newDepth, v);
    float []m4 = subdivide(v12, v23, v31, newDepth, v);

    float [] sum =  m1 + m2 + m3 + m4;

    return sum;

}
