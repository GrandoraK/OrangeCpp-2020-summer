#include <iostream>
#include "SimpleFunc.h"	// Here

void BestComImpl::SimpleFunc(void)
{
	std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}

//main함수를 제외한 나머지 두 함수의 정의를 삽입