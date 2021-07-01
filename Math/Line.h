#ifndef LINALG_LINE_H
#define LINALG_LINE_H


#include "Vector3.h"

class Line {
public:
    Vector3& start;
    Vector3& end;

public:
    Line(Vector3 &start, Vector3& end);
};


#endif //LINALG_LINE_H
