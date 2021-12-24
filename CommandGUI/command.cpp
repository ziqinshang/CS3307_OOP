//
//  command.cpp
//  CS3307_A
//
//  Created by David Shang on 2021-09-23.
//

#include "command.hpp"
using namespace std;
command::command(string whole){
    //char_separator is the character delimiters much in the same way that strtok() does
    boost::char_separator<char> sep(", ");
    vector<string> tmplist; // the temporary container of the entire command
    boost::tokenizer<boost::char_separator<char>> tokens(whole, sep); //definition of tokenizer
    //for every string separated by a space, tokenize it, the parameters can be multiple by modification
        for(boost::tokenizer<boost::char_separator<char>>::iterator beg=tokens.begin(); beg!=tokens.end();++beg){
            if (beg==tokens.begin())cmd = *beg; //the first word of the entire string will be command
            else para = *beg; //the rest will be parameters
        }
    tmplist.push_back(cmd); //push the command into temporary container
    tmplist.push_back(para); //push the parameters into temporary container
    string tmpwhole = boost::algorithm::join(tmplist, " "); //concatenate command and parameters
    entire = tmpwhole; //put it into class attribute "entire"
}

string command::get_command(){
    return entire;
}
string command::get_result(){
    return result;
}
int command::get_code(){
    return code;
}
void command::execute(){
    string tmp2 = entire;//fetch the command
    vector<string> tmplist2;//create a temporary container for the result output
    boost::process::ipstream pipe_stream;
    try{ //try for the error, if a process_error was thrown, display error messages
    boost::process::child c(tmp2, boost::process::std_out > pipe_stream);
        //std::cout << c.exit_code() << std::endl;
        code = c.exit_code(); //set the code as exit code from boost
        c.wait();
        std::string line;
        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()){
            tmplist2.push_back(line); //push the result line into temporary container
        }
        //concatenate all results and separate them with a newline
        string tmpresult = boost::algorithm::join(tmplist2, "\n");
        cout << tmpresult << "\n";
        result = tmpresult;
    }
    catch (boost::process::process_error& exception) {
        std::cout << "ERROR" << std::endl;
        code = -1;
        result = "ERROR";
    }
}


