# Lab 2 Branch Prediction
In this lab, I simulate a correlating branch predictor that makes use of 2-bit saturating counters. 
## Branch Predictor Architecture
My design consists of 2m+k 2-bit saturating counters indexed using m LSBs of each branch instruction and a k bit Branch History Register (BHR) that records the outcomes of the previous k branches. Each 2-bit saturating predictor starts in the 11 (Predict Taken with High Confidence) state and is updated as per the finite state machine discussed in Lecture 12. Further, you can assume that the BHR is initialized assuming the previous k branches were Taken.  
The values of m and k are specified in a config file config.txt. 
The maximum values of m = 20 and k = 8.
## Config File
The config file config.txt contains a single line with the value of m and k. A sample file for m=12 and k=2 is provided.
## Trace File
The trace file, trace.txt, contains one branch per line. Each line has the PC for the corresponding branch (in hex format) followed by a single bit indicating Taken (1) or Not Taken (0). A sample trace file is provided.  A sample trace file is provided.
## Output Format
The output from your simulator should be a file trace.out that has one line per branch. Each line has a single bit which indicates whether that branch was predicted as Taken (1) or Not Taken (0).
## How to compile
Use g++ to compile the source code.
the config.txt and trace.txt should be in the same path with the source code.
in virtual machine, use "./branchsimulator config.txt trace.txt" to execute the simulator, the terminal will also output the value of m and k, as well as the miss prediction rate.
