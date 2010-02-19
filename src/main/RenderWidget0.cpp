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
        // delete cubeShape;
        // delete sphereShape;
    }
}

void RenderWidget0::initSceneEvent()
{
    sceneManager = new SceneManager();

    // Camera
    camera = sceneManager->createCamera();

    cubeShape = createCube();
    blade1 = drawShape(cubeShape);
    //blade2 = drawShape(cubeShape);//maybe works

    Matrix4 translateLeft(
        1, 0, 0, 2,
        0, 1, 0, 0,
        0, 0, 1, 2,
        0, 0, 0, 1
        );
    blade1->setTransformation(translateLeft);

    sphereShape = createSphere(3);
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
    blade1->setTransformation(m2*m*blade1->getTransformation());
//    sphere->setTransformation(m*m2*sphere->getTransformation());
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
    float v [] = { 0, //dummy value
        -1,-1,1, 1,-1,1, 1,1,1, -1,1,1,
        -1,1,-1, 1,1,-1, 1,-1,-1, -1,-1,-1
    };

    //the # of elements in v
    int v_elem_num = nVerts*3;

    //allocates memory on heap for vertices array
    float * vertices = new float[v_elem_num + 1];

    //set the first element of the array to the number of elements
    vertices[0] = v_elem_num;

    //puts colors array on heap
    float c [] = {0,
        1,0,0, 0,1,0, 0,0,1, 1,1,0,
        0,1,1, 1,0,1, 1,1,1, 0.5,0.5,0.5
    };
    int c_elem_num = nVerts*3;
    float * colors = new float[c_elem_num + 1];
    colors[0] = c_elem_num;

    //copies local array values to heap array
    for (int i = 1; i < v_elem_num + 1; i++)
    {
        vertices[i] = v[i];
        colors[i] = c[i];
    }


    // The index data that stores the connectivity of the triangles
    int i[] = {0,
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
    for (int elem = 1; elem < i_elem_num; elem ++)
    {
        indices[elem] = i[elem];
    }

    return (new Shape3D(nVerts, vertices, colors, indices));
}

Shape3D * RenderWidget0::createSphere(int depth)
{
    float * vertices = subdivideVertices(depth);

    float * colors = subdivideColor(depth);

    int * indices = subdivideIndices(depth);

    int nVerts = pow(2, 2*depth + 3);

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
        0, v[0]*sizeof(s[1]), (unsigned char*)(&v[1]));

    float * c = s->getColors();
    vertexData.createVertexBuffer(
        1, c[0]*sizeof(c[1]), (unsigned char*)(&c[1]));

    int * indices (s->getIndices());
    vertexData.createIndexBuffer(indices[0], (&indices[1]));

    return temp;
}

float * RenderWidget0:: subdivideVertices(int depth)
{
    Vector3 vTop(0, 1, 0);          //top vertex
    Vector3 vFrontLeft(-1, 0, 1);   //front left vertex
    Vector3 vFrontRight(1, 0, 1);   //front right vertex
    Vector3 vBackRight(1, 0, -1);   //back right vertex
    Vector3 vBackLeft(-1, 0, -1);   //back left vertex
    Vector3 vBottom(0, -1, 0);      //bottom vertex

    float vTopMag = vTop.magnitude();
    vTop.normalize(vTopMag);
    float vFrontLeftMag = vFrontLeft.magnitude();
    vFrontLeft.normalize(vFrontLeftMag);
    float vFrontRightMag = vFrontRight.magnitude();
    vFrontRight.normalize(vFrontRightMag);
    float vBackRightMag = vBackRight.magnitude();
    vBackRight.normalize(vBackRightMag);
    float vBackLeftMag = vBackLeft.magnitude();
    vBackLeft.normalize(vBackLeftMag);
    float vBottomMag = vBottom.magnitude();
    vBottom.normalize(vBottomMag);

    float * m1 = subdivideVertices(vFrontLeft, vFrontRight, vTop, depth);
    float * m2 = subdivideVertices(vBackLeft, vFrontLeft, vTop, depth);
    float * m3 = subdivideVertices(vBackRight, vBackLeft, vTop, depth);
    float * m4 = subdivideVertices(vFrontRight, vBackRight, vTop, depth);
    float * m5 = subdivideVertices(vFrontLeft, vBottom, vFrontRight, depth);
    float * m6 = subdivideVertices(vBackLeft, vBottom, vFrontLeft, depth);
    float * m7 = subdivideVertices(vBackRight, vBottom, vBackLeft, depth);
    float * m8 = subdivideVertices(vFrontRight, vBottom, vBackRight, depth);

    int numSubdivisions = 8;

    //update numElements, all are the same so only look up 1
    int subElements = m1[0];
    int numVertices = subElements*numSubdivisions;
    float * final;
    final = new float [numVertices + 1];
    final[0] = numVertices;

    //copy the first array into sum starting after the first element for both

    for (int i = 1; i < subElements + 1; i++)
    {
        final[i] = m1[i];
        final[i+subElements] = m2[i];
        final[i+2*subElements] = m3[i];
        final[i+3*subElements] = m4[i];
        final[i+4*subElements] = m5[i];
        final[i+5*subElements] = m6[i];
        final[i+6*subElements] = m7[i];
        final[i+7*subElements] = m8[i];
    }

    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
    delete m6;
    delete m7;
    delete m8;

    return final;

}

float * RenderWidget0::subdivideVertices(Vector3 v1,
                                         Vector3 v2,
                                         Vector3 v3,
                                         int depth)
{
    if (depth == 0)
    {
        //create an array on heap so it's returnable
        float * baseArray = new float [10];

        //maintain the # of elements as first element
        baseArray[0] = 9.0f;

        baseArray[1] = v1.getX();
        baseArray[2] = v1.getY();
        baseArray[3] = v1.getZ();
        baseArray[4] = v2.getX();
        baseArray[5] = v2.getY();
        baseArray[6] = v2.getZ();
        baseArray[7] = v3.getX();
        baseArray[8] = v3.getY();
        baseArray[9] = v3.getZ();

        return baseArray;
    }

    Vector3 v12 = (v1 + v2)*0.5f;
    float v12Mag = v12.magnitude();
    v12.normalize(v12Mag);
    Vector3 v23 = (v2 + v3)*0.5f;
    float v23Mag = v23.magnitude();
    v23.normalize(v23Mag);
    Vector3 v31 = (v3 + v1)*0.5f;
    float v31Mag = v31.magnitude();
    v31.normalize(v31Mag);

    int newDepth = depth - 1;
    float * m1 = subdivideVertices(v1, v12, v31, newDepth);
    float * m2 = subdivideVertices(v2, v23, v12, newDepth);
    float * m3 = subdivideVertices(v3, v31, v23, newDepth);
    float * m4 = subdivideVertices(v12, v23, v31, newDepth);

    int numSubdivisions = 4;

    //update numElements, all 4 are the same so only look up 1
    int subElements = m1[0];
    int numVertices = subElements*numSubdivisions;
    float* sum;
    sum = new float [numVertices + 1];
    sum[0] = numVertices;

    for (int i = 1; i < subElements + 1; i++)
    {
        sum[i] = m1[i];
        sum[i+subElements] = m2[i];
        sum[i+2*subElements] = m3[i];
        sum[i+3*subElements] = m4[i];
    }

    delete m1;
    delete m2;
    delete m3;
    delete m4;

    return sum;

}

float * RenderWidget0::subdivideColor(int depth)
{

    Vector3 topColor1(1.0f, 0.0f, 0.0f);       //top front and back color- red
    Vector3 topColor2(1.0f, 1.0f, 0.0f);       //top right and left color- yellow
    Vector3 bottomColor1(0.0f, 0.0f, 1.0f);    //bottom front and back color- blue
    Vector3 bottomColor2(0.0f, 1.0f, 0.0f);    //bottom right and left color- green

    float * m1 = subdivideColor(topColor1, depth);
    float * m2 = subdivideColor(topColor2, depth);
    float * m3 = subdivideColor(topColor1, depth);
    float * m4 = subdivideColor(topColor2, depth);
    float * m5 = subdivideColor(bottomColor1, depth);
    float * m6 = subdivideColor(bottomColor2, depth);
    float * m7 = subdivideColor(bottomColor1, depth);
    float * m8 = subdivideColor(bottomColor2, depth);

    int numSubdivisions = 8;

    //update numElements, all 4 are the same so only look up 1
    int subElements = m1[0];
    int numVertices = subElements*numSubdivisions;

    float * final;
    final = new float [numVertices + 1];
    final[0] = numVertices;

    //copy the first array into sum starting after the first element for both
    for (int i = 1; i < subElements + 1; i++)
    {
        final[i] = m1[i];
        final[i+subElements] = m2[i];
        final[i+2*subElements] = m3[i];
        final[i+3*subElements] = m4[i];
        final[i+4*subElements] = m5[i];
        final[i+5*subElements] = m6[i];
        final[i+6*subElements] = m7[i];
        final[i+7*subElements] = m8[i];
    }
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
    delete m6;
    delete m7;
    delete m8;

    return final;
}

float * RenderWidget0::subdivideColor(Vector3 c,
                                      int depth)
{
    if (depth == 0)
    {
        float * array;
        array = new float [10];
        array[0] = 9.0f;

        for (int i = 0; i < 3; i++)
        {
            //counting
            array[3*i+1] = c.getX();
            array[3*i+2] = c.getY();
            array[3*i+3] = c.getZ();
        }
        return array;
    }

    int newDepth = depth - 1;

    float * m1 =  subdivideColor(c, newDepth);
    float * m2 = subdivideColor(c, newDepth);
    float * m3 = subdivideColor(c, newDepth);

    float newR = c.getX() + (1 - c.getX())*0.5;
    float newG = c.getY() + (1 - c.getY())*0.5;
    float newB = c.getZ() + (1 - c.getZ())*0.5;
    Vector3 newC(newR, newG, newB);
    float * m4 = subdivideColor(newC, newDepth);

    int numSubdivisions = 4;

    //update numElements, all 4 are the same so only look up 1
    int subElements = m1[0];
    int numVertices = subElements*numSubdivisions;
    float* sum = new float [numVertices + 1];
    sum[0] = numVertices;
    //copy the first array into sum starting after the first element for both
    for (int i = 1; i < subElements + 1; i++)
    {
        sum[i] = m1[i];
        sum[i+subElements] = m2[i];
        sum[i+2*subElements] = m3[i];
        sum[i+3*subElements] = m4[i];
    }

    delete m1;
    delete m2;
    delete m3;
    delete m4;

    return sum;


}

int * RenderWidget0::subdivideIndices(int depth)
{
    int i_elem_num = 3*pow(2, 2*depth + 3);
    int * indices = new int [i_elem_num + 1] ;

    indices[0] = i_elem_num;

    for (int i = 1; i < i_elem_num+1; i++)
    {
        indices[i] = i - 1;
    }

    return indices;
}
