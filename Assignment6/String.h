class String
{
    private:
        int size;
        char* str;
    public:
        String();
        String(const int _size);
        String(const char _str[], const int _size);
        String(const String &rhs);


        void set(const int index, const char val);
        char at(const int index) const;
        int length() const;
        String substring(const int startIndex, const int length) const;
        void clear();
        bool empty() const;
        int find(const String substr, const int startIndex) const;
        int count(const String subtr) const;
        bool equal(const String other) const;
        bool add(const String other);
        void print() const;
        
        bool operator==(const String other) const;

        ~String();
};
