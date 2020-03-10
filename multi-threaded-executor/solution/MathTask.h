#pragma once


class MathTask
{
private:
    string task;
    int operand1;
    int operand2;

    string optr;
    int result;

    friend ostream & operator<<(ostream & out,const MathTask & t);

public:
    MathTask() {
        
    }
    MathTask(const string & task,const int & operand1,const int & operand2)
    {
        this->task = task;
        this->operand1 = operand1;
        this->operand2 = operand2;
    }

    void eval() {
        if(task == "add") {
            optr = "+";
            result = operand1+operand2;
        }
        else if(task == "sub") {
            optr = "-";
            result = operand1-operand2;
        }
        else if(task == "mul") {
            optr = "*";
            result = operand1*operand2;
        }
        else if(task == "div") {
            optr = "/";
            result = operand1/operand2;
        }
    }
};


ostream & operator<<(ostream & out,const MathTask & t) {
    out << t.operand1 << t.optr << t.operand2 << '=' <<  t.result;
    return out;
}