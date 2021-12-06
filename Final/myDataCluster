// #include "myData.h"
// #include "math.h"

// using namespace std;

// //SETTERS for size

// myData::myData(): data(nullptr), size(0), nvals(0), clusters(nullptr), nclust(0) {
//     clusts = nullptr;
// }
// myData::myData(const long int nobserv, const int _nvals, const double val=0): size(nobserv), nvals(_nvals), clusters(nullptr), nclust(0){
//     //initilize array to be used to populate object (from given value)
//     /*double valArr[nvals];
//     for(int i(0); i<nvals; i++){
//         valArr[i] = val;
//     }*/
//     //initialize data of object with given value
//     clusts = nullptr;
//     data = new Point*[size];
//     for(int i(0); i<size; i++){
//         data[i] = new Point(nvals, val);
//     }
// }
// /*myData::myData(const long int nobserv, const int _nvals, const double **_data): clusters(nullptr), nclust(0){
//     size = nobserv;
//     nvals = _nvals;
//     data = new Point*[size];
//     for(int i(0); i<size; i++){
//         data[i] = new Point(nvals, _data[i]);
//     }
// }*/
// myData::myData(const myData &other){
//     //copy clusts////////////////////////////////////////////////////////////////////
//     size = other.size;
//     if(size != 0){ 
//         data = new Point*[size];
//         for(int i(0); i<size; i++){
//             data[i] = new Point(*other.data[i]);
//         }
//     }
//     else{
//         data = nullptr;
//     }
//     nclust = other.nclust;
//     if(nclust != 0){
//         clusters = new Cluster*[nclust];
//         for(int i(0); i<nclust; i++){
//             clusters[i] = new Cluster(*other.clusters[i]);
//         }
//     }
//     else{
//         clusters = nullptr;
//     }
// }
// myData::~myData(){
//     for(int i(0); i<nclust; i++){
//         delete clusters[i];
//     }
//     delete [] clusters;
//     for(int i(0); i<size; i++){
//         delete data[i];
//     }
//     delete [] data;
//     delete [] clusts;
// }

// const myData & myData::operator=(const myData &rhs){
//     size = rhs.size;
//     if(size != 0){ 
//         data = new Point*[size];
//         for(int i(0); i<size; i++){
//             data[i] = new Point(*rhs.data[i]);
//         }
//     }
//     else{
//         data = nullptr;
//     }
//     nclust = rhs.nclust;
//     if(nclust != 0){
//         clusters = new Cluster*[nclust];
//         for(int i(0); i<nclust; i++){
//             clusters[i] = new Cluster(*rhs.clusters[i]);
//         }
//     }
//     else{
//         clusters = nullptr;
//     }
//     return(rhs); 
// }

// long int myData::getSize() const{return(size);}
// int myData::getNvals() const{return(nvals);}
// int myData::getNclust() const{return(nclust);}

// Point * myData::accessObserv(const int index){
//     return(data[index]);
// }

// void myData::print() const{
//     for(int i(0); i<size; i++){
//         cout << *data[i] << endl;
//     }
// }

// void myData::summary() const{
//     cout << "Number of points in each column: " << size << endl << endl;;
//     for(int i(0); i<nvals; i++){
//         cout << "Column " << i << endl;
//         cout << "Minimum Value: " << getMinValue(i) << endl;
//         cout << "Maximum Value: " << getMaxValue(i) << endl;
//         double mean(getMean(i));
//         cout << "Mean: " << mean << endl;
//         cout << "Standard Deviation: " << getStandDev(i, mean) << endl;
//         cout << endl;
//     }
// }
// double myData::getMinValue(const int col) const{
//     if(size==0){
//         cout << "no data" << endl;
//         exit(1);
//     }
//     double min((*data[0])[col]);    //get value at given column of first Point in data array
//     for(int i(1); i<size; i++){
//         double next((*data[i])[col]);
//         if(next<min){
//             min = next;
//         }
//     }
//     return(min);
// }
// double myData::getMaxValue(const int col) const{
//     if(size==0){
//         cout << "no data" << endl;
//         exit(1);
//     }
//     double max((*data[0])[col]);    //get value at given column of first Point in data array
//     for(int i(1); i<size; i++){
//         double next((*data[i])[col]);
//         if(next>max){
//             max = next;
//         }
//     }
//     return(max);
// }
// double myData::getMean(const int col) const{
//     if(size==0){
//         cout << "no data" << endl;
//         exit(1);
//     }
//     double sum(0);
//     for(int i(0); i<size; i++){
//         sum += (*data[i])[col];
//     }
//     return(sum/size);
// }
// double myData::getStandDev(const int col, const double mean) const{
//     if(size==0){
//         cout << "no data" << endl;
//         exit(1);
//     }
//     double sum(0);
//     for(int i(0); i<size; i++){
//         sum += pow(((*data[i])[col]-mean), 2);
//     }
//     return(sqrt(sum/size));
// }

// istream & operator>>(istream &lhs, myData &rhs){
//     //requires number of observations (size) to be set beforehand
//     cout << "Enter " << rhs.getSize() << " observations of " << rhs.getNvals() << " values:" << endl;
//     for(int i(0); i<rhs.getSize(); i++){
//         lhs >> *rhs.accessObserv(i);
//     }
//     return(lhs);
// }

// bool myData::kMeansClustering(int _nclust, int maxIter, double toler){
//     /*if(nclust != 0){
//         for(int i(0); i<nclust; i++){
//             delete clusters[i];
//         }
//         delete [] clusters;
//         nclust = 0;
//     }
//     nclust = _nclust;
//     clusters = new Cluster*[nclust];
//     for(int i(0); i<nclust; i++){
//         clusters[i] = new Cluster();
//     }*/
//     if(clusts != 0){
//         delete [] clusts;
//         nclust = 0;
//     }
//     nclust = _nclust;
//     clusts = new Clust[nclust];
//     for(int i(0); i<nclust; i++){
//         clusts[i].centroid = Point();
//     }
//     return(1);
// }