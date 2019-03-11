#ifndef REVIEWERASSIGNER_H_
#define REVIEWERASSIGNER_H_

#include <string>
#include <vector>

class ReviewerAssigner{
    public:
        void load();
        void choose();
        void output(std::string filename);
        void show();

    private:
        class StudentInfo{
            public:
                std::string student_no;
                std::string email;
                std::vector<int> reviewers;
        };
        std::vector<StudentInfo> student_infos;
};

#endif // REVIEWERASSIGNER_H_
