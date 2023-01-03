class Student{
    int num;
    float* grade;
    int ng;
    public:
    Student(int, float*, int);
    Student();
    Student(const Student& src);
    Student& operator=(const Student& src);
    void set(int student_num, float* grades, int ng_);
    void display() const;
    void read();
    ~Student();
};