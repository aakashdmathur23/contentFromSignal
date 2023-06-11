// Function main() : Defines the entry point for the console application.
//
// A program to bring in binary data from a file and assign that data to an
// array for the purpose of program development.
//
// Usage: unlimited 'file'.bin
//
// Developed for the Programming for Engineers 3 course (ANSI C)
// June 2001
//
// Adapted for the Programming for Engineers 4 course
// January 2005
//
// Further adapted for the Programming for Software Systems course in C++
// February 2007 / 2008
//
// Further adaption in C++ February 2009
// Additional adaptation for Virtual Week exercise February 2012
// Further adaption for Programming for Engineers (ELEE1147) January 2019
// Modified for Programming for Engineers (ELEE1147) November 2020
//
// Dr D I Armour-Chelu / School of Engineering

#include "unlimited.hpp"
#include "binfileread.hpp"
#include "decimate.hpp"
#include "binfilewrite.hpp"
#include "getContentFromSignal.hpp"

int main(int argc, char* argv[])
{
	
    if(argc == 1)
	{

		cout << "Usage: " << argv[0] << "<data file>" << endl;
		exit(0);

	}

	if(argc > 2)
	{
		cout << "Too many input parameters" << endl;
		cout << "Usage: " << argv[0] << " <data file>" << endl;
		exit(0);
	}
	
	// Read the data file
    struct dataContent datareturn;
    datareturn = readBinaryFile(argv[1]);
    
    // Process the data file
    struct dataContent dataprocessed;
    dataprocessed = decimate(datareturn);
    
    // Write the processed data to file
    writeBinaryFile(dataprocessed);

	return 0;

} // End of main()
