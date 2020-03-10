#pragma once

class MathTaskExecuterPool 
{
private:
    mutex out_mutex;
    vector<thread> thread_pool;
public:
    MathTaskExecuterPool(vector<MathTask> & tasks,ostream & os) {

        for(MathTask & t : tasks) {
            thread_pool.push_back(thread(MathTaskExecutable(t,os,out_mutex)));
        }
        
    }

    void join() 
    {
        for(thread & t : thread_pool) {
            t.join();
        }
    }
};