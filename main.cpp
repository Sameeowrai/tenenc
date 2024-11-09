#include "tenenc.hpp"

int main(int argc, char* argv[]) {
    int op;
    if (string(argv[1]) == "-encrypt") {
        op = 0;
    } else if (string(argv[1]) == "-decrypt") {
        op = 1;
    }

    string text;
    string filePath = argv[2];
    ifstream file(filePath);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            text += line;
        }
    }else{
        text = argv[2];
    }
    Tenenc tenenc;
    string result = "";
    switch (op)
    {
        case 0:{
            result = tenenc.encode(text);
            break;
        }
            
        
        case 1:{
            result = tenenc.decode(text);
            break;
        }

        default:
            break;
    }

    int outIndex = tenenc.find("-out", argv, argc);
    if (outIndex != -1 && outIndex + 1 < argc) { 
        ofstream outFile(argv[outIndex + 1]);
        if (outFile.is_open()) {
            outFile << result;
            outFile.close();
        }
    }
}
