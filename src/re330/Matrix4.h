#ifndef __Matrix4__
#define __Matrix4__

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

        inline Matrix4()
        {
        }

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
                m[1][0] * m2.m[0][3] + m[1][1] * m2.m[1][3] + m[1][2]
                          * m2.m[2][3] + m[1][3] * m2.m[3][3] );

            r.m[2][0] = (
                m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2]
                          * m2.m[2][0] + m[2][3] * m2.m[3][0] );
            r.m[2][1] = (
                m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2]
                          * m2.m[2][1] + m[2][3] * m2.m[3][1] );
            r.m[2][2] = (
                m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2]
                          * m2.m[2][2] + m[2][3] * m2.m[3][2] );
            r.m[2][3] = (
                m[2][0] * m2.m[0][3] + m[2][1] * m2.m[1][3] + m[2][2]
                          * m2.m[2][3] + m[2][3] * m2.m[3][3] );

            r.m[3][0] = (
                m[3][0] * m2.m[0][0] + m[3][1] * m2.m[1][0] + m[3][2]
                          * m2.m[2][0] + m[3][3] * m2.m[3][0] );
            r.m[3][1] = (
                m[3][0] * m2.m[0][1] + m[3][1] * m2.m[1][1] + m[3][2]
                          * m2.m[2][1] + m[3][3] * m2.m[3][1] );
            r.m[3][2] = (
                m[3][0] * m2.m[0][2] + m[3][1] * m2.m[1][2] + m[3][2]
                          * m2.m[2][2] + m[3][3] * m2.m[3][2] );
            r.m[3][3] = (
                m[3][0] * m2.m[0][3] + m[3][1] * m2.m[1][3] + m[3][2]
                          * m2.m[2][3] + m[3][3] * m2.m[3][3] );

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

            result.setY (
                m[1][0] * v.getX() +
                m[1][1] * v.getY() +
                m[1][2] * v.getZ() +
                m[1][3] * v.getW()
                );

            result.setZ (
                m[2][0] * v.getX() +
                m[2][1] * v.getY() +
                m[2][2] * v.getZ() +
                m[2][3]  *v.getW()
                );

            result.setW (
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

        inline float* getElementPointer()
        {
            return static_cast<float *>(_m);
        }
    };

}

#endif
