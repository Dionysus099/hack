#include<stdlib.h>
#include<iostream>
using namespace std;
#include "FiveNumberSummary.h"

FiveNumberSummary :: FiveNumberSummary(){
}

FiveNumberSummary :: ~FiveNumberSummary(){

}

ostream &operator<<(ostream &out, FiveNumberSummary &fns){
	out<<fns.s_min<<","<<fns.lq<<","<<fns.med<<","<<fns.uq<<","<<fns.s_max;
	return out;
}

