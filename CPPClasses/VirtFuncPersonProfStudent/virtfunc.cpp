#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/virtual-functions/problem

class Person {
    protected :
        string name;
        int age;
    public :
        virtual void getdata() {cin >> name >> age;}
        virtual void putdata() {cout << name << age << endl;};
};

class Professor: public Person {
    private :
        int publications;
        int cur_id;
        static int id;
    public :
        Professor() {
            cur_id = ++id;
        }
        void getdata() {
            cin >> name >> age >> publications;
            return;
        }
        void putdata() {cout << name << " " << age << " " << publications << " " << cur_id << endl;}
}; int Professor::id = 0;

class Student: public Person {
    private :
        vector<int> marks;
        int cur_id;
        int marks_sum;
        static int id;
    public :
        Student() : marks(6,0) {
            cur_id = ++id;
        };
        void getdata() {
            cin >> name >> age;
            for (unsigned iter = 0; iter < marks.size(); ++iter) {
                cin >> marks[iter];
            }
            return;
        }
        int sum_marks() {
            marks_sum = 0;
            for (unsigned iter = 0; iter <marks.size(); ++iter) {
                marks_sum = marks_sum + marks[iter];
            }
            return marks_sum;
        }
        void putdata() {cout << name << " " << age << " " << sum_marks() << " " << cur_id << endl;}
        
}; int Student::id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}