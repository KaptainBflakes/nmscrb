#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
//removes unwanted strings from filenames listed in a text file.
using namespace std;
using namespace std::filesystem;
int main(int argc,char**argv){
	//argv[1] is the string to scrub, argv[2] is the list
	fstream f;f.open(argv[2]);
	vector<string> worklist;
	if(f.good()){//loads worklist file to memory
		char c;string out="";
		while(f.get(c)){
			if(c=='\n'){worklist.push_back(out);out="";}
			else{out+=c;}
		}
	}f.close();
	string rmstr=argv[1];//string to remove from all files
	for(int i=0;i<worklist.size();i++){
		string out;
		for(int c=0;c<worklist[i].size();c++){
			if(worklist[i][c]==rmstr[0]){
				bool wrong = false;
				int l;
				for(l=1;l<rmstr.size();l++){
					if(worklist[i][c+l]!=rmstr[l]){
						wrong=true;break;
					}
				}
				if (!wrong){
					c+=l;
				}
			}
			out+=worklist[i][c];
		}
		try{
			rename(worklist[i], out);
		}catch(...){
			cout<<"Path at line \""<<to_string(i)<<"failed to rename.\n";
		}
	}
}