#ifndef __Matrix4__
#define __Matrix4__

#include <iostream>
#include <assert.h>
#include "Vector4.h"
#include "Vector3.h"


namespace RE330
{
    /** Matrix class for 4x4 matrices.
     */
    class RE330_EXPORT Matrix4
    {
    protected:
        union {
            float m[4][4];
            float _m[16];
        };

    public:
        static const Matrix4 IDENTITY;

        inline Matrix4() {}

        inline Matrix4(
            float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33 )
        {
            m[0][0] = m00;
            m[0][1] = m01;
            m[0][2] = m02;
            m[0][3] = m03;
            m[1][0] = m10;
            m[1][1] = m11;
            m[1][2] = m12;
            m[1][3] = m13;
            m[2][0] = m20;
            m[2][1] = m21;
            m[2][2] = m22;
            m[2][3] = m23;
            m[3][0] = m30;
            m[3][1] = m31;
            m[3][2] = m32;
            m[3][3] = m33;
        }

        inline Matrix4 operator*(const Matrix4 &m2) const
        {
            Matrix4 r;
            r.m[0][0] = (
                m[0][0] * m2.m[0][0] +
                m[0][1] * m2.m[1][0] +
                m[0][2] * m2.m[2][0] +
                m[0][3] * m2.m[3][0]
                );
            r.m[0][1] = (
                m[0][0] * m2.m[0][1] +
                m[0][1] * m2.m[1][1] +
                m[0][2] * m2.m[2][1] +
                m[0][3] * m2.m[3][1]
                );
            r.m[0][2] = (
                m[0][0] * m2.m[0][2] +
                m[0][1] * m2.m[1][2] +
                m[0][2]
                * m2.m[2][2] +
                m[0][3] * m2.m[3][2]
                );
            r.m[0][3] = (
                m[0][0] * m2.m[0][3] +
                m[0][1] * m2.m[1][3] +
                m[0][2] * m2.m[2][3] +
                m[0][3] * m2.m[3][3]
                );

            r.m[1][0] = (
                m[1][0] * m2.m[0][0] +
                m[1][1] * m2.m[1][0] +
                m[1][2] * m2.m[2][0] +
                m[1][3] * m2.m[3][0]
                );
            r.m[1][1] = (
                m[1][0] * m2.m[0][1]
                + m[1][1] * m2.m[1][1]
                + m[1][2] * m2.m[2][1]
                + m[1][3] * m2.m[3][1]
                );
            r.m[1][2] = (
                m[1][0] * m2.m[0][2]
                + m[1][1] * m2.m[1][2]
                + m[1][2] * m2.m[2][2]
                + m[1][3] * m2.m[3][2]
                );
            r.m[1][3] = (
                m[1][0] * m2.m[0][3] +
                m[1][1] * m2.m[1][3] +
                m[1][2] * m2.m[2][3] +
                m[1][3] * m2.m[3][3]
                );

            r.m[2][0] = (
                m[2][0] * m2.m[0][0] +
                m[2][1] * m2.m[1][0] +
                m[2][2] * m2.m[2][0] +
                m[2][3] * m2.m[3][0]
                );
            r.m[2][1] = (
                m[2][0] * m2.m[0][1] +
                m[2][1] * m2.m[1][1] +
                m[2][2] * m2.m[2][1] +
                m[2][3] * m2.m[3][1]
                );
            r.m[2][2] = (
                m[2][0] * m2.m[0][2] +
                m[2][1] * m2.m[1][2] +
                m[2][2] * m2.m[2][2] +
                m[2][3] * m2.m[3][2]
                );
            r.m[2][3] = (
                m[2][0] * m2.m[0][3] +
                m[2][1] * m2.m[1][3] +
                m[2][2] * m2.m[2][3] +
                m[2][3] * m2.m[3][3]
                );

            r.m[3][0] = (
                m[3][0] * m2.m[0][0] +
                m[3][1] * m2.m[1][0] +
                m[3][2] * m2.m[2][0] +
                m[3][3] * m2.m[3][0]
                );
            r.m[3][1] = (
                m[3][0] * m2.m[0][1] +
                m[3][1] * m2.m[1][1] +
                m[3][2] * m2.m[2][1] +
                m[3][3] * m2.m[3][1]
                );
            r.m[3][2] = (
                m[3][0] * m2.m[0][2] +
                m[3][1] * m2.m[1][2] +
                m[3][2] * m2.m[2][2] +
                m[3][3] * m2.m[3][2] );
            r.m[3][3] = (
                m[3][0] * m2.m[0][3] +
                m[3][1] * m2.m[1][3] +
                m[3][2] * m2.m[2][3] +
                m[3][3] * m2.m[3][3]
                );

            return r;
        }

        inline Vector4 operator*(Vector4 &v) const
        {
            Vector4 result;

            result.setX(
                m[0][0] * v.getX() +
                m[0][1] * v.getY() +
                m[0][2] * v.getZ() +
                m[0][3] * v.getW()
                );

            result.setY(
                m[1][0] * v.getX() +
                m[1][1] * v.getY() +
                m[1][2] * v.getZ() +
                m[1][3] * v.getW()
                );

            result.setZ(
                m[2][0] * v.getX() +
                m[2][1] * v.getY() +
                m[2][2] * v.getZ() +
                m[2][3] * v.getW()
                );

            result.setW(
                m[3][0] * v.getX() +
                m[3][1] * v.getY() +
                m[3][2] * v.getZ() +
                m[3][3] * v.getW()
                );

            return result;
        }

        inline Matrix4 transpose() const
        {
            Matrix4 r;
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    r._m[i*4+j]=_m[j*4+i];
                }
            }
            return r;
        }

        inline Matrix4 rotateAxis(char axis,
                                  float angle)
        {
            Matrix4 result(IDENTITY);
            float cosAngle = cos(angle);
            float sinAngle = sin(angle);

            switch(axis)
            {
            case 'x':
                result.m[1][1] = cosAngle;
                result.m[1][2] = -sinAngle;
                result.m[2][1] = sinAngle;
                result.m[2][2] = cosAngle;
                break;

            case 'y':
                result.m[0][0] = cosAngle;
                result.m[0][2] = sinAngle;
                result.m[2][0] = -sinAngle;
                result.m[2][2] = cosAngle;
                break;

            case 'z':
                result.m[0][0] = cosAngle;
                result.m[0][1] = -sinAngle;
                result.m[1][0] = sinAngle;
                result.m[1][1] = cosAngle;
                break;

            default:
                std::cout << "you should have used a lower-case letter" << std::endl;
            }

            return result;
        }

        inline Matrix4 rotateArbitrary(Vector4 vector,
                                       float angle)
        {
            Matrix4 result(IDENTITY);

            float x = vector.getX();
            float y = vector.getY();
            float z = vector.getZ();

            float cosA = cos(angle);
            float sinA = sin(angle);

            float x2 = pow(x, 2);
            result.m[0][0] = x2 + cosA * (1 - x2);
            result.m[0][1] = x * y * (1 - cosA) - z * sinA;
            result.m[0][2] = x * z * (1 - cosA) + y * sinA;

            float y2 = pow(y, 2);
            result.m[1][0] = x * y * (1 - cosA) + z * sinA;
            result.m[1][1] = y2 + cosA * (1 - y2);
            result.m[1][2] = y * z * (1 - cosA) - x * sinA;

            float z2 = pow(z, 2);
            result.m[2][0] = x * z * (1 - cosA) - y * sinA;
            result.m[2][1] = y * z * (1 - cosA) + x * sinA;
            result.m[2][2] = z2 + cosA * (1 - z2);

            return result;
        }

        inline Matrix4 scale(float x,
                             float y,
                             float z)
        {
            Matrix4 result(IDENTITY);

            result.m[0][0] = x;
            result.m[1][1] = y;
            result.m[2][2] = z;

            return result;
        }

        inline Matrix4 translate(float x,
                                 float y,
                                 float z)
        {
            Matrix4 result(IDENTITY);

            result.m[0][3] = x;
            result.m[1][3] = y;
            result.m[2][3] = z;

            return result;
        }


        inline float* getElementPointer()
        {
            return static_cast<float *>(_m);
        }

        inline bool equals(Matrix4 &rhs)
        {

            for (int row = 0; row < 4; row++)
            {
                for (int col = 0; col < 4; col++)
                {
                    if (m[row][col] != rhs.m[row][col])
                    {
                        return false;
                    }
                }
            }

            return true;
        }

    };

}

#endif
