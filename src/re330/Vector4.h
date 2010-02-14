#ifndef __Vector4_h__
#define __Vector4_h__

#include <math.h>
#include "RE330_global.h"

namespace RE330
{
    class RE330_EXPORT Vector4
    {

    private:
        float x, y, z, w;

    public:
        inline Vector4() {}

        inline Vector4(float xParam, float yParam, float zParam, float wParam)
        {
            x = xParam;
            y = yParam;
            z = zParam;
            w = wParam;
        }

        float getX() { return x; }
        float getY() { return y; }
        float getZ() { return z; }
        float getW() { return w; }

        void setX(float x2) { x = x2; }
        void setY(float y2) { y = y2; }
        void setZ(float z2) { z = z2; }
        void setW(float w2) { w = w2; }

        inline Vector4 operator+(Vector4& rhs)
        {
            Vector4 result;

            result.x = x + rhs.getX();
            result.y = y + rhs.getY();
            result.z = z + rhs.getZ();
            result.w = w + rhs.getW();

            return result;

        }

        inline Vector4 operator-(Vector4& rhs)
        {
            Vector4 result;

            result.x = x - rhs.getX();
            result.y = y - rhs.getY();
            result.z = z - rhs.getZ();
            result.w = w - rhs.getW();

            return result;
        }

        inline Vector4 operator*(float scaleFactor)
        {
            Vector4 result;

            result.x = x * scaleFactor;
            result.y = y * scaleFactor;
            result.z = z * scaleFactor;
            result.w = w * scaleFactor;

            return result;
        }

        inline float dotProduct(Vector4 rhs)
        {
            float dotProduct = (x*rhs.getX() +
                                y*rhs.getY() +
                                z*rhs.getZ() +
                                w*rhs.getW());
            return dotProduct;

        }

        inline float magnitude()
        {
            float magnitude = sqrt(pow(x, 2) +
                                   pow(y, 2) +
                                   pow(z, 2) +
                                   pow(w, 2));

            return magnitude;
        }

        inline void normalize(float magnitude)
        {
            x = x/magnitude;
            y = y/magnitude;
            z = z/magnitude;
            w = w/magnitude;
        }

        inline bool equals(Vector4 &rhs)
        {
            if ( x == rhs.getX() and
                 y == rhs.getY() and
                 z == rhs.getZ() and
                 w == rhs.getW() )
            {
                return true;
            }

            return false;
        }

    };

}

#endif
