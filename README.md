# Get-Content-From-Signal
This a program that takes a file from the audio archive and retrieves the content within.  The content should be then written back to the archive.




#MAC user Instructions

1. Go to terminal.
2. Paste this - git clone git@github.com:taufique-06/Get-Content-From-Signal.git
3. Go to the folder where you cloned the repo.
4. Paste this - clang++ -std=c++11 -stdlib=libc++ binfileread.cpp binfilewrite.cpp decimate.cpp main.cpp moments.cpp trim.cpp getContentFromSignal.cpp -o main.exe
5. And this - ./main.exe 42_10wpm.bin

 
