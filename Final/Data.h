#define MYDATA_H
#include "Centroid.h"

class myData{
    public:
        myData();
        myData(const int nobserv, const int nvals, const double vals=0);
        myData(const int nobserv, const int nvals, const double **data);
        myData(const myData &other);
        ~myData();

        const double * getObservation(int observ);
        void setObservation(int observ, double *data);

        const myData & operator=(const myData &other);
        bool operator==(const myData &other) const;
        bool operator!=(const myData &other) const;
        const myData operator+(const myData &other) const;

        //opeartor >> and << and kmeans
    private:
        Point *data;
};


