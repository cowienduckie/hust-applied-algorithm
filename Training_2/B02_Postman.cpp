#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>


using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int cus_num = 0, max_carry = 0;
    long long min_time = 0;   //Number of customers
                                                    //Max packages can be carried
                                                    //Min time for shipping
    map <int, int> customer; //Store customer list
    vector <int> left;  //Customers at the left of Company 
    vector <int> right; //Customers at the right of Company 
    //-----left side-----------Company-----------right side------> 
    //
    //-----negative--------------0---------------positive-------->  

    //Preparation
    cin >> cus_num >> max_carry;

    for (int i = 0; i < cus_num; ++i){
        int location = 0, pack = 0;

        cin >> location >> pack;

        customer.insert(pair <int, int> (location, pack));
        if (location < 0) {
            left.push_back(location);
        }
        else {
            right.push_back(location);
        }
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    //Deliver for left side
    vector <int> :: iterator farthest = left.begin();
    int carry = 0;
    
    while (left.empty() == false){
        farthest = left.begin(); //Update new farthest customer
        if (carry == 0){
            int trip = abs((int)ceil((double)customer[*farthest] / max_carry));

            carry = max_carry * trip; //Refill packages
            min_time += abs(*farthest) * trip * 2;
        } 

        if (customer[*farthest] > carry){   //farthest order is not done
            customer[*farthest] -= carry;

            carry = 0;
        }
        else if (customer[*farthest] < carry) {  //farthest order is done and some packages in excess
            carry -= customer[*farthest];

            customer[*farthest] = 0;

            left.erase(farthest);
        }
        else { //farthest order is done and no excess
            customer[*farthest] = 0;

            left.erase(farthest);

            carry = 0;
        }
        
    }

    //Deliver for left side
    carry = 0;

    while (right.empty() == false){
        farthest = right.end() - 1; //Update new farthest customer
        if (carry == 0){
            long long trip = (int)ceil((double)customer[*farthest] / max_carry);

            carry = max_carry * trip; //Refill packages
            min_time += (*farthest) * trip * 2;
        } 

        if (customer[*farthest] > carry){   //farthest order is not done
            customer[*farthest] -= carry;

            carry = 0;
        }
        else if (customer[*farthest] < carry){  //farthest order is done and some packages in excess
            carry -= customer[*farthest];

            customer[*farthest] = 0;

            right.erase(farthest);
        }
        else { //farthest order is done and no excess
            customer[*farthest] = 0;

            right.erase(farthest);

            carry = 0;
        }
    }
    
    //Output
    cout << min_time;

    return 0;
}