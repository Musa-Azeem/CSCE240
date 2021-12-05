#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point{
    friend std::ostream & operator<<(std::ostream &lhs, const Point &rhs);
    friend std::istream & operator>>(std::istream &lhs, Point &rhs);
    public:
        Point();
        Point(const int numOfCoord, const double val);
        Point(const int numOfCoord, const double val, const int _membership);
        Point(const int numOfCoord, const double *_coord);
        Point(const int numOfCoord, const double *_coord, const int _membership);
        Point(const int numOfCoord, const double *_coord, const int _membership, const double _centroidDistance);
        Point(const Point &other);
        ~Point();
        void init(const int _size, const double *_data, const int _membership, const double _centroidDistance);

        int getSize() const;
        int getMembership() const;
        double getCentroidDistance() const;
        const double * getCoord() const;

        bool setCentroidDistance(const double _centroidDistance);
        bool setMembership(const int _membership);

        double distance(const Point &other) const;

        double operator[](const int index) const;
        double & operator[](const int index);
        bool operator==(const Point &rhs) const;
        //const Point & operator=(const Point &rhs);
    protected:
        double *coord;
        int size;
        int membership;
        double centroidDistance;
};

#endif