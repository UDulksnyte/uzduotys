#include "Libraries.h"
#include "Functions.h"

int main(){
    vector<string> details;
    vector<TYPES>firstRow;
    vector<vector<TYPES>>converted;
    vector<string>strings;
    vector<char>columnsNames;
    bool wrongInput;
    int x=1;

    string filename="C:\\Users\\37067\\CLionProjects\\stroustrup\\cmake-build-debug\\CMakeFiles\\failas.csv";
    details=readFile(filename,details);
    getTypes(details,converted);
    compareData(converted);
cout<<converted.size()<<endl;
    for(int d=0;d<firstRow.size()-1;d++){

    }
    cout<<endl;
    showDetails(converted,strings);

    return 0;

}