#include <iostream>
using namespace std;

#include "Matrix4.h"
#include "Vector4.h"
using namespace RE330;

#include "MatrixTest.h"

MatrixTestSuite::MatrixTestSuite()
{
}

MatrixTestSuite::~MatrixTestSuite()
{
}

int MatrixTestSuite::main()
{
    testMatrixMult();
    testVectorMult();
    return 1;
}

void MatrixTestSuite::testMatrixMult()
{
    RE330::Matrix4 lhs(RE330::Matrix4::IDENTITY);

    float value = 2;

    RE330::Matrix4 rhs( value, value, value, value,
                        value, value, value, value,
                        value, value, value, value,
                        value, value, value, value );

    RE330::Matrix4 result = lhs*rhs;

    if (!result.equals(rhs))
    {
        cout << "matrix4 matrix-matrix multiplication failed" << endl;
    }

    else
    {
        cout << "matrix4 matrix-matrix multiplication passed" << endl;
    }
}

void MatrixTestSuite::testVectorMult()
{
    RE330::Matrix4 lhs(RE330::Matrix4::IDENTITY);

    float value = 2;

    RE330::Vector4 rhs (value, value, value, value);

    RE330::Vector4 result = lhs*rhs;

    if (!result.equals(rhs))
    {
        cout << "matrix4 matrix-vector4 multiplication failed" << endl;
    }

    else
    {
        cout << "matrix4 matrix-vector4 multiplication passed" << endl;
    }
}
