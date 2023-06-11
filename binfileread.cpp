// Function binfileread()
// A function that reads in a binary data file
// Inputs: pointer to a char
// Outputs: none

#include "unlimited.hpp"
#include "binfileread.hpp"
#include "decimate.hpp"

DoubleArrayPtr memoryBlock;
bool memoryAllocated;

struct dataContent readBinaryFile(CharArrayPtr binfile)
{

    int numberofvalues = 0;
    struct dataContent datareturn;
    
	ifstream file(binfile, ios::in|ios::binary|ios::ate);		//opening a file stream with an i/o mode parameter.
	
	long int filesize = file.tellg(); 							//getting current position of the cursor.
	numberofvalues = (int)filesize / sizeof(double);
	cout << "Binary File size is: " << filesize << endl;
	cout << "The number of values from the binary file is: " << numberofvalues << endl;
		
	memoryBlock = new double [filesize];
	memoryAllocated = true;
	file.seekg (0, ios::beg); 									//moving our get cursor by x from the begining.
	file.read(reinterpret_cast<char*>(memoryBlock), filesize); 	//reading the file

		if (!file) 												//if there is an error occured
			{
        			
        		file.gcount(); 									//returns the number of bytes read.
				cout << file.gcount() << endl;
			cout << "Error opening the file" << endl;
        		file.clear(); 									//will reset the stream state so it is usable again.
    		}
		else
			{
				// cout << "No error occured" << endl;
			}
		
	file.close();												//closing the file
	cout << "The complete binary file content is in memory" << endl;
	cout << endl;
        
    datareturn.numberofvalues = numberofvalues;
    datareturn.datasize = numberofvalues / BUFFER_SIZE;
    datareturn.sizeoffile = filesize;
    datareturn.memorydata = memoryBlock;
        
    return datareturn;
    
} // End of binfileread()



// Copyright - David and Aakash
