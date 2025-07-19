#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;

template <class f>
class audioprocessing {
public:
    vector<f> inputsignal;
    int windowsize;

    audioprocessing(int windowsize=3 ) {
        this->windowsize = windowsize;
    }


    virtual void noisereduction() = 0;

    vector<f> printsignal() {
        return inputsignal;
    }
};

template <class f>
class medianfilter : public audioprocessing<f> {
public:
    medianfilter(int windowsize ) {
        this->windowsize = windowsize;
    }

    void noisereduction()  {
        vector<f> outputsignal;
        int halfwindow = this->windowsize / 2;
        
        for (int i = 0; i < this->inputsignal.size(); ++i) {
            vector<f> window;
            for (int j = -halfwindow; j <= halfwindow; ++j) {
                int id = i + j;
                if (id >= 0 && id < this->inputsignal.size()) {
                    window.push_back(this->inputsignal[id]);
                }
            }
            
            
            sort(window.begin(), window.end());
            f median = window[window.size() / 2];
            outputsignal.push_back(median);
        }

        
        this->inputsignal = outputsignal;
    }
};

int main() {
    string inputfile = "/Users/nikitagrover/CODIIIIING/pbl/inputsignal.txt";
    string outputfile = "/Users/nikitagrover/CODIIIIING/pbl/outputsignal.txt";
    vector<double> inputsignal;

    ifstream input(inputfile);
    if (!input) {
        cerr << "file couldn't be opened due to an error" << inputfile << endl;
        return -1;
    }
    
    double v;
    while (input >> v) {
        inputsignal.push_back(v);
    }
    input.close();

    medianfilter<double> filter(3);
    filter.inputsignal = inputsignal;

    
    filter.noisereduction();

    ofstream output(outputfile);
    if (!output) {
        cerr << "the file couldn't be opened due to an error  " << outputfile << endl;
        return -1;
    }

    
    for (int i = 0; i < filter.printsignal().size(); ++i) {
        output << filter.printsignal()[i] << endl;
    }

    output.close();
    cout << "noise reduction is complete! " << endl;
    return 0;
}
