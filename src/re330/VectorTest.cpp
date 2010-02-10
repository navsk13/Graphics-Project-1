#include <iostream>
using namespace std;

#include "Vector3.h"
#include "Vector4.h"
using namespace RE330;

#include "VectorTest.h"

VectorTestSuite::VectorTestSuite()
{
}

VectorTestSuite::~VectorTestSuite()
{
}

int VectorTestSuite::main()
{
    testAdd();
    testSub();
    testMult();
    testDot();
    return 1;
}

void VectorTestSuite::testAdd()
{
    float value = 1;
    Vector3 v3_1 = Vector3(value, value, value);
    Vector3 v3_2 = v3_1;
    Vector3 temp = v3_2 + v3_1;

    if (temp.getX() != value*2 ||
        temp.getY() != value*2 ||
        temp.getZ() != value*2)
    {
        cout << "vector3 addition failed" << endl;
    }
    else
    {
        cout << "vector3 addition passed" << endl;
    }
}

void VectorTestSuite::testSub()
{
    float value = 1;
    Vector3 v3_1 = Vector3(value, value, value);
    Vector3 v3_2 = v3_1;
    Vector3 temp = v3_2 - v3_1;

    if (temp.getX() != value*0 ||
        temp.getY() != value*0 ||
        temp.getZ() != value*0)
    {
        cout << "vector3 subtraction failed" << endl;
    }
    else
    {
        cout << "vector3 subtraction passed" << endl;
    }
}

void VectorTestSuite::testMult()
{
    float value = 1;
    float scalar = 2;
    Vector3 v3_1 = Vector3(value, value, value);
    Vector3 temp = v3_1*scalar;

    if (temp.getX() != value*scalar ||
        temp.getY() != value*scalar ||
        temp.getZ() != value*scalar)
    {
        cout << "vector3 multiplication failed" << endl;
    }
    else
    {
        cout << "vector3 multiplication passed" << endl;
    }
}

void VectorTestSuite::testDot()
{
    float value = 1;
    Vector3 v3_1 = Vector3(value, value, value);
    Vector3 v3_2 = v3_1;
    float temp = v3_1.dotProduct(v3_2);

    if (temp != (3 * pow(value, 2)) )
    {
        cout << "vector3 dot product failed" << endl;
    }
    else
    {
        cout << "vector3 dot product passed" << endl;
    }
}

void VectorTestSuite::testCross()
{
    float value = 1;
    Vector3 v3_1 = Vector3(value, value, value);
    Vector3 v3_2 = v3_1;
    Vector3 temp = v3_1.crossProduct(v3_2);

    if (true)
    {
        cout << "vector3 cross product failed" << endl;
    }
    else
    {
        cout << "vector3 cross product passed" << endl;
    }
}

void VectorTestSuite::testMag()
{
    float value = 1;
    Vector3 v3_1 = Vector3(value, value, value);
    float temp = v3_1.magnitude();

    if (temp != (3 * pow(value, 2)) )
    {
        cout << "vector3 magnitude failed" << endl;
    }
    else
    {
        cout << "vector3 magnitude passed" << endl;
    }
}

void VectorTestSuite::testNorm()
{
    float value = 1;
    Vector3 v3_1 = Vector3(value, value, value);
    v3_1.normalize( v3_1.magnitude() );

    if (false )
    {
        cout << "vector3 normalize failed" << endl;
    }
    else
    {
        cout << "vector3 normalize passed" << endl;
    }
}
