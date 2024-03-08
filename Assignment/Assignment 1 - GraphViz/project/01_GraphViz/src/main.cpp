/*
 * TODO: complete this file comment.
 */
#include <iostream>
#include <chrono>
#include <cmath>
#include "SimpleGraph.h"

using namespace std;

const double kPi = 3.14159265358979323;
void Welcome();
stringstream PromptUser();
int getInteger();
void nodesCircle(SimpleGraph& g,int x);
void addEdge(stringstream& buffer,SimpleGraph& g);

// Main method
int main() {
    Welcome();
    /* TODO: your implementation here */
    SimpleGraph g;
    int x;
    stringstream buffer;

    InitGraphVisualizer(g);
    buffer = PromptUser();
    buffer>>x;
    //getInteger();
    nodesCircle(g,x);
    addEdge(buffer,g);
    DrawGraph(g);


    return 0;
}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome() {
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}

stringstream PromptUser(){
    string filename;
    stringstream buffer;
    ifstream targetFile;


    cout<<"Please enter a filename to open:"<<endl;
    getline(cin,filename);
    targetFile.open(filename);
    while(!targetFile.is_open()){
        cout<<"cannot open the file,please try again"<<endl;
        getline(cin,filename);
    }

    buffer<<targetFile.rdbuf();
    return buffer;
}

int getInteger(){
    while(true){
        string line;
        int result;


        if(!getline(cin,line)){
            cout<<"try again"<<endl;
            continue;
        }

        istringstream microSeconds(line);
        if(microSeconds>>result){
            return result;
        }


    }
}
void nodesCircle(SimpleGraph& g,int x){

    for(int i=0;i<x;i++){
        Node t;
        t.x = cos(2*kPi*i/x);
        t.y = sin(2*kPi*i/x);
        g.nodes.push_back(t);

    }

}

void addEdge(stringstream buffer,SimpleGraph& g){
    int st,ed;
    Edge E;
    while(buffer.eof()){
        buffer>>st;
        buffer>>ed;

        E.start = st;
        E.end = ed;

        g.edges.push_back(E);
    }
}




