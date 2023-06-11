#include "unlimited.hpp"

#ifndef GETCONTENTFROMSIGNAL_H
#define GETCONTENTFROMSIGNAL_H

class GetContentFromSignal
{
public:
    int countON ;
    int countOFF;
    string dash;
    string dot;
    string message;
    string content;
    vector <string> signalMessage;

    
    void checkONandOFF (vector <double> m, int j);
    void takeAction(int dashValue, int dotValue, int IWS);
    void convertMorseCode (string morseCodeParameter);
    void displayContent();
};

#endif /* decimate_hpp */