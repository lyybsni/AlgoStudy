/* lyybsni C++ Goodbye 2018 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point{
    int x;
    int y;
    point(int x, int y):x(x),y(y){};
    
    point operator +(const point& vector){
        return point(x+vector.x, y+vector.y);
    }
    
    point operator -(const point& vector){
        return point(x-vector.x, y-vector.y);
    }
    
    bool operator ==(const point& point){
        return (point.x == x && point.y == y);
    }
};

bool comp(const point& pt1, const point& pt2){
    if (pt1.x > pt2.x) return true;
    else if(pt1.x == pt2.x) return pt1.y >= pt2.y;
    else return false;
}

ostream& operator <<(ostream& out, const point point){
    out << point.x << " " << point.y;
    return out;
}

bool find(const vector<point>& pts, const point& pt){
    for(point p:pts){
        if(p == pt) return true;
    }
    return false;
}

int main(){
    
    int number;
    cin >> number;
    
    vector<point> source, vec;
    
    int tempx, tempy;
    for(int i = 0; i < number; i++){
        cin >> tempx >> tempy;
        source.push_back(point(tempx, tempy));
    }
    for(int i = 0; i < number; i++){
        cin >> tempx >> tempy;
        vec.push_back(point(tempx, tempy));
    }
    
    sort(source.begin(), source.end(), comp);
    sort(vec.begin(), vec.end(), comp);
    
    cout << source.front() + vec.back() << endl;
    
    return 0;
}
