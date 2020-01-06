#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <bitset>

using namespace std;

int main (int argc, char** argv) {
	ifstream config;
	config.open(argv[1]);

    float n = 0;
	float count = 0;

	int m, k;
	config >> m >> k;
	cout<<"m = "<<m<<"; "<<"k = "<<k<<endl;

	config.close();

	ofstream out;
	string out_file_name = string(argv[2]) + ".out";
	out.open(out_file_name.c_str());
	
	ifstream trace;
	trace.open(argv[2]);
	unsigned long pc; 
	bool taken;    

    vector<int> bhr(k);
	for (int a=0; a<k; a++){                        // initialize BHR
		bhr[a] = 1;
	}

	int rows = pow(2, m);
	int columns = pow(2, k);
    vector<vector<int> > PHT(rows,vector<int>(columns));
    for(int i=0; i<rows; i++){                      // initialize PHT
        for(int j=0; j<columns; j++){
            PHT[i][j] = 3;
        }
    }

    trace >> std::hex >> pc >> taken;

	while (!trace.eof()) {
		
		bool prediction;
		prediction = true;		
		
		bitset<32> PC = bitset<32> (pc);
		int addr = stoi(PC.to_string().substr(32-m, m), 0, 2);

        string str;
		for (int i=0; i<k; i++){
			str += to_string(bhr[i]);
		}	
        int BHR = stoi(str, 0, 2);


		if (PHT[addr][BHR] >= 2){                   // predict
			prediction = true;
		}else{
			prediction = false;
		}
			
		if (taken){                                      // update PHT
			if (PHT[addr][BHR] == 3){
				PHT[addr][BHR] = 3;
			}else if(PHT[addr][BHR] == 2){
				PHT[addr][BHR] = 3;
			}else if(PHT[addr][BHR] == 1){
				PHT[addr][BHR] = 3;
			}else{
				PHT[addr][BHR] = 1;
			}
		}else{
			if (PHT[addr][BHR] == 3){
				PHT[addr][BHR] = 2;
			}else if(PHT[addr][BHR] == 2){
				PHT[addr][BHR] = 0;
			}else if(PHT[addr][BHR] == 1){
                PHT[addr][BHR] = 0;
			}else{
				PHT[addr][BHR] = 0;
			}
		}
		bhr.erase(bhr.begin()+k-1);			           // update BHR
		bhr.insert(bhr.begin(), taken);

		n++;
		if (taken != prediction){
			count++;
		}

		out << prediction << endl;
		trace >> std::hex >> pc >> taken;
	}

	float rate = count/n;
	cout << "miss prediction rate: "<< rate << endl;

	trace.close();	
	out.close();
}
