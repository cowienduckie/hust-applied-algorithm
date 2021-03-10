#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector <string> dir;    //Current directory in vector;
    dir.push_back("");     //Root directory

    int num = 0; cin >> num;    //Take number of commands

    for (int i = 0; i < num; i++){

        string cmd; cin >> cmd; //Take current command;

        if (cmd == "pwd"){  //pwd -> print current directory
            for (string str : dir){
                cout << str << "/";
            }
            cout << endl;
        }
        else{   //cd [path] -> change current directory
            string str;    cin >> str;
            stringstream ss(str);   //Store path into stringstream

            vector <string> path;

            while (getline(ss, str, '/')){  //Split stream into folders by ignore slashes
                if (str == "")  dir.clear();    //If path begin with slash -> absolute

                if (str == "..")  dir.pop_back();   //Return parent folder
                else
                    dir.push_back(str);
            }            
        }
    }

    return 0;
}