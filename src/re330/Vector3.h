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

    Vector3 add(Vector3 v1, Vector3 v2){
      Vector3 addVector;

      float addVectorX = v1.getXComp() + v2.getXComp();
      float addVectorY = v1.getYComp() + v2.getYComp();
      float addVectorZ = v1.getZComp() + v2.getZComp();

      addVector.x = addVectorX;
      addVector.y = addVectorY;
      addVector.z = addVectorZ;

      return addVector;
    }

    Vector3 operator+(const Vector3& left, const Vector3& right)
    {
      Vector3 result;
    }

    Vector3 subtract(Vector3 v1, Vector3 v2){
      Vector3 subtractVector;

      float subtractVectorX = v1.getXComp() - v2.getXComp();
      float subtractVectorY = v1.getYComp() - v2.getYComp();
      float subtractVectorZ = v1.getZComp() - v2.getZComp();

      subtractVector.x = subtractVectorX;
      subtractVector.y = subtractVectorY;
      subtractVector.z = subtractVectorZ;

      return subtractVector;
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
