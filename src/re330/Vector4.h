#ifndef __Vector4_h__
#define __Vector4_h__

#include "RE330_global.h"

namespace RE330 
{
  class RE330_EXPORT Vector4
  {
  private:
    float x, y, z, w;
  public:
    float getXComp() { return x; }
    float getYComp() { return y; }
    float getZComp() { return z; }
    float getWComp() { return w; }

    void setXComp(float x2) { x = x2; }
    void setYComp(float y2) { y = y2; }
    void setZComp(float z2) { z = z2; }
    void setWComp(float z2) { w = w2; }

    Vector4 operator+(const Vector4& left, const Vector4& right)
    {
      Vector4 result;
      float resultX = left.getXComp() + left.getXComp();
      float resultY = left.getYComp() + left.getYComp();
      float resultZ = left.getZComp() + left.getZComp();

      result.x = resultX;
      result.y = resultY;
      result.z = resultZ;

      return result;

    }

    Vector4 operator-(const Vector4& left, const Vector4& right)
    {
      Vector4 result;
      float resultX = left.getXComp() - left.getXComp();
      float resultY = left.getYComp() - left.getYComp();
      float resultZ = left.getZComp() - left.getZComp();

      result.x = resultX;
      result.y = resultY;
      result.z = resultZ;

      return result;

    }

  };

}

#endif

