/* Problem: You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted. */

double average(int* salary, int salarySize){
double sum=0,min=*(salary+0),max=0;
    int i;
    for(i=0;i<salarySize;i++){
        sum+=*(salary+i);
        if(min>*(salary+i)) min=*(salary+i);
        if(max<*(salary+i)) max=*(salary+i);
    }
    return((sum-(min+max))/(salarySize-2));
}
