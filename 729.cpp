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

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
