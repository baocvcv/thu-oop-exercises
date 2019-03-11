#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "ReviewerAssigner.h"

void ReviewerAssigner::load(){
    std::ifstream file_in("ContactEmail.txt");
    std::string student_no;
    std::string email;
    file_in >> student_no >> email;

    while(!file_in.eof()){
        file_in >> student_no >> email;
        StudentInfo info;
        info.student_no = student_no;
        info.email = email;
        student_infos.push_back(info);
    }
    file_in.close();
}

void ReviewerAssigner::choose(){
    srand((unsigned)time(0));

    for(unsigned int i = 0; i < student_infos.size(); i++){
        for(int j = 0; j < 3; j++){
            int x;
            bool flag;
            do{
                flag = true;
                x = rand() % student_infos.size();
                for(unsigned int k = 0; k < student_infos[i].reviewers.size(); k++){
                    if(student_infos[i].reviewers[k] == x){
                        flag = false;
                        break;
                    }
                }
            }while(!flag);
            student_infos[i].reviewers.push_back(x);
        }
    }
}

void ReviewerAssigner::output(std::string filename){
    std::ofstream file_out(filename);
    file_out << "Student_No.  " << "Email  " << "Reviewer_No." << std::endl;
    for(unsigned int i = 0; i < student_infos.size(); i++){
        file_out << student_infos[i].student_no << ' ';
        file_out << student_infos[i].email << ' ';
        for(unsigned int j = 0; j < 3; j++){
            file_out << student_infos[student_infos[i].reviewers[j]].student_no << ' ';
        }
        file_out << std::endl;
    }
    file_out.close();
}

void ReviewerAssigner::show(){
    std::cout << "Student No.\t" << "Email\t" << "Reviewers\t" << std::endl; 
    for(unsigned int i = 0; i < student_infos.size(); i++){
        std::cout << student_infos[i].student_no << ' ';
        std::cout << student_infos[i].email << ' ';
        for(unsigned int j = 0; j < student_infos[i].reviewers.size(); j++){
            std::cout << student_infos[i].reviewers[j] << ' ';
        }
        std::cout << std::endl;
    }
}
