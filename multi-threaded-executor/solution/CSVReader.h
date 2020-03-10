#pragma once

class CSVReader
{
public:
    static vector<MathTask> read(string filename,char seperator) 
    {
        ifstream fin;
        vector<MathTask> tasks;
        fin.open(filename);
        if(!fin) {
            cout << "Unable to open file";
            return tasks;
        }
        string line;
        getline(fin,line);
        while(getline(fin,line)) 
        {
            istringstream ss(line);
            string task,op1,op2;
            getline(ss,task,seperator);
            getline(ss,op1,seperator);
            getline(ss,op2);

            tasks.push_back(MathTask(task,stoi(op1),stoi(op2)));
        }
        return tasks;
    }
};
