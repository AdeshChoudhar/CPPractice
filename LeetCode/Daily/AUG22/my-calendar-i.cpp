//
// Created by adeshchoudhar on 3/8/22.
//

class MyCalendar {
public:
    map<int, int> bookings;

    MyCalendar() {

    }

    bool book(int start, int end) {
        bool ans = false;
        map<int, int>::iterator curr = this->bookings.begin(), prev = this->bookings.end();
        while ((curr != this->bookings.end()) && (curr->second <= start)) {
            prev = curr;
            curr++;
        }
        if (curr == this->bookings.end()) {
            this->bookings[start] = end;
            ans = true;
        } else {
            if ((prev->second <= start) && (curr->first >= end)) {
                this->bookings[start] = end;
                ans = true;
            }
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
