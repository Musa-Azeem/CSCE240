#define CENTROID_H
#ifndef POINT_H
#include "Point.h"
#endif

class Centroid: public Point{
    public:
        Centroid();
        Centroid(const int _nCoord, double *_coord, const int _id);
        Centroid(const Centroid &other);
        ~Centroid();

        int getID() const;
        void print() const;
    private:
        const int id;
};