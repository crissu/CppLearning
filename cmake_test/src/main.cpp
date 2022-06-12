//main.cpp
#include <iostream>
#include<math.h>
#include<vector>
#include<future>
#include<pthread.h>
#include"./test/test.h"

double calcAvg(const std::vector<int> & vec){
    double sum = 0;
    for (auto & v : vec){
        sum += v;
    }
    return sum;
}

void Func(){
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    {
        std::future<double> fu = std::async(std::launch::async, calcAvg, std::ref(vec));
    }
    std::cout << "func data"<< "--------" << std::endl;
}

int main(int argc, char** argv)
{
    Func();
    // myprint();
    std::cout << "func main"<< "--------" << std::endl;
    return 0;
}

// #include <pthread.h>
// #include <stdio.h>
 
// void* threadFunc(void* p)
// {
// 	while (1)
// 	{
// 		printf("a");
// 	}
 
// 	return NULL;
// }
 
// int main ()
// {
// 	pthread_t id;
// 	pthread_create (&id, NULL, threadFunc, NULL);
 
// 	while (1)
// 	{
// 		printf("b");
// 	}
 
// 	return 0;
// }   