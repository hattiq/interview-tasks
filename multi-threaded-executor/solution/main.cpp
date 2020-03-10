#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#include<thread>
#include <mutex>

using namespace std;

#include"MathTask.h"
#include"MathTaskExecutable.h"
#include"MathTaskExecuterPool.h"
#include"CSVReader.h"


int main(int argc, char* argv[]) 
{
    vector<MathTask> tasks = CSVReader::read("tasks.csv",'|');
    
    MathTaskExecuterPool pool(tasks,cout);
    pool.join();
}