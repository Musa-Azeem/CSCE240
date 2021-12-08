#include <iostream>
#include <fstream>
#include <string>
#include "myData.h"

using namespace std;

int main(int argc, char** argv)
{
    ifstream in_file;
    ofstream out_file;
    string inFile, outFile, Input;
    int obs, dim;
    double fitness(0);

    if(argc != 3) {
       cout << "Usage for " << argv[0] << ":" << endl;
       cout << argv[0] << " <InputFileName> <OutputFileName>" << endl;
       exit(0);
    }
    inFile = argv[1];
    outFile = argv[2];

    cout << "Enter the number of observations and the number of variables: ";
    cin >> obs >> dim;

    in_file.open(inFile);
    if (in_file.fail())
    {
        cout << "Error openning the file " << inFile << " \n";
        exit(1);
    }

    out_file.open(outFile);
    if (out_file.fail())
    {
        cout << "Error openning the file " << outFile << " \n";
        exit(1);
    }

    myData data1;
    myData data2(obs, dim, 0);

    in_file >> data2;
    data2.Summary();
    fitness = data2.kMeansClustering(2, 100, 0.001);
    cout << "K-Means Cluster with 2 clusters produced a fitness of " << fitness;
    cout << endl;
    //kMeansClustering.ClusterSummary();
    data2.ClusterSummary();

    myData data3(data2);
    out_file << data2;

    data1 = data2;

    in_file.close();
    out_file.close();

    return(0);
}
