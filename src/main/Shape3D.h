
class Shape3D
{
public:
    Shape3D(int _numVerts, float _vertices[],
            float _colors[], int _indices[]
        ):
        numVerts(_numVerts),
        vertices(_vertices),
        colors(_colors),
        indices(_indices)
        {
        }

    inline int getNumVerts() { return numVerts; }
    inline float * getVertices() { return vertices; }
    inline float * getColors() { return colors; }
    inline int * getIndices() { return indices; }

private:
    int numVerts;
    float * vertices;
    float * colors;
    int * indices;

 };
