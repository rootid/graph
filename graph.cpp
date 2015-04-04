#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<utility>

using namespace std;

//Traversal 
struct GraphInput {
    int noOfVertex;
    int noOfEdges;
    vector< pair<int,int> > edges;
    GraphInput () : 
        noOfVertex(0),noOfEdges(0)
    {

    }
};

struct AdjM {
   
    int vx;
    int es; 
    vector<vector <int> > g;
    AdjM (int i,int j) : 
        vx(i) , es(j) 
    {
        g.resize(vx,vector<int>(vx,0) );    
    }
    void addEdge (int i,int j) {
        g[i][j] = 1;
    }
};


vector<string> splitString(string& s,char del) {
    int idx = 0;
    int sIdx = 0;
    int len = s.length();
    vector<string> result;
    while (idx < len) {
        if (s[idx] == del) {
           result.push_back(s.substr(sIdx, (idx - sIdx))); 
           sIdx = idx + 1;
        }
        idx += 1;
    }
    result.push_back(s.substr(sIdx)); 
    return result;
}

void representAdjMat (GraphInput &gip) {
    
    AdjM *adjM = new AdjM (gip.noOfVertex,gip.noOfEdges);
    for (int i=0;i<gip.edges.size();i++) {
       //cout << gip.edges[i].first << " , " << gip.edges[i].second << endl;
       adjM->addEdge(gip.edges[i].first,gip.edges[i].second);
    }

    //display graph
    for (int i=0;i < adjM->g.size();i++) {
        for (int j=0;j < adjM->g[i].size();j++) {
            cout << adjM->g[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

}


int main () {

    string line;
    ifstream myfile("tiny.txt");
    int idx = 0;
    GraphInput gip;
    if (myfile.is_open() ) {
        while (getline(myfile,line) )  {
           //cout <<  line << endl;
           if (idx == 0) {
               gip.noOfVertex = stoi(line);
           } else if (idx == 1) {
               gip.noOfEdges = stoi(line);
           } else {
                vector<string> fs = splitString(line,' ');
                int firstV = stoi(fs[0]);
                int secondV = stoi(fs[1]);
                gip.edges.push_back(make_pair(firstV,secondV));
           }
           idx++;
        }
    }
    myfile.close();

    representAdjMat (gip);

    return 0;
}


