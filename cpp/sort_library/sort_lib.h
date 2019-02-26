/************************************
 * sort_lib.h
 * Header for sorting library
 * Author : Aditya Patwardhan
 */

#ifndef __SORT_LIB_H__
#define __SORT_LIB_H__

#include <iostream>
#include <vector>
/*
 * APIs for sorting arrays
 */

namespace sortLib
{
    class MySortLib
    {
    public:

        void quickSort(std::vector<int> &array);
 
    };
}

#endif
