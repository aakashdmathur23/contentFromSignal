// General use header file for unlimited

#ifndef UNLIMITED_H
#define UNLIMITED_H

#include <iostream>
using namespace std;

#include<valarray>
using namespace std;

#include<fstream>
using namespace std;

#include<string>
using namespace std;

#include<vector>
using namespace std;

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include<list>
#include <sys/stat.h>

// Edit this value to experiment with the data block size
// for the processing of data blocks
#define BUFFER_SIZE 240

typedef double* DoubleArrayPtr;
typedef char* CharArrayPtr;
// A structure is group of data elements grouped together under one name. These data elements known as members

// Declares a structure types, called Statistics, and defines it having 4 members: mean, variance, stddev, kurtosis each of a different fundamental type.

//This declaration creates a new type (Statistics), which is then used to declare three objects (variables) of this type


struct Statistics
{
    double mean;
    double variance;
    double stddev;
    double kurtosis;
};

struct dataContent
{
    DoubleArrayPtr data;
    DoubleArrayPtr memorydata;
    int numberofvalues;
    int datasize;
    long int sizeoffile;
};

struct Morse
{
    string alphabet;
    string morseCode;
    Morse(string alphabetName, string morseCodeValue) :
            alphabet(alphabetName), morseCode(morseCodeValue)
    {
    }
};

struct dataContent decimate(struct dataContent);
struct dataContent readBinaryFile(CharArrayPtr);
void binfilewrite(struct dataContent);
void moments(struct dataContent, struct Statistics*);


#endif /* unlimited_hpp */
