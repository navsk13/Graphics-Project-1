#ifndef __Vector3_h__
#define __Vector3_h__

#include "RE330_global.h"
#include <math.h>

namespace RE330
{
  class RE330_EXPORT Vector3
  {
  private:
    float x, y, z;
  public:
    float getXComp() { return x; }
    float getYComp() { return y; }
    float getZComp() { return z; }

    void setXComp(float x2) { x = x2; }
    void setYComp(float y2) { y = y2; }
    void setZComp(float z2) { z = z2; }

    Vector3 operator+(Vector3& right)
    {
      Vector3 result;

      result.x = x + right.getXComp();
      result.y = y + right.getYComp();
      result.z = z + right.getZComp();

      return result;

    }

    Vector3 operator-(Vector3& right)
    {
      Vector3 result;

      result.x =  x - right.getXComp();
      result.y = y - right.getYComp();
      result.z = z - right.getZComp();

      return result;

    }

    void operator*(float scalarFactor)
    {
      x = x * scalarFactor;
      y = y * scalarFactor;
      z = z * scalarFactor;
    }

    float dotProduct(Vector3& rhs) {

      float dotProduct = x*rhs.getXComp() +
	                 y*rhs.getYComp() +
	                 z*rhs.getZComp();
      return dotProduct;
		  
    }

    Vector3 crossProduct(Vector3& rhs) {
      Vector3 crossProductVector;

      crossProductVector.x = y*rhs.getZComp() -
	                    z*rhs.getYComp();; 
      crossProductVector.y = z*rhs.getXComp() -
	                    x*rhs.getZComp();;
      crossProductVector.z =  x*rhs.getYComp() -
	                    y*rhs.getXComp();;

      return crossProductVector;
    }

    float magnitude() {
      float magnitude = sqrt( pow(x, 2) +
			      pow(y, 2) +
			      pow(z, 2) );
      return magnitude;
    }

    void normalize() {
      float magnitude = this.magnitude();
      
      float normalX = x/magnitude;
      float normalY = y/magnitude;
      float normalZ = z/magnitude;

      x = normalX;
      y = normalY;
      z = normalZ;

    }
  };
}

#endif
