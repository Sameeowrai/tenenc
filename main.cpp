#include <iostream>
#include <fstream>

using namespace std;

string Encode(string text){
    string result = "";
    for(int i=0; i < text.length(); i++){
        string newValue;
        if(text[i] == '\n'){
            newValue = "9999";
        }else{
            int AsciiValue = int(text[i]);
            newValue = to_string(AsciiValue*10);
        }
        while(newValue.length()<4){
            newValue = "0" + newValue;
        }
        result += newValue;
    }
    return result;
}

string Decode(string text) {
    string result = "";
    for (size_t i = 0; i < text.length(); i += 4) {
        int value = stoi(text.substr(i, 4)) / 10;
        if(value==9999){
            result += "\n";
        }else{
            result += static_cast<char>(value); 
        }
    }
    return result;
}

int Find(string str, char* argv[], int size){
    for(int i=0; i < size; i++){
        if(string(argv[i]) == str){
            return i;
        }
    }
    return -1;
}

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

    string result = "";
    switch (op)
    {
        case 0:{
            result = Encode(text);
            break;
        }
            
        
        case 1:{
            result = Decode(text);
            break;
        }

        default:
            break;
    }

    int outIndex = Find("-out", argv, argc);
    if (outIndex != -1 && outIndex + 1 < argc) { 
        ofstream outFile(argv[outIndex + 1]);
        if (outFile.is_open()) {
            outFile << result;
            outFile.close();
        }
    }
}
