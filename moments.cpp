// Function moments()
//
// A function that applies some statistical moments on a data array
//
// Inputs: pointer to a structure of different data types and sizes
// Outputs: none
//
// Adapted from the moments() function given by
// "Numerical Recipes in C" (second edition)
// by W.H.Press, S.A.Teukolsky, W.T.Vettering, B.P.Flannery
//
// Dr D I Armour - Chelu / February 2009
// Further modified for Programming for Engineers (ELEE1147) November 2020

#include "unlimited.hpp"
#include "moments.hpp"

void moments(struct dataContent processing, struct Statistics* pmoments)
{

  int j, k;
  int arraysize = processing.numberofvalues;
  //int arraysize = 160;
    cout << "Number ofvalues in moments() is: " << arraysize << endl;
  double sum = 0.0, abstotal = 0.0, p =0.0, mean = 0.0,
    avedev = 0.0, skewness = 0.0, kurtosis = 0.0, epsilon = 0.0,
    variance = 0.0, stddev = 0.0;
    
  //size_t size_short = 480;
  //vector<double> sum_short(size_short);
  //for(int s = 0 ; s < 480 ; ++s)
  //{
    //sum_short[s] = dataprocess.memorydata[s];
  //}
    
  // First time around then get the mean value
  for(j = 4 ; j < arraysize ; j++)
  {
	sum += processing.memorydata[j];
  }

  mean = sum / arraysize;
  pmoments->mean = mean;

  // Second time around to get the first (absolute), second, third, and
  // fourth moments of the deviation from the mean
  for(k = 4 ; k < arraysize ; k++)
  {
	avedev = fabs(abstotal = processing.memorydata[k] - mean);
	epsilon += abstotal;
	variance += (p = abstotal * abstotal);
	skewness += (p *= abstotal);
    kurtosis += (p *= abstotal);
  }

  // Corrected two-pass formula for variance and then put the pieces
  // together according to the conventional definitions
  avedev /= arraysize;
  variance = (variance - epsilon * epsilon / arraysize) / (arraysize);
  stddev = sqrt(variance);
  pmoments->variance = (variance - epsilon * epsilon / arraysize) / (arraysize);
  pmoments->stddev = sqrt(variance);

  if(variance > 0)
  {
	skewness /= (arraysize * (variance) * (stddev));
	//pmoments->kurtosis = (kurtosis / (arraysize * variance * variance)) - 3.0;
    pmoments->kurtosis = (kurtosis / (arraysize * variance * variance));
  }
  else
  {
	cout << "No skewness / kurtosis when variance = 0 (in moment)" << endl;
  }

} // End of moments()
