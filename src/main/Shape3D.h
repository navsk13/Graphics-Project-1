
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

    inline const int getNumVerts() { return numVerts; }
    inline const float* getVertices() { return vertices; }
    inline const float* getColors() { return colors; }
    inline const int* getIndices() { return indices; }

private:
    const int numVerts;
    const float* vertices;
    const float* colors;
    const int* indices;
};
