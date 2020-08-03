#include <iostream>
#include "fraction.h"

using namespace std;


fraction::fraction() {  //constructor set defalut 
	num = 1;
	denom = 1;
}
fraction::fraction(int newnum, int newdenom) {//set new value

	num = newnum;
	denom = newdenom;
}

void fraction::setnum(int newnum) {  // mutators set num
	num = newnum;
}
void fraction::setdenom(int newdenom) {//set denom
	denom = newdenom;

}

fraction setlower(fraction& f) {//set lower fraction
	//define tmp = f.num
	int tmp = f.num;
	//denom must not = 0, because we can't divine by 0
	if (f.denom != 0) {
		//if denom = num, change it
		if (f.num == f.denom && f.num != 0 && f.denom != 0) {
			f.num = f.num / f.num;
			f.denom = f.denom / tmp;

			return f;
		}
		//if f.num % f.denom == 0, change it
		else if (f.num % f.denom == 0) {
			f.num = f.num / f.denom;
			f.denom = f.denom / f.denom;

			return f;
		}
		//if f.denom % f.num == 0, change it
		else if (f.denom % f.num == 0) {
			f.num = f.num / f.num;
			f.denom = f.denom / tmp;

			return f;
		}
		//else some thing 4/6 , 6/9
		else {
			//loop for divine
			int check0 = 0;
			while (check0 != 1) {

				//loop divine by 2
				if (f.num % 2 == 0 && f.denom % 2 == 0) {

					int check1 = 0;
					while (check1 != 1) {
						f.num = f.num / 2;
						f.denom = f.denom / 2;
						if (f.num % 2 != 0 || f.denom % 2 != 0) {

							check1 = 1;
						}
					}

				}
				//loop divine by 3
				else if (f.num % 3 == 0 && f.denom % 3 == 0) {

					int check2 = 0;
					while (check2 != 1) {
						f.num = f.num / 3;
						f.denom = f.denom / 3;
						if (f.num % 3 != 0 || f.denom % 3 != 0) {
							check2 = 1;

						}
					}

				}
				//if can't divine out of loop
				else {
					check0 = 1;
				}
			}
			//and return vaule
			f.num = f.num;
			f.denom = f.denom;
			return f;
		}
	}
	//if denom = 0
	else {
		f.num = f.num;
		f.denom = f.denom;
		return f;
	}
}

int fraction::getnum() {   //accessors get num
	return num;
}
int fraction::getdenom() { //get denom
	return denom;
}

//show display num and denom
void fraction::show(int i) {
	cout << "f" << i << " num = " << num << endl;
	cout << "f" << i << " denom = " << denom << endl;
}


//operator ++
fraction operator ++(fraction& f1) {
	//num plus follow denom
	for (int i = 0; i < f1.denom; i++) {
		f1.num++;
	}
	//if denom=0 so vaule is 0/0 
	//0/0 +1 = 1/1
	if (f1.denom == 0) {
		f1.num++;
		f1.denom++;
	}
	return f1;
}
//operator --
fraction operator --(fraction& f1) {
	//num minus follow denom
	for (int i = 0; i < f1.denom; i++) {
		f1.num--;
	}
	//if denom=0 so vaule is 0/0 
	//0/0 -1 = -1/1
	if (f1.denom == 0) {
		f1.num--;
		f1.denom = 0;
	}
	return f1;
}




//operator ==
bool operator ==(fraction f1, fraction f2) {
	//set low f1

	setlower(f1);
	setlower(f2);
	//so we have low fraction
	//set int
	int num1 = f1.num;
	int denom1 = f1.denom;
	int num2 = f2.num;
	int  denom2 = f2.denom;

	//if num1 == num2 && denom1 == denom2 it equal
	if (num1 == num2 && denom1 == denom2) {
		return true;
	}
	//else false
	else {
		return false;
	}

}
bool operator !=(fraction f1, fraction f2) {
	//set low f1

	setlower(f1);
	setlower(f2);
	//so we have low fraction
	int num1 = f1.num;
	int denom1 = f1.denom;
	int num2 = f2.num;
	int  denom2 = f2.denom;

	if (num1 != num2 || denom1 != denom2) {
		return true;
	}
	else {
		return false;
	}

}
bool operator >(fraction f1, fraction f2) {

	setlower(f1);
	setlower(f2);
	//so we have low fraction
	int num1 = f1.num;
	int denom1 = f1.denom;
	int num2 = f2.num;
	int  denom2 = f2.denom;
	int sumnum1;
	int sumnum2;
	int sumdivine;
	if (denom1 == denom2) {
		if (num1 > num2) {
			return true;
		}
		else {
			return false;
		}

	}
	else if (denom1 == 0 && denom2 == 0) {
		return false;

	}
	else if (denom1 == 0) {

		return false;

	}
	else if (denom2 == 0) {
		return true;

	}
	else {
		//make divine equal
		sumdivine = denom1 * denom2;
		//make true sum
		sumnum1 = (sumdivine / denom1) * num1;
		sumnum2 = (sumdivine / denom2) * num2;
		//compare it
		if (sumnum1 > sumnum2) {
			return true;
		}
		else {
			return false;
		}
	}


}

bool operator <(fraction f1, fraction f2) {

	setlower(f1);
	setlower(f2);
	//so we have low fraction
	int num1 = f1.num;
	int denom1 = f1.denom;
	int num2 = f2.num;
	int  denom2 = f2.denom;
	int sumnum1;
	int sumnum2;
	int sumdivine;
	if (denom1 == denom2) {
		if (num1 < num2) {
			return true;
		}
		else {
			return false;
		}

	}
	else if (denom1 == 0 && denom2 == 0) {
		return false;

	}
	else if (denom1 == 0) {

		return true;

	}
	else if (denom2 == 0) {
		return false;

	}
	else {
		//make divine equal
		sumdivine = denom1 * denom2;
		//make true sum
		sumnum1 = (sumdivine / denom1) * num1;
		sumnum2 = (sumdivine / denom2) * num2;
		//compare it
		if (sumnum1 < sumnum2) {
			return true;
		}
		else {
			return false;
		}
	}


}

bool operator >=(fraction f1, fraction f2) {

	setlower(f1);
	setlower(f2);
	//so we have low fraction
	int num1 = f1.num;
	int denom1 = f1.denom;
	int num2 = f2.num;
	int  denom2 = f2.denom;
	int sumnum1;
	int sumnum2;
	int sumdivine;
	if (denom1 == denom2) {
		if (num1 >= num2) {
			return true;
		}
		else {
			return false;
		}

	}
	else if (denom1 == 0 && denom2 == 0) {
		return true;

	}
	else if (denom1 == 0) {

		return false;

	}
	else if (denom2 == 0) {
		return true;

	}
	else {
		//make divine equal
		sumdivine = denom1 * denom2;
		//make true sum
		sumnum1 = (sumdivine / denom1) * num1;
		sumnum2 = (sumdivine / denom2) * num2;
		//compare it
		if (sumnum1 >= sumnum2) {
			return true;
		}
		else {
			return false;
		}
	}

}

bool operator <=(fraction f1, fraction f2) {

	setlower(f1);
	setlower(f2);
	//so we have low fraction
	int num1 = f1.num;
	int denom1 = f1.denom;
	int num2 = f2.num;
	int  denom2 = f2.denom;
	int sumnum1;
	int sumnum2;
	int sumdivine;
	if (denom1 == denom2) {
		if (num1 <= num2) {
			return true;
		}
		else {
			return false;
		}

	}
	else if (denom1 == 0 && denom2 == 0) {
		return true;

	}
	else if (denom1 == 0) {

		return true;

	}
	else if (denom2 == 0) {
		return false;

	}
	else {
		sumdivine = denom1 * denom2;
		sumnum1 = (sumdivine / denom1) * num1;
		sumnum2 = (sumdivine / denom2) * num2;
		if (sumnum1 <= sumnum2) {
			return true;
		}
		else {
			return false;
		}
	}

}

fraction operator +(fraction f1, fraction f2) {
	setlower(f1);
	setlower(f2);

	//so we have low fraction
	if (f1.num == 0 || f1.denom == 0) {
		f1.num = 0;
		f1.denom = 0;
	}
	else if (f2.num == 0 || f2.denom == 0) {
		f2.num = 0;
		f2.denom = 0;
	}
	int divine = 0;
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	//case1 denom1 = denom2
	if (f1.denom == f2.denom) {
		f1.num = f1.num + f2.num;
		f1.denom = f1.denom;
		//if num = denom = 1/1
		if (f1.num == f1.denom && f1.denom != 0) {
			f1.num = f1.num / f1.num;
			f1.denom = f1.denom / f1.denom;
			return f1;
		}
		else {
			return f1;
		}


	}
	else {
		if (f1.denom != 0 && f2.denom != 0) {
			//normal case
			divine = f1.denom * f2.denom;
			num1 = (divine / f1.denom) * f1.num;
			num2 = (divine / f2.denom) * f2.num;
			sum = num1 + num2;

			f1.num = sum;
			f1.denom = divine;
			//set lower
			if (sum == divine) {
				f1.num = sum / sum;
				f1.denom = divine / divine;
				return f1;
			}
			else if (divine % sum == 0) {
				f1.num = sum / sum;
				f1.denom = divine / sum;
				return f1;
			}
			else {
				return f1;
			}
		}
		//case 0 return
		else if (f1.denom == 0 || f1.num == 0) {
			f1.num = f2.num;
			f1.denom = f2.denom;
			return f1;
		}
		//some thing else return
		else {
			f1.num = f1.num;
			f1.denom = f1.denom;
			return f1;
		}
	}

}

fraction operator -(fraction f1, fraction f2) {
	setlower(f1);
	setlower(f2);
	//so we have low fraction
	//set != 0
	if (f1.num == 0 || f1.denom == 0) {
		f1.num = 0;
		f1.denom = 0;
	}
	if (f2.num == 0 || f2.denom == 0) {
		f2.num = 0;
		f2.denom = 0;
	}
	//set int
	int divine = 0;
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	//case1 denom1 = denom2
	if (f1.denom == f2.denom) {
		f1.num = f1.num - f2.num;
		f1.denom = f1.denom;
		//if num = denom = 1/1
		if (f1.num == f1.denom) {
			f1.num = f1.num / f1.num;
			f1.denom = f1.denom / f1.denom;
			return f1;
		}
		//if num =0 = 0/0
		else if (f1.num == 0) {
			f1.num = 0;
			f1.denom = 0;
			return f1;
		}
		// return
		else {
			return f1;
		}
	}

	else {
		//denom must !=0
		if (f1.denom != 0 && f2.denom != 0) {
			//normal case
			divine = f1.denom * f2.denom;
			num1 = (divine / f1.denom) * f1.num;
			num2 = (divine / f2.denom) * f2.num;
			sum = num1 - num2;

			//if num = denom = 1/1
			if (sum == divine) {
				f1.num = sum / sum;
				f1.denom = divine / divine;
				return f1;
			}
			//if num =0 = 0/0
			else if (sum == 0) {
				f1.num = 0;
				f1.denom = 0;
				return f1;
			}
			//set lower
			else if (divine % sum == 0 && sum > 1) {
				f1.num = sum / sum;
				f1.denom = divine / sum;

				return f1;
			}
			else {
				f1.num = sum;
				f1.denom = divine;

				return f1;
			}
		}
		//case 0 return
		else if (f1.denom == 0 || f1.num == 0) {
			f1.num = f2.num;
			f1.denom = f2.denom;
			return f1;
		}
		//some thing else return
		else {
			f1.num = f1.num;
			f1.denom = f1.denom;
			return f1;
		}
	}

}

fraction operator *(fraction f1, fraction f2) {
	setlower(f1);
	setlower(f2);
	//so we have low fraction

	int divine = 0;
	int sum = 0;
	// multiple it!!
	divine = f1.denom * f2.denom;
	sum = f1.num * f2.num;
	//change to lower
	if (divine != 0 || sum != 0) {

		if (sum == divine && sum != 0) {
			f1.num = sum / sum;

			f1.denom = divine / sum;

			return f1;
		}
		else if (divine % sum == 0 && sum != 0) {

			f1.num = sum / sum;
			f1.denom = divine / sum;
			return f1;
		}
		else {

			f1.num = sum;
			f1.denom = divine;
			return f1;
		}
	}
	else if (sum == 0 || divine == 0) {
		f1.num = 0;
		f1.denom = 0;
		return f1;
	}
	else {

		f1.num = 0;
		f1.denom = 0;
		return f1;
	}

}

fraction operator /(fraction f1, fraction f2) {
	setlower(f1);
	setlower(f2);
	//so we have low fraction
	int divine = 0;
	int sum = 0;
	int tmpnum = 0;
	//change f2.denom to num and numto denom
	tmpnum = f2.num;
	f2.num = f2.denom;
	f2.denom = tmpnum;

	// multiple it!!
	divine = f1.denom * f2.denom;
	sum = f1.num * f2.num;
	//change it to lower
	if (divine != 0 || sum != 0) {
		if (sum == divine && sum != 0) {
			f1.num = sum / sum;
			f1.denom = divine / sum;
			return f1;
		}
		else if (divine % sum == 0 && sum != 0) {
			f1.num = sum / sum;
			f1.denom = divine / sum;
			return f1;
		}
		else {
			f1.num = sum;
			f1.denom = divine;
			return f1;
		}
	}
	else if (sum == 0 || divine == 0) {
		f1.num = 0;
		f1.denom = 0;
		return f1;
	}
	else {
		f1.num = 0;
		f1.denom = 0;
		return f1;
	}

}