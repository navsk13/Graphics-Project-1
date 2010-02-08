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

        inline void operator*(float scaleFactor) {
            x = x * scaleFactor;
            y = y * scaleFactor;
            z = z * scaleFactor;
            w = w * scaleFactor;
        }

        inline float dotProduct(Vector4 rhs) {
            float dotProduct = x*rhs.getX() +
                y*rhs.getY() +
                z*rhs.getZ() +
                w*rhs.getW();
            return dotProduct;

        }

        inline float magnitude() {
            float magnitude = sqrt(pow(x, 2) +
                                   pow(y, 2) +
                                   pow(z, 2) +
                                   pow(w, 2));

            return magnitude;
        }

        inline void normalize(float magnitude) {
            x = x/magnitude;
            y = y/magnitude;
            z = z/magnitude;
            z = w/magnitude;
        }

    };

}

#endif
