#include "getContentFromSignal.hpp"
#include "trim.hpp"

void GetContentFromSignal::checkONandOFF (vector <double> m, int j)
{
	
	
    if (m[j] > 0.5)                                     // checking whether value is higer than 0.5
        {  
            countON ++;                                 // counting how many blocks are ON
            countOFF =0;                                // countOFF has been set to 0 when counting ON values.
                    
        }
        else 
        {
            countOFF++;                                 // counting how many blocks are OFF
            countON = 0;                                // countON has been set to 0 when counting OFF values.
        }
}

void GetContentFromSignal::takeAction(int dashValue, int dotValue, int IWS)
{
    if (countON == dashValue)                       /* if signal is ON for 9 consecutives blocks (Assuming 42_20wpm.bin 
							                            file is passed, for different file, might have differnt baud rate, 
							                            will have different consecutive blocks ) */ 
        {       
            dash = "-";                                 // initialize the dash to "-"
            message += dash;                            /* adding the value with the previous value (which is dash) in a 
							                            variable called message */
            // cout << "" << endl;
            // cout << "Dash" << endl;
            // cout << "" << endl;     
        }
                    
        if (countON == dotValue)                        // if signal is ON for 3 consecutives blocks
        {
            dot = ".";                                  // initialize the dot to "."
            message += dot;                             // adding the value with the previous value (which is dot) in a variable called message
            // cout << "" << endl;
            // cout<< "dot" << endl;     
            // cout << "" << endl;
        }
        else if (countOFF == dotValue)                  // if signal is OFF for 3 consecutives blocks
        {
            // cout << " " << endl;
            // message += "";                           
            // cout << "It is IES (Space between two components)" <<endl;
            // cout <<  "" << endl;
        }    
            
        else if(countOFF == dashValue)                  // if signal is OFF for 9 consecutives blocks
        {
            // cout << "It is ICS (Space between two letters)" <<endl;
            message = trim(message);                            //calling the trim function
            // cout << "Message with trimming: " << message << endl;
                        
                for (int i =0; i < message.length(); i++) // using FOR loop
                    {
                        char messagefront = message[i];         //getting the first letter of the word
                        std::string s(1, messagefront);         //making it string from char
                        char messagefronttwo = message[i + 1];  //getting the second letter of the word
                        std::string stwo(1, messagefronttwo);   //making it string from char
                        string firstTwoCharacter = s + stwo;    //concatenating first and second letter of the word
                        // cout << firstTwoCharacter << endl;

                        if (firstTwoCharacter == ".-")          //if first and second letter is ".-"
                            {
                                message.erase(i, 1);            //then erase the first letter
                            }
                    }          
                        // cout << "Message after erase: " <<message<< endl;
                        convertMorseCode(message);              /* calling the convertMorseCode function to get letter to 
								produce word */
                        // cout << content << endl;
                        message = "";                           /* Once all the above commands are done, empty the message 
								variable for holding another new letter and word */
                        // cout <<  "" << endl;
        }
        else if(countOFF == IWS)                                // if the signal is OFF for 21 blocks
        {
            // cout << "It is IWS (Space between two words)" << endl;
            signalMessage.push_back(" ");                       //add a space for having a space between words
            message += "   ";
            // cout <<  "" << endl;
            content += " ";
        }

}

void GetContentFromSignal::convertMorseCode (string morseCodeParameter)
{
    
    // created a list for having all Morse Code for different number and letter
    std::list <Morse> listofMorse = {Morse("A", ".-"), Morse("B", "-..."), Morse("C", "-.-.") , Morse("D", "-.."), 
                                     Morse("E", "."), Morse("F", "..-."), Morse("G", "--."), Morse("H", "...."), 
                                     Morse("I", ".."), Morse("J", ".---"), Morse("K", "-.-"), Morse("L", ".-.."), 
                                     Morse("M", "--"), Morse("N", "-."), Morse("O", "---"), Morse("P", ".--."), 
                                     Morse("Q", "--.-"), Morse("R", ".-."), Morse("S", "..."), Morse("T", "-"), 
                                     Morse("U", "..-"), Morse("V", "...-"), Morse("W", ".--"), Morse("X", "-..-"), 
                                     Morse("Y", "-.--"), Morse("Z", "--.."), Morse("1", ".----"), Morse("2", "..---"), 
                                     Morse("3", "...--"),Morse("4", "....-"), Morse("5", "....."), Morse("6", "-...."), 
                                     Morse("7", "--..."), Morse("8", "---.."), Morse("9", "----."), Morse("0", "-----")};

    // 
    std::list<Morse>::iterator it;
        for (it = listofMorse.begin(); it != listofMorse.end(); it++)
        {
            // Accessing the object through iterator
            string alphabet = it->alphabet;
            string morseCode = it->morseCode;
            if (morseCode == morseCodeParameter) // checking if the parameter that is passed match with our stored morse code
            {
                    // cout << alphabet <<endl;
                    signalMessage.push_back(alphabet); // if there is a match, add it in the vector called signalMessage
                    
            }
            
        }
      
}



// copyright - Aakash Dutt Mathur.




void GetContentFromSignal::displayContent()
{
     cout << " " << endl;
        cout << "The content of the borij_20wpm.bin file is: " << endl;
        cout << " " << endl;
        for (auto ac = signalMessage.begin(); ac != signalMessage.end(); ++ac) 
        cout <<  *ac << "";                                                          // displaying our content
        // cout << "\e[3m" << *ac << "";                                            // comment out to see the content as a BOLD
        cout << " " << endl;
        cout << " " << endl;
}
