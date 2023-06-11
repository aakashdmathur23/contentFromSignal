// Function binfilewrite()
//
// A function that writes to a binary data file
//
// Inputs: vector<double>
// Outputs: none
///Users/staff/COMP1712_ExamplePrograms/Twovars/main.c
// Developed for the Programming for Engineers (ELEE1147) course
//
// Dr D I Armour - Chelu / November 2020

#include "unlimited.hpp"
#include "binfilewrite.hpp"

void writeBinaryFile(struct dataContent writedata)
{

    ofstream file;
    // This absolute path will have to edited to where you wish it to be saved
    file.open("Processed_42_20wpm_Short.bin", std::ios::out | std::ios::binary);
    
    // check open file for write
	if (!file.is_open()) 
    {
		cout << "Error in open file './out.bin'" << endl;
	}
    size_t size = writedata.datasize;
    vector<double> sum(size);
    sum[0] = 0.0;

    for (int i = 0; i < size; i++)
    {
        sum[i] = writedata.memorydata[i];
        //cout << "Value of sum[] in binfilewrite() is: " << sum[i] << endl;
    }

    //DoubleArrayPtr sum = writedata.data;
    long int filelength = writedata.sizeoffile /  BUFFER_SIZE;
    
    file.write(reinterpret_cast<char*>(&sum[0]), filelength);
    
    file.close();

} // End of binfilewrite()
