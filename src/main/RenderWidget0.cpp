#include "RenderWidget0.h"
#include "Vector3.h"
#include "Camera.h"
#include "GLWidget.h"
#include "GLRenderContext.h"
#include "VertexData.h"

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
    }
}

void RenderWidget0::initSceneEvent()
{
    sceneManager = new SceneManager();

    // Camera
    camera = sceneManager->createCamera();

    Shape3D cubeShape = createCube();
    cube = drawShape(cubeShape);

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
    Matrix4 m(cos(0.01),-sin(0.01),0,0, sin(0.01),cos(0.01),0,0, 0,0,1,0, 0,0,0,1);
    Matrix4 m2(1,0,0,0, 0,cos(0.01), -sin(0.01),0, 0,sin(0.01),cos(0.01),0, 0,0,0,1);
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

&Shape3D RenderWidget0::createSphere(int depth)
{
    int nVerts = 24;
    float vertices[] = {
        -1,0, 1,  1,0,1,  0,1,0,       //top front face
        -1,0,-1, -1,0,1, 0,1,0,    //top left face
        1,0,-1, -1,0,-1, 0,1,0,    //top back face
        1,0,1, 1,0,-1, 0,1,0,      //top right face
        -1,0,1, 0,-1,0, 1,0,1,     //bottom front face
        -1,0,-1, 0,-1,0, -1,0,1,    //bottom left face
        1,0,-1, 0,-1,0, -1,0,-1,    //bottom back face
        1,0,1, 0,-1,0, 1,0,-1      //bottom right face
    };

    float colors[] = {
        1,0,0, 1,0,0, 1,0,0,
        0,1,0, 0,1,0, 0,1,0,
        1,0,0, 1,0,0, 1,0,0,
        0,1,0, 0,1,0, 0,1,0,
        0,0,1, 0,0,1, 0,0,1,
        1,0,1, 1,0,1, 1,0,1,
        0,0,1, 0,0,1, 0,0,1,
        1,0,1, 1,0,1, 1,0,1
    };

    // The index data that stores the connectivity of the triangles
    int indices[] = {
        0,1,2,		// top front face
        3,4,5,		// top left face
        6,7,8,         // top back face
        9,10,11,       // top right face
        12,13,14,	// bottom front face
        15,16,17,	// bottom left face
        18,19,20,       // bottom back face
        21,22,23     // bottom right face
    };
    return new Shape3D(nVerts, vertices, colors, indices);
}

&Shape3D RenderWidget0::createCube()
{
    // A cube
    int nVerts = 8;
    float vertices[] = {-1,-1,1, 1,-1,1, 1,1,1, -1,1,1,
                        -1,1,-1, 1,1,-1, 1,-1,-1, -1,-1,-1};

    float colors[] = {1,0,0, 0,1,0, 0,0,1, 1,1,0,
                      0,1,1, 1,0,1, 1,1,1, 0.5,0.5,0.5};

    // The index data that stores the connectivity of the triangles
    int indices[] = {0,2,3, 0,1,2,    // front face
                     7,3,4, 7,0,3,    // left face
                     6,4,5, 6,7,4,    // back face
                     1,5,2, 1,6,5,    // right face
                     2,4,3, 2,5,4,    // top face
                     0,6,1, 0,7,6};   // bottom face

    return new Shape3D(nVerts, vertices, colors, indices);
}

Object& drawShape(Shape3D s)
{
    new Object temp;
    temp = sceneManager->createObject();
    // Set up the vertex data
    VertexData& vertexData = o->vertexData;

    // Specify the elements of the vertex data:
    // - one element for vertex positions
    vertexData.vertexDeclaration.addElement(
        0, 0, 3, 3*sizeof(float), RE330::VES_POSITION);
    // - one element for vertex colors
    vertexData.vertexDeclaration.addElement(
        1, 0, 3, 3*sizeof(int), RE330::VES_DIFFUSE);

    // Create the buffers and load the data
    vertexData.createVertexBuffer(
        0, nVerts*3*sizeof(float), (unsigned char*)s.getVertices());

    vertexData.createVertexBuffer(
        1, nVerts*3*sizeof(float), (unsigned char*)s.getColors());
    float[] indices (s.getIndices());

    vertexData.createIndexBuffer(sizeof indices / sizeof indices[0],
                                 indices());

    return &temp;
}
