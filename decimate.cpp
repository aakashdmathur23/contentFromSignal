#include "unlimited.hpp"
#include "decimate.hpp"
#include "moments.hpp"
#include "binfilewrite.hpp"
#include "getContentFromSignal.hpp"
#include "trim.hpp"

struct dataContent decimate(struct dataContent dataprocess)
{
    GetContentFromSignal getContent;

    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, p = 0, q = 0, r = 0, s = 0, t = 0; //Interger varibable declaration
    
   
	cout << "Total number of blocks is: " << dataprocess.datasize << endl;
    cout << endl;
    
    size_t size = dataprocess.datasize; 

    double calBaudRate = size/ BUFFER_SIZE;
    int dotValue = round((calBaudRate /3) + 1);
    int dashValue = dotValue * 3;
    int IWS = dotValue * 7;

    vector<double> sum(size); 
    vector<double> mean(size); 
    vector<double> secondmoment(size); 
    vector<double> fourthmoment(size);
    vector<double> kurtosis(size);

    
    sum[0] = 0.0;
    secondmoment[0] = 0.0;
    fourthmoment[0] = 0.0;
    kurtosis[0] = 0.0;
        
    // Finding statistical moments for the data: mean, second- and fourth-order moments, and kurtosis
    for(j = 0 ; j < size ; ++j)
	{
         
		// Mean Value
        for(i = k ; i < (k + BUFFER_SIZE) ; i++)
		{
			sum[j] = sum[j] + abs(dataprocess.memorydata[i]);
            //sum[j] = sum[j] + dataprocess.memorydata[i];
		}
        
		mean[j] = sum[j] / BUFFER_SIZE;
		cout << "The mean of the absolute value of data in block " << (j + 1) << " is: " << mean[j] << endl;   
        
        getContent.checkONandOFF(mean, j);                  //calling checkONandOFF function to count how many blocks are ON and OFF
        getContent.takeAction(dashValue, dotValue, IWS);    //calling takeAction function to take actions based on the ON and OFF

		k = k + BUFFER_SIZE;
        
        // Second Moment around the Mean:
        for(l = m ; l < (m + BUFFER_SIZE) ; l++)
        {
            secondmoment[j] = (secondmoment[j] + pow((dataprocess.memorydata[l] - mean[j]), 2));
        }
        
        secondmoment[j] = secondmoment[j] / BUFFER_SIZE;
        //cout << "The second moment around the mean in block " << (j + 1) << " is: " << secondmoment[j] << endl;
        m = m + BUFFER_SIZE;
        
        // Fourth Moment around the Mean:
        for(n = p ; n < (p + BUFFER_SIZE) ; n++)
        {
            fourthmoment[j] = (fourthmoment[j] + pow((dataprocess.memorydata[n] - mean[j]), 4));
        }
        
        fourthmoment[j] = fourthmoment[j] / BUFFER_SIZE;
        //cout << "The fourth moment around the mean in block " << (j + 1) << " is: " << fourthmoment[j] << endl;
        p = p + BUFFER_SIZE;
        
        // Kurtosis Value for Block
        for(q = r ; q < (r + BUFFER_SIZE) ; q++)
        {
            kurtosis[j] = (fourthmoment[j] / pow((secondmoment[j]), 2));
        }
        
        // cout << "The kurtosis value in block " << (j + 1) << " is: " << kurtosis[j] << endl;
        
        for (s = t; s < (t + BUFFER_SIZE); s++)
        {
            dataprocess.memorydata[j] = mean[j];
        }  
    }  
   
    getContent.displayContent(); // displaying the content

    return dataprocess;
    	
} // End of decimate()
