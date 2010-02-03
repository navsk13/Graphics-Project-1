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

    Vector3 operator+(const Vector3& left, const Vector3& right)
    {
      Vector3 result;
      float resultX = left.getXComp() + left.getXComp();
      float resultY = left.getYComp() + left.getYComp();
      float resultZ = left.getZComp() + left.getZComp();

      result.x = resultX;
      result.y = resultY;
      result.z = resultZ;

      return result;

    }

    Vector3 operator-(const Vector3& left, const Vector3& right)
    {
      Vector3 result;
      float resultX = left.getXComp() - left.getXComp();
      float resultY = left.getYComp() - left.getYComp();
      float resultZ = left.getZComp() - left.getZComp();

      result.x = resultX;
      result.y = resultY;
      result.z = resultZ;

      return result;

    }

    float dotProduct(Vector3 v1, Vector3 v2) {

      float dotProduct = v1.getXComp()*v2.getXComp() +
	                 v1.getYComp()*v2.getYComp() +
	                 v1.getZComp()*v2.getZComp();
      return dotProduct;
		  
    }

    Vector3 crossProduct(Vector v1, Vector3 v2) {
      Vector 3 crossProductVector;
		  
      float crossProductX = v1.getYComp()*v2.getZComp() -
	                    v1.getZComp()*v2.getYComp();
      float crossProductY = v1.getZComp()*v2.getXComp() -
	                    v1.getXComp()*v2.getZComp();
      float crossProductZ = v1.getXComp()*v2.getYComp() -
	                    v1.getYComp()*v2.getXComp();

      crossProductVector.x = crossProductX;
      crossProductVector.y = crossProductY;
      crossProductVector.z = crossProductZ;

      return crossProductVector;
    }

    float magnitude(Vector v) {
      float magnitude = sqrt((v.getXComp())^2 +
			     (v.getYComp())^2 +
			     (v.getZComp())^2);
      return magnitude;
    }

    Vector normalize(Vector v) {
      float magnitude = magnitude(v);
      
      float normalX = v.getXComp()/magnitude;
      float normalY = v.getYComp()/magnitude;
      float normalZ = v.getZComp()/magnitude;

      v.x = normalX;
      v.y = normalY;
      v.z = normalZ;

      return v;
      

  };
}

#endif
