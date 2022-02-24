//  A2_Liao.cpp
//  Programming Assignment 2
//	Author: Yunan Liao
//	Calculate summary, average, stdev
//	https://github.com/ynliao99/cs231/blob/main/A2_Liao.cpp
//	Edit History:
//		2/23 Initial Version

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// use long double to guarantee that even larger numbers can be processed

class Stats
{
	public:
		Stats (vector<long double> nums_array);
		void calcAvg();
		void calcStdev();
		void printArray(int);
		void printData(int field);
	private:
		vector<long double> numbers;
		size_t size;
		long double sum = 0;
		long double avg = 0;
		long double stdev = 0;
		
};

Stats::Stats(vector<long double> nums_array)
{
	numbers = nums_array;
	size = numbers.size();
	for (int i = 0; i< size; i++){
		sum += numbers[i];
	}
	//cout << size;
	calcAvg();
	calcStdev();
}

void Stats::calcAvg()
{
	avg = sum / size;
}

void Stats::calcStdev()
{
	calcAvg(); // make sure avg is accurate
	long double temp_sum;
	for(int i = 0; i < size ; i++){
        temp_sum += pow(numbers[i] - avg, 2);
    }
	stdev = sqrt( temp_sum / size );
}

//PRINT DATA

void Stats::printArray()
{
	cout<<"\nNumbers in the array are: ";
	for(int i=0; i < size - 1 ; i++){
        cout << numbers[i] <<", ";
    }
    cout << numbers[size-1];
    cout<<endl;
}

void Stats::printData(int field)
{
	switch (field){
		case 0:
			cout<<"\nNumbers in the array are: ";
			for(int i=0; i < size - 1 ; i++){
        		cout << numbers[i] <<"; ";
    		}
    		cout << numbers[size-1];
    		cout<<endl;
    		break;
    	case 1:
    		cout<<"\nAvgerage :"<< avg << endl;	
    		break;
    	case 2:
    		cout<<"\nStandard Deviation :"<< stdev << endl;
    		break;
    	case 3:
    		cout<<"\nSummary :"<< sum << endl;
    		break;
    	case 4:
    		cout<<"\nArray Size :"<< size << endl;
    		break;
	}
}

vector<long double> buildArray(){
	long double temp[100];
	int n = 0;
	char x;
	cout<<"Please enter a group (max 100) of numbers, use SPACE to separate them: ";
    while((x=getchar())!='\n')
    {
    
        if(x!=' ' or x =='.')// use SPACE to seperate numbers, **make sure the DECIMAL POINT can be processed correctly
        {
            ungetc(x,stdin);
            cin>>temp[n++];
        }
    }
    vector<long double> nums;
    for (int i = 0; i<n ;i++){
        nums.push_back(temp[i]); //add numbers to the new array
    }
    return nums;
}

int main()
{
    
    Stats myStat1(buildArray()); // Construct a object
    
    //myStat1.printData(3);
    myStat1.printArray();
    myStat1.printData(1);
    myStat1.printData(2);
    
    return 0;
}
