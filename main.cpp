#include <bits/stdc++.h>
#include <dirent.h>
using namespace std;
class codeWriterMain{
    int eCounter = 0, gCounter=0, lCounter=0, labelCounter=0;
    string fileName;
    fstream file;

public:
    explicit codeWriterMain(string &fi){
        string temp = fi+"asm";
        fileName = fi;
        file.open(temp, ios::out);
        if(!file.is_open()){
            cout<<"***************  ERROR  ******************"<<endl;
            exit(911);
        }
    }

    ~codeWriterMain()
    {
        file.close();
    }

    void pushStack(vector<string> &data, vector<string> &pushData, string &str){
//        for(auto &a : data){
//            cout<<a<<" ";
//        }
//        cout<<endl;
        transform(data[1].begin(), data[1].end(), data[1].begin(), ::tolower);
        int index = 0, tem = 5;
        istringstream(data[2]) >> index;
        tem += index;
        file<<"//   "<<str<<"\n";
        //  Local segment command
        if(data[1]=="local"){
            file<<"@LCL\nD=M\n@"<<index<<"\n";
        }
            //  ARGUMENT segment command
        else if(data[1]=="argument"){
            file<<"@ARG\nD=M\n@"<<index<<"\n";
        }
            //  THIS segment command
        else if(data[1]=="this"){
            file<<"@THIS\nD=M\n@"<<index<<"\n";
        }
            //  THAT segment command
        else if(data[1]=="that"){
            file<<"@THAT\nD=M\n@"<<index<<"\n";
        }
            //  TEMPORARY segment command
        else if(data[1]=="temp"){
            file<<"@"<<tem;
            file<<"\nD=M\n@SP\nAM=M+1\nA=A-1\nM=D\n";
            return;
        }
            //  CONSTANT segment command
        else if(data[1]=="constant"){
            file<<"@"<<index;
            file<<"\nD=A\n@SP\nAM=M+1\nA=A-1\nM=D\n";
            return;
        }
            //  POINTER segment Command
        else if(data[1]=="pointer"){
            if(index == 0){
                file<<"@THIS"<<endl;
            }
            else if(index == 1){
                file<<"@THAT"<<endl;
            }
            file<<"D=M"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M+1"<<endl;
            file<<"A=A-1"<<endl;
            file<<"M=D"<<endl;
            return;
        }
            //  STATIC segment command
        else if(data[1] == "static"){
            file<<"@"<<fileName<<index<<endl;
            file<<"D=M"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M+1"<<endl;
            file<<"A=A-1"<<endl;
            file<<"M=D"<<endl;
            return;
        }
        for(auto& x : pushData){
            file<<x<<endl;
        }
    }

    void  popStack(vector<string> &data, vector<string> &popData, string &str){
//        for(auto &a : data){
//            cout<<a<<" ";
//        }
//        cout<<endl;
        transform(data[1].begin(), data[1].end(), data[1].begin(), ::tolower);
        int index = 0, tem = 5;
        istringstream(data[2]) >> index;
        tem += index;
        file<<"//   "<<str<<"\n";
        if(data[1] == "local"){
            file<<"@LCL"<<endl;
            file<<"D=M"<<endl;
            file<<"@"<<index<<endl;
        }
        else if(data[1] == "argument"){
            file<<"@ARG"<<endl;
            file<<"D=M"<<endl;
            file<<"@"<<index<<endl;
        }
        else if(data[1] == "this"){
            file<<"@THIS"<<endl;
            file<<"D=M"<<endl;
            file<<"@"<<index<<endl;
        }
        else if(data[1] == "that"){
            file<<"@THAT"<<endl;
            file<<"D=M"<<endl;
            file<<"@"<<index<<endl;
        }
        else if(data[1] == "pointer"){
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            if(index == 0)file<<"@THIS"<<endl;
            else file<<"@THAT"<<endl;
            file<<"M=D"<<endl;
            return;
        }
        else if(data[1] == "temp"){
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"@"<<tem<<endl;
            file<<"M=D"<<endl;
            return;
        }
        else if(data[1] == "static"){
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"@"<<fileName<<index<<endl;
            file<<"M=D"<<endl;
            return;
        }
        for(auto &x : popData){
            file<<x<<endl;
        }
    }

    void arithmeticOperations(vector<string> &data, string &str){
//        for(auto &a : data){
//            cout<<a<<" ";
//        }
//        cout<<endl;
        file<<"//   "<<str<<"\n";
        if(data[0]=="add"){
            //file<<"//Addition"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"A=A-1"<<endl;
            file<<"M=D+M"<<endl;
        }
        else if(data[0]=="sub"){
            //file<<"//Subtraction"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"A=A-1"<<endl;
            file<<"M=M-D"<<endl;
        }
        else if(data[0]=="neg"){
            //file<<"//Negation"<<endl;
            file<<"@SP"<<endl;
            file<<"A=M-1"<<endl;
            file<<"M=-M"<<endl;
        }
        else if(data[0]=="and"){
            //file<<"//Bitwise AND"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"A=A-1"<<endl;
            file<<"M=D&M"<<endl;
        }
        else if(data[0]=="or"){
            //file<<"//Bitwise OR"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"A=A-1"<<endl;
            file<<"M=D|M"<<endl;
        }
        else if(data[0]=="not"){
            //file<<"//Complement or Bitwise NOT"<<endl;
            file<<"@SP"<<endl;
            file<<"A=M-1"<<endl;
            file<<"M=!M"<<endl;
        }
        else if(data[0]=="eq"){
            //file<<"//Equal Operator"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"A=A-1"<<endl;
            file<<"D=D-M"<<endl;
            file<<"M=-1"<<endl;
            file<<"@EQUAL_END_LABEL_"<<eCounter<<endl;
            file<<"D;JEQ"<<endl;
            file<<"@SP"<<endl;
            file<<"A=M-1"<<endl;
            file<<"M=0"<<endl;
            file<<"(EQUAL_END_LABEL_"<<eCounter<<")"<<endl;
            eCounter++;
        }
        else if(data[0]=="gt"){
            //file<<"//Greater than Operator"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"A=A-1"<<endl;
            file<<"D=D-M"<<endl;
            file<<"M=0"<<endl;
            file<<"@GREATER_END_LABEL_"<<gCounter<<endl;
            file<<"D;JGT"<<endl;
            file<<"@SP"<<endl;
            file<<"A=M-1"<<endl;
            file<<"M=-1"<<endl;
            file<<"(GREATER_END_LABEL_"<<gCounter<<")"<<endl;
            gCounter++;
        }
        else if(data[0]=="lt"){
            //file<<"//Less than Operator"<<endl;
            file<<"@SP"<<endl;
            file<<"AM=M-1"<<endl;
            file<<"D=M"<<endl;
            file<<"A=A-1"<<endl;
            file<<"D=D-M"<<endl;
            file<<"M=0"<<endl;
            file<<"@LESS_END_LABEL_"<<lCounter<<endl;
            file<<"D;JGT"<<endl;
            file<<"@SP"<<endl;
            file<<"A=M-1"<<endl;
            file<<"M=-1"<<endl;
            file<<"(LESS_END_LABEL_"<<lCounter<<")"<<endl;
            lCounter++;
        }
    }

    void branchOperations(vector<string> &data, string &str){
        file<<"//   "<<str<<"\n";
        if(data[0]=="label"){
            file<<"($"<<data[1]<<")\n";
        }
        else if(data[0]=="goto"){
            file<<"@$"<<data[1]<<"\n0;JMP";
        }
        else if(data[0]=="if-goto"){
            file<<"@SP\nAM=M-1\nD=M\n@$"<<data[1]<<"\nD;JNE\n";
        }
    }

    void functionCalling(vector<string> &data, string &str){
        file<<"//   "<<str<<"\n";
        int args=0;
        if(data[0] == "function" || data[0] == "call"){
            istringstream(data[2]) >> args;
        }
        if(data[0]=="function"){
            file<<"("<<fileName<<data[1]<<")\n";
            for(int i=0;i<args;i++){
                file<<"@"<<i<<"\nD=A\n@LCL\nA=D+M\nM=0\n";
            }
        }
        else if(data[0]=="call"){
            file<<"@$ret."<<labelCounter<<"\nD=A\n@SP\nAM=M+1\nA=A-1\nM=D\n";
            file<<"@LCL\n";
            file<<"D=A\n@SP\nAM=M+1\nA=A-1\nM=D\n";
            file<<"@ARG\n";
            file<<"D=A\n@SP\nAM=M+1\nA=A-1\nM=D\n";
            file<<"@THIS\n";
            file<<"D=A\n@SP\nAM=M+1\nA=A-1\nM=D\n";
            file<<"@THAT\n";
            file<<"D=A\n@SP\nAM=M+1\nA=A-1\nM=D\n";

            file<<"@5\nD=A\n@SP\nD=A-D\n@"<<args<<"\nD=D-A\nARG=D\n";
            file<<"@SP\nD=M\n@LCL\nM=D\n";
            file<<"@"<<data[1]<<"\n0;JMP\n";
            file<<"($ret."<<labelCounter++<<")\n";
        }
        else if(data[0]=="return"){
            file<<"@R14\nM=LCL\n";
            file<<"@5\nD=A\n@R14\nD=M-D\n@R15\nM=D\n";
            file<<"@SP\nA=M-1\nD=M\n@ARG\nA=M\nM=D\n";
            file<<"D=A+1\n@SP\nM=D\n";
            file<<"@R14\nAM=M-1\nD=M\n@THAT\nM=D\n";
            file<<"@R14\nAM=M-1\nD=M\n@THIS\nM=D\n";
            file<<"@R14\nAM=M-1\nD=M\n@ARG\nM=D\n";
            file<<"@R14\nAM=M-1\nD=M\n@LCL\nM=D\n";
            file<<"@R15\nA=M\n0;JMP\n";
        }
    }
};
class Parser{
public:
    static vector<string>parserString(string str){
        vector<string> v;
        int ds, comment=0, i=0;
        string temp, otp;
        ds = str.find("//");
        if(ds>0)comment = 1;
        if(str.empty() || ds == 0)return v;
        while(i<str.size()){
            if(comment && i==ds){
                if(temp.empty())continue;
                v.push_back(temp);
                return v;
            }
            if(str[i]==' '){
                if(temp.empty())continue;
                v.push_back(temp);
                temp = "";
                i++;
                continue;
            }
            temp+=str[i];
            i++;
        }
        if(temp.empty())return v;
        v.push_back(temp);
        return v;
    }
};

void codeWriter(codeWriterMain &obj, string &str, vector<string> &data){
    transform(data[0].begin(), data[0].end(), data[0].begin(), ::tolower);
    vector<string>pushVector, popVector;
    pushVector.emplace_back("D=D+A");
    pushVector.emplace_back("A=D");
    pushVector.emplace_back("D=M");
    pushVector.emplace_back("@SP");
    pushVector.emplace_back("AM=M+1");
    pushVector.emplace_back("A=A-1");
    pushVector.emplace_back("M=D");

    popVector.emplace_back("D=D+A");
    popVector.emplace_back("@R13");
    popVector.emplace_back("M=D");
    popVector.emplace_back("@SP");
    popVector.emplace_back("AM=M-1");
    popVector.emplace_back("D=M");
    popVector.emplace_back("@R13");
    popVector.emplace_back("A=M");
    popVector.emplace_back("M=D");
//    for(auto &x:data)cout<<x<<" ";
//    cout<<endl;
    if(data[0]=="push")
        obj.pushStack(data, pushVector, str);
    else if(data[0]=="pop")
        obj.popStack(data, popVector, str);
    else if(data[0]=="goto" || data[0]=="if-goto" || data[0]=="label")
        obj.branchOperations(data, str);
    else if(data[0]=="function" || data[0]=="call" || data[0] == "return")
        obj.functionCalling(data, str);
    else
        obj.arithmeticOperations(data, str);
}

int main(int argc, char *argv[]) {
    if(argc!=2)return 0;
    string fileName, of, str;
    fileName = argv[1];
    for(int i=(int)fileName.size()-3; i>=0;i--){
        if(fileName[i]=='/' || fileName[i]=='\\')break;
        of = fileName[i] + of;
    }
    fstream file1;
    codeWriterMain object(of);
    file1.open(fileName, ios::in);
    while(getline(file1, str)){
        vector<string> parsed;
        parsed = Parser::parserString(str);
        if(parsed.empty())continue;
        codeWriter(object, str, parsed);
    }
    file1.close();
    return 0;
}