class MyCalendarTwo {
public:
    vector<pair<int,int>> bks;
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        MyCalendar doublebook = MyCalendar();
        for(int i = 0; i < bks.size(); i++){
            if(max(bks[i].first, start) < min(bks[i].second, end)){
                if(!doublebook.book(max(bks[i].first,start),min(bks[i].second,end)))
                    return false;
            }
        }
        bks.push_back(make_pair(start,end));
        return true;
    }

    private:
    class MyCalendar {
        public:
        vector<pair<int,int>> books;
        MyCalendar() {

        }

        bool book(int start, int end) {
            for(int i = 0; i < books.size(); i++){
                if(max(books[i].first, start) < min(books[i].second, end)){
                    return false;
                }
            }
            books.push_back(make_pair(start,end));
            return true;
        }
    };
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
