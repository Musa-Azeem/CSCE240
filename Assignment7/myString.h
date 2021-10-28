class myString
{
    private:
        int size;
        char* str;
    public:
        myString();
        myString(const int _size);
        myString(const char _str[], const int _size);
        myString(const myString &rhs);
        ~myString();


        void set(const int index, const char val);
        char at(const int index) const;
        int length() const;
        myString substring(const int startIndex, const int length) const;
        void clear();
        bool empty() const;
        int find(const myString &substr, const int startIndex) const;
        int count(const myString &subtr) const;
        bool equal(const myString &other) const;
        bool add(const myString &other);
        void remove(const int index, const int length);
        void print() const;
        
        const myString & operator=(const myString &rhs);
        bool operator==(const myString &rhs) const;
        bool operator!=(const myString &rhs) const;
        myString operator+(const myString &rhs) const;
        myString operator-(const myString &rhs) const;
        const myString & operator++();
        //overload for pre increment somehow
        char operator[](const int index);   //get
        //void operator[](const int index); overload for setting
        //>>
        //<<

};
