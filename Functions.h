#include "Libraries.h"
void displayMessage (string message){
    cout<<message<<endl;
}
enum TYPES{INTEGER, STRING, CHAR, EMPTY,UNKNOWN};
vector<string>readFile(string filename,vector<string>scannedFile){
string line;
    fstream file (filename, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {

            scannedFile.push_back(line);
        }
    }
    else
        cout<<"Could not open the file\n";
    return scannedFile;
}

char* getCharArr(string s) {
    char arr[s.length()+1];
    strcpy(arr, s.c_str());
    char* pointer=arr;
    return pointer;
}
int countDigits(string val){
    int i,check,j;
    int it=0;
    char arr[val.length()+1];
    for(i=0;i<=val.length();i++){
        arr[i]= (getCharArr(val))[i];
    }
    for(j=0;j<val.length();j++){
        check= isdigit(arr[j]);
        if (check)
            it++;
    }
    return it;
}


TYPES checkType(string val){
    int it=countDigits(val);
    if(it==val.length()&&it>0){
        return INTEGER;
    }
    else if(it==0&&val.length()>1){
        return STRING;
    }
    else if(it==0&&val.length()==1){
        return CHAR;
    }

    else if(val.length()==0){
        return EMPTY;
    }
    else
      return UNKNOWN;
}
void getTypes(vector<string>file,vector<vector<TYPES>> &results) {
    vector<TYPES> rows;
    string word;
    int it, i,c;
    TYPES types;
    for (i = 1; i < file.size(); i++) {
        stringstream str(file[i]);
        while (getline(str, word, ',')) {
            types = checkType(word);
            rows.push_back(types);
        }
        results.push_back(rows);
        rows.clear();
    }
}
char getColumnName(int pos)
{
    int i;
    char letter;
    {
        letter = pos + 65;
    }
    return letter;
}
string enumString(TYPES Entype){
    string type;

    switch (Entype)
    {
        case 0:
            type="INTEGER";
            break;
        case 1:
            type="STRING";
            break;
        case 2:
            type="CHAR";
            break;
        case 3:
            type="EMPTY";
            break;
        default: type="UNKNOWN";

    }
    return type;
}
void compareData(vector<vector<TYPES>>converted){
    vector<TYPES>firstRow=converted[0];
        for(int i=1;i<converted.size()-1;i++) {
            for (int j = 0; j < firstRow.size(); j++) {
                bool wrongInput = false;
                vector<TYPES> firstRow = converted[0];
                if (firstRow[j] == CHAR&&converted[i][j] == STRING ||
                firstRow[j] == EMPTY && converted[i][j] == STRING||
                        firstRow[j] == STRING&&converted[i][j] ==INTEGER ) {
                    converted[0][j] = STRING;
                }
                else if (firstRow[j] == CHAR&&converted[i][j] == EMPTY||
                        firstRow[j] == EMPTY&&converted[i][j] == CHAR||
                        firstRow[j]==CHAR
                ) {
                    converted[0][j] = CHAR;
                }
                else if (firstRow[j] == STRING && converted[i][j] == EMPTY||firstRow[j] == STRING) {
                    converted[0][j] = STRING;
                }
                else if (firstRow[j] == STRING && converted[i][j] == CHAR) {
                    converted[0][j] = STRING;
                }
                else if (firstRow[j] ==INTEGER && converted[i][j] == STRING) {
                    converted[0][j] = STRING;
                }
                else if (firstRow[j] ==INTEGER && converted[i][j] == UNKNOWN) {
                    converted[0][j] = UNKNOWN;
                }
                else if (firstRow[j] == INTEGER && converted[i][j] == EMPTY) {
                    converted[0][j] = INTEGER;
                } else if (firstRow[j] == EMPTY && converted[i][j] == INTEGER) {
                    converted[0][j] = INTEGER;
                } else if (firstRow[j] == EMPTY && converted[i][j] == UNKNOWN ||
                           firstRow[j] == STRING && converted[i][j] == UNKNOWN ||
                           firstRow[j] == CHAR && converted[i][j] == UNKNOWN||
                        firstRow[j] == UNKNOWN && converted[i][j] == INTEGER ||
                        firstRow[j] == UNKNOWN && converted[i][j] == STRING ||
                        firstRow[j] == UNKNOWN && converted[i][j] == CHAR||
                        firstRow[j]==UNKNOWN ||
                        firstRow[j] == UNKNOWN && converted[i][j] == EMPTY
                           ) {
                    converted[0][j] = UNKNOWN;
                } else {
                    wrongInput = true;
                }
                if (firstRow[j] != converted[i][j] && wrongInput == true) {
                    cout <<"INCORRECT DATA TYPE:  ROW: " << i + 1 << " COLUMN: ";
                    cout << getColumnName(j) << " ";
                    cout << "NOT " << enumString(firstRow[j]) << " BUT " << enumString(converted[i][j]) << endl;
                }
            }
        }
}

    void showDetails(vector<vector<TYPES>>types,vector<string>&output) {
        cout<<"DATA TYPES: "<<endl;
for(int i=0;i<types[0].size();i++){
    output.push_back(enumString(types[0][i]));
}
        for (int j = 0; j < output.size(); j++) {
            cout<<getColumnName(j);
            cout << " : " << output[j]<<" * ";
        }
        cout << endl;
    }
#ifndef STROUSTRUP_FUNCTIONS_H
#define STROUSTRUP_FUNCTIONS_H

#endif //STROUSTRUP_FUNCTIONS_H
