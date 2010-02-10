#ifndef __Vector3_h__
#define __Vector3_h__

#include <math.h>
#include "RE330_global.h"

namespace RE330
{
//#include <math.h> using namespace std;
    class RE330_EXPORT Vector3
    {
    private:
        float x, y, z;
    public:
        float getX() { return x; }
        float getY() { return y; }
        float getZ() { return z; }

        void setX(float x2) { x = x2; }
        void setY(float y2) { y = y2; }
        void setZ(float z2) { z = z2; }

        inline Vector3 operator+(Vector3& right)
        {
            Vector3 result;

            result.x = x + right.getX();
            result.y = y + right.getY();
            result.z = z + right.getZ();

            return result;

        }

        inline Vector3 operator-(Vector3& right)
        {
            Vector3 result;

            result.x = x - right.getX();
            result.y = y - right.getY();
            result.z = z - right.getZ();

            return result;

        }

        inline void operator*(float scalarFactor)
        {
            x = x * scalarFactor;
            y = y * scalarFactor;
            z = z * scalarFactor;
        }

        inline float dotProduct(Vector3& rhs) {

            float dotProduct = x*rhs.getX() +
                y*rhs.getY() +
                z*rhs.getZ();
            return dotProduct;

        }

        inline Vector3 crossProduct(Vector3& rhs) {
            Vector3 crossProductVector;

            crossProductVector.x = y*rhs.getZ() -
                z*rhs.getY();;
            crossProductVector.y = z*rhs.getX() -
                x*rhs.getZ();;
            crossProductVector.z =  x*rhs.getY() -
                y*rhs.getX();;

            return crossProductVector;
        }

        inline float magnitude() {
            float magnitude = sqrt( pow(x, 2) +
                                    pow(y, 2) +
                                    pow(z, 2) );
            return magnitude;
        }

        inline void normalize(float magnitude) {
            x = x/magnitude;
            y = y/magnitude;
            z = z/magnitude;

        }
    };
}

#endif
