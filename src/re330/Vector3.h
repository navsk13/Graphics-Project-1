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

  };

}

#endif
