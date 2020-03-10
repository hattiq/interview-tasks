#pragma once

class MathTaskExecutable
{
private:
    MathTask task;
    ostream & out;
    mutex & out_mutex;
public:
    MathTaskExecutable(const MathTask & t,ostream & os,mutex & mutx) : out(os), out_mutex(mutx)
    {
        this->task = t;
    }

    void operator()()
    {
        task.eval();
        lock_guard<mutex> guard(out_mutex);
        out<<task<<'\n';
    }
};
